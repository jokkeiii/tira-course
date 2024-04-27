#include "Extended_queue.h"
#include "Plane.h"
#include "Queue.h"
#include "Random.h"
#include "Runway.h"
#include <iostream>

void initialize(int &end_time, int &queue_limit, double &arrival_rate,
                double &departure_rate, const int version)
/*
Pre:  The user specifies the number of time units in the simulation,
      the maximal queue sizes permitted, the version of simulation to run
      and the expected arrival and departure rates for the airport.
Post: The program prints instructions and initializes the parameters
      end_time, queue_limit, arrival_rate, and departure_rate to
      the specified values.
*/
{
  bool acceptable;

  switch (version) {
  case 1:
    std::cout << "This program simulates an airport with only one runway."
              << std::endl
              << "One plane can land or depart in each unit of time."
              << std::endl;

    break;
  case 2:
    std::cout << "This program simulates an airport with two runways."
              << std::endl
              << "One plane can land or depart in each unit of time."
              << std::endl;
    std::cout << "Up to what number of planes can be waiting to land "
              << "or take off at any time? " << flush;
    break;
  }

  std::cout << "Up to what number of planes can be waiting to land "
            << "or take off at any time? " << flush;
  cin >> queue_limit;

  std::cout << "How many units of time will the simulation run?" << flush;
  cin >> end_time;

  do {
    std::cout << "Expected number of arrivals per unit time?" << flush;
    cin >> arrival_rate;
    std::cout << "Expected number of departures per unit time?" << flush;
    cin >> departure_rate;
    if (arrival_rate < 0.0 || departure_rate < 0.0)
      cerr << "These rates must be nonnegative." << std::endl;
    else
      acceptable = true;

    if (acceptable && arrival_rate + departure_rate > 1.0)
      cerr << "Safety Warning: This airport will become saturated. "
           << std::endl;

  } while (!acceptable);
}

void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
  std::cout << time << ": Runway is idle." << std::endl;
}

void run_p1() {
  int end_time;    //  time to run simulation
  int queue_limit; //  size of Runway queues
  int flight_number = 0;
  double arrival_rate, departure_rate;
  initialize(end_time, queue_limit, arrival_rate, departure_rate, 1);
  Random variable;

  Runway small_airport(queue_limit);

  //  loop over time intervals
  for (int current_time = 0; current_time < end_time; current_time++) {
    //  current arrival requests
    int number_arrivals = variable.poisson(arrival_rate);
    for (int i = 0; i < number_arrivals; i++) {
      Plane current_plane(flight_number++, current_time, arriving);
      if (small_airport.can_land(current_plane) != success)
        current_plane.refuse();
    }

    //  current departure requests
    int number_departures = variable.poisson(departure_rate);
    for (int j = 0; j < number_departures; j++) {
      Plane current_plane(flight_number++, current_time, departing);
      if (small_airport.can_depart(current_plane) != success)
        current_plane.refuse();
    }

    Plane moving_plane;
    //  let at most one plane onto the runway at current_time.
    switch (small_airport.activity(current_time, moving_plane)) {
    case land:
      moving_plane.land(current_time);
      break;
    case takeoff:
      moving_plane.fly(current_time);
      break;
    case idle:
      run_idle(current_time);
    }
  }
  small_airport.shut_down(end_time);
}

void run_p2() {
  int end_time;
  int queue_limit;
  int flight_number = 0;
  double arrival_rate, departure_rate;
  initialize(end_time, queue_limit, arrival_rate, departure_rate, 2);
  Random variable;

  // create two runway objects: one for landings and another for takeoffs.
  Runway landing_runway(queue_limit);
  Runway takeoff_runway(queue_limit);

  for (int current_time = 0; current_time < end_time; current_time++) {
    //  current arrival requests
    int number_arrivals = variable.poisson(arrival_rate);
    for (int i = 0; i < number_arrivals; i++) {
      Plane current_plane(flight_number++, current_time, arriving);
      if (landing_runway.can_land(current_plane) != success)
        current_plane.refuse();
    }

    //  current departure requests
    int number_departures = variable.poisson(departure_rate);
    for (int j = 0; j < number_departures; j++) {
      Plane current_plane(flight_number++, current_time, departing);
      if (takeoff_runway.can_depart(current_plane) != success)
        current_plane.refuse();
    }

    Plane moving_plane;
    // process landing runway activity
    if (landing_runway.activity(current_time, moving_plane) == land) {
      moving_plane.land(current_time);
    } else {
      run_idle(current_time); // if no landings, check for idleness.
    }

    // process takeoff runway activity separately
    if (takeoff_runway.activity(current_time, moving_plane) == takeoff) {
      moving_plane.fly(current_time);
    } else {
      run_idle(current_time); // if no takeoffs, it may still be idle.
    }
  }

  landing_runway.shut_down(end_time);
  takeoff_runway.shut_down(end_time);
}

//  Airport simulation program
int main() {
  bool running = true;
  int choice;

  while (running) {
    std::cout << "Airport Simulator Menu:\n"
              << "1. Run P1 version of Airport simulator\n"
              << "2. Run P2 version of Airport simulator\n"
              << "6. Quit the program\n"
              << "Your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      run_p1();
      break;
    case 2:
      run_p2();
      break;
    case 6:
      running = false;
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
      break;
    }
  }

  std::cout << "Exiting program.\n";
  return 0;
}
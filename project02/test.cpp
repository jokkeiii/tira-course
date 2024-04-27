#include "Extended_queue.h"
#include "Plane.h"
#include "Queue.h"
#include "Random.h"
#include "Runway.h"
#include <iostream>

// enum Status { idle, land, takeoff, success };

void initialize(int &end_time, int &queue_limit, double &arrival_rate,
                double &departure_rate, int version, bool automated = true) {
  // Direct initialization without user input, for automated experiments
  end_time = 1000; // Set a default simulation time or pass as a parameter
  if (!automated) {
    // Your existing user input code for manual initialization
  }
  // Automated settings use parameters directly, so nothing more is needed here
}

void run_idle(int time) {
  std::cout << time << ": Runway is idle." << std::endl;
}

void run_simulation(int end_time, int queue_limit, double arrival_rate,
                    double departure_rate, int version) {
  int flight_number = 0;
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

void experiment_with_parameters(int min_queue_size, int max_queue_size,
                                int step, double min_rate, double max_rate,
                                double rate_step) {
  int version = 2; // Change as needed for version
  for (int queue_size = min_queue_size; queue_size <= max_queue_size;
       queue_size += step) {
    for (double arrival_rate = min_rate; arrival_rate <= max_rate;
         arrival_rate += rate_step) {
      for (double departure_rate = min_rate; departure_rate <= max_rate;
           departure_rate += rate_step) {
        std::cout << "Queue Size: " << queue_size
                  << ", Arrival Rate: " << arrival_rate
                  << ", Departure Rate: " << departure_rate << std::endl;
        int end_time = 1000; // Example simulation time
        run_simulation(end_time, queue_size, arrival_rate, departure_rate,
                       version);
      }
    }
  }
}

int main() {
  int min_queue_size = 5;
  int max_queue_size = 20;
  int queue_step = 5;
  double min_rate = 0.1;
  double max_rate = 0.9;
  double rate_step = 0.1;

  experiment_with_parameters(min_queue_size, max_queue_size, queue_step,
                             min_rate, max_rate, rate_step);

  return 0;
}

# Open the input file
input_file = "test.txt"
output_file = "output.txt"

# Define the keywords to search for
keywords = [
    "Queue Size:",
    "Total number of planes refused",
    "Total number of planes that",
]


# Function to filter lines based on keywords
def filter_lines(line):
    return any(keyword in line for keyword in keywords)


# Read the input file and filter lines
with open(input_file, "r") as f:
    lines = f.readlines()
    filtered_lines = filter(filter_lines, lines)

# Write filtered lines to the output file
with open(output_file, "w") as f:
    f.writelines(filtered_lines)

print("Filtered content has been saved to", output_file)

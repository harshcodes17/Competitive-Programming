def generate_tle_test_case(filename="in0.txt", n=1000):
    """
    Generates a test case for a deep linear tree with n nodes,
    where n is the maximum constraint to potentially induce TLE in inefficient solutions.
    The output is saved to a file specified by `filename`.
    """
    with open(filename, "w") as file:
        # First line: number of nodes
        file.write(f"{n}\n")
        
        # Next n-1 lines: edges forming a linear tree
        for i in range(1, n):
            file.write(f"{i} {i + 1}\n")

# Run the generator function to create in0.txt
generate_tle_test_case()

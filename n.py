# Step 1: Initialize the array
a = [i for i in range(50)]

# Step 2: Perform the bitwise OR operation and create a new array
b = [0] * 50  # Initialize the new array

for i in range(50):
    if i == 0:
        b[i] = a[i] | a[i+1]
    elif i == 49:
        b[i] = a[i-1] | a[i]
    else:
        b[i] = a[i-1] | a[i] | a[i+1]

# The result is stored in array b
print(b)

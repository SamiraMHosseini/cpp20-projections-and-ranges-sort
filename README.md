
# Modern Sorting Techniques in C++20: Exploring Projections and std::ranges::sort

This repository demonstrates the use of modern sorting techniques in C++20, focusing on the use of the `std::ranges::sort` function and projections to sort a vector of custom objects. This example provides a thorough understanding of how to leverage the new features introduced in C++20 to simplify and streamline your C++ code.

# What's Inside

The code defines a `Person` struct with `name`, `age`, and `ID` fields. A vector of `Person` objects is sorted in four different ways:

1. **Operator Overloading**: The less than operator is overloaded in the `Person` struct to sort by age.
3. **Custom Comparison Function**: A custom comparison function (`Comp`) is used to sort the vector by ID.
4. **Lambda Function**: A lambda function is used to sort the vector by name.
5. **C++20 Projections**: The new `std::ranges::sort` function from C++20 is used with a projection to sort the vector by age.

Each sorting method is printed out to clearly see the results.

## Why is this Useful

Embracing modern C++ features, such as those found in C++20, allows for more concise, readable, and efficient code. The examples in this repository serve as a reference for these new features and how to apply them in real-world scenarios.

## Requirements

This code uses features from C++20. Please ensure your compiler supports C++20 and that it is enabled; otherwise, the `std::ranges::sort` function will not work correctly.

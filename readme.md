# Normalization Sort Algorithm

## Overview
Normalization Sort is a sorting algorithm that leverages the concept of normalizing the values within an array to efficiently sort the data. This implementation uses a recursive approach to handle subsets of the array based on their normalized positions.

## Features
- Recursive sorting mechanism.
- Normalization based on the range of data within subsets of the array.
- Efficient handling of various data distributions including uniform, normal, and Pareto distributions.

## Usage
The repository contains the implementation of the Normalization Sort algorithm along with functions to generate different types of data distributions:

- Uniform data generation
- Normal (Gaussian) data generation
- Pareto data generation

## Building and Running
To build and run the Normalization Sort algorithm:

1. Clone the repository to your local machine.
2. Use a C++ compiler to compile the code. For example:
g++ -o normalizationSort main.cpp
3. Run the compiled executable:
./normalizationSort



## Example
The `main` function in `normalizationSort.cpp` demonstrates the use of the Normalization Sort algorithm with different data distributions. It includes timing the sorting process to measure performance.

## Data Generation
The program generates datasets of specified sizes using different distributions. Modify the parameters in the `main` function to test with different sizes and distribution characteristics.

## Performance
The algorithm's performance is measured in seconds, and the output displays the time taken to sort the datasets. Performance may vary based on dataset size and distribution.

## Contributions
Contributions to the algorithm, optimizations, and enhancements are welcome. Please feel free to fork the repository and submit pull requests.

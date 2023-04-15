# Word Search Algorithm using C++ and 2D Vectors

This program searches for specific words in a matrix and prints the location of the word if found. It makes use of C++ STL (Standard Template Library) which allows easier manipulation of data structures.

## Prerequisites

This program uses an input text file "mp6input.txt" with a matrix of characters. The input file should contain a list of words to search for. The output will be written to an output file "mp6output.txt".

## Usage

1. Open the project folder in your C++ IDE or text editor.
2. Compile and run the program.
3. Check the output file "mp6output.txt" to see the search results.

## Code Description

* The program uses a 2D vector named table with 8 rows and 8 columns to represent the matrix. The input matrix is read from the file and stored in this 2D vector.

* The program has three functions: horizontal_check(), vertical_check(), and diagonal_search() that search for the given word in horizontal, vertical and diagonal directions respectively. These functions return true if the word is found, otherwise false.

* The all_checks() function calls all three search functions and prints the location of the word if found, otherwise prints that the word was not found.

* The readWords() function reads the list of words from the input file and calls the all_checks() function for each word.

* The printArray() function prints the input matrix for verification purposes.

* The program uses an output file to print the search results.

## Dependencies
* The program uses the <bits/stdc++.h> header which includes all standard libraries in the C++ STL.

// Copyright (c) 2022 Melody Berhane All rights reserved.
//
// Created by: Melody Berhane
// Created on: Feb 2, 2022
// This program uses a nested for loops to generate and
// print random numbers in a 2d array. It then calculates
// and displays the average of the numbers.

#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <iomanip>

// this function calculates the smallest value in the array of elements
template <int rows, int columns>
float CalcAverage(int (&passedList)[rows][columns]) {
    float sum = 0;
    float average;

    for (size_t rowValue = 0; rowValue < rows; ++rowValue) {
        for (size_t columnValue = 0; columnValue < columns; ++columnValue) {
            sum += passedList[rowValue][columnValue];
        }
    }

    // calculates the average
    average = sum / (rows * columns);

    // copies average back to main
    return average;
}


// creates 2d array and random numbers
int main() {
    // declaring constants
    const int MIN_NUM = 1;
    const int MAX_NUM = 50;
    const int NUM_ROWS = 5;
    const int NUM_COLUMNS = 3;

    // declaring variables
    int a2DArray[NUM_ROWS][NUM_COLUMNS];
    float averageUser;

    // helps to generate random numbers
    srand(time(NULL));

    // display opening message
    std::cout << "This program creates a 2D array. ";
    std::cout << "It will then populate it with \n";
    std::cout << "random numbers and calculate the average of the numbers.";
    std::cout << std::endl;
    std::cout << std::endl;

    // displays random numbers in 2d array
    for (int counterRows = 0; counterRows < NUM_ROWS; counterRows++) {
        for (int counterColumns = 0;
             counterColumns < NUM_COLUMNS; counterColumns++) {
            int randomNumber = (rand() % MAX_NUM) + MIN_NUM;
            a2DArray[counterRows][counterColumns] = randomNumber;
            std::cout << randomNumber << " ";
        }
        std::cout << std::endl;
    }
    // assigns variable to function call
    averageUser = CalcAverage(a2DArray);
    // displays result to user
    std::cout << std::endl;
    std::cout << "The average is: " << std::fixed;
    std::cout << std::setprecision(2) << averageUser;
}

// Implements the HandlingErrors class, providing functionality for input validation and error correction.
// It ensures user inputs are valid according to the game's requirements.


#include "HandlingErrors.h"
#include <iostream>
#include <sstream>


const std::string HandlingErrors::nonNegativeIntError = "Must be a non-negative number. Please enter again: ";
const std::string HandlingErrors::positiveDoubleError = "Must be a positive number. Please enter again: ";
const std::string HandlingErrors::wholeNumberTypeError = "Invalid type. Please enter a whole number.";

// Attempts to parse an integer from the input string. Returns true if successful, false otherwise.
bool tryParseInt(const std::string& input, int& output) {
    std::istringstream stream(input);
    stream >> output;
    return stream.eof() && !stream.fail();
}

// Attempts to parse a double from the input string. Returns true if successful, false otherwise.
bool tryParseDouble(const std::string& input, double& output) {
    std::istringstream stream(input);
    stream >> output;
    return stream.eof() && !stream.fail();
}

// Prompts the user for an integer input, validates it according to provided criteria,
// and returns the validated integer. Repeats the prompt for invalid inputs.
int HandlingErrors::getValidatedInt(const std::string& prompt, const std::string& errorMessage, const std::string& typeErrorMessage) {
    std::string input;
    int value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (tryParseInt(input, value)) {
            if (value >= 0) {
                break;
            } else {
                std::cout << errorMessage;  // For range errors
            }
        } else {
            std::cout << typeErrorMessage;  // For type errors, e.g., when a double is entered instead of an int
        }
    }
    return value;
}

// Prompts the user for a double input, validates it as a positive number,
// and returns the validated double. Repeats the prompt for invalid inputs.
double HandlingErrors::getValidatedDouble(const std::string& prompt, const std::string& errorMessage) {
    std::string input;
    double value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (tryParseDouble(input, value) && value > 0) {
            break;
        } else {
            std::cout << errorMessage;
        }
    }
    return value;
}
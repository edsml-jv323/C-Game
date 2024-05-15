// This file defines a utility class for input validation and error handling.
// It includes methods for ensuring that user input meets specific criteria before proceeding.

#ifndef CLEAN_HANDLINGERRORS_H
#define CLEAN_HANDLINGERRORS_H

#include <string>

class HandlingErrors {
public:
    // Static methods to validate integer and double inputs. These methods prompt the user,
    // display error messages for invalid inputs, and only return once a valid input is provided.
    static int getValidatedInt(const std::string& prompt, const std::string& errorMessage, const std::string& typeErrorMessage);
    static double getValidatedDouble(const std::string& prompt, const std::string& errorMessage);

    // Error messages used by validation methods to inform the user of the specific validation rules.
    static const std::string nonNegativeIntError;
    static const std::string positiveDoubleError;
    static const std::string wholeNumberTypeError;
};

#endif //CLEAN_HANDLINGERRORS_H

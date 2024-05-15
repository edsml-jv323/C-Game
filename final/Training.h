// Abstract base class for different types of training sessions for monsters.
// Defines common attributes and methods for training, as well as pure virtual methods for specific adjustments.


#ifndef CLEAN_TRAINING_H
#define CLEAN_TRAINING_H

#include "Monster.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class Training {
public:
    Training() : successRate(80), tirednessIncrease(5), healthBenefit(5), scaryPowerIncrease(0) {}
    virtual ~Training() = default;

    virtual void applyTraining(Monster& monster); // Applies training to the monster, success depends on random chance.

protected:
    int successRate; // Chance of successful training
    int tirednessIncrease; // Base tiredness increase
    int healthBenefit; // Base health benefit
    int scaryPowerIncrease; // Base scary power increase

    void displayTrainingAnimation(const Monster& monster, const std::string& emoji) const;

    // Adjust monster stats for successful or failed training - to be implemented by derived classes.
    virtual void adjustForSuccess(Monster& monster);
    virtual void adjustForFailure(Monster& monster);
};


#endif //CLEAN_TRAINING_H

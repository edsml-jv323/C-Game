// Implements PhysicalTraining class, providing specific effects and animations for physical training.

#include "PhysicalTraining.h"
#include <iostream>


PhysicalTraining::PhysicalTraining() {
    this->successRate = 75;
    this->tirednessIncrease = 10;
    this->healthBenefit = 20;
    this->scaryPowerIncrease = 5;
}

void PhysicalTraining::applyTraining(Monster& monster) {
    displayTrainingAnimation(monster, "💪");

    Training::applyTraining(monster);
}

// Provide specific adjustments for successful physical training.
void PhysicalTraining::adjustForSuccess(Monster& monster) {
    // Call the base class method for common adjustments
    Training::adjustForSuccess(monster);

    std::cout << monster.getName() << " has become stronger and more frightening!" << std::endl;
    monster.increaseScaryPower(scaryPowerIncrease + 5);
}

// Handle adjustments for failed physical training, including extra penalties.
void PhysicalTraining::adjustForFailure(Monster& monster) {
    Training::adjustForFailure(monster);

    // Additional logic for physical training failure
    std::cout << monster.getName() << " pushed too hard and is extremely tired now." << std::endl;
    monster.addHealth(-5);
}
//
// Created by Veiras Yanes, Jorge on 07/03/2024.
//

#include "MentalTraining.h"
#include <iostream>

MentalTraining::MentalTraining() {
    this->successRate = 70;
    this->tirednessIncrease = 15;
    this->healthBenefit = 5;
    this->scaryPowerIncrease = 10;
}

void MentalTraining::applyTraining(Monster& monster) {
    displayTrainingAnimation(monster, "\U0001F4DA");
    
    Training::applyTraining(monster);
}

void MentalTraining::adjustForSuccess(Monster& monster) {
    Training::adjustForSuccess(monster);
    std::cout << monster.getName() << " has improved mentally!" << std::endl;
}

void MentalTraining::adjustForFailure(Monster& monster) {
    Training::adjustForFailure(monster);
    std::cout << "The mental strain was too much for " << monster.getName() << "." << std::endl;
}
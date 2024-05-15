//
// Created by Veiras Yanes, Jorge on 07/03/2024.
//

#include "RoarTraining.h"
#include <iostream>

RoarTraining::RoarTraining() {
    this->successRate = 15;
    this->tirednessIncrease = 20;
    this->healthBenefit = 40;
    this->scaryPowerIncrease = 60;
}

void RoarTraining::applyTraining(Monster& monster) {
    displayTrainingAnimation(monster, "\U0001F981");

    Training::applyTraining(monster);
}

void RoarTraining::adjustForSuccess(Monster& monster) {
    Training::adjustForSuccess(monster);
    std::cout << monster.getName() << " has learned to roar terrifyingly!" << std::endl;
}

void RoarTraining::adjustForFailure(Monster& monster) {
    Training::adjustForFailure(monster);
    std::cout << monster.getName() << " couldn't find their roar." << std::endl;
}
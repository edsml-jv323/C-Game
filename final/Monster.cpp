// Implements the Monster class, providing specific behaviors for eating, sleeping, training, and managing tiredness and scary power.
#include <iostream>
#include "Monster.h"
#include <thread>
#include <chrono>


Monster::Monster() : Creature("", 0, 0, 0.0, 0.0, 0), ScaryPower(0), tiredness(0) {
}

Monster::Monster(const std::string& name, int eyes, int health, double weight, double height, int age, int scaryPower, int tiredness)
        : Creature(name, eyes, health, weight, height, age), ScaryPower(scaryPower), tiredness(tiredness) {}


void Monster::displayEatingAnimation(const std::string& message, const std::string& emoji) const {
    std::cout << name << " " << message << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << emoji;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "\nEating complete!\n";
}


void Monster::eat(FoodType food) {
    switch(food) {
        case FoodType::healthy:
            displayEatingAnimation("loves healthy food!!", "\U0001F34F");
            addHealth(5);
            addWeight(0.5);
            break;
        case FoodType::junk:
            displayEatingAnimation("is eating junk food :(", "\U0001F354");
            Creature::eat(food);
            break;
        case FoodType::monster_food:
            displayEatingAnimation("LOVES monster food, scary power is increasing!!", "\U0001F357");
            addHealth(10);
            addWeight(1);
            increaseScaryPower(5);
            break;
        case FoodType::baby_food:
            std::cout << "Monster cannot eat baby food, choose another one." << std::endl;
            break;
    }
}



void Monster::increaseScaryPower(int amount) {
    ScaryPower += amount;
}


int Monster::getScaryPower() const {
    return ScaryPower;
}


int Monster::getTiredness() const {
    return tiredness;
}



void Monster::uniqueAbility() {
    ScaryPower += 10;
}

void Monster::addTiredness(int amount) {
    tiredness += amount;
    if (tiredness < 0) {
        tiredness = 0;
    }
    if (tiredness > maxTiredness) {
        tiredness = maxTiredness;
        std::cout << name << " is too tired and got captured by the parents!" << std::endl;

    }
}


void Monster::sleep() {
    std::cout << name << " is sleeping and recovering " << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "💤";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << "\n" << name << " feels refreshed!\n";

    addHealth(5);
    addTiredness(-20);

}

std::string Monster::getName() const {
    return name;
}


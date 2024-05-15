// Implements the Child class, providing functionality to randomize stats, eat, sleep, and manage ScaryTolerance.


#include "Child.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Child::Child() : Creature("Boo", 2, 100, 30, 1.0, 5) {
    randomizeStats();
}

void Child::randomizeStats() {
    srand(static_cast<unsigned int>(time(nullptr)));


    int health = rand() % 101 + 50; // Random health between 50 and 150
    double weight = static_cast<double>(rand() % 21 + 20); // Random weight between 20.0 and 40.0
    double height = 0.8 + static_cast<double>(rand() % 41) / 100.0; // Random height between 0.8 and 1.2
    int age = rand() % 8 + 3; // Random age between 3 and 10
    int scaryTolerance;

    int chance = rand() % 100;
    if (chance < 90) { //The Child may have a normal or a high scary tolerance. Depends on game
        scaryTolerance = rand() % 11 + 5; // Normal scary tolerance between 5 and 15
    } else {
        scaryTolerance = rand() % 501 + 100; // High scary tolerance between 100 and 500
    }


    setName("Boo");
    setEyes(2);
    setHealth(health);
    setWeight(weight);
    setHeight(height);
    setAge(age);
    setScaryTolerance(scaryTolerance);
}

void Child::eat(FoodType food) {
    switch(food) {
        case FoodType::healthy:
        case FoodType::junk:
            Creature::eat(food);
            break;
        case FoodType::baby_food:
            addHealth(5);
            addWeight(0.5);
            increaseScaryTolerance(1);
            break;
        case FoodType::monster_food:
            std::cout << "Child cannot eat monster food, choose another one." << std::endl;
            break;
    }
}
// Override sleep method to include ScaryTolerance increase along with health recovery.
void Child::sleep() {
    Creature::sleep();
    increaseScaryTolerance(1); // Sleeping increases ScaryTolerance
}

void Child::increaseScaryTolerance(int amount) {
    ScaryTolerance += amount;
}

void Child::uniqueAbility() {
    ScaryTolerance += 10;
}

int Child::getScaryTolerance() const {
    return ScaryTolerance;
}

void Child::setScaryTolerance(int scaryTolerance) {
    ScaryTolerance = scaryTolerance;
}
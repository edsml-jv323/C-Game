// Implementation of the Creature class methods, including constructors, eat, sleep, and setters/getters.



#include "Creature.h"
#include <iostream>


Creature::Creature(const std::string& name, int eyes, int health, double weight, double height, int age)
        : name(name), eyes(eyes), health(health), weight(weight), height(height), age(age) {}



void Creature::addHealth(int amount) {
    health += amount;
}

void Creature::addWeight(double amount) {
    weight += amount;

}

void Creature::addHeight(double amount) {
    height += amount;

}


// Method to simulate the creature eating different types of food, affecting its stats.
void Creature::eat(FoodType food) {
    switch(food) {
        case FoodType::healthy:
            addHealth(5);
            addWeight(0.5);
            addHeight(0.1);
            break;
        case FoodType::junk:
            addHealth(-4);
            addWeight(0.5);
            addHeight(0.1);
            break;
        case FoodType::monster_food:
        case FoodType::baby_food:
            // These types do not affect the base creature stats.
            break;
    }
}

int Creature::getHealth() const {
    return health;
}

double Creature::getHeight() const {
    return height;
}

double Creature::getWeight() const {
    return weight;
}

void Creature::sleep() {
    addHealth(5);
}

// Setters with validation to ensure valid attribute values.
void Creature::setEyes(int eyes) {
    if (eyes >= 0) {
        this->eyes = eyes;
    } else {
        std::cout << "Invalid value for eyes. Must be a non-negative number.\n";
    }
}

void Creature::setHealth(int health) {
    if (health >= 0) {
        this->health = health;
    } else {
        std::cout << "Invalid value for health. Must be a non-negative number.\n";
    }
}

void Creature::setWeight(double weight) {
    if (weight > 0) {
        this->weight = weight;
    } else {
        std::cout << "Invalid value for weight. Must be a positive number.\n";
    }
}

void Creature::setHeight(double height) {
    if (height > 0) {
        this->height = height;
    } else {
        std::cout << "Invalid value for height. Must be a positive number.\n";
    }
}

void Creature::setAge(int age) {
    if (age >= 0) {
        this->age = age;
    } else {
        std::cout << "Invalid value for age. Must be a non-negative number.\n";
    }
}

void Creature::setName(const std::string& newName) {
    name = newName;
}

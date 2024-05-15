// Derived class from Creature, specifically representing a monster in the game.
// Adds attributes and methods relevant to monsters, such as ScaryPower and tiredness management.

#ifndef CLEAN_MONSTER_H
#define CLEAN_MONSTER_H

#include "Creature.h"

class Monster : public Creature {
private:
    int ScaryPower; // Unique attribute representing the monster's ability to scare.
    int tiredness;
    static const int maxTiredness = 100; // Maximum tiredness a monster can reach before consequences.

public:
    Monster(); //Default constructor
    Monster(const std::string& name, int eyes, int health, double weight, double height, int age, int scaryPower, int tiredness);

    void eat(FoodType food) override;
    void sleep() override;

    void increaseScaryPower(int amount);
    int getScaryPower() const;
    int getTiredness() const;
    void addTiredness(int amount);



    void uniqueAbility() override;

    std::string getName() const;

private: // Private method for showing eating animation.
    void displayEatingAnimation(const std::string& message, const std::string& emoji) const;
};


#endif //CLEAN_MONSTER_H

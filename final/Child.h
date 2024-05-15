// A class representing a child in the game, derived from the Creature class.
// It introduces the ScaryTolerance attribute, which affects interactions with monsters.

#ifndef CLEAN_CHILD_H
#define CLEAN_CHILD_H


#include "Creature.h"

class Child : public Creature {
private:
    int ScaryTolerance; // Represents how much scare a child can tolerate before being scared.


public:
    // Constructor
    Child();

    void randomizeStats(); // Randomizes child's stats to provide varied gameplay.

    void eat(FoodType food) override;
    void sleep() override;

    void increaseScaryTolerance(int amount);

    void uniqueAbility() override;

    int getScaryTolerance() const;
    void setScaryTolerance(int scaryTolerance);
};





#endif //CLEAN_CHILD_H

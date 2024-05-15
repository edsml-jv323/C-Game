// Base class for all creatures in the game, including monsters and children.
// It defines common properties like name, eyes, health, etc., and declares virtual methods for common actions.


#ifndef CLEAN_CREATURE_H
#define CLEAN_CREATURE_H

#include <string>

enum class FoodType { healthy, junk, monster_food, baby_food };

class Creature {
protected:
    std::string name;
    int eyes;
    int health;
    double weight;
    double height;
    int age;

public:
    Creature(const std::string& name, int eyes, int health, double weight, double height, int age);
    // Virtual destructor to allow derived class objects to be properly cleaned up.
    virtual ~Creature() {}

    virtual void eat(FoodType food);
    virtual void sleep();
    virtual void uniqueAbility() = 0;

    // Getters and setters for creature attributes.
    std::string getName() const;
    int getEyes() const;
    int getHealth() const;
    double getWeight() const;
    double getHeight() const;
    int getAge() const;

    void addHealth(int amount);
    void addWeight(double amount);
    void addHeight(double amount);

    void setEyes(int eyes);
    void setName(const std::string& newName);
    void setHealth(int health);
    void setWeight(double weight);
    void setHeight(double height);
    void setAge(int age);
};



#endif //CLEAN_CREATURE_H

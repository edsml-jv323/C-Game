#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "Child.h"
#include "PhysicalTraining.h"
#include "MentalTraining.h"
#include "RoarTraining.h"
#include "HandlingErrors.h"

std::vector<std::string> foodOptions = {"Healthy", "Junk", "Monster Food"};

std::unique_ptr<Monster> createCustomMonster() {
    std::string name;
    std::cout << "Enter monster name: ";
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline

    int eyes = HandlingErrors::getValidatedInt("Enter number of eyes: ", HandlingErrors::nonNegativeIntError, HandlingErrors::wholeNumberTypeError);
    int health = HandlingErrors::getValidatedInt("Enter health: ", HandlingErrors::nonNegativeIntError, HandlingErrors::wholeNumberTypeError);
    double weight = HandlingErrors::getValidatedDouble("Enter weight: ", HandlingErrors::positiveDoubleError);
    double height = HandlingErrors::getValidatedDouble("Enter height: ", HandlingErrors::positiveDoubleError);
    int scaryPower = HandlingErrors::getValidatedInt("Enter scary power: ", HandlingErrors::nonNegativeIntError, HandlingErrors::wholeNumberTypeError);
    int age = HandlingErrors::getValidatedInt("Enter age: ", HandlingErrors::nonNegativeIntError, HandlingErrors::wholeNumberTypeError);

    // Create and return a unique_ptr to a new Monster object.
    return std::make_unique<Monster>(name, eyes, health, weight, height, age, scaryPower, 0);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation

    // Vector to hold monsters. Smart pointers are used for automatic memory management.
    std::vector<std::unique_ptr<Monster>> monsters;
    Child boo;

    std::cout << "Do you want to create a custom monster? (y/n): ";
    char choice;
    std::cin >> choice;

    std::unique_ptr<Monster> chosenMonster = nullptr; // Pointer to store the chosen monster.


    if (choice == 'y' || choice == 'Y') {
        chosenMonster = createCustomMonster(); // Directly assigning the returned unique_ptr
    } else {
        // Predefined monsters added to the vector
        monsters.push_back(std::make_unique<Monster>("Sully", 2, 100, 90, 1.75, 5, 20, 0));
        monsters.push_back(std::make_unique<Monster>("Mike", 1, 100, 45, 1.20, 4, 10, 0));
        monsters.push_back(std::make_unique<Monster>("Randall", 2, 100, 55, 1.80, 6, 30, 0));

        std::cout << "Select a monster:\n";
        for (size_t i = 0; i < monsters.size(); ++i) {
            std::cout << i + 1 << ". " << monsters[i]->getName() << "\n";
        }
        int monsterChoice;
        std::cin >> monsterChoice;
        if (monsterChoice < 1 || monsterChoice > monsters.size()) {
            std::cout << "Invalid choice. Exiting game.\n";
            return 0;
        }
        chosenMonster = std::move(monsters[monsterChoice - 1]); // Move the selected monster to chosenMonster
    }

    // Initialize training sessions
    PhysicalTraining pt;
    MentalTraining mt;
    RoarTraining rt;

    // Main game loop.
    while (true) {
        std::cout << "Choose action for " << chosenMonster->getName() << ":\n";
        std::cout << "1. Feed\n2. Put to Sleep\n3. Train\n4. Try to Scare Boo\n5. Quit\n";
        int action;
        std::cin >> action;

        switch (action) {
            case 1: { // Feed the monster.
                std::cout << "Select food type:\n";
                for (size_t i = 0; i < foodOptions.size(); ++i) {
                    std::cout << i + 1 << ". " << foodOptions[i] << "\n";
                }
                int foodChoice;
                std::cin >> foodChoice;
                if (foodChoice < 1 || foodChoice > static_cast<int>(foodOptions.size())) {
                    std::cout << "Invalid food choice.\n";
                    continue;
                }
                chosenMonster->eat(static_cast<FoodType>(foodChoice - 1));
                break;
            }
            case 2: // Put the monster to sleep.
                chosenMonster->sleep();
                break;
            case 3: { // Train the monster.
                std::cout << "Select training type:\n";
                std::cout << "1. Physical Training\n2. Mental Training\n3. Roar Training\n";
                int trainingChoice;
                std::cin >> trainingChoice;
                switch (trainingChoice) {
                    case 1:
                        pt.applyTraining(*chosenMonster);
                        break;
                    case 2:
                        mt.applyTraining(*chosenMonster);
                        break;
                    case 3:
                        rt.applyTraining(*chosenMonster);
                        break;
                    default:
                        std::cout << "Invalid training choice.\n";
                        continue;
                }
                break;
            }
            case 4: // Try to scare Boo.
                if (chosenMonster->getScaryPower() >= 2 * boo.getScaryTolerance()
                    && chosenMonster->getHealth() >= 2 * boo.getHealth()
                    && chosenMonster->getWeight() >= 2 * boo.getWeight()
                    && chosenMonster->getHeight() >= 2 * boo.getHeight()) {
                    std::cout << chosenMonster->getName() << " successfully scared Boo. You win!\n";
                    return 0; // Exiting game after a successful scare
                } else {
                    std::cout << chosenMonster->getName()
                              << " failed to scare Boo and was captured by the parents. You lose.\n";
                    return 0;
                }


            case 5: // Quit the game.
                std::cout << "Quitting game.\n";
                return 0; // Exit the main loop and end the game.
            default:
                std::cout << "Invalid action. Please try again.\n";
                break;
        }

        // After action check for tiredness
        if (chosenMonster->getTiredness() >= 100) {
            std::cout << chosenMonster->getName() << " is too tired and got captured by the parents!\n";
            break; // End game loop if monster is too tired
        }

        std::cout << "\nCurrent Stats for " << chosenMonster->getName() << ":\n"
                  << "Health: " << chosenMonster->getHealth() << "\n"
                  << "Weight: " << chosenMonster->getWeight() << " kg\n"
                  << "Height: " << chosenMonster->getHeight() << " m\n"
                  << "Scary Power: " << chosenMonster->getScaryPower() << "\n"
                  << "Tiredness: " << chosenMonster->getTiredness() << "/100\n\n";
    }

    return 0;
}
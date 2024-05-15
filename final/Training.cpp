// Implements the Training class, providing a framework for applying training sessions to monsters.
#include "Training.h"

void Training::displayTrainingAnimation(const Monster& monster, const std::string& emoji) const {
    std::cout << monster.getName() << " is training " << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << emoji;
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "\n";
}

// Apply training to the monster, determining success or failure randomly.
void Training::applyTraining(Monster& monster) {

    // Random success check
    int roll = rand() % 100;
    if (roll < successRate) {
        adjustForSuccess(monster);
    } else {
        adjustForFailure(monster);
    }
}

void Training::adjustForSuccess(Monster& monster) {
    monster.addHealth(healthBenefit);
    monster.addTiredness(tirednessIncrease);
    monster.increaseScaryPower(scaryPowerIncrease);
}

void Training::adjustForFailure(Monster& monster) {
    // Failure increase tiredness more than success, without the benefits
    monster.addTiredness(tirednessIncrease + 10);
}
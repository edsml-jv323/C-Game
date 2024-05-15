// Derived class from Training, represents physical training sessions for monsters.
// Adjusts monster stats specifically for physical training success or failure.


#ifndef CLEAN_PHYSICALTRAINING_H
#define CLEAN_PHYSICALTRAINING_H


#include "Training.h"

class PhysicalTraining : public Training {
public:
    PhysicalTraining();

    void applyTraining(Monster& monster) override;

protected:
    void adjustForSuccess(Monster& monster) override;
    void adjustForFailure(Monster& monster) override;
};



#endif //CLEAN_PHYSICALTRAINING_H

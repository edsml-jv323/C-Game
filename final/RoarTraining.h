// Specialized training class derived from Training, focuses on enhancing the monster's roaring ability.
// Successful roar training significantly increases a monster's scary power.

#ifndef CLEAN_ROARTRAINING_H
#define CLEAN_ROARTRAINING_H

#include "Training.h"

class RoarTraining : public Training {
public:
    RoarTraining();

    void applyTraining(Monster& monster) override;

protected:
    void adjustForSuccess(Monster& monster) override;
    void adjustForFailure(Monster& monster) override;
};


#endif //CLEAN_ROARTRAINING_H

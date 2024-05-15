// Implementation of the MentalTraining class, providing effects of mental training on monsters.

#ifndef CLEAN_MENTALTRAINING_H
#define CLEAN_MENTALTRAINING_H

#include "Training.h"

class MentalTraining : public Training {
public:
    MentalTraining();

    void applyTraining(Monster& monster) override;

protected:
    void adjustForSuccess(Monster& monster) override;
    void adjustForFailure(Monster& monster) override;
};


#endif //CLEAN_MENTALTRAINING_H

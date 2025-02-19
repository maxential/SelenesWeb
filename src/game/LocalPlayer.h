//
// Created by max on 2/16/2025.
//

#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H
#include "BaseCharacter.h"


class LocalPlayer : public BaseCharacter{
    protected:
    int healAmount;
    int doAction();
    public:
    LocalPlayer();
};



#endif //LOCALPLAYER_H

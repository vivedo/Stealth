//
// Created by vivedo on 10/08/20.
//

#ifndef STEALTH_ADVANCEMENTMANAGER_HPP
#define STEALTH_ADVANCEMENTMANAGER_HPP


#include "EnemyShootingObserver.hpp"
#include "IsStealthObserver.hpp"
#include "WalkObserver.hpp"
#include "PlayerLifeObservable.hpp"
#include "Stealth.hpp"
#include "MissionOneObserver.hpp"

class AdvancementManager : public EnemyShootingObserver, public IsStealthObserver, public WalkObserver, public PlayerLifeObservable, public MissionOneObserver {
public:
    AdvancementManager(Stealth &stealth) : stealth(stealth) {};
    void enemyShoots() override;
    void changeStealthStatus() override;
    void updateWalked() override;
    void changePlayerLife(int health) override;
    void isTargetDestroyed(int health) override;

    void update();

private:

    Stealth &stealth;
    struct Advancements{
        int enemyKilled = 0;
        int walked = 0;
        bool isStealth = true;
    };
    Advancements advancements;

};


#endif //STEALTH_ADVANCEMENTMANAGER_HPP

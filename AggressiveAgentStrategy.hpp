//
//  AggressiveAgentStrategy.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_AGGRESSIVEAGENTSTRATEGY_H
#define PA5GAME_AGGRESSIVEAGENTSTRATEGY_H

#include "Game.hpp"
#include "Strategy.hpp"

namespace Gaming
{
    
    class AggressiveAgentStrategy : public Strategy
    {
        double __agentEnergy;
        
    public:
        static const double DEFAULT_AGGRESSION_THRESHOLD;
        
        AggressiveAgentStrategy(double agentEnergy) : __agentEnergy(agentEnergy) {}
        ~AggressiveAgentStrategy();
        
        ActionType operator()(const Surroundings & s) const override;
        
    };
    
}


#endif //PA5GAME_AGGRESSIVEAGENTSTRATEGY_H

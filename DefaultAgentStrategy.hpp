//
//  DefaultAgentStrategy.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_DEFAULTAGENTSTRATEGY_H
#define PA5GAME_DEFAULTAGENTSTRATEGY_H

#include "Strategy.hpp"

namespace Gaming
{
    class DefaultAgentStrategy : public Strategy
    {
    public:
        
        DefaultAgentStrategy() {}
        ~DefaultAgentStrategy();
        ActionType operator()(const Surroundings & s) const override;
    };
    
}

#endif //PA5GAME_DEFAULTAGENTSTRATEGY_H

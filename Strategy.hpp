//
//  Strategy.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_STRATEGY_H
#define PA5GAME_STRATEGY_H

#include "Gaming.hpp"

namespace Gaming
{
    
    class Strategy
    {
    public:
        Strategy() {}
        virtual ~Strategy() {}
        virtual ActionType operator()(const Surroundings & s) const = 0;
    };
    
}


#endif //PA5GAME_STRATEGY_H
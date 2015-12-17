//
//  Strategic.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_STRATEGIC_H
#define PA5GAME_STRATEGIC_H

#include "Game.hpp"
#include "Agent.hpp"
#include "Strategy.hpp"
#include "DefaultAgentStrategy.hpp"

namespace Gaming
{
    class Strategic : public Agent
    {
    private:
        static const char STRATEGIC_ID;
        
        Strategy *__strategy;
        
    public:
        Strategic(const Game & g, const Position & p, double energy, Strategy *s = new DefaultAgentStrategy()) : Agent(g, p, energy), __strategy(s)
        {
            __energy = energy;
        }
        
        ~Strategic();
        
        PieceType getType() const override { return PieceType::STRATEGIC; }
        
        void print(std::ostream & os) const override;
        
        ActionType takeTurn(const Surroundings & s) const override;
        
    };
    
}


#endif //PA5GAME_STRATEGIC_H

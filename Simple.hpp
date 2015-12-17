//
//  Simple.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_SIMPLE_H
#define PA5GAME_SIMPLE_H

#include "Game.hpp"
#include "Agent.hpp"

namespace Gaming
{
    
    class Simple : public Agent
    {
    private:
        static const char SIMPLE_ID;
        
    public:
        Simple(const Game & g, const Position & p, double energy) : Agent(g, p, energy)
        {
            __energy = energy;
        }
        
        ~Simple();
        
        PieceType getType() const override { return PieceType::SIMPLE; }
        
        void print(std::ostream & os) const override;
        
        ActionType takeTurn(const Surroundings & s) const override;
        
    };
}

#endif //PA5GAME_SIMPLE_H

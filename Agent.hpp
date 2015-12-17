//
//  Agent.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_AGENT_H
#define PA5GAME_AGENT_H

#include "Game.hpp"
#include "Piece.hpp"

namespace Gaming
{
    class Agent : public Piece
    {
        
    protected:
        double __energy;
        
    public:
        static const double AGENT_FATIGUE_RATE;
        
        Agent(const Game & g, const Position & p, double energy) : Piece(g, p), __energy(energy) {}
        
        ~Agent();
        
        double getEnergy() const { return __energy; }
        void addEnergy(double e) { __energy += e; }
        
        void age() override final;
        
        bool isViable() const override final { return !isFinished() && __energy > 0.0; }
        
        Piece &operator*(Piece &other) override final;
        Piece &interact(Agent *) override final;
        Piece &interact(Resource *) override final;
        
    };
    
}


#endif //PA5GAME_AGENT_H

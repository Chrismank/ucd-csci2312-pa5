//
//  Resource.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_RESOURCE_H
#define PA5GAME_RESOURCE_H

#include "Game.hpp"
#include "Piece.hpp"

namespace Gaming
{
    
    class Resource : public Piece
    {
        
    protected:
        double __capacity;
        
    public:
        static const double RESOURCE_SPOIL_FACTOR;
        
        Resource(const Game & g, const Position & p, double __capacity) : Piece(g, p), __capacity(__capacity) {}
        
        ~Resource();
        
        virtual double getCapacity() const { return __capacity; }
        virtual double consume();
        
        void age() override final;
        
        bool isViable() const override final { return !isFinished() && __capacity > 0.0; }
        
        ActionType takeTurn(const Surroundings & s) const override;
        
        // note: these won't be called while resources don't move
        Piece &operator*(Piece & other) override final;
        Piece &interact(Agent *) override final;
        Piece &interact(Resource *) override final; // note: no interaction between resources
    };
    
}


#endif //PA5GAME_RESOURCE_H

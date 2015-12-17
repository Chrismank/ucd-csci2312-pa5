//
//  Advantage.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_WEAPON_H
#define PA5GAME_WEAPON_H

#include "Game.hpp"
#include "Resource.hpp"

namespace Gaming
{
    class Advantage : public Resource
    {
    private:
        static const char ADVANTAGE_ID;
        
    public:
        static const double ADVANTAGE_MULT_FACTOR;
        
        Advantage(const Game & g, const Position & p, double capacity) : Resource(g, p, capacity)
        {
            __capacity = capacity;
        }
        
        ~Advantage();
        
        PieceType getType() const override { return PieceType::ADVANTAGE; }
        
        void print(std::ostream &os) const override;
        
        double getCapacity() const override;
        double consume() override;
    };
}


#endif //PA5GAME_WEAPON_H

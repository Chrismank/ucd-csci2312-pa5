//
//  Food.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_FOOD_H
#define PA5GAME_FOOD_H

#include "Game.hpp"
#include "Resource.hpp"

namespace Gaming
{
    class Food : public Resource
    {
    private:
        static const char FOOD_ID;
        
    public:
        Food(const Game & g, const Position & p, double capacity) : Resource(g, p, capacity)
        {
            __capacity = capacity;
        }
        
        ~Food();
        
        PieceType getType() const override { return PieceType::FOOD; }
        
        void print(std::ostream & os) const override;
    };
    
}


#endif //PA5GAME_FOOD_H

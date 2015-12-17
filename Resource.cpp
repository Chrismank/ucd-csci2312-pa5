//
//  Resource.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Resource.hpp"

namespace Gaming
{
    const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;
    
    Resource::~Resource()
    {
        
    }
    
     double Resource::consume()
    {
        return 0;
    }
    
    void Resource::age()
    {
        
    }
    
    ActionType Resource::takeTurn(const Surroundings & s) const
    {
        return N;
    }
    
    Piece & Resource::operator*(Piece & other)
    {
        return other.interact(this);
    }
    
    Piece & Resource::interact(Agent * a)
    {
        return *this;
    }
    
    Piece & Resource::interact(Resource * r)
    {
        return *this;
    }
}
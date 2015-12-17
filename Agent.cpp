//
//  Agent.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Agent.hpp"

namespace Gaming
{
    const double Agent::AGENT_FATIGUE_RATE = 0.3;
    
    Agent::~Agent()
    {
        
    }
    
    Piece & Agent::operator*(Piece & other)
    {
        return other.interact(this);
    }

    Piece & Agent::interact(Agent *a)
    {
        // implement code
        return *this;
    }

    Piece & Agent::interact(Resource *r)
    {
        // implement code
        return *this;
    }
    
    void Agent::age()
    {
        __energy = __energy * AGENT_FATIGUE_RATE;
    }
    
}
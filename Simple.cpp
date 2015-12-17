//
//  Simple.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Simple.hpp"

namespace Gaming
{
    const char Simple::SIMPLE_ID = 'S';
    
    Simple::~Simple()
    {
        
    }
    
    ActionType Simple::takeTurn(const Surroundings & s) const
    {
        // s is a structure
        // iterate through vector s.array and look for a resource
        // Simple agents don't challenge
        
        auto it = s.array.begin();
        int index = 0;
        
        for( ; it != s.array.end(); ++it)
        {
            // if there is a resource, return ActionType to the location of the resource
            if(*it == FOOD || *it == ADVANTAGE)
            {
                switch(index)
                {
                    case 0: return NW;
                        break;
                    case 1: return N;
                        break;
                    case 2: return NE;
                        break;
                    case 3: return W;
                        break;
                    case 4: return STAY;
                        break;
                    case 5: return E;
                        break;
                    case 6: return SW;
                        break;
                    case 7: return S;
                        break;
                    case 8: return SE;
                        break;
                }
            }
            
            // if there is no resource, return ActionType to an empty position
            if(*it == EMPTY)
            {
                // return an action type
                switch(index)
                {
                    case 0: return NW;
                        break;
                    case 1: return N;
                        break;
                    case 2: return NE;
                        break;
                    case 3: return W;
                        break;
                    case 4: return STAY;
                        break;
                    case 5: return E;
                        break;
                    case 6: return SW;
                        break;
                    case 7: return S;
                        break;
                    case 8: return SE;
                        break;
                }
            }
            
            index ++;
        }
        
        // if no empty positions, return stay
        return STAY;
    }
    
    void Simple::print(std::ostream & os) const
    {
        os << SIMPLE_ID;
    }
}
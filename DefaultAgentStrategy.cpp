//
//  DefaultAgentStrategy.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "DefaultAgentStrategy.hpp"

namespace Gaming
{
    DefaultAgentStrategy::~DefaultAgentStrategy()
    {
    
    }
    
    ActionType DefaultAgentStrategy::operator()(const Surroundings & s) const
    {
        // encoded as an array/vector top-left row-wise bottom-right
        // [0][1][2]
        // [3][4][5]
        // [6][7][8]
        // the piece is always at 1x1 (SELF)
        
        // this will return action type which is a parameter taken by the move function that will return the correct position
        int index = 0;
        auto it = s.array.begin();
        
        for( ; it != s.array.end(); ++it)
        {
            // if vector s.array has an advantage, move to this position
            if(*it == ADVANTAGE)
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
        
            // if vector s.array has doesn't have an advantage, but has food, move to this position
            if(*it == FOOD)
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
        
            // if vector s.array doesn't have food, move to empty position
            if(*it == EMPTY)
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
        
            // if vector s.array doesn't have any empty positions, move to adjacent Simple agent
            if(*it == SIMPLE)
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
        
            index ++;
        }
        
        // if not adjacent simple agents, returns STAY
        return STAY;
        
    }
}
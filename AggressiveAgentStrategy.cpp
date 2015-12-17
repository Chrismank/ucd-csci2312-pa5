//
//  AggressiveAgentStrategy.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "AggressiveAgentStrategy.hpp"

namespace Gaming
{
    const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;
    
    AggressiveAgentStrategy::~AggressiveAgentStrategy()
    {
        
    }

    ActionType AggressiveAgentStrategy::operator()(const Surroundings & s) const
    {
        auto it = s.array.begin();
        int index = 0;
        
        for( ; it != s.array.end(); ++it)
        {
            if((__agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD) && (*it == SIMPLE || *it == STRATEGIC))
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
            
            else if(*it == ADVANTAGE)
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
            
            else if(*it == FOOD)
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
            
            else if(*it == EMPTY)
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
        }
        
        index ++;
        
        return STAY;
    }
}
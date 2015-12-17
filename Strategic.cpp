//
//  Strategic.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Strategic.hpp"

namespace Gaming
{
    const char Strategic::STRATEGIC_ID = 'T';
    
    Strategic::~Strategic()
    {
        delete __strategy;
    }

    void Strategic::print(std::ostream & os) const
    {
        os << STRATEGIC_ID;
    }

    ActionType Strategic::takeTurn(const Surroundings & s) const
    {
        DefaultAgentStrategy strat;
        
        return strat(s);
    }
}
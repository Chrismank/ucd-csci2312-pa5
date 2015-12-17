//
//  Food.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Food.hpp"

namespace Gaming
{
    const char Food::FOOD_ID = 'F';

    Food::~Food()
    {
        
    }
    
    void Food::print(std::ostream & os) const
    {
        os << FOOD_ID;
    }
}
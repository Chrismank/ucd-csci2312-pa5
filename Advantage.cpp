//
//  Advantage.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Advantage.hpp"

namespace Gaming
{
    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;
    
    Advantage::~Advantage()
    {
        
    }
    
    void Advantage::print(std::ostream & os) const
    {
        os << ADVANTAGE_ID;
    }
    
    double Advantage::getCapacity() const
    {
        return __capacity;
    }
    
    double Advantage::consume()
    {
        double consume;
        return consume;
    }
}
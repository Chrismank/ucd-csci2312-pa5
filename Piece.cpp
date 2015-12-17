//
//  Piece.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Piece.hpp"

namespace Gaming
{
 
    unsigned int Piece::__idGen = 1;
    
    std::ostream & operator<<(std::ostream & os, const Piece & piece)
    {
        // each class' print statement should print out its own character id
        
        piece.print(os);
    
        os << piece.__id;
        
        return os;
    }
}
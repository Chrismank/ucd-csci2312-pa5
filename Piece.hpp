//
//  Piece.hpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef PA5GAME_GAMEUNIT_H
#define PA5GAME_GAMEUNIT_H

#include <string>

#include "Game.hpp"

namespace Gaming
{
    
    class Resource;
    
    class Piece
    {
        
    private:
        static unsigned int __idGen;
        
        bool __finished;
        bool __turned;
        
        Position __position;
        
    protected:
        const Game & __game; // note: a reference to the Game object
        unsigned int __id;
        
        virtual void print(std::ostream &os) const = 0;
        
        void finish() { __finished = true; }
        bool isFinished() const { return __finished; }
        
    public:
        Piece(const Game & g, const Position & p) : __game(g), __position(p), __id(__idGen++), __turned(false) {}
        virtual ~Piece() {}
        
        const Position getPosition() const { return __position; }
        void setPosition(const Position & p) { __position = p; }
        
        bool getTurned() const { return __turned; }
        void setTurned(bool turned) { __turned = turned; }
        
        virtual void age() = 0;
        virtual bool isViable() const = 0;
        virtual PieceType getType() const = 0;
        
        virtual ActionType takeTurn(const Surroundings & surr) const = 0; // note: doesn't actually change the object
        
        virtual Piece &operator*(Piece & other) = 0;
        virtual Piece &interact(Agent *) = 0;
        virtual Piece &interact(Resource *) = 0;
        
        friend std::ostream &operator<<(std::ostream & os, const Piece & piece);
    };
}


#endif //PA5GAME_GAMEUNIT_H

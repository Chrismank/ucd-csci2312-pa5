//
//  Game.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "Game.hpp"
#include "Piece.hpp"
#include "Simple.hpp"
#include "Food.hpp"
#include "Advantage.hpp"
#include "Strategic.hpp"

namespace Gaming
{
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
    const unsigned Game::MIN_WIDTH = 3;
    const unsigned Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;
    const double Game::STARTING_RESOURCE_CAPACITY = 10;
    
    Game::Game(const Game & another)
    {
        
    }
   
    Game::~Game()
    {
        
    }
    
    unsigned int Game::getNumPieces() const
    {
        auto it = __grid.begin();
        
        unsigned int empty = 0;
        unsigned int pieces;
        unsigned int total = __width * __height;
        
        for( ; it != __grid.end(); ++it)
        {
            if(*it == nullptr)
            {
                empty++;
            }
        }
        
        pieces = total - empty;
        
        return pieces;
        
    }
    
    unsigned int Game::getNumAgents() const
    {
        return getNumSimple() + getNumStrategic();
    }
    
    unsigned int Game::getNumSimple() const
    {
        auto it = __grid.begin();
        unsigned int count = 0;
        
        for( ; it != __grid.end(); ++it)
        {
            if(*it != nullptr)
            {
                if((*it)->getType() == SIMPLE)
                {
                    count++;
                }
            }
        }
        
        return count;
    }

    unsigned int Game::getNumStrategic() const
    {
        auto it = __grid.begin();
        unsigned int count = 0;
        
        for( ; it != __grid.end(); ++it)
        {
            if(*it != nullptr)
            {
                if((*it)->getType() == STRATEGIC)
                {
                    count++;
                }
            }
        }
        
        return count;
    }

    unsigned int Game::getNumResources()
    {
        auto it = __grid.begin();
        unsigned int count = 0;
        
        for( ; it != __grid.end(); ++it)
        {
            if(*it != nullptr)
            {
                if((*it)->getType() == FOOD || (*it)->getType() == ADVANTAGE)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    bool Game::addSimple(const Position & position)
    {
        unsigned int x = position.x;
        unsigned int y = position.y;
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }
        
        __grid[x * __width + y] = new Simple(*this, position, STARTING_AGENT_ENERGY);
        
        return true;
    }
    
    bool Game::addSimple(unsigned x, unsigned y)
    {
        Position p(x,y);
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }

        __grid[x * __width + y] = new Simple(*this, p, STARTING_AGENT_ENERGY);
        
        return true;
    }
   
    bool Game::addStrategic(const Position & position, Strategy *s)
    {
        unsigned int x = position.x;
        unsigned int y = position.y;
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }
        
        __grid[x * __width + y] = new Strategic(*this, position, STARTING_AGENT_ENERGY, s);
        
        return true;
    }
    
    bool Game::addStrategic(unsigned x, unsigned y, Strategy *s)
    {
        Position p(x, y);
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }
        
        __grid[x * __width + y] = new Strategic(*this, p, STARTING_AGENT_ENERGY, s);
        
        return true;
    }

    bool Game::addFood(const Position & position)
    {
        unsigned int x = position.x;
        unsigned int y = position.y;
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }
        
        __grid[x * __width + y] = new Food(*this, position, STARTING_RESOURCE_CAPACITY);
        
        return true;
    }
    
    bool Game::addFood(unsigned x, unsigned y)
    {
        Position p(x,y);
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }
    
        __grid[x * __width + y] = new Food(*this, p, STARTING_RESOURCE_CAPACITY);
    
        return true;
    }

    bool Game::addAdvantage(const Position & position)
    {
        unsigned int x = position.x;
        unsigned int y = position.y;
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }
        
        __grid[x * __width + y] = new Advantage(*this, position, STARTING_RESOURCE_CAPACITY);
        
        return true;
    }
    
    bool Game::addAdvantage(unsigned x, unsigned y)
    {
        Position p(x,y);
        
        if(__grid[x * __width + y] != nullptr)
        {
            return false;
        }
        
        __grid[x * __width + y] = new Advantage(*this, p, STARTING_RESOURCE_CAPACITY);
        
        return true;
    }

    const Surroundings Game::getSurroundings(const Position & pos) const
    {
        Surroundings s;
        int x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
        
        // Position consists of an x and a y, action type = n, nw, etc.
        // [(0,0)][(0,1)][(0,2)]
        // [(1,0)][(1,1)][(1,2)]
        // [(2,0)][(2,1)][(2,2)][(1,3)]
        // [(0,0)][(0,1)][(0,2)][(2,3)]
        // [(1,0)][(1,1)][(1,2)][(3,3)]
        // [(2,0)][(2,1)][(2,2)][(4,3)]
        
        
        x0 = pos.x - 1;
        y0 = pos.y - 1;
        
        if(x0 < 0 || y0 < 0 || x0 > (__height - 1) || y0 > (__width - 1))
        {
            s.array[0] = INACCESSIBLE;
        }
        
        else if(__grid[x0 * __width + y0] == nullptr)
        {
            s.array[0] = EMPTY;
        }
        
        else
        {
            s.array[0] = __grid[x0 * __width + y0]->getType();
        }
        
        x1 = pos.x - 1;
        y1 = pos.y;
        
        if(x1 < 0 || y1 < 0 || x1 > (__height - 1) || y1 > (__width - 1))
        {
            s.array[1] = INACCESSIBLE;
        }
        
        else if(__grid[x1 * __width + y1] == nullptr)
        {
            s.array[1] = EMPTY;
        }
        
        else
        {
              s.array[1] = __grid[x1 * __width + y1]->getType();
        }
        
        x2 = pos.x - 1;
        y2 = pos.y + 1;
        
        if(x2 < 0 || y2 < 0 || x2 > (__height - 1) || y2 > (__width - 1))
        {
            s.array[2] = INACCESSIBLE;
        }
        
        else if(__grid[x2 * __width + y2] == nullptr)
        {
            s.array[2] = EMPTY;
        }
        
        else
        {
            s.array[2] = __grid[x2 * __width + y2]->getType();
        }
        
        x3 = pos.x;
        y3 = pos.y - 1;
        
        if(x3 < 0 || y3 < 0 || x3 > (__height - 1) || y3 > (__width - 1))
        {
            s.array[3] = INACCESSIBLE;
        }
        
        else if(__grid[x3 * __width + y3] == nullptr)
        {
            s.array[3] = EMPTY;
        }
        
        else
        {
            s.array[3] = __grid[x3 * __width + y3]->getType();
        }
        
        x4 = pos.x;
        y4 = pos.y;
        
        if(x4 < 0 || y4 < 0 || x4 > (__height - 1) || y4 > (__width - 1))
        {
            s.array[4] = INACCESSIBLE;
        }
        
        else if(__grid[x4 * __width + y4] == nullptr)
        {
            s.array[4] = EMPTY;
        }
        
        else
        {
            s.array[4] = SELF;
        }
        
        x5 = pos.x;
        y5 = pos.y + 1;
        
        if(x5 < 0 || y5 < 0 || x5 > (__height - 1) || y5 > (__width - 1))
        {
            s.array[5] = INACCESSIBLE;
        }
        
        else if(__grid[x5 * __width + y5] == nullptr)
        {
            s.array[5] = EMPTY;
        }
        
        else
        {
            s.array[5] = __grid[x5 * __width + y5]->getType();
        }
        
        x6 = pos.x + 1;
        y6 = pos.y - 1;
        
        if(x6 < 0 || y6 < 0 || x6 > (__height - 1) || y6 > (__width - 1))
        {
            s.array[6] = INACCESSIBLE;
        }
        
        else if(__grid[x6 * __width + y6] == nullptr)
        {
            s.array[6] = EMPTY;
        }
        
        else
        {
            s.array[6] = __grid[x6 * __width + y6]->getType();
        }
        
        x7 = pos.x + 1;
        y7 = pos.y;
        
        if(x7 < 0 || y7 < 0 || x7 > (__height - 1) || y7 > (__width - 1))
        {
            s.array[7] = INACCESSIBLE;
        }
       
        else if(__grid[x7 * __width + y7] == nullptr)
        {
            s.array[7] = EMPTY;
        }
        
        else
        {
            s.array[7] = __grid[x7 * __width + y7]->getType();
        }
        
        x8 = pos.x + 1;
        y8 = pos.y + 1;
        
        if(x8 < 0 || y8 < 0 || x8 > (__height - 1) || y8 > (__width - 1))
        {
            s.array[8] = INACCESSIBLE;
        }
        
        else if(__grid[x8 * __width + y8] == nullptr)
        {
            s.array[8] = EMPTY;
        }
        
        else
        {
            s.array[8] = __grid[x8 * __width + y8]->getType();
        }
        
        return s;
    }
    
    void Game::populate()
    {
       
    }

    std::ostream &operator<<(std::ostream & os, const Game & game)
    {
            os << "Round " << game.getRound() << ":" << std::endl;
            
            for(int j = 0; j < game.__height; j++)
            {
                for(int k = 0; k < game.__width; k++)
                {
                    if(game.__grid[k] != nullptr)
                    {
                        os << "[" << *game.__grid[k] << "     ]";
                    }
                    
                    else
                    {
                        os << "[     ]";
                    }
                }
                
                 os << std::endl;
            }
        
        if(game.getStatus() == 0)
            os << "Status: Not Started" << std::endl;
        
        else if(game.getStatus() == 1)
            os << "Status: Playing..." << std::endl;
        
        else
            os << "Status: Over!" << std::endl;
        
        return os;
    }
    
    bool Game::isLegal(const ActionType & ac, const Position & pos) const
    {
        int x, y;
        
        if(ac == N)
        {
            x = pos.x - 1;
            y = pos.y;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
            
        }
        
        if(ac == NE)
        {
            x = pos.x - 1;
            y = pos.y + 1;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
        }
        
        if(ac == E)
        {
            x = pos.x;
            y = pos.y + 1;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
        }
        
        if(ac == SE)
        {
            x = pos.x + 1;
            y = pos.y + 1;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
        }
        
        if(ac == S)
        {
            x = pos.x + 1;
            y = pos.y;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
        }
        
        if(ac == SW)
        {
            x = pos.x + 1;
            y = pos.y - 1;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
        }
        
        if(ac == W)
        {
            x = pos.x;
            y = pos.y - 1;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
        }
        
        if(ac == NW)
        {
            x = pos.x - 1;
            y = pos.y - 1;
            
            if(x < 0 || y < 0 || x > (__height - 1) || y > (__width - 1))
            {
                return false;
            }
        }
        
        return true;
    }
    
    const Position Game::move(const Position & pos, const ActionType & ac) const
    {
        // Position consists of an x and a y, action type = n, nw, etc.
        // [(0,0)][(0,1)][(0,2)]
        // [(1,0)][(1,1)][(1,2)]
        // [(2,0)][(2,1)][(2,2)]
        
        Position new_pos;
        
        if(isLegal(ac, pos) == true)
        {
            if(ac == N)
            {
                new_pos.x = pos.x - 1;
                new_pos.y = pos.y;
                
                return new_pos;
            }
            
            if(ac == NW)
            {
                new_pos.x = pos.x - 1;
                new_pos.y = pos.y - 1;
                
                return new_pos;
            }
            
            if(ac == NE)
            {
                new_pos.x = pos.x - 1;
                new_pos.y = pos.y + 1;
                
                return new_pos;
            }
            
            if(ac == S)
            {
                new_pos.x = pos.x + 1;
                new_pos.y = pos.y;
                
                return new_pos;
            }
            
            if(ac == SW)
            {
                new_pos.x = pos.x + 1;
                new_pos.y = pos.y - 1;
                
                return new_pos;
            }
            
            if(ac == SE)
            {
                new_pos.x = pos.x + 1;
                new_pos.y = pos.y + 1;
                
                return new_pos;
            }
            
            if(ac == E)
            {
                new_pos.x = pos.x;
                new_pos.y = pos.y + 1;
                
                return new_pos;
            }
            
            if(ac == W)
            {
                new_pos.x = pos.x;
                new_pos.y = pos.y - 1;
                
                return new_pos;
            }
        
        }
       
        return pos;
        
    } // note: assumes legal, use with isLegal()
    
    const ActionType Game::reachSurroundings(const Position & from, const Position & to)
    {
        if((from.x - to.x) == 1 && (from.y - to.y) == 0)
        {
            return N;
        }
        
        if((from.x - to.x) == 1 && (from.y - to.y) == -1)
        {
            return NE;
        }
        
        if((from.x - to.x) == 0 && (from.y - to.y) == -1)
        {
            return E;
        }
        
        if((from.x - to.x) == -1 && (from.y - to.y) == -1)
        {
            return SE;
        }
        
        if((from.x - to.x) == -1 && (from.y - to.y) == 0)
        {
            return S;
        }
        
        if((from.x - to.x) == -1 && (from.y - to.y) == 1)
        {
            return SW;
        }
        
        if((from.x - to.x) == 0 && (from.y - to.y) == 1)
        {
            return W;
        }
        
        if((from.x - to.x) == 1 && (from.y - to.y == 1))
        {
            return NW;
        }
       
        return STAY;
    }

    void Game::round()
    {
        auto it = __grid.begin();
        
        for( ; it != __grid.end(); ++it)
        {
            if(*it != nullptr)
            {
                if((*it)->getTurned() == false)
                {
                    (*it)->takeTurn(getSurroundings((*it)->getPosition()));
                    (*it)->setTurned(true);
                }
            }
        }
        
        it = __grid.begin();
        
        for( ; it !=__grid.end(); ++it)
        {
            if(*it != nullptr)
            {
                if((*it)->isViable() == true)
                {
                    (*it)->age();
                    (*it)->setTurned(false);
                }
            }
        }
    }
    
    void Game::play(bool)
    {
        round();
    }
    
}
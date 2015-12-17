//
//  main.cpp
//  Programming Assignment 5
//
//  Created by Kathryn Chrisman on 12/10/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "ErrorContext.hpp"
#include "GamingTests.hpp"
#include "Game.hpp" // delete later

using std::cout;
using std::endl;

using namespace Testing;

int main()
{
    
    // Uncomment GamingTests.cpp as you start implementing
    
    const int NumIters = 3;
    
    cout << endl << "Testing PA5!!" << endl << endl;
    
    cout << "NOTE:  If you see any memory errors, you MUST fix them!" << endl;
    cout << "       Tests intentionally invoke destructors after they complete,"
    << endl;
    cout << "       so if you see a seg-fault after a passed test, it is"
    << endl;
    cout << "       probably a bug in your destructor." << endl;
    
    cout << endl;
    
    ErrorContext ec(cout);
    
    // piece tests
    test_piece_smoketest(ec);
    test_piece_print(ec, NumIters);
    test_piece_aging(ec, NumIters);
//    test_piece_energy(ec, NumIters);
//    test_piece_turntaking(ec, NumIters);
//    test_piece_interaction(ec, NumIters);
//
//    // surroundings tests
    test_surroundings_smoketest(ec);
//    
//    // action tests
    test_action_smoketest(ec);
//    
//    // game tests
    test_game_smoketest(ec);
    test_game_populate(ec, NumIters);
    test_game_print(ec, NumIters);
    test_game_play(ec, NumIters);
    
    return 0;
}

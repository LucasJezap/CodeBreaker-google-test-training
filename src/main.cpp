#include <iostream>
#include <gtest/gtest.h>
#include "game.h"
#include <string.h>

/* 
    mode:
    0 - only tests
    1 - only game
    2 - both 
*/

int main(int argc, char* argv[])
{
    int mode;
    if (argc != 2) {
        mode = 2;
    }
    else {
        mode = atoi(argv[1]);
    } 

    if (mode != 1) {
        ::testing::InitGoogleTest(&argc, argv);

        int x = RUN_ALL_TESTS();    
    }
    if (mode != 0) {
        CodeBreaker::Game game;
        game.play(std::cin, true);
    }
}

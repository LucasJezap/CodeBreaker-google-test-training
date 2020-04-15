#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include "output.h"
#include "input.h"

namespace CodeBreaker {

class Game {
private:
    guess * result;
    guess ** guesses;

public:
    // method starting the game
    void play(std::istream& input, bool clear);

};
} // namespace CodeBreaker


#endif // GAME_H

#ifndef OUTPUT_H
#define OUTPUT_H

#include <bits/stdc++.h>
#include "color.h"

namespace CodeBreaker {

    class Output {

    public:
        // method printing win message in good-looking format
        static void print_victory(bool clear);
        // method printing lose message in good-looking format
        static void print_loser(bool clear);
        // method printing whole game structure
        static void show_guesses(guess ** guesses, guess * result, bool &g);
        // method printing result
        static void show_result(guess * result);
    };
} // namespace CodeBreaker


#endif // OUTPUT_H

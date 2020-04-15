#ifndef INPUT_H
#define INPUT_H

#include <bits/stdc++.h>
#include "color.h"

namespace CodeBreaker {

    class Input {

    public:
        // method filling result by user (or randomly)
        static void fill_result(guess * result,std::istream& input);
        // method which takes guess from user
        static void make_guess(guess ** guesses, int guess_number,std::istream& input);

    };
} // namespace CodeBreaker


#endif // INPUT_H

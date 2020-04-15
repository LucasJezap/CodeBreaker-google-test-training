#ifndef GAME_S
#define GAME_S

#include "game.h"

namespace CodeBreaker {

void Game::play(std::istream& input, bool clear) {
    result = new guess[5];
    guesses = new guess*[12];
    for (int i=0; i<12; i++)
        guesses[i] = new guess[5];
    for (int i=0; i<12; i++)
        for (int j=0; j<5; j++)
            guesses[i][j]=0;

    Input::fill_result(result,input);
    if (clear) system("clear");
    bool guessed = false;
    Output::show_guesses(guesses,result,guessed);
    for (int i=0; i<12; i++) {
        Input::make_guess(guesses,i,input);
        if (clear) system("clear");
        Output::show_guesses(guesses,result,guessed);
        if (guessed)
            break;
    }
    std::chrono::milliseconds timespan(1500);
    std::this_thread::sleep_for(timespan);
    (guessed)? Output::print_victory(true): Output::print_loser(true);

    std::cout << "The sequence was: \n";
    Output::show_result(result);

    for (int i=0; i<12; i++)
        free(guesses[i]);
    free(result);
    free(guesses);
    if (!clear) {
        if (guessed) std::cout << "GUESSED\n" << std::endl;
        else std::cout << "NOT GUESSED\n" << std::endl;
    }
}

} // namespace CodeBreaker


#endif // GAME_S

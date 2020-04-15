#ifndef INPUT_S
#define INPUT_S

#include "input.h"

namespace CodeBreaker {

void Input::fill_result(guess * result, std::istream& input) {
    char answer;
    std::cout << "You want to choose the result or make it random? (Y\\N):\n";
    input >> answer;

    if (answer == 'N') {
        guess colors[8] = {32,31,37,36,33,34,35,30};
        for (int i=0; i<5; i++) {
            result[i] = colors[rand()%8];
        }
        return;
    }

    std::cout << "Please fill your result with appropriate colors\n";
    Color::change_color(GREEN); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - G (GREEN)\n";
    Color::change_color(RED); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - R (RED)\n";
    Color::change_color(WHITE); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - W (WHITE)\n";
    Color::change_color(CYAN); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - C (CYAN)\n";
    Color::change_color(YELLOW); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - Y (YELLOW)\n";
    Color::change_color(BLUE); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - B (BLUE)\n";
    Color::change_color(BLACK); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - L (BLACK)\n";
    Color::change_color(MAGENTA); std::cout << "\u006F "; Color::change_color(DEFAULT); std::cout << " - M (MAGENTA)\n";
    for (int i=0; i<5; i++) {
        std::string tmp;
        input >> tmp;
        result[i] = Color::parse_color_to_int(tmp);
    }

}

void Input::make_guess(guess ** guesses, int guess_number, std::istream& input) {
    std::cout << "\nMake your guess?\n";
    for (int i=0; i<5; i++) {
        std::string tmp;
        input >> tmp;
        guesses[guess_number][i] = Color::parse_color_to_int(tmp);
    }
}

} // namespace CodeBreaker


#endif // INPUT_S

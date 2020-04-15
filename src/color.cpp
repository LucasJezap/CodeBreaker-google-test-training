#ifndef COLOR_S
#define COLOR_S

#include "color.h"

namespace CodeBreaker {

int Color::parse_color_to_int(std::string color) {
    if (color.compare("G")==0) return 32;
    else if (color.compare("R")==0) return 31;
    else if (color.compare("W")==0) return 37;
    else if (color.compare("C")==0) return 36;
    else if (color.compare("Y")==0) return 33;
    else if (color.compare("B")==0) return 34;
    else if (color.compare("L")==0) return 30;
    else if (color.compare("M")==0) return 35;
    return 0;
}

std::string Color::parse_color_to_string(int color) {
    if (color == 32) return GREEN;
    else if (color == 31) return RED;
    else if (color == 37) return WHITE;
    else if (color == 36) return CYAN;
    else if (color == 33) return YELLOW;
    else if (color == 34) return BLUE;
    else if (color == 30) return BLACK;
    else if (color == 35) return MAGENTA;
    return DEFAULT;
}

void Color::change_color(std::string color) {
    std::cout << color;
}

} // namespace CodeBreaker


#endif // COLOR_S


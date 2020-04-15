#ifndef COLOR_H
#define COLOR_H

#include <bits/stdc++.h>

#define GREEN "\033[0;1;32m"
#define RED "\033[0;1;31m"
#define WHITE "\033[0;1;37m"
#define CYAN "\033[0;1;36m"
#define YELLOW "\033[0;1;33m"
#define BLUE "\033[0;1;34m"
#define MAGENTA "\033[0;1;35m"
#define BLACK "\033[0;1;30m"
#define DEFAULT "\033[0m"

namespace CodeBreaker {
    /* more matching type name */
    typedef unsigned int guess;

    class Color {

    public:
        // method parsing color from string to int
        static int parse_color_to_int(std::string color);
        // method changing output color to given color
        static void change_color(std::string color);
        // method parsing color from int to string
        static std::string parse_color_to_string(int color);
    };
} // namespace CodeBreaker


#endif // COLOR_H

#ifndef OUTPUT_S
#define OUTPUT_S

#include "output.h"

namespace CodeBreaker {

// method printing win message in good-looking format
void Output::print_victory(bool clear) {
    if (clear) system("clear");
    std::cout << " .----------------.  .----------------.  .-----------------. .-----------------. .----------------.  .----------------. \n";
    std::cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n";
    std::cout << "| | _____  _____ | || |     _____    | || | ____  _____  | || | ____  _____  | || |  _________   | || |  _______     | |\n";
    std::cout << "| ||_   _||_   _|| || |    |_   _|   | || ||_   \\|_   _| | || ||_   \\|_   _| | || | |_   ___  |  | || | |_   __ \\    | |\n";
    std::cout << "| |  | | /\\ | |  | || |      | |     | || |  |   \\ | |   | || |  |   \\ | |   | || |   | |_  \\_|  | || |   | |__) |   | |\n";
    std::cout << "| |  | |/  \\| |  | || |      | |     | || |  | |\\ \\| |   | || |  | |\\ \\| |   | || |   |  _|  _   | || |   |  __ /    | |\n";
    std::cout << "| |  |   /\\   |  | || |     _| |_    | || | _| |_\\   |_  | || | _| |_\\   |_  | || |  _| |___/ |  | || |  _| |  \\ \\_  | |\n";
    std::cout << "| |  |__/  \\__|  | || |    |_____|   | || ||_____|\\____| | || ||_____|\\____| | || | |_________|  | || | |____| |___| | |\n";
    std::cout << "| |              | || |              | || |              | || |              | || |              | || |              | |\n";
    std::cout << "| \'--------------\' || \'--------------\' || \'--------------\' || \'--------------\' || \'--------------\' || \'--------------\' |\n";
    std::cout << " \'----------------\'  \'----------------\'  \'----------------\'  \'----------------\'  \'----------------\'  \'----------------\' \n";
}

// method printing lose message in good-looking format
void Output::print_loser(bool clear) {
    if (clear) system("clear");
    std::cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n";
    std::cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n";
    std::cout << "| |   _____      | || |     ____     | || |    _______   | || |  _________   | || |  _______     | |\n";
    std::cout << "| |  |_   _|     | || |   .\'    `.   | || |   /  ___  |  | || | |_   ___  |  | || | |_   __ \\    | |\n";
    std::cout << "| |    | |       | || |  /  .--.  \\  | || |  |  (__ \\_|  | || |   | |_  \\_|  | || |   | |__) |   | |\n";
    std::cout << "| |    | |   _   | || |  | |    | |  | || |   \'.___`-.   | || |   |  _|  _   | || |   |  __ /    | |\n";
    std::cout << "| |   _| |__/ |  | || |  \\  `--\'  /  | || |  |`\\____) |  | || |  _| |___/ |  | || |  _| |  \\ \\_  | |\n";
    std::cout << "| |  |________|  | || |   `.____.\'   | || |  |_______.\'  | || | |_________|  | || | |____| |___| | |\n";
    std::cout << "| |              | || |              | || |              | || |              | || |              | |\n";
    std::cout << "| \'--------------\' || \'--------------\' || \'--------------\' || \'--------------\' || \'--------------\' |\n";
    std::cout << " \'----------------\'  \'----------------\'  \'----------------\'  \'----------------\'  \'----------------\' \n";
}

// method printing whole game structure
void Output::show_guesses(guess ** guesses, guess * result, bool &g) {
    bool *checked = new bool[5];
    bool *guessed = new bool[5];
    std::cout << std::string(104,'#') << "\n";
    printf("##%13s  _____ ____  _____  ______ ____  _____  ______          _  ________ _____%13s##\n","","");
    printf("##%13s / ____/ __ \\|  __ \\|  ____|  _ \\|  __ \\|  ____|   /\\   | |/ /  ____|  __ \\ %11s##\n","","");
    printf("##%13s| |   | |  | | |  | | |__  | |_) | |__) | |__     /  \\  | \' /| |__  | |__) |%11s##\n","","");
    printf("##%13s| |   | |  | | |  | |  __| |  _ <|  _  /|  __|   / /\\ \\ |  < |  __| |  _  / %11s##\n","","");
    printf("##%13s| |___| |__| | |__| | |____| |_) | | \\ \\| |____ / ____ \\| . \\| |____| | \\ \\ %11s##\n","","");
    printf("##%13s \\_____\\____/|_____/|______|____/|_|  \\_\\______/_/    \\_\\_|\\_\\______|_|  \\_\\%11s##\n","","");
    printf("##%100s##\n","");
    std::cout << std::string(104,'#') << "\n";
    printf("##   Attempt no   ####      Guesses      ##                          Results                          ##\n");
    std::cout << std::string(104,'#') << "\n";
        for(int i=0; i<12; i++) {
            memset(checked,false,5*sizeof(bool));
            memset(guessed,false,5*sizeof(bool));
            int right_placed = 0;
            int badly_placed = 0;
            printf("##%16s####%19s##%59s##","","","");
            if(i==0) printf("        Try yourself with Codebreaker!");
            if(i==1) printf("        Every round you have to make a guess of a sequence containing 5 colors (order is important!)");
            if(i==2) printf("        But the color might be in a wrong place!");
            if(i==4) { Color::change_color(WHITE); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - W (WHITE)"); }
            if(i==5) { Color::change_color(YELLOW); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - Y (YELLOW)"); }
            if(i==6) { Color::change_color(MAGENTA); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - M (MAGENTA)"); }
            if(i==7) printf("        Copyright 2020 Lukasz Jezapkowicz");
            printf("\n");
            printf("##   Attempt %-5d####     ",i+1);
            for(int j=0; j<5; j++) {
                Color::change_color(Color::parse_color_to_string(guesses[i][j]));
                if (guesses[i][j]==0) std::cout << "  ";
                else std::cout << "\u006F ";
                if (guesses[i][j]==result[j]) {
                    right_placed++;
                    checked[j]=true;
                    guessed[j]=true;
                }
            }

            for(int j=0; j<5; j++) {
                if(guessed[j]) continue;
                for(int k=0; k<5; k++) {
                    if(!checked[k]) {
                        if (guesses[i][j] == result[k]) { badly_placed++; checked[k]=true; break;}
                    }
                }
            }
            Color::change_color(DEFAULT);
            if(right_placed == 5) {
                g = true;
            }
            printf("    ##%25s","");
            for (int j=0; j<badly_placed; j++) std::cout << "\u006F ";
            for (int j=0; j<right_placed; j++) std::cout << "x ";
            for (int j=0; j<5-badly_placed-right_placed; j++) std::cout << "  ";
            printf("%-24s##","");
            if(i==0) printf("        Codebreaker is a logic game where you have to guess correctly the sequence of five colors");
            if(i==1) printf("        After every guess you'll get a return information about your sequence");
            if(i==2) printf("        If you guessed correctly a place in a sequence you will get x instead");
            if(i==3) printf("        You can pick from following colors:");
            if(i==4) { Color::change_color(GREEN); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - G (GREEN)"); }
            if(i==5) { Color::change_color(BLUE); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - B (BLUE)"); }
            printf("\n");
            printf("##%16s####%19s##%59s##","","","");
            if(i==0) printf("        Seems too harsh? Don't worry, there are tips that aim to help you beat the game");
            if(i==1) printf("        For every right color guess you will get a \'o\' sign meaning that a color is right");
            if(i==2) printf("        Keep in mind that colors might be repeated!");
            if(i==3) { Color::change_color(CYAN); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - C (CYAN)"); }
            if(i==4) { Color::change_color(RED); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - R (RED)"); }
            if(i==5) { Color::change_color(BLACK); std::cout << "        \u006F "; Color::change_color(DEFAULT); printf(" - L (BLACK)"); }
            printf("\n");
        }
    std::cout << std::string(104,'#') << "\n";
}

void Output::show_result(guess * result) {
    for (int i=0; i<5; i++) {
        Color::change_color(Color::parse_color_to_string(result[i]));
        std::cout << "\u006F ";
    }
    Color::change_color(DEFAULT);
    std::cout << std::endl;
}

} // namespace CodeBreaker


#endif // OUTPUT_S

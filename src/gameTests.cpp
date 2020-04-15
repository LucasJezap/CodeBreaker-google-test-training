#include <cstring> // strlen()

#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sstream> // std::ostringstream
#include <gtest/gtest.h>

#include "game.h"

using namespace std;
using namespace ::testing;
using namespace CodeBreaker;

/* class which handles output redirection during tests */
class OutputRedirection {
    public:
        std::stringstream ss;
        std::streambuf *old_buf;
        int stdout_fd;

        OutputRedirection() {};
        
        void standardOutputToStringStream() {
            old_buf = std::cout.rdbuf(ss.rdbuf());
        }

        std::string getString() {
            return ss.str();
        }

        void returnToStandardOutput() {
            std::cout.rdbuf(old_buf);
        }

        void oldCOutputToFile() {
            system("touch libs/gtest/trash");
            fflush(stdout);
            stdout_fd = dup(STDOUT_FILENO);
            int redir_fd = open("libs/gtest/trash",O_WRONLY);
            dup2(redir_fd,STDOUT_FILENO);
            close(redir_fd);
        }

        void returnToOldC() {
            fflush(stdout);
            dup2(stdout_fd,STDOUT_FILENO);
            close(stdout_fd);
            system("rm libs/gtest/trash");
        }
};

/* here are tests testing Game class */
struct GameTester : public ::testing::Test
{
};

/* this test checks if after whole gameplay of bad guesses you see the lost message */
TEST_F(GameTester, lostGame) {
    /* this code redirects all output from printf to custom file */
    OutputRedirection red;
    red.oldCOutputToFile();

    /* this code redirects all output to stringstream */
    red.standardOutputToStringStream();

    /* this code allows us to get input from custom file prepared for testing */ 
    std::ifstream ifs ("libs/gtest/game_test_1");                                 

    /* test */
    Game game;
    game.play(ifs,false);
    string ss = red.getString();
    ASSERT_TRUE(ss.find("NOT GUESSED") != std::string::npos);

    /* redirecting output back to standard output */
    red.returnToStandardOutput();

    /* redirecting output from printf back to standard output */
    red.returnToOldC();
}

/* this test checks if after guessing in midtime of gameplay you see the win message */
TEST_F(GameTester, winGameMidTime) {
    /* this code redirects all output from printf to custom file */
    OutputRedirection red;
    red.oldCOutputToFile();

    /* this code redirects all output to stringstream */
    red.standardOutputToStringStream();  

    /* this code allows us to get input from custom file prepared for testing */
    std::ifstream ifs ("libs/gtest/game_test_2");                               

    /* test */
    Game game;
    game.play(ifs,false);
    string ss = red.getString();
    ASSERT_FALSE(ss.find("NOT GUESSED") != std::string::npos);
    
    /* redirecting output back to standard output */
    red.returnToStandardOutput();

    /* redirecting output from printf back to standard output */
    red.returnToOldC();
}

/* this test checks if after guessing in last breath of gameplay you see the win message */
TEST_F(GameTester, winGameLastRound) {
    /* this code redirects all output from printf to custom file */
    OutputRedirection red;
    red.oldCOutputToFile();
    
    /* this code redirects all output to stringstream */
    red.standardOutputToStringStream();
    
    /* this code allows us to get input from custom file prepared for testing */
    std::ifstream ifs ("libs/gtest/game_test_3");                                 

    /* test */
    Game game;
    game.play(ifs,false);
    string ss = red.getString();
    ASSERT_FALSE(ss.find("NOT GUESSED") != std::string::npos);
    
    /* redirecting output back to standard output */
    red.returnToStandardOutput();

    /* redirecting output from printf back to standard output */
    red.returnToOldC();
}
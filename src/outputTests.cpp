#include <cstring> // strlen()

#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sstream> // std::ostringstream
#include <gtest/gtest.h>

#include "output.h"

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

std::string getText(std::ifstream& ifs) {
    string txt = "";
    string line;
    while(std::getline(ifs,line))
        txt += line + "\n";
    return txt;
}

/* here are tests testing Output class */
struct OutputTester : public ::testing::Test
{
};

/* this test checks if after win victory message is printed and if it's printed correctly */
TEST_F(OutputTester, victoryMessage) 
{
    /* this code redirects all output to stringstream */
    OutputRedirection red;
    red.standardOutputToStringStream();  

    /* this code allows us to get input from custom file prepared for testing */
    std::ifstream ifs ("libs/gtest/victory_test");                                

    /* preparing data */
    string vic = getText(ifs);

    /* test */
    Output::print_victory(false);
    string ss = red.getString();
    ASSERT_EQ(vic,ss);

    /* redirecting output back to standard output */
    red.returnToStandardOutput();
}

/* this test checks if after lose loser message is printed and if it's printed correctly */
TEST_F(OutputTester, loseMessage) 
{
    /* this code redirects all output to stringstream */
    OutputRedirection red;
    red.standardOutputToStringStream();

    /* this code allows us to get input from custom file prepared for testing */ 
    std::ifstream ifs ("libs/gtest/lose_test");                                 

    /* preparing data */
    string lose = getText(ifs);

    /* test */    
    Output::print_loser(false);
    string ss = red.getString();
    ASSERT_EQ(lose,ss);

    /* redirecting output back to standard output */
    red.returnToStandardOutput();
}

/* this test checks if result is printed correctly and in correct colors after closing message */
TEST_F(OutputTester, printResult) 
{
    /* this code redirects all output to stringstream */
    OutputRedirection red;
    red.standardOutputToStringStream();

    /* preparing data */
    int column_number = 5;
    guess result[column_number] = {30,31,35,35,37};
    std::string expected = BLACK;
    expected.append("o ");
    expected.append(RED);
    expected.append("o ");
    expected.append(MAGENTA);
    expected.append("o ");
    expected.append(MAGENTA);
    expected.append("o ");
    expected.append(WHITE);
    expected.append("o ");
    expected.append(DEFAULT);
    expected.append("\n");

    /* test */
    Output::show_result(result);
    string ss = red.getString();
    ASSERT_EQ(expected,ss);

    /* redirecting output back to standard output */
    red.returnToStandardOutput();
}

/* this test checks if after correct sentence of guesses flag is set to win */
TEST_F(OutputTester, testIfGuessed)
{
    /* this code redirects all output from printf to custom file */
    OutputRedirection red;
    red.oldCOutputToFile();

    /* this code redirects all output to stringstream */
    red.standardOutputToStringStream();

    /* preparing data */  
    int row_number = 12;
    int column_number = 5;
    guess result[column_number] = {37,37,36,34,34};
    guess ** guesses = new guess *[row_number];
    bool guessed = false;

    for(int row=0; row<row_number; row++) {
        guesses[row] = new guess[column_number]; 
    }

    const guess tmp[row_number][column_number] = {
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32},
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32},
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32},
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32}};

    for(int row=0; row<row_number; row++)
        for(int column=0; column<column_number; column++)
            guesses[row][column]=tmp[row][column];

    /* test */
    Output::show_guesses(guesses,result,guessed);
    ASSERT_TRUE(guessed); 

    /* redirecting output back to standard output */
    red.returnToStandardOutput();

    /* redirecting output from printf back to standard output */    
    red.returnToOldC();

    /* freeing memory */
    for(int row=0; row<row_number; row++)
        delete[] guesses[row];
    delete[] guesses;
}

/* this test checks if after wrong sentence of guesses flag is set to lose */
TEST_F(OutputTester, testIfNotGuessed)
{
    /* this code redirects all output from printf to custom file */
    OutputRedirection red;
    red.oldCOutputToFile();

    /* this code redirects all output to stringstream */
    red.standardOutputToStringStream(); 

    /* preparing data */
    int row_number = 12;
    int column_number = 5;
    guess result[column_number] = {37,37,36,34,32};
    guess ** guesses = new guess *[row_number];
    bool guessed = false;

    for(int row=0; row<row_number; row++) {
        guesses[row] = new guess[column_number];
    }

    const guess tmp[row_number][column_number] = {
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32},
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32},
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32},
    {32,31,31,37,36},
    {37,37,36,34,34},
    {35,35,37,36,32}};

    for(int row=0; row<row_number; row++)
        for(int column=0; column<column_number; column++)
            guesses[row][column]=tmp[row][column];

    /* test */
    Output::show_guesses(guesses,result,guessed);
    ASSERT_FALSE(guessed);

    /* redirecting output back to standard output */
    red.returnToStandardOutput();

    /* redirecting output from printf back to standard output */    
    red.returnToOldC();

    /* freeing memory */
    for(int row=0; row<row_number; row++)
        delete[] guesses[row];
    delete[] guesses;
}
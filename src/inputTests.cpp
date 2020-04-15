#include <cstring> // strlen()

#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sstream> // std::ostringstream
#include <gtest/gtest.h>

#include "input.h"

using namespace std;
using namespace ::testing;
using namespace CodeBreaker;

/* class which handles output redirection during tests */
class OutputRedirection {
    public:
        std::stringstream ss;
        std::streambuf *old_buf;

        OutputRedirection() {};
        
        void standardOutputToStringStream() {
            old_buf = std::cout.rdbuf(ss.rdbuf());
        }

        std::stringstream& getStringStream() {
            return ss;
        }

        void returnToStandardOutput() {
            std::cout.rdbuf(old_buf);
        }
};

/* here are tests testing Input class */
struct InputTester : public ::testing::Test
{
};

/* this test checks if guess given by user is correctly parsed */
TEST_F(InputTester, makeGuessFromInput)
{
    /* this code redirects all output to stringstream */
    OutputRedirection red;
    red.standardOutputToStringStream();

    /* this code allows us to get input from custom file prepared for testing */
    std::ifstream ifs ("libs/gtest/input_test_1");                                 

    /* preparing data */
    const int row_number = 1;
    const int column_number = 5;
    guess ** one_guess = new guess *[row_number];
    one_guess[0] = new guess[column_number];
    const guess expected[column_number] = {32,31,31,37,36};

    /* test */
    Input::make_guess(one_guess,0,ifs);
    for(int column=0; column<column_number; column++)
        ASSERT_EQ(expected[column],one_guess[0][column]) << "index: " << column;

    /* redirecting output back to standard output */
    red.returnToStandardOutput();

    /* freeing memory */
    delete[] one_guess[0];
    delete[] one_guess;
}

/* this test checks if sentence of guesses given by user is correctly parsed */
TEST_F(InputTester, makeMaxGuessesFromInput)
{
    /* this code redirects all output to stringstream */
    OutputRedirection red;
    red.standardOutputToStringStream();  

    /* this code allows us to get input from custom file prepared for testing */
    std::ifstream ifs ("libs/gtest/input_test_2");                                 

    /* preparing data */
    const int row_number = 12;
    const int column_number = 5;
    guess ** guesses = new guess *[row_number];
    const guess expected[row_number][column_number] = {
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

    /* test */
    for(int row=0; row<row_number; row++) {
        guesses[row] = new guess[column_number];
        Input::make_guess(guesses,row,ifs);
    }
    for(int row=0; row<row_number; row++) {
        for(int column=0; column<column_number; column++)
            ASSERT_EQ(expected[row][column],guesses[row][column]) << "row: " << row << " column: " << column;
    }

    /* redirecting output back to standard output */
    red.returnToStandardOutput();

    /* freeing memory */
    for(int row=0; row<row_number; row++)
        delete[] guesses[row];
    delete[] guesses;
}

/* this test checks if result given by user is correctly parsed */
TEST_F(InputTester, makeResultFromInput)
{
    /* this code redirects all output to stringstream */
    OutputRedirection red;
    red.standardOutputToStringStream();

    /* this code allows us to get input from custom file prepared for testing */
    std::ifstream ifs ("libs/gtest/input_test_3");                               

    /* preparing data */
    const int column_number = 5;
    guess * result = new guess[column_number];
    const guess expected[column_number] = {32,31,31,37,36};

    /* test */
    Input::fill_result(result,ifs);
    for(int column=0; column<column_number; column++)
        ASSERT_EQ(expected[column],result[column]) << "column: " << column;

    /* redirecting output back to standard output */
    red.returnToStandardOutput();
    
    /* freeing memory */
    delete[] result;
}
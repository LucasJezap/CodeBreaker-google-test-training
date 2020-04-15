#include <gtest/gtest.h>

#include "color.h"

using namespace std;
using namespace ::testing;
using namespace CodeBreaker;

/* here are tests testing Color class */
struct ColorTester : public ::testing::Test
{ 
};

/* this test checks is color given by string is correctly parsed to integer */
TEST_F(ColorTester, parsingColorToAppropriateInt)
{
    /* tested data */
    const int numberOfColors = 9;
    const string colors[numberOfColors] = {"G","R","W","C","Y","B","L","M","D"};
    const int int_colors[numberOfColors] = {32,31,37,36,33,34,30,35,0};

    /* test */
    for (int index=0; index<numberOfColors; index++) {
        int expColor = int_colors[index];
        int actColor = Color::parse_color_to_int(colors[index]);
        ASSERT_EQ(expColor,actColor);
    }
}

/* this test checks if color given by int is correctly parsed to integer */
TEST_F(ColorTester, parsingColorToAppropriateString)
{
    /* tested data */
    const int numberOfColors = 9;
    const int colors[numberOfColors] = {32,31,37,36,33,34,30,35,0};
    const string string_colors[numberOfColors] = {GREEN,RED,WHITE,CYAN,YELLOW,BLUE,BLACK,MAGENTA,DEFAULT};

    /* test */
    for (int index=0; index<numberOfColors; index++) {
        string expColor = string_colors[index];
        string actColor = Color::parse_color_to_string(colors[index]);
        ASSERT_EQ(expColor,actColor) << "index: " << index;
    }
}
#ifndef GLOBALVARIABLES_H_INCLUDED
#define GLOBALVARIABLES_H_INCLUDED

#include <string.h>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
const int DOT_VEL = 3;
const std::string WINDOW_TITLE = "Mystery Maze";
const int NUMBER_OF_SPRITE = 4;
const int NUMBER_OF_CHARACTER = 3;
const std::string pre[NUMBER_OF_CHARACTER] = {"hp", "hg", "rw"};

const int CHARACTER_WIDTH = 32;
const int CHARACTER_HEIGHT = 48;
const int DECREASE_FOOT_STEP = 5;

enum DIRECTION{
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

enum CHARACTER{
    HARRY_POTTER = 0,
    HERMIONE_GRANGER = 1,
    RON_WEASLEY = 2
};



#endif // GLOBALVARIABLES_H_INCLUDED

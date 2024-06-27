#ifndef HEADER_H
#include "precompiled.h"
#include ".\rendering\render.h"

// ANSI escape sequences
#define ANSI_CLEAR_SCREEN "\033[2J"
#define ANSI_HOME_CURSOR "\033[H"

void gemeloop();
void setup();

unsigned long long millis();
unsigned int measure_fps();

const unsigned int LENGHT_X = 20;
const unsigned int  LENGHT_Y = 20;

#define FIELD_METHOD char *field, const unsigned int lenght_x, const unsigned int lenght_y // makes method defines more readable
#define FIELD_CALL field, LENGHT_X, LENGHT_Y    // makes method calls more readable

struct field{
    char buffer[LENGHT_X*LENGHT_Y]={'0'};
    char length_x = LENGHT_X;
    char length_y = LENGHT_Y;
}_field;

                             


void draw_field(const FIELD_METHOD);
void clear_terminal();
void fill_field_with_char(FIELD_METHOD, const char character);
void draw_point(FIELD_METHOD, const unsigned int Xpos, const unsigned int Ypos, char block);


#endif
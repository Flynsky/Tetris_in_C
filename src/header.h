#ifndef HEADER_H
#include "precompiled.h"
#include ".\rendering\render.h"

// ANSI escape sequences
const char ANSI_CLEAR_SCREEN[]= "\033[2J";
#define ANSI_HOME_CURSOR "\033[H"

void gemeloop();
void setup();

unsigned long long millis();
unsigned int measure_fps();

const unsigned int LENGHT_X = 20;
const unsigned int  LENGHT_Y = 20;

struct field{
    char buffer[LENGHT_X*LENGHT_Y]={'_'};
    const unsigned int length_x = LENGHT_X;
    const unsigned int length_y = LENGHT_Y;
}_field;

                             


void draw_field(struct field * _field);
void clear_terminal();
void fill_field_with_char(struct field * _field, const char character);
void draw_point(struct field * _field, const unsigned int Xpos, const unsigned int Ypos, char block);


#endif
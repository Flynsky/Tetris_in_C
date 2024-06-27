#ifndef HEADER_H
#include "precompiled.h"
#define FIELD_METHOD char *field, const u_int lenght_x, const u_int lenght_y // makes method defines more readable
#define FIELD_CALL field, LENGHT_X, LENGHT_Y                                 // makes method calls more readable

// ANSI escape sequences
#define ANSI_CLEAR_SCREEN "\033[2J"
#define ANSI_HOME_CURSOR "\033[H"

void gemeloop();
void setup();

void draw_field(const FIELD_METHOD);
void clear_terminal();
void fill_field_with_char(FIELD_METHOD, const char character);
void draw_point(FIELD_METHOD, const u_int Xpos, const u_int Ypos, char block);

unsigned long long millis();
unsigned int measure_fps();
#endif
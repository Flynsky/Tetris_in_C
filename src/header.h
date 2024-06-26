#ifndef HEADER_H
#include "precompiled.h"

void draw_field(const char *playfield, const u_int lenght_x, const u_int lenght_y);
void fill_field(char *playfield, const u_int lenght_x, const u_int lenght_y,const char character);

unsigned long long millis();
void print_fps();
#endif
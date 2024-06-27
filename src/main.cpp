#include "header.h"

/** look for out\compile_and_run.bat*/

const u_int LENGHT_X = 20;
const u_int LENGHT_Y = 20;
u_int tick_time = 200; // time between each game tick in ms

char field[LENGHT_X * LENGHT_Y] = {0};

int main()
{
    setup();
    gemeloop();
    return 0;
}

void gemeloop()
{
    static unsigned long long last_tick = millis();
    for (;;)
    {
        if (millis() > last_tick)
        {
            last_tick = millis() + tick_time;
            static u_int a = 0;

            fill_field_with_char(FIELD_CALL, 'O');

            draw_point(FIELD_CALL, 1, a, 'X');
            a += 1;
            draw_field(FIELD_CALL);
        }
        fill_field_with_char(FIELD_CALL, '_');
        draw_point(FIELD_CALL, 1, 1, 'X');
        draw_field(FIELD_CALL);
    }
}

void setup()
{
    u_int fps = measure_fps();
    printf("\nfps of console: %u\n", fps);
}

/**
 *draws a single char int the field
 */
void draw_point(FIELD_METHOD, const u_int Xpos, const u_int Ypos, char block)
{
    field[Xpos + LENGHT_X * Ypos] = block;
}

/**
 * places a block
 */
void draw_block(FIELD_METHOD, const u_int Xpos, const u_int Ypos, const u_int Type)
{
    switch (Type)
    {
    case 0:
        /* code */
        break;

    default:
        break;
    }
}

void fill_field_with_char(FIELD_METHOD, const char character)
{
    for (u_int i = 0; i < (lenght_y * lenght_x); i++)
    {
        field[i] = character;
    }
}

/**outputs the field to the console */
void draw_field(const FIELD_METHOD)
{
    const int lenght_row = lenght_x * 2 + 2; // with start and end simbol
    const int size_buffer = sizeof(char) * lenght_row * lenght_y - 1;

    char *consoleBuffer = (char *)malloc(size_buffer);

    for (int y = 0; y < lenght_y; y += 1)
    {
        consoleBuffer[y * lenght_row] = '|';
        for (int x = 0; x < lenght_x; x += 1)
        {
            consoleBuffer[y * lenght_row + x * 2 + 1] = field[x + y * lenght_y];
            consoleBuffer[y * lenght_row + x * 2 + 2] = '|';
        }
        consoleBuffer[y * lenght_row - 1] = '\n';
    }
    clear_terminal();
    fwrite(consoleBuffer, sizeof(char), size_buffer, stdout);
    fflush(stdout);
}

void clear_terminal()
{
    system("cls");
    // printf(ANSI_CLEAR_SCREEN);
    // printf(ANSI_HOME_CURSOR);
    // for(int i = 0;i<(LENGHT_Y+2);i++){
    // printf("\n");}
}

/**returns the refreshrate of the console */
unsigned int measure_fps()
{
    const unsigned long duration_ms = 100;
    const unsigned long long start_time = millis();
    unsigned long a = 0;
    printf("\n");
    for (;;)
    {
        printf("time till launch: %llums counter: %u \r", millis() - start_time, a);
        a += 1;

        if (millis() - start_time > duration_ms)
        {
            return (u_int)(a / ((millis() - start_time) / duration_ms));
        }
    }
    printf("                                                   ");
}

// returns time since pc start in ms
unsigned long long millis()
{
    static LARGE_INTEGER frequency = {0};
    static char initialized = 0;
    LARGE_INTEGER counter;

    if (!initialized)
    { // Initialize frequency only once
        if (!QueryPerformanceFrequency(&frequency))
        {
            return 0; // Handle error
        }
        initialized = 1;
    }

    if (!QueryPerformanceCounter(&counter))
    {
        return 0; // Handle error
    }

    return (counter.QuadPart * 1000ULL) / frequency.QuadPart;
}

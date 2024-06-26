#include "header.h"

/** look for out\compile_and_run.bat*/

const u_int LENGHT_X = 2;
const u_int LENGHT_Y = 2;
char field[] = {LENGHT_X * LENGHT_Y};

int main()
{
    print_fps();
    fill_field(field, LENGHT_X, LENGHT_Y, 'O');
    draw_field(field, LENGHT_X, LENGHT_Y);
    return 0;
}

void fill_field(char *playfield, const u_int lenght_x, const u_int lenght_y, const char character)
{
    for (u_int i = 0; i < (lenght_y * lenght_x); i++)
    {
        playfield[i] = character;
    }
}

void draw_field(const char *playfield, const u_int lenght_x, const u_int lenght_y)
{
    for (u_int y = 0; y < lenght_y; y++)
    {
        printf("|");
        for (u_int x = 0; x < lenght_x; x++)
        {
            printf(" %c |", playfield[x + y * lenght_x]);
        }
        printf("\n");
    }
}

/**prints the refreshrate of the console */
void print_fps()
{
    const unsigned long duration_ms = 100;
    const unsigned long long start_time = millis();
    unsigned long a = 0;
    printf("\n");
    for (;;)
    {
        printf("time till launch: %ums counter: %u \r", millis() - start_time, a);
        a += 1;

        if (millis() - start_time > duration_ms)
        {
            printf("FPS console: %i                        \n", a / ((millis() - start_time) / duration_ms));
            break;
        }
    }
    printf("\n");
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

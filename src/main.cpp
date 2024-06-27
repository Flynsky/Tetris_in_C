#include "header.h"
#include ".\rendering\render.h"

/** look for out\compile_and_run.bat*/

u_int tick_time = 100; // time between each game tick in ms

char field[LENGHT_X * LENGHT_Y] = {0};

int main()
{
    // setup();
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
            fill_field_with_char(&_field, 'O');
            draw_point(&_field, 1, a, 'X');
            a += 1;
            draw_field(&_field);
            // break;
        }
    }
}

void setup()
{
    u_int fps = measure_fps();
    printf("\nfps of console: %u\n", fps);
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

/**
 *draws a single char int the field
 */
void draw_point(struct field * _field, const unsigned int Xpos, const unsigned int Ypos, char block)
{
    _field->buffer[Xpos + LENGHT_X * Ypos] = block;
}

/**
 * places a block
 */
void draw_block(struct field * _field, const unsigned int Xpos, const unsigned int Ypos, const unsigned int Type)
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

void fill_field_with_char(struct field *_field, const char character)
{
    for (unsigned int i = 0; i < (_field->length_x * _field->length_y); i++)
    {
        _field->buffer[i] = character;
    }
}

/**outputs the field to the console */
void draw_field(struct field *_field)
{
    // for(unsigned int i = 0;i<_field->length_x*_field->length_y;i++){
    //     printf("%c",_field->buffer[i]);
    // }

    const int lenght_row = _field->length_x * 2 + 2; // with start and end simbol
    unsigned int ansi_len = 6;

    const unsigned int size_buffer = ansi_len * sizeof(char) + sizeof(char) * lenght_row * _field->length_y;

    char *consoleBuffer = (char *)malloc(size_buffer);
    if (!consoleBuffer)
    {
        printf("malloc error in drwa_field");
        return;
    }

    for (unsigned int y = 0; y < _field->length_y; y += 1)
    {
        consoleBuffer[y * lenght_row] = '|';
        for (unsigned int x = 0; x < _field->length_x; x += 1)
        {
            consoleBuffer[y * lenght_row + x * 2 + 1] = _field->buffer[x + y * _field->length_y]; //_field->buffer[x + y * _field->length_y]
            consoleBuffer[y * lenght_row + x * 2 + 2] = '|';
        }
        consoleBuffer[y * lenght_row + lenght_row - 1] = '\n';
    }

    memmove(consoleBuffer + ansi_len, consoleBuffer, size_buffer-ansi_len);
    memcpy(consoleBuffer, ANSI_CLEAR_SCREEN, ansi_len);
    fwrite(consoleBuffer, sizeof(char), size_buffer, stdout);
    fflush(stdout);
    free(consoleBuffer);
}

void clear_terminal()
{
    // system("cls");
    printf(ANSI_CLEAR_SCREEN);
    printf(ANSI_HOME_CURSOR);
    // for(int i = 0;i<(LENGHT_Y+2);i++){
    // printf("\n");}
}
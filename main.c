#include <stdint.h>

#define REG_DISPCNT (*(volatile uint16_t*)0x04000000)
#define MODE3 0x0003
#define BG2_ENABLE 0x0400

#define SCREEN ((volatile uint16_t*)0x06000000)

int main(void)
{
    REG_DISPCNT = MODE3 | BG2_ENABLE;

    // Fill the GBA screen with a test color.
    for (int i = 0; i < 240 * 160; i++)
    {
        SCREEN[i] = 0x03E0;
    }

    while (1)
    {
    }

    return 0;
}

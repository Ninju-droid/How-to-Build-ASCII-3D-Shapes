#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
// roteted point
int main() {
    int width = 80, height = 40;
    char screen[width * height];
    float angle = 0;
    float radius = 10;

    printf("\x1b[2J"); // Clear screen once

    while (1) {
        memset(screen, ' ', width * height); // Clear buffer

        // 2D Rotation Formula
        // x' = r * cos(theta)
        // y' = r * sin(theta)
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Map to screen coordinates (with centering and aspect ratio fix)
        int xp = (int)(width / 2 + x * 2); 
        int yp = (int)(height / 2 + y);

        // Plot the point
        if (xp >= 0 && xp < width && yp >= 0 && yp < height) {
            screen[yp * width + xp] = '@';
        }

        // Print screen
        printf("\x1b[H"); // Reset cursor to home
        for (int i = 0; i < width * height; i++) {
            putchar(i % width == 0 && i != 0 ? '\n' : screen[i]);
        }

        angle += 0.1; // Increase angle to spin
        usleep(30000);
    }
    return 0;
}
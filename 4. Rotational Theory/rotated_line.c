#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main() {
    int width = 80, height = 40;
    char screen[width * height];
    float angle = 0;
    float line_length = 15;

    printf("\x1b[2J");

    while (1) {
        memset(screen, ' ', width * height);

        // Draw a line by plotting points along the radius
        for (float r = 0; r < line_length; r += 0.5) {
            // Calculate point position for this specific radius
            float x = r * cos(angle);
            float y = r * sin(angle);

            int xp = (int)(width / 2 + x * 2); // x2 for aspect ratio
            int yp = (int)(height / 2 + y);

            if (xp >= 0 && xp < width && yp >= 0 && yp < height) {
                screen[yp * width + xp] = '#';
            }
        }

        printf("\x1b[H");
        for (int i = 0; i < width * height; i++) {
            putchar(i % width == 0 && i != 0 ? '\n' : screen[i]);
        }

        angle += 0.05; 
        usleep(30000);
    }
    return 0;
}
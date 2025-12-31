#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
// rotating plate by z-buffer 
int main() {
    int width = 80, height = 40;
    char screen[width * height];
    float zBuffer[width * height]; // Our new depth array
    float A = 0;
    float K1 = 40, K2 = 50;

    printf("\x1b[2J");

    while (1) {
        printf("\x1b[2J");
        // Reset buffers
        memset(screen, ' ', width * height);
        // We set Z-buffer to 0 (very far away)
        for(int i = 0; i < width * height; i++) zBuffer[i] = 0;

        // Draw a SOLID square (filling it in)
        for (float i = -10; i <= 10; i += 0.5) {
            for (float j = -10; j <= 10; j += 0.5) {
                
                // Rotation
                float x = i * cos(A); 
                float y = j;
                float z = -i * sin(A);

                // Projection
                float ooz = 1.0 / (K2 + z); // One Over Z
                int xp = (int)(width / 2 + K1 * x * ooz * 2);
                int yp = (int)(height / 2 + K1 * y * ooz);

                if (xp >= 0 && xp < width && yp >= 0 && yp < height) {
                    int idx = yp * width + xp;
                    
                    // Z-BUFFER CHECK
                    // If the current 'ooz' is larger than what's stored, 
                    // it means this point is CLOSER to the camera.
                    if (ooz > zBuffer[idx]) {
                        zBuffer[idx] = ooz; // Update depth
                        screen[idx] = '#';  // Update character
                    }
                }
            }
        }

        printf("\x1b[H");
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? screen[k] : 10);
        }
        A += 0.05;
        usleep(30000);
    }
    return 0;
}
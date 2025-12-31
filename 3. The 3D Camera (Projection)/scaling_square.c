#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<unistd.h> 

int main(){
    int width = 80 ; 
    int height = 40 ; 
    char screen[width*height]; 
    float speed = 0.5; 
    float k1 = 40; 
    float k2 = 60 ; 
    float z = 0 ;

    while(1){
        memset(screen , ' ' , width*height);
        float fact = 1.0/(k2+z) ; 
        for(float x = -10 ; x <= 10 ; x += 0.5){
            for(float y = -10 ; y <= 10 ; y += 0.5){
                if(fabs(x)==10 || fabs(y)==10){
                    int xp = (int)(width/2 + k1 *x *fact *2 ) ; 
                    int yp = (int)(height/2 + k1 *y *fact ); 

                    if (xp >= 0 && xp < width && yp >= 0 && yp < height) {
                        screen[yp * width + xp] = '#';
                    }
                }
            }
        }

        printf("\x1b[H");
        for (int i = 0; i < width * height; i++) {
            putchar(i % width ? screen[i] : 10);
        }

        z+=speed ; 
        if(z>= 30 || z<= -30 ) speed = -speed ; 

        usleep(30000) ; 
    }
    return 0 ; 
}
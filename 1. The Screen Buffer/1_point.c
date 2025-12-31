#include<stdio.h> 
#include<string.h> 

// This is the first step to "How to render " and in this code we render a point in the middle of our screen . 

int main(){
    int height = 20 ; 
    int width = 100 ; 
    char screen[width*height] ;

    memset(screen,'.',width*height); // this Function is for set the memory space '.' , provided by <string.h>
    int x = width/2; 
    int y = height/2; 
    screen[y*width+x] = '@' ; 
    for(int i=0;i<width*height;i++){
        if(i%width==0 && i!=0)putchar('\n'); 

        putchar(screen[i]); 
    }
    putchar('\n'); 
    return 0 ;
}

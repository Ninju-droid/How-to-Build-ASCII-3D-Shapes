#include<stdio.h> 
#include<string.h> 

int main(){
    int height = 20 ; 
    int width = 100 ; 
    char screen[width*height] ;

    memset(screen,'.',width*height); 
    int x = width/2; 
    int y = height/2; 
    for(int i=0;i<width;i++){
        screen[y*width+i] = '@' ; 
    }
    for(int i=0;i<width*height;i++){
        if(i%width==0 && i!=0)putchar('\n'); 

        putchar(screen[i]); 
    }
    putchar('\n'); 
    return 0 ;
}
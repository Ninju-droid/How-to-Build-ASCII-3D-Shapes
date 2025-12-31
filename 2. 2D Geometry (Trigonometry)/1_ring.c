#include<stdio.h> 
#include<math.h> 
#include<unistd.h> 
#include<string.h> 

                                                     int main(){ 
                                                int N  =  1990000000;
                                            /* Code  in shape of   Circle*/            
                                      int width = 80 ;           int height = 25 ; 
                                  int radius = 10 ;                /*F*/int angle = 0;
                                printf("\x1b[2J");                      //// Clear screen 
                              N = width*height ;                             char screen[N]; 
                            memset(screen,' '                                   ,width*height); 
                          char ch = '@';                                         /*****/ while(1){
                        memset(screen,' ',                                              width*height);
                       for(float theta=0;                                               theta<6.28;theta 
                       +=0.1){ int x =                                                  /**/(int)(width/2
                       + 2*radius*cos                                                     (theta+angle)); 
                       int y = (int)                                                    (height/2+radius*
                        sin(theta+angle));                                         if(ch=='@') ch = '#'; 
                         else ch = '@';                                             if(x>=0 && x<width
                          && y>=0 && y< height)                                    {screen[y*width+x]
                            = ch;                                                   /*Vish2503*/} }
                             for(int i=0;i<                                          width*height;
                               i++){if(i%width                                      ==0 && i!=0)                        
                                   putchar('\n');                         putchar(screen[i])       
                                        ;} angle+=0.1;                  usleep(50000);} 
                                             return                     /** */ 0 ; } 
                                                /* Code  in shape of   Circle*/
                                                        // Thank You ! 
                                                           /* */
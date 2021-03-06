#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>}
#include <dos.h>

void Symmetry(int x, int y, int h, int k){
   putpixel(x+h, y+k, 1);
   putpixel(x+h, -y+k, 2);
   putpixel(-x+h, y+k, 3);
   putpixel(-x+h, -y+k, 4);
   putpixel(y+h, x+k, 5);
   putpixel(y+h, -x+k, 6);
   putpixel(-y+h, x+k, 7);
   putpixel(-y+h, -x+k, 8);
   delay(10);
}
void BresCircle(int h, int k, double r){
    int x = 0, y = r;
    int d = 3-2*r;
    while(x<=y){
       Symmetry(x,y,h,k);
       if(d<0)
	   d = d + 4*x + 6;
       else {
	  d = d + 4*(x-y) + 10;
	  y--;
       }
       x++;
    }
}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   int h,k;
   double r;
   scanf("%d %d %lf",&h,&k,&r);
   BresCircle(h,k,r);
   getch();
   closegraph();
   return 0;
}

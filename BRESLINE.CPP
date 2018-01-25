#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
void BresLine(double x1, double y1,double x2,double y2){
    int x=x1, y=y1;
    int dx = x2-x1, dy = y2-y1;
    int dT = 2*(dy-dx), dS=2*dy;
    int d = 2*dy-dx;
    putpixel(x,y,3);
    while(x<x2){
       x++;
       if(d<0)
	   d = d + dS;
       else {
	  y++;
	  d = d + dT;
       }
       putpixel(x,y,3);
       delay(100);
    }
}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   double x1,y1,x2,y2;
   scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
   BresLine(x1,y1,x2,y2);
   getch();
   closegraph();
   return 0;
}

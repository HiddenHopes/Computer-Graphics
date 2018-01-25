#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
double max(double a, double b){
   if(a>b) return a;
   else return b;
}
double min(double a, double b){
   if(a<b) return a;
   else return b;
}
void DDALine(double x1, double y1,double x2,double y2){
   double m,x,y,xp,yp;
   m=(y2-y1)/(x2-x1);
   xp = min(x1,x2);
   yp = min(y1,y2);
  if(fabs(m)>1)
      for(int i=min(y1,y2); i<=max(y1,y2); i++){
	y = i;
	x = xp+(1/m);
	putpixel(x,y,BLUE);
	xp = x;
      }
  else
      for(int i=min(x1,x2);i<=max(x1,x2);i++){
	x = i;
	y = yp+m;
	putpixel(x,y,WHITE);
	yp = y;
      }

}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   double x1,y1,x2,y2;
   scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
   DDALine(x1,y1,x2,y2);
   getch();
   closegraph();
   return 0;
}

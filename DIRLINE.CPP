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
void DirLine(double x1, double y1,double x2,double y2){
   double b,m,x,y;
   m=(y2-y1)/(x2-x1);
   b=y1-m*x1;
  if(fabs(m)>1)
      for(int i=min(y1,y2);i<=max(y1,y2);i++){
	y=i;
	x=(y-b)/m;
	putpixel(x,y,BLUE);
      }
  else
      for(int i=min(x1,x2);i<=max(x1,x2);i++){
	x=i;
	y=m*x+b;
	putpixel(x,y,WHITE);
      }

}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   double x1,y1,x2,y2;
   scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
   DirLine(x1,y1,x2,y2);
   getch();
   closegraph();
   return 0;
}

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>}
#include <dos.h>
float x1, y1, x2, y2;
float max(float a, float b){
    if(a>b) return a;
    else return b;
}
float min(float a, float b){
    if(a<b) return a;
    else return b;
}
void PointClip(float x, float y){
    float xmin, xmax, ymin, ymax;
    putpixel(x,y,RED);
    delay(10);
    xmin = min(x1,x2);
    xmax = max(x1, x2);
    ymin = min(y1, y2);
    ymax = max(y1, y2);
    if(xmin<=x&&x<=xmax){
	if(ymin<=y&&y<=ymax)
	   putpixel(x,y,GREEN);
	else
	   putpixel(x,y,BLACK);
    }
    else putpixel(x,y,BLACK);
}
void LineClip(float x1, float y1, float x2, float y2){
   float b,m,x,y;
   m=(y2-y1)/(x2-x1);
   b=y1-m*x1;
  if(fabs(m)>1)
      for(int i=min(y1,y2);i<=max(y1,y2);i++){
	y=i;
	x=((y-b)/m)+0.5;
	PointClip(x,y);
      }
  else
      for(int i=min(x1,x2);i<=max(x1,x2);i++){
	x=i;
	y=(m*x+b)+0.5;
	PointClip(x,y);
      }
}

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   float a,b,c,d;
   scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
   rectangle(x1,y1,x2,y2);
   while(1){
      scanf("%f %f %f %f", &a, &b, &c, &d);
      if(a<0) break;
      line(a,b,c,d);
      LineClip(a,b,c,d);
   }
   getch();
   closegraph();
   return 0;
}

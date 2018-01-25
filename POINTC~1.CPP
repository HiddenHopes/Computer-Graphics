#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>}
#include <dos.h>
int x1, y1, x2, y2;
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
int min(int a, int b){
    if(a<b) return a;
    else return b;
}
void POINTCLIP(int x, int y){
    int xmin, xmax, ymin, ymax;
    putpixel(x,y,WHITE);
    delay(1000);
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

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   int x,y;
   scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
   rectangle(x1,y1,x2,y2);
   while(1){
      scanf("%d %d",&x,&y);
      if(x==0&&y==0) break;
      POINTCLIP(x,y);
   }
   getch();
   closegraph();
   return 0;
}

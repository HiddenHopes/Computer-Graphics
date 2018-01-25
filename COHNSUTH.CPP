#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>}
#include <dos.h>

double xmax, ymax, xmin, ymin;
int bin[11]={0, 1,10,11,100,101,110,111,1000,1001,1010};
int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
int getcode(double x,double y){
    int code = 0;
    if(y<ymin) code |=TOP;
    if(y>ymax) code |=BOTTOM;
    if(x<xmin) code |=LEFT;
    if(x>xmax) code |=RIGHT;
    return code;
}

void CohSuthLC(float x1, float y1, float x2, float y2){
   double x, y;
   double m = (y2-y1)/(x2-x1);
  // printf("m=%.2lf\n",m);
   int code1=getcode(x1,y1), code2=getcode(x2,y2);
   printf("code1=%04d code2=%04d\n",bin[code1],bin[code2]);
   if(code1==0 && code2==0){
	printf("visible\n");
   }
   else if((code1&code2)!=0){
	printf("not visible\n");
	setcolor(RED);
	line(x1,y1,x2,y2);
   }
   else if((code1&code2)==0){
       if((code1&LEFT)==LEFT) { x = xmin; y = y2 - m*(x2-xmin);}
       else if((code1&RIGHT)==RIGHT) {x = xmax; y = y2 - m*(x2-xmax);}
       if((code1&TOP)==TOP) {y = ymin; x = x2 - (y2-ymin)/m;}
       else if((code1&BOTTOM)==BOTTOM) {y = ymax; x = x2 - (y2-ymax)/m;}
       setcolor(RED);
       if(code1) {line(x1,y1,x,y);
       x1 = floor(x+0.5); y1 = floor(y+0.5);}
       //printf("x1=%.2lf y1=%.2lf\n",x1,y1);
       if((code2&LEFT)==LEFT) {x = xmin; y = y1 + m*(xmin-x1);}
       if((code2&RIGHT)==RIGHT) {x = xmax; y = y1 + m*(xmax-x1);}
       if((code2&TOP)==TOP) {y = ymin; x = x1 + (ymin-y1)/m;}
       if((code2&BOTTOM)==BOTTOM) {y = ymax; x = x1 + (ymax-y1)/m;}

       if(code2) {line(x,y,x2,y2);
       x2 = floor(x+0.5); y2 = floor(y+0.5);}
       //printf("x2=%.2lf y2=%.2lf\n",x2,y2);
       setcolor(BLUE);
       line(x1,y1,x2,y2);
   }
}

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   double x1,y1,x2,y2;
   scanf("%lf %lf %lf %lf",&xmin,&ymin,&xmax,&ymax);
   rectangle(xmin, ymin, xmax, ymax);
   int t=4;
   while(t--){
      scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
      if(x1<0) break;
      setcolor(WHITE);
      line(x1,y1,x2,y2);
      delay(1000);
      CohSuthLC(x1,y1,x2,y2);
   }
   getch();
   closegraph();
   return 0;
}

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#define pi 3.14159
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   double x,y;
   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   //setbkcolor(WHITE);
   setcolor(BLUE);

   /* draw the direct line */
   x=0;
   while(x<=1000){
      y=10*sin((x*pi)/180);
      putpixel(x,200-10*y,3);
      delay(10);
      x+=1;
   }
   /* clean up */
   getch();
   closegraph();
   return 0;
}

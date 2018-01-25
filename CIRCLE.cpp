#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   int radius = 100;
   char ch;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:/Program Files/CodeBlocks");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setbkcolor(WHITE);
   setcolor(BLUE);

   /* draw the circle */
  for(;;){
     ch=getch();
     if(ch=='+') {
	cleardevice();
	radius+=4;
	circle(midx, midy, radius);
     }
     else if(ch=='-'){
	cleardevice();
	radius-=4;
	circle(midx, midy, radius);
     }
     else if(ch==75){
	cleardevice();
	midx-=4;
	circle(midx, midy, radius);
     }
     else if(ch==77){
	cleardevice();
	midx+=4;
	circle(midx, midy, radius);
     }
     else if(ch==72){
	cleardevice();
	midy-=4;
	circle(midx, midy, radius);
     }
     else if(ch==80){
	cleardevice();
	midy+=4;
	circle(midx, midy, radius);
     }
     else if(ch==27) exit(1);
  }
   /* clean up */
   getch();
   closegraph();
   return 0;
}

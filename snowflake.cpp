#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
void koch(int x1, int y1, int x2, int y2, int it)
 {
   float angle = (60*3.14)/180;
   int x3 = (2*x1+x2)/3;
   int y3 = (2*y1+y2)/3;
   
   int x4 = (2*x2+x1)/3;
   int y4 = (2*y2+y1)/3;
   
   int x = x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
   int y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);
   
   if(it>0)
   
   {
     koch(x1,y1,x3,y3,it-1);
     koch(x3,y3,x,y,it-1);
     koch(x,y,x4,y4,it-1);
     koch(x4,y4,x2,y2,it-1);  
   }
   
   else
   {
     setcolor(YELLOW);
     line(x1,y1,x3,y3);
     line(x3,y3,x,y);
     setcolor(BLUE);
     line(x,y,x4,y4);
     line(x4,y4,x2,y2);
   }
 }
int main(void)
{
   int x1, y1, x2, y2, x3, y3,it;
   float angle = (60*3.14)/180;
   cout<<"enter x1:"<<endl;
   cin>>x1;
   cout<<"enter y1:"<<endl;
   cin>>y1;
   cout<<"enter x2:"<<endl;
   cin>>x2;
   cout<<"enter y2:"<<endl;
   cin>>y2;
   cout<<"enter number of iteration:"<<endl;
   cin>>it;
   
   int gd = DETECT ,gm;
   initgraph(&gd, &gm, NULL);
   x3 = x1 + (x2-x1)*cos(angle) + (y2-y1)*sin(angle);
   y3 = y1 - (x2-x1)*sin(angle) + (y2-y1)*cos(angle);
  
   koch(x2,y2,x1,y1,it);
   koch(x1,y1,x3,y3,it);
   koch(x3,y3,x2,y2,it);
   delay(100000);
   return 0;
}

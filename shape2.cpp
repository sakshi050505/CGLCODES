
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void circle(float centx,float centy,float rad)
{
float x,y,p;
x=0;
y=rad;
p=3-(2*rad);
do{
putpixel(centx+x,centy-y,4);
putpixel(centx-x,centy-y,4);
putpixel(centx+x,centy+y,4);
putpixel(centx-x,centy+y,4);
putpixel(centx+y,centy+x,4);
putpixel(centx+y,centy-x,4);
putpixel(centx-y,centy+x,4);
putpixel(centx-y,centy-x,4);

if(p<0){
p = p+(4*x) +6;}
else{
p = p +(4*(x-y))+10;
y=y-1;}
x=x+1;
}while(x<y);
}

void line(float x1,float y1,float x2,float y2)
{
float x,y,len,dx,dy,xin,yin;
dx = x2-x1;
dy = y2-y1;

if (abs(dx) >= abs(dy)){
len = abs(dx);}
else{
len = abs(dy);}

xin = dx/len;
yin = dy/len;
x = x1+0.5;
y = y1+0.5;
int i = 1;
while(i<= len){
putpixel(x,y,RED);
x = x +xin;
y = y +yin;
i++;
}
};

int main(){
float x,y,r;
cout<<"enter x coordinate"<<endl;
cin>>x;
cout<<"enter y coordinate"<<endl;
cin>>y;
cout<<"enter radius of outer circle"<<endl;
cin>>r;
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
float x1,y1,x2,y2,x3,y3,R;
R=r/2;
x1=x;
y1=y-r;
x2=x-(0.866*r);
y2=y+(r/2);
x3=x+(0.866*r);
y3=y+(r/2);

circle(x,y,R);
circle(x,y,r);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x1,y1,x3,y3);
delay(50000);
closegraph();
return 0;
}


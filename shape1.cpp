#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void circle(float centx,float centy,float r)
{
float x,y,p;
x=0;
y=r;
p=3-(2*r);
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

float x1,y1,x2,y2;
cout<<"enter x1 coordinate"<<endl;
cin>>x1;
cout<<"enter y1 coordinate"<<endl;
cin>>y1;
cout<<"enter x2 coordinate"<<endl;
cin>>x2;
cout<<"enter y2 coordinate"<<endl;
cin>>y2;

int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
float x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,cx,cy,D,d,r;
x3=x2;
y3=y1;
x4=x1;
y4=y2;
x5=((x1+x3)/2);
y5=y1;
x6=x2;
y6=((y3+y2)/2);
x7=x5;
y7=y2;
x8=x1;
y8=y6;
cx=x5;
cy=y6;
D=(x3-x1);
d=(y7-y5);
r=(D*d)/(2*(sqrt((d*d)+(D*D))));
circle(cx,cy,r);
line(x1,y1,x3,y3);
line(x3,y3,x2,y2);
line(x4,y4,x2,y2);
line(x1,y1,x4,y4);
line(x6,y6,x7,y7);
line(x7,y7,x8,y8);
line(x6,y6,x5,y5);
line(x5,y5,x8,y8);
delay(50000);
closegraph();
return 0;
}

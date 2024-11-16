#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
float centx,centy,x,y,r,p;
cout<<"enter centx"<<endl;
cin>>centx;
cout<<"enter centy"<<endl;
cin>>centy;
cout<<"enter radius"<<endl;
cin>>r;

x=0;
y=r;
p=3-(2*r);
do{
putpixel(centx+x,centy-y,4);
if(p<0){
p = p+(4*x) +6; }
else{
p = p +(4*(x-y))+10;
y=y-1;}
x=x+1;
}
while(x<y);
delay(50000);
closegraph();
return 0;
}

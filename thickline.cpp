#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
float x1,x2,y1,y2,x,y,len,dx,dy,t,j;
float xin,yin;
cout<<"enter x1;"<<endl;
cin>>x1;
cout<<"enter x2;"<<endl;
cin>>x2;
cout<<"enter y1;"<<endl;
cin>>y1;
cout<<"enter y2;"<<endl;
cin>>y2;
cout<<"enter thickness t:"<<endl;
cin>>t;

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
for(j=0;j<t;j++){
putpixel(x,y+j,RED);
}
x = x +xin;
y = y +yin;
i++;
}
delay(10000);
closegraph();
return 0;
}
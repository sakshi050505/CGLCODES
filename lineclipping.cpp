#include<iostream>
#include<graphics.h>
#include<math.h>
#include<cstdlib>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
static int xmin, ymin, xmax, ymax;

int getcode(int x, int y) {
    int code = 0;
    if (y > ymax) code |= TOP;
    if (y < ymin) code |= BOTTOM;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT; 
    return code;
}

int main() {
    int gdriver = DETECT, gmode;
    initwindow(640, 480);  // Init window for Linux

    setcolor(WHITE);
    cout << "Enter top left and bottom right co-ordinates of window: ";
    cin >> xmin >> ymin >> xmax >> ymax;

    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;

    outtextxy(200, 50, "Before clipping");  // Modified for Ubuntu
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    delay(5000);  // Pause for 5 seconds to view the unclipped line

    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    int accept = 0;

    while (1) {
        float m = (float)(y2 - y1) / (x2 - x1);
        if (outcode1 == 0 && outcode2 == 0) {
            accept = 1;
            break;
        } else if ((outcode1 & outcode2) != 0) {
            break;
        } else {
            int x, y;
            int temp;

            if (outcode1 != 0) temp = outcode1;
            else temp = outcode2;

            if (temp & TOP) {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            } else if (temp & BOTTOM) {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            } else if (temp & LEFT) {
                x = xmin;
                y = y1 + m * (xmin - x1);
            } else if (temp & RIGHT) {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }

            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    setcolor(BLUE);
    cleardevice();

    if (accept) {
        outtextxy(200, 50, "After clipping");
        rectangle(xmin, ymin, xmax, ymax);
        line(x1, y1, x2, y2);
    } else {
        outtextxy(200, 50, "After clipping");
        rectangle(xmin, ymin, xmax, ymax);
    }

    getch();
    closegraph();
}

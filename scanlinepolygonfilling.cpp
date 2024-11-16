#include <iostream>
#include <graphics.h>
using namespace std;

struct edge {
    int x1, y1, x2, y2, flag;
};

int main() {
    int gd = DETECT, gm, n, i, j = 0, k;
    struct edge ed[10], temped;
    float dx, dy, m[10], x_int[10], inter_x[10];
    int x[10], y[10], ymax = 0, ymin = 480, yy, temp;
    
    // Initialize graphics
    initgraph(&gd, &gm, NULL);
    
    // Read the number of vertices of the polygon
    cout << "Enter the number of vertices of the graph: ";
    cin >> n;

    // Read the vertices of the polygon and find ymax and ymin
    cout << "Enter the vertices (x y): ";
    for(i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if(y[i] > ymax)
            ymax = y[i];
        if(y[i] < ymin)
            ymin = y[i];
        ed[i].x1 = x[i];
        ed[i].y1 = y[i];
    }
    
    // Store edge information
    cout << "\nEdge Information\n";
    for(i = 0; i < n - 1; i++) {
        ed[i].x2 = ed[i + 1].x1;
        ed[i].y2 = ed[i + 1].y1;
        ed[i].flag = 0;
        cout << "(" << ed[i].x1 << ", " << ed[i].y1 << ") (" << ed[i].x2 << ", " << ed[i].y2 << ")" << endl;
    }
    ed[i].x2 = ed[0].x1;
    ed[i].y2 = ed[0].y1;
    ed[i].flag = 0;
    cout << "(" << ed[i].x1 << ", " << ed[i].y1 << ") (" << ed[i].x2 << ", " << ed[i].y2 << ")" << endl;

    // Check for y1 > y2; if not, interchange y1 and y2
    cout << "\nUpdated Edge Information\n";
    for(i = 0; i < n; i++) {
        if(ed[i].y1 < ed[i].y2) {
            temp = ed[i].x1;
            ed[i].x1 = ed[i].x2;
            ed[i].x2 = temp;
            temp = ed[i].y1;
            ed[i].y1 = ed[i].y2;
            ed[i].y2 = temp;
        }
        cout << "(" << ed[i].x1 << ", " << ed[i].y1 << ") (" << ed[i].x2 << ", " << ed[i].y2 << ")" << endl;
    }

    // Draw the polygon
    for(i = 0; i < n; i++) {
        line(ed[i].x1, ed[i].y1, ed[i].x2, ed[i].y2);
    }

    // Calculate 1/slope of each edge
    for(i = 0; i < n; i++) {
        dx = ed[i].x2 - ed[i].x1;
        dy = ed[i].y2 - ed[i].y1;
        if(dy == 0) {
            m[i] = 0;
        } else {
            m[i] = dx / dy;
        }
        inter_x[i] = ed[i].x1;
    }

    yy = ymax;

    // Active edges logic
    while(yy > ymin) {
        for(i = 0; i < n; i++) {
            if(yy > ed[i].y2 && yy <= ed[i].y1)
                ed[i].flag = 1;   // Active edge
            else
                ed[i].flag = 0;   // Not active edge
        }

        j = 0;
        for(i = 0; i < n; i++) {
            if(ed[i].flag == 1) {
                if(yy == ed[i].y1) {
                    x_int[j] = ed[i].x1;
                    j++;
                } else {
                    x_int[j] = inter_x[i] + (-m[i]);
                    inter_x[i] = x_int[j];
                    j++;
                }
            }
        }

        // Sorting the x intersection
        for(i = 0; i < j; i++) {
            for(k = 0; k < j - 1; k++) {
                if(x_int[k] > x_int[k + 1]) {
                    temp = (int)x_int[k];
                    x_int[k] = x_int[k + 1];
                    x_int[k + 1] = temp;
                }
            }
        }

        // Extracting pairs of values to draw lines
        for(i = 0; i < j; i += 2) {
            setcolor(GREEN);
            line((int)x_int[i], yy, (int)x_int[i + 1], yy);
        }
        yy--;
        delay(50);
    }

    delay(10000);
    closegraph();
    return 0;
}
//Enter the vertices 80 20 100 80 150 60 130 200 40 250

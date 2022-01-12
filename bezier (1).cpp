#include <stdio.h>
#include <graphics.h>
#include <math.h>

int x[4] = {200, 100, 200, 250};
int y[4] = {200, 150, 75, 100};

void bezier ()
{
    int i;
    double t, xt, yt;
    for (t = 0.0; t < 1.0; t+= 0.0005)
    {
        xt = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        yt = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
        putpixel (xt, yt, WHITE);
    }

    for (i=0; i<4; i++)
        putpixel (x[i], y[i], YELLOW);
        getch();
        closegraph();
}


int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, " ");
    bezier();
}

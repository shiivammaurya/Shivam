#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#define PI 3.14159265

void drawPlanet(int x, int y, int r, int color, const char* name) {
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, r, r);
    setcolor(WHITE);
    outtextxy(x + r + 5, y - 5, (char*)name);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;
    double scale = 1.0;

    double radii[8] = {40, 70, 100, 130, 170, 210, 250, 290};
    double speeds[8] = {0.05, 0.04, 0.03, 0.025, 0.02, 0.015, 0.012, 0.01};
    double angles[8] = {0};
    int colors[8] = {LIGHTGRAY, YELLOW, BLUE, RED, CYAN, LIGHTMAGENTA, LIGHTBLUE, WHITE};
    const char* names[8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};

    int ch;

    while (1) {
        cleardevice();
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(midX, midY, 20, 20);
        setcolor(WHITE);
        outtextxy(midX + 25, midY - 5, (char*)"Sun");

        for (int i = 0; i < 8; i++) {
            int r = (int)(scale * radii[i]);
            setcolor(DARKGRAY);
            circle(midX, midY, r);
            int x = midX + (int)(r * cos(angles[i]));
            int y = midY + (int)(r * sin(angles[i]));
            drawPlanet(x, y, 5 + (i == 4 ? 3 : 0), colors[i], names[i]);
            angles[i] += speeds[i];
        }

        if (kbhit()) {
            ch = getch();
            if (ch == '+') scale += 0.1;
            else if (ch == '-') { scale -= 0.1; if (scale < 0.1) scale = 0.1; }
            else if (ch == 27) break;
        }

        delay(40);
    }

    closegraph();
    return 0;
}
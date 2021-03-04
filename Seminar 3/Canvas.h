#pragma once

class Canvas
{
private:
    int width, height;
    char** matrix;
    static int dist2 (int x1, int y1, int x2, int y2);      // returns the square of the distance between two points
public:
    Canvas (int width, int height);

    void drawCircle (int x, int y, float radius, char ch);
    void fillCircle (int x, int y, int radius, char ch);
    void drawRect (int left, int top, int right, int bottom, char ch);
    void fillRect (int left, int top, int right, int bottom, char ch);
    void setPoint (int x, int y, char ch);
    void drawLine (int x1, int y1, int x2, int y2, char ch);

    void print ();
    void clear ();
};

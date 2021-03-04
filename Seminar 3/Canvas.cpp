#include <iostream>

#include "Canvas.h"

Canvas::Canvas (int width, int height)
{
	this->width = width;
	this->height = height;

	matrix = new char* [height];

	for (int i = 0; i < height; i++)
		matrix[i] = new char[width];
}

int Canvas::dist2 (int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void Canvas::drawCircle (int x, int y, float radius, char ch)
{
	if (x + radius >= height || x - radius < 0 || y + radius >= width || y - radius < 0)
	{
		printf ("[ERROR] Circle out of bounds\n");
		return;
	}

	int x1 = -radius, y1 = 0, err = 2 - 2 * radius; 
	do {											
		setPoint (x - x1, y + y1, ch);				
		setPoint (x - y1, y - x1, ch);				
		setPoint (x + x1, y - y1, ch);				
		setPoint (x + y1, y + x1, ch);				
		radius = err;
		if (radius <= y1) 
			err += ++y1 * 2 + 1;          
		if (radius > x1 || err > y1)
			err += ++x1 * 2 + 1;
	} while (x1 < 0);
}
void Canvas::fillCircle (int x, int y, int radius, char ch)
{
	if (x + radius >= height || x - radius < 0 || y + radius >= width || y - radius < 0)
	{
		printf ("[ERROR] Circle out of bounds\n");
		return;
	}

	drawCircle (x, y, radius, ch);		// the circles look weird without this
	for (int i = x - radius; i <= x + radius; i++)
		for (int j = y - radius; j <= y + radius; j++)
			if (dist2 (x, y, i, j) <= radius * radius)
				setPoint (i, j, ch);
}

void Canvas::drawRect (int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || top < 0 || right >= width || bottom >= height)
	{
		printf ("[ERROR] Rectangle out of bounds\n");
		return;
	}

	for (int i = top; i <= bottom; i++)
		matrix[i][left] = matrix[i][right] = ch;
	for (int i = left; i <= right; i++)
		matrix[top][i] = matrix[bottom][i] = ch;
}
void Canvas::fillRect (int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || top < 0 || right >= width || bottom >= height)
	{
		printf ("[ERROR] Rectangle out of bounds\n");
		return;
	}

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			matrix[i][j] = ch;
}

void Canvas::setPoint (int x, int y, char ch)
{
	if (x < 0 || x >= height || y < 0 || y >= width)
	{
		printf ("[ERROR] Point out of bounds\n");
		return;
	}

	matrix[x][y] = ch;
}

void Canvas::drawLine (int x1, int y1, int x2, int y2, char ch)
{
	if (x1 < 0 || x1 >= height || y1 < 0 || y1 >= width ||
		x2 < 0 || x2 >= height || y2 < 0 || y2 >= width)
	{
		printf ("[ERROR] Line out of bounds\n");
		return;
	}

	int dx = abs (x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = -abs (y2 - y1), sy = y1 < y2 ? 1 : -1;
	int err = dx + dy, e2;

	for (;;)
	{
		setPoint (x1, y1, ch);
		if (x1 == x2 && y1 == y2) 
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::print ()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			printf ("%c ", matrix[i][j]);
		printf ("\n");
	}
}
void Canvas::clear ()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}

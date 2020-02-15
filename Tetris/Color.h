#ifndef COLOR_H
#define COLOR_H

struct Color
{
	const byte r, g, b;
	Color(const byte red, const byte green, const byte blue) : r(red), g(green), b(blue) {}
};

static const Color c_color_red = Color(255, 0, 0);
static const Color c_color_orange = Color(255, 100, 0);
static const Color c_color_yellow = Color(255, 255, 0);
static const Color c_color_green = Color(0, 255, 0);
static const Color c_color_blue = Color(0, 0, 255);
static const Color c_color_cyan = Color(0, 255, 255);
static const Color c_color_magenta = Color(255, 0, 255);

#endif

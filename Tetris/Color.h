#ifndef COLOR_H
#define COLOR_H

namespace Colors
{
	struct Color
	{
		unsigned char r, g, b, a;
		Color(const unsigned char red, const unsigned char green, const unsigned char blue) : r(red), g(green), b(blue), a(255) {}
		Color(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha) : r(red), g(green), b(blue), a(alpha) {}

		Color& operator=(const Color& other)
		{
			r = other.r;
			g = other.g;
			b = other.b;
			a = other.a;
			return *this;
		}
	};

	const Color c_color_clear = Color(255, 255, 255, 50);
	const Color c_color_red = Color(255, 0, 0);
	const Color c_color_orange = Color(255, 100, 0);
	const Color c_color_yellow = Color(255, 255, 0);
	const Color c_color_green = Color(0, 255, 0);
	const Color c_color_blue = Color(0, 0, 255);
	const Color c_color_cyan = Color(0, 255, 255);
	const Color c_color_magenta = Color(255, 0, 255);
}

#endif

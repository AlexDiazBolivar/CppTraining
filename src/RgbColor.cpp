#include "RgbColor.h"
#include <stdexcept>

namespace training::geometry
{
	// Definitions
	RgbColor RgbColor::BLACK(0,0,0);
	RgbColor RgbColor::WHITE(255,255,255);
	RgbColor RgbColor::RED(255, 0, 0);
	RgbColor RgbColor::GREEN(0, 255, 0);
	RgbColor RgbColor::BLUE(0,0,255);

	// Setters
	void RgbColor::Set(int r, int g, int b)
	{
		if (r >= 0 && r <= 255 && 
			g >= 0 && g <= 255 && 
			b >= 0 && b <= 255)
			rgb = r << 16 | g << 8 | b;

		else
			throw std::invalid_argument("rgb must be between 0-255");
	}

	// Operators
	RgbColor RgbColor::operator + (const RgbColor& c2) const
	{
			int r = Red() + c2.Red();
			int g = Green() + c2.Green();
			int b = Blue() + c2.Blue();
			r = r > 255 ? 255 : r;
			g = g > 255 ? 255 : g;
			b = b > 255 ? 255 : b;
			return RgbColor(r, g, b);
	}

	std::ostream& operator << (std::ostream& o, const RgbColor& c)
	{
		o << "Color object (" << c.Red() << ", " << c.Green() << ", " << c.Blue() << ")";
		return o;
	}
}

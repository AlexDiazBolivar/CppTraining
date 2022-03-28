#include "RgbColor.h"
#include <stdexcept>

namespace training::geometry
{
	RgbColor RgbColor::BLACK(0,0,0);
	RgbColor RgbColor::WHITE(255,255,255);
	RgbColor RgbColor::RED(255, 0, 0);
	RgbColor RgbColor::GREEN(0, 255, 0);
	RgbColor RgbColor::BLUE(0,0,255);

	void RgbColor::Set(int r, int g, int b)
	{
		if (r >= 0 && r <= 255 && 
			g >= 0 && g <= 255 && 
			b >= 0 && b <= 255)
			rgb = r << 16 | g << 8 | b;

		else
			throw std::invalid_argument("rgb must be between 0-255");
	}
}

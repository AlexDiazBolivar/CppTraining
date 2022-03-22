#pragma once

namespace training::geometry
{

	class RgbColor
	{
	public:
		static RgbColor BLACK;
		static RgbColor WHITE;
		static RgbColor RED;
		static RgbColor GREEN;
		static RgbColor BLUE;

		RgbColor() { rgb = 0; }
		RgbColor(int rgb)
		{
			this->rgb = rgb;
		}
		RgbColor(int r, int g, int b)
		{
			Set(r, g, b);
		}
		int Red() const { return (rgb >> 16); }
		int Green() const { return (rgb >> 8) & 0xFF; }
		int Blue() const { return rgb & 0xFF; }
		int Value() const { return rgb; }
		void SetRed(int value)
		{
			Set(value, Green(), Blue());
		}
		void SetGreen(int value)
		{
			Set(Red(), value, Blue());
		}
		void SetBlue(int value);
		void Set(int r, int g, int b);

	private:
		int rgb;
	};

	inline void RgbColor::Set(int r, int g, int b)
	{
		rgb = r << 16 | g << 8 | b;
	}
}
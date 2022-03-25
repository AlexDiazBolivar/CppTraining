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

		// Constructor
		inline RgbColor() { rgb = 0; }
		inline RgbColor(int rgb) { this->rgb = rgb; }
		inline RgbColor(int r, int g, int b) { Set(r, g, b); }

		// Getters
		inline int Red() const { return (rgb >> 16); }
		inline int Green() const { return (rgb >> 8) & 0xFF; }
		inline int Blue() const { return rgb & 0xFF; }

		inline int Value() const { return rgb; }

		// Setters
		inline void SetRed(int value) { Set(value, Green(), Blue()); }
		inline void SetGreen(int value) { Set(Red(), value, Blue()); }
		inline void SetBlue(int value) { Set(Red(), Green(), value); }

		void Set(int r, int g, int b);

	private:
		int rgb;
	};
}

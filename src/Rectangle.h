#pragma once
#include <string>
#include "RgbColor.h"


namespace training::geometry {
	class Rectangle
	{
	public:
		Rectangle() :Rectangle(0,0,"noname", RgbColor::BLUE) {}
		Rectangle(float width, float height, std::string name, RgbColor color)
		{
			SetDimension(width, height);
			SetName(name);
			SetColor(color);
		}

		float Width() const { return width; }
		float Height() const { return height; }
		std::string Name() const { return name; }
		RgbColor Color() const { return color; }
		void SetDimension(float width, float height)
		{
			this->width = width;
			this->height = height;
		}
		void SetName(std::string name)
		{
			this->name = name;
		}
		void SetColor(RgbColor color)
		{
			this->color = color;
		}

		float Area()
		{
			return Width() * Height();
		}
		float Perimeter()
		{
			return (Width() + Height())*2;
		}

	private:
		std::string name;
		RgbColor color;
		float width;
		float height;
	};

}
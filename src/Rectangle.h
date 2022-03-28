#pragma once
#include <string>
#include "RgbColor.h"


namespace training::geometry 
{
	class Rectangle
	{
	public:
		// Constructors
		inline Rectangle() : Rectangle(0,0,"noname", RgbColor::BLUE) {}
		inline Rectangle(float width, float height, const std::string& name, RgbColor color)
		{
			SetDimension(width, height);
			SetName(name);
			SetColor(color);
		}

		// Getters
		inline float Width() const { return width; }
		inline float Height() const { return height; }
		inline std::string Name() const { return name; }
		inline RgbColor Color() const { return color; }

		// Setters
		void SetDimension(float width, float height);
		inline void SetName(const std::string& name) { this->name = name; }
		inline void SetColor(RgbColor color) { this->color = color; }

		// Member functions
		inline float Area() { return Width() * Height(); }
		inline float Perimeter() { return (Width() + Height())*2; }

	private:
		std::string name;
		RgbColor color;
		float width;
		float height;
	};

}
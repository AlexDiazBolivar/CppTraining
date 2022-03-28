#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include "RgbColor.h"


namespace training::geometry
{
	class Circle
	{
	public:
		// Constructor
		inline Circle() : Circle(1, "noname", RgbColor::BLACK) {}

		inline Circle(float radius, const std::string& name, RgbColor color)
		{
			SetRadius(radius);
			SetName(name);
			SetColor(color);
		}

		// Getters
		inline float Radius() const { return radius; }
		inline std::string Name() const { return name; }
		inline RgbColor Color() const { return color; }

		// Setters
		void SetRadius(float radius);
		inline void SetName(const std::string& name) { this->name = name; }
		inline void SetColor(RgbColor color) { this->color = color; }

		// Member functions
		float Area() const;
		float Perimeter() const;

	private:
		std::string name;
		RgbColor color;
		float radius;
	};
}

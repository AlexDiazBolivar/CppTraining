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
		Circle() : Circle(1, "noname", RgbColor::BLACK) {}

		Circle(float radius, std::string name, RgbColor color)
		{
			SetRadius(radius);
			SetName(name);
			SetColor(color);
		}

		float Radius() const { return radius; }
		std::string Name() const { return name; }
		RgbColor Color() const { return color; }
		void SetRadius(float radius)
		{
			this->radius = radius;
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
			return (float) (M_PI * Radius() * Radius());
		}
		float Perimeter()
		{
			return (float) (M_PI * Radius() * 2);
		}

	private:
		std::string name;
		RgbColor color;
		float radius;
	};

}
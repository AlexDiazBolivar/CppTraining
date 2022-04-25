#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include "RgbColor.h"
#include <iostream>


namespace training::geometry
{
	class Circle
	{
	public:
		inline static int Count() { return count; }

		// Constructor
		inline Circle() : Circle(1, "noname", RgbColor::BLACK) {}

		// Copy constructor
		inline Circle(const Circle& other)
			: Circle(other.radius, other.name, other.color)
		{}

		inline Circle(float radius, const std::string& name, RgbColor color)
		{
			SetRadius(radius);
			SetName(name);
			SetColor(color);
			count++;
		}

		inline ~Circle() { count--; }

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

		// Operators
		Circle operator + (const Circle& c2);
		Circle& operator ++ ();
		void operator ++ (int);
		Circle& operator += (float val);
		
	private:
		static int count;
		std::string name;
		RgbColor color;
		float radius;
	};

	// Operators
	std::ostream& operator << (std::ostream& o, const Circle& c);

}

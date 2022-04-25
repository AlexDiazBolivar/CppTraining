#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Circle.h"
#include "NotImplException.h"


namespace training
{
	using training::geometry::Circle;	
	using CircleUptr=std::unique_ptr<Circle>;

	class Landscape
	{

	public:
		// Constructor
		inline Landscape(const std::string& name)
		{
			SetName(name);
		}

		// Copy constructor
		inline Landscape(const Landscape& other) 
		: name(other.name)
		{
			for (int i=0; i<other.circles.size(); i++)
			{
				Add(other.circles[i].get());
			}
		}

		// Getters
		inline std::string Name() const { return name; }

		// Setters
		inline void SetName(const std::string& name) { this->name = name; }

		// Member functions
		inline void Add (const Circle* circle)
		{
			circles.push_back(CircleUptr(new Circle(*circle)));
		}
		inline float Area() const
		{
			float total = 0;
			for (int i=0; i<circles.size(); i++)
			{
				total += circles[i]->Area();
			}
			return total;
		}
		inline float Perimeter() const
		{
			float total = 0;
			for (int i=0; i<circles.size(); i++)
			{
				total += circles[i]->Perimeter();
			}
			return total;
		}

	private:
		std::string name;
		std::vector<CircleUptr> circles;
	};
}

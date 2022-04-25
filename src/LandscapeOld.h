#pragma once

#include <string>
#include "Circle.h"
#include "NotImplException.h"


namespace training
{
	using training::geometry::Circle;	
	class Landscape
	{

	public:
		// Constructor
		inline Landscape(const std::string& name)
		{
			circs = new const Circle* [20]; // Initial allocation
			SetName(name);
			size = 0;
		}

		// Copy constructor
		inline Landscape(const Landscape& other) 
		: name(other.name), size(other.size)
		{
			circs = new const Circle*[20];
			for (int i=0; i<size; i++)
			{
				circs[i] = other.circs[i];
			}
		}

		// Move constructor
		inline Landscape(Landscape&& other)
		 : name(other.name), size(other.size), circs(other.circs)
		{
			other.circs = nullptr;
		}

		// Copy assignment operator
		inline Landscape& operator = (const Landscape& other)
		{
			name = other.name;
			size = other.size;
			for (int i=0; i<size; i++)
			{
				circs[i] = other.circs[i];
			}
			return *this;
		}

		// Move assignment operator	
		inline Landscape& operator = (Landscape&& other)
		{
			name = other.name;
			size = other.size;
			circs = other.circs;
			other.circs = nullptr;
			return *this;
		}

		// Destructor
		inline ~Landscape() 
		{ 
			if (circs == nullptr)
				delete[] circs; 
		}

		// Getters
		inline std::string Name() const { return name; }

		// Setters
		inline void SetName(const std::string& name) { this->name = name; }

		// Member functions
		inline void Add (const Circle* circle)
		{
			circs[size++] = circle;
		}
		inline float Area() const
		{
			float total = 0;
			for (int i=0; i<size; i++)
			{
				total += circs[i]->Area();
			}
			return total;
		}
		inline float Perimeter() const
		{
			float total = 0;
			for (int i=0; i<size; i++)
			{
				total += circs[i]->Perimeter();
			}
			return total;
		}

	private:
		std::string name;
		const Circle** circs;
		int size;
	};
}

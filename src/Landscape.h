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
		Landscape(const std::string& name)
		{
		}
		std::string Name() const { throw NotImplException(); }
		void SetName(const std::string& name)
		{
			throw NotImplException();
		}
		void Add (const Circle* circle)
		{
			throw NotImplException();
		}
		float Area() const
		{
			throw NotImplException();
		}
		float Perimeter() const
		{
			throw NotImplException();
		}

	private:
		std::string name;
	};

}
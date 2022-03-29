#include "Circle.h"
#include <stdexcept>

namespace training::geometry 
{ 
    // Setters
    void Circle::SetRadius(float radius)
    { 
        if (radius < 0)
          throw std::invalid_argument("Radius must be > 0");
        this->radius = radius;
    }
  
    // Member functions
    float Circle::Area() const
    {
		return (float) (M_PI * Radius() * Radius());
    }

    float Circle::Perimeter() const
    {
        return (float) (M_PI * Radius() * 2);
    }
		
    // Operators
    Circle Circle::operator + (const Circle& c2)	
		{
			auto area = Area() + c2.Area();
			Circle ret;
			ret.SetRadius((float)( std::sqrt(area/M_PI) ));
			return ret;
		}

		Circle& Circle::operator ++ ()
		{
			return *this += 1;
		}

		void Circle::operator ++ (int) 
    { 
        ++(*this); 
    }

		Circle& Circle::operator += (float val)
		{
			SetRadius((float)( std::sqrt((Area() + val)/M_PI) ));
			return *this;
		}

	  std::ostream& operator << (std::ostream& o, const Circle& c)
    {
        o << "a circle" << c.Name() << "with area of " << c.Area();
        return o;
	  }

}

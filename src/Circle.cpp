#include "Circle.h"
#include <stdexcept>

namespace training::geometry 
{ 
    void Circle::SetRadius(float radius)
    { 
        if (radius < 0)
          throw std::invalid_argument("Radius must be > 0");
        this->radius = radius;
    }
  
    float Circle::Area() const
    {
		return (float) (M_PI * Radius() * Radius());
    }

    float Circle::Perimeter() const
    {
        return (float) (M_PI * Radius() * 2);
    }

}
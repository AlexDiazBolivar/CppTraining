#include "Circle.h"

namespace training::geometry 
{
    float Circle::Area() const
    {
		return (float) (M_PI * Radius() * Radius());
    }

    float Circle::Perimeter() const
    {
        return (float) (M_PI * Radius() * 2);
    }

}
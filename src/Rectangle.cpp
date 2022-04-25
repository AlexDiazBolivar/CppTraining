#include "Rectangle.h"
#include <stdexcept>

namespace training::geometry 
{ 
    void Rectangle::SetDimension(float width, float height)
    {
        if (width < 0 || height < 0)
            throw std::invalid_argument("Dimension should be positive");
        this->width = width;
        this->height = height;
    }
	  
    std::ostream& operator << (std::ostream& o, const Rectangle& r)
    {
        o << "a rectangle" << r.Name() << "with area of " << r.Area();
        return o;
	  }
}

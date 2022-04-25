#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Templates.h"

namespace training::test
{
    using namespace training::geometry;
    using std::cout;

    TEST (TemplatesTest, ShowTest) 
    {
        Circle c(10, "TC1", RgbColor::BLUE);
        Rectangle r (10, 10, "TR1", RgbColor::RED);

        Show(c, r, std::string("Hello World"), 10.);
    }

}

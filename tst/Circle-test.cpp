#include "gtest/gtest.h"
#include "Circle.h"

using namespace training::geometry;

class CircleTest : public ::testing::Test
{
public:
  CircleTest() : name("Cindy"), color(30, 30, 10) {}

protected:
  void SetUp() override
  {
    c1.SetName(name);
    c1.SetColor(color);
    c1.SetRadius(radius);
  }
  double radius = 10;
  std::string name;
  RgbColor color;
  Circle c1;
};

TEST_F(CircleTest, Name)
{
  ASSERT_EQ(name, c1.Name());
}

TEST_F(CircleTest, Size)
{
    ASSERT_FLOAT_EQ(radius, c1.Radius());
}

TEST_F(CircleTest, Color)
{
  ASSERT_EQ(color.Value(), c1.Color().Value());
}

TEST_F(CircleTest, Area)
{
  ASSERT_NEAR(314, c1.Area(), .2f);
}

TEST_F(CircleTest, Perimeter)
{
  ASSERT_NEAR(62.8f, c1.Perimeter(), .2f);
}
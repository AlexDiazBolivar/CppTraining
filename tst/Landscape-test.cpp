#include <stdexcept>
#include <memory>
#include "gtest/gtest.h"
#include "Landscape.h"
#include "Circle.h"

using namespace training;
using namespace training::geometry;

class LandscapeTest : public ::testing::Test
{
public:
    LandscapeTest() : sut("Test") {}

protected:
    void SetUp() override
    {
        c1.reset(new Circle());
        c2.reset(new Circle());
        c1->SetRadius(10);
        c2->SetRadius(20);
        sut.Add(c1);
        sut.Add(c2);
    }
    Landscape sut;
    CircleSptr c1;
    CircleSptr c2;
};

TEST_F(LandscapeTest, WeakPointerTest)
{
    {
        CircleSptr cptr = std::make_shared<Circle>(10, "Cirlce", RgbColor::BLUE);
        sut.Add(cptr);
        EXPECT_FLOAT_EQ(c1->Area() + c2->Area() + cptr->Area(), sut.Area());
    }
    ASSERT_FLOAT_EQ(c1->Area() + c2->Area(), sut.Area(), .01f);
}

TEST_F(LandscapeTest, DISABLED_ResourceTest)
{
    int count = Circle::Count();
    {
        Landscape tmp("test");
        tmp.Add(c1);
        tmp.Add(c2);
        EXPECT_EQ(count, Circle::Count());
        {
            Landscape tmp("test2");
            tmp.Add(c1);
            tmp.Add(c2);
            EXPECT_EQ(count, Circle::Count());
        }

    }
    ASSERT_EQ(count, Circle::Count());
}

void func(Landscape ls)
{

}
TEST_F(LandscapeTest, MemoryCorrupt)
{
    func(sut);
    sut.Area();
}

TEST_F(LandscapeTest, Name)
{
    ASSERT_EQ("Test", sut.Name());
}

TEST_F(LandscapeTest, Area)
{
    ASSERT_NEAR(1570, sut.Area(), 1.0f);
}

TEST_F(LandscapeTest, Perimeter)
{
    ASSERT_NEAR(188, sut.Perimeter(), 1.0f);
}

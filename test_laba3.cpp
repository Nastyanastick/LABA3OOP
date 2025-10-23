
#include <gtest/gtest.h>
#include "Trap/trapezoid.h"
#include "Square/square.h"
#include "Rect/rectangle.h"
#include "Array/Array.h"


TEST(TrapezoidleTest, AreaCalculation) {
    Trap trapezoid({{{0, 0}, {4, 0}, {3, 2}, {1, 2}}});
    EXPECT_DOUBLE_EQ(6.0, trapezoid.area());
}

TEST(SquareTest, AreaCalculation) {
    Square square({{{0, 0}, {2, 0}, {2, 2}, {0, 2}}});
    EXPECT_DOUBLE_EQ(4.0, square.area());
}

TEST(RectangleTest, AreaCalculation) {
    Rect rectangle({{{0, 0}, {4, 0}, {4, 3}, {0, 3}}});
    EXPECT_DOUBLE_EQ(12.0, rectangle.area());
}



TEST(TrapezoidleTest, CenterCalculation){
    Trap trapezoid({{{0, 0}, {4, 0}, {3, 2}, {1, 2}}});
    auto center = trapezoid.center();
    EXPECT_DOUBLE_EQ(2.0, center.first);
    EXPECT_DOUBLE_EQ(1.0, center.second);

}


TEST(FigureArrayTest, AddAndRemove) {
    Array array;
    auto trapezoid = std::make_unique<Trap>(std::array<std::pair<double, double>, 4>{
        std::make_pair(0, 0), std::make_pair(4, 0), std::make_pair(3, 2), std::make_pair(1, 2)
    });
    
    array.add(std::move(trapezoid));
    EXPECT_EQ(1, array.size());
    
    array.remove(0);
    EXPECT_EQ(0, array.size());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
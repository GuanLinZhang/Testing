#include "gtest/gtest.h"
#include "Formula.h"

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    EXPECT_EQ (Formula::bla (0),  0);
}


TEST(blaTest, test2) {
    //arrange
    //act
    //assert
    EXPECT_EQ (Formula::bla (10), 30);
}

TEST(blaTest, test3) {
    //arrange
    //act
    //assert
    EXPECT_EQ (Formula::bla (50), 220);
}


#include <gtest/gtest.h>
#include <vector>

std::vector<int> FindPrimesInRange(int a, int b);

TEST(PrimesTest, Basic) {
    std::vector<int> result = FindPrimesInRange(1, 10);
    std::vector<int> expected = {2, 3, 5, 7};
    EXPECT_EQ(result, expected);
}

TEST(PrimesTest, InvalidRange) {
    std::vector<int> result = FindPrimesInRange(10, 1);
    EXPECT_TRUE(result.empty());  
}

TEST(PrimesTest, EdgeCases) {
    std::vector<int> result1 = FindPrimesInRange(-5, 5);
    std::vector<int> expected1 = {2, 3, 5};
    EXPECT_EQ(result1, expected1);
    
    std::vector<int> result2 = FindPrimesInRange(7, 7);
    std::vector<int> expected2 = {7};
    EXPECT_EQ(result2, expected2);
    
    std::vector<int> result3 = FindPrimesInRange(4, 4);
    EXPECT_TRUE(result3.empty());
}
TEST(PrimesTest, WrongInterval) {
    std::vector<int> result1 = FindPrimesInRange(24, 28);
    EXPECT_TRUE(result1.empty());
}
    
    
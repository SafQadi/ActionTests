#include "gtest/gtest.h"

// TEST(MathTest, Plus)
// {
//     EXPECT_EQ(2 + 2, 4);
// }

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

int sumo(int a, int b)
{
  return a + b;
}

class Testme : public testing::Test {
 protected:
  void SetUp() override {
  }
};

TEST_F(Testme, sumoTest) {
  EXPECT_EQ(sumo(2U, 5U), 7);
}

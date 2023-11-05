#include "gtest/gtest.h"
#include "matho.hpp"

// TEST(MathTest, Plus)
// {
//     EXPECT_EQ(2 + 2, 4);
// }

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }


class mathoTest : public testing::Test {
 public:
    matho tst;

 protected:
  void SetUp() override {
  }
};

TEST_F(mathoTest, sumoTest) {
  EXPECT_EQ(tst.sumo(2U, 5U), 7U);
}

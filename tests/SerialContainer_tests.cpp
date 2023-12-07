#include <gtest/gtest.h>
#include "../SerialContainer.hpp"

struct SerialContainerFixtureInt : public testing::Test{
    const int size = 10;
    SerialContainer<int> serial;

    void SetUp() override{
        for(int i = 0; i < size; i++){
            serial.push_back(i);
        }
    }
};

TEST(SerialContainerInt, CreateContainer) {
    // Arrange
    SerialContainer<int> serial;
    SerialContainer<int> *ptr = &serial;

    // Act

    // Assert
    EXPECT_TRUE(ptr != nullptr);
}
TEST(SerialContainerInt, PushBack){
    // Arrange
    SerialContainer<int> serial;
    bool flag = true;

    // Act
    for(int i = 0; i < 10; i++){
        serial.push_back(i);
        if(serial[i] != i){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
}
TEST(SerialContainerInt, PushFront){
    // Arrange
    SerialContainer<int> serial;
    bool flag = true;

    // Act
    for(int i = 0; i < 10; i++){
        serial.insert(0, i);
        if(serial[0] != i){
            flag = false;
        }
    }
    // Assert
    EXPECT_TRUE(flag);
}
TEST(SerialContainerInt, InsertMiddle){
    // Arrange
    SerialContainer<int> serial;
    const int position = 3;
    bool flag = true;

    for(int i = 0; i < 10; i++){
        serial.push_back(i);
    }

    // Act
    for(int i = 0; i < 10; i++){
        serial.insert(position, i);
            if(serial[position] != i){
                flag = false;
            }
        }

    // Assert
    EXPECT_TRUE(flag);
}
TEST_F(SerialContainerFixtureInt, Size){
    // Arrange
    // Act
    // Assert
    ASSERT_EQ(serial.size(), 10);
}
TEST_F(SerialContainerFixtureInt, PopBack){

}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

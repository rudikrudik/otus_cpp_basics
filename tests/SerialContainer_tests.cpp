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
    SerialContainer<int> *pSerial = nullptr;
    pSerial = new SerialContainer<int>;

    // Act

    // Assert
    EXPECT_TRUE(pSerial != nullptr);
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
TEST_F(SerialContainerFixtureInt, InsertMiddle){
    // Arrange
    const int position = 3;
    bool flag = true;

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
    // Arrange
    // Act
    for(int i = 0; i < size; i++){
        serial.erase(serial.size() - 1);
    }
    // Assert
    EXPECT_EQ(serial.size(), 0);
}
TEST_F(SerialContainerFixtureInt, PopFront){
    // Arrange
    //Act
    for(int i = 0; i < size; i++){
        serial.erase(0);
    }
    //Assert
    EXPECT_EQ(serial.size(), 0);
}
TEST_F(SerialContainerFixtureInt, PopMiddle){
    // Arrange
    const int middle_pos = 4;
    int temp = serial[middle_pos];

    //Act
    serial.erase(middle_pos);

    //Assert
    EXPECT_EQ(serial.size(), 9);
    EXPECT_EQ(middle_pos, temp);
}
TEST_F(SerialContainerFixtureInt, PopMiddleCountN){
    // Arrange
    int position = 3;
    // Act
    for(int i = 0; i < 6; i++){
        serial.erase(position);
    }
    // Assert
    EXPECT_EQ(serial.size(), 4);
}
TEST_F(SerialContainerFixtureInt, GetElement){
    // Arrange
    bool flag = true;
    // Act
    for(int i = 0; i < size; i++){
        if(serial[i] != i){
            flag = false;
        }
    }
    // Assert
    EXPECT_TRUE(flag);
}
TEST_F(SerialContainerFixtureInt, CopyContainer){
    // Arrange
    SerialContainer<int> serialTwo;
    serialTwo = serial;
    SerialContainer<int> *pOne = &serial;
    SerialContainer<int> *pTwo = &serialTwo;

    bool flag = true;
    //Act
    for(int i = 0; i < size; i++){
        if(serial[i] != serialTwo[i]){
            flag = false;
        }
    }

    //Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(serial.size(), serialTwo.size());
    EXPECT_NE(pOne, pTwo);
}
TEST_F(SerialContainerFixtureInt, Destructor){
    // Arrange

    // Act
    for(int i = 0; i < size; i++){
        serial.erase(0);
    }

    // Assert
    EXPECT_TRUE(serial[0] != 0);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

#pragma once
#include <gtest/gtest.h>
#include "../SerialContainer.hpp"

const int SIZE = 10;

struct SerialContainerFixtureInt : public testing::Test{
    SerialContainer<int> serial;

    void SetUp() override{
        for(int i = 0; i < SIZE; i++){
            serial.push_back(i);
        }
    }
};

TEST(SerialContainerInt, CreateContainer) {
    // Arrange
    SerialContainer<int> *pSerial = nullptr;

    // Act
    pSerial = new SerialContainer<int>;

    // Assert
    EXPECT_TRUE(pSerial != nullptr);
    EXPECT_EQ(pSerial->size(), 0);
}
TEST(SerialContainerInt, PushBack){
    // Arrange
    SerialContainer<int> serial;
    bool flag = true;

    // Act
    for(int i = 0; i < SIZE; i++){
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
    for(int i = 0; i < SIZE; i++){
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
    for(int i = 0; i < SIZE; i++){
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
    for(int i = 0; i < SIZE; i++){
        serial.erase(serial.size() - 1);
    }
    // Assert
    EXPECT_EQ(serial.size(), 0);
}
TEST_F(SerialContainerFixtureInt, PopFront){
    // Arrange
    //Act
    for(int i = 0; i < SIZE; i++){
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
    for(int i = 0; i < SIZE; i++){
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
    for(int i = 0; i < SIZE; i++){
        if(serial[i] != serialTwo[i]){
            flag = false;
        }
    }

    //Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(serial.size(), serialTwo.size());
    EXPECT_NE(pOne, pTwo);
}
TEST_F(SerialContainerFixtureInt, GetElementLessContainerSize){
    // Arrange
    int FirstElem = serial[0];

    // Act
    int ElemLessSize = serial[-1];
    int ElemGreatLessSize = serial[-100];

    // Assert
    EXPECT_EQ(FirstElem, ElemLessSize);
    EXPECT_EQ(FirstElem, ElemGreatLessSize);
}
TEST_F(SerialContainerFixtureInt, GetElementMoreContainerSize){
    // Arrange
    int elemLastInContainer = serial[serial.size() - 1];

    // Act
    int elemMoreContSize = serial[serial.size()];
    int elemGreatMoreLastInContainer = serial[serial.size() + 10];

    // Assert
    EXPECT_EQ(elemLastInContainer, elemMoreContSize);
    EXPECT_EQ(elemLastInContainer, elemGreatMoreLastInContainer);
}
TEST_F(SerialContainerFixtureInt, EraseElemLessContainerSize){
    // Arrange

    // Act
    serial.erase(-1);

    // Assert
    EXPECT_EQ(serial.size(), 10);
}
TEST_F(SerialContainerFixtureInt, EraseElemMoreContainerSize){
    // Arrange
    // Act
    serial.erase(serial.size() + 1);

    // Assert
    EXPECT_EQ(serial.size(), 10);
}
TEST_F(SerialContainerFixtureInt, InsertElemLessContainerSize){
    // Arrange

    // Act
    serial.insert(-1, 11);

    // Assert
    EXPECT_EQ(serial.size(), 10);
}
TEST_F(SerialContainerFixtureInt, InsertElemMoreContainerSize){
    // Arrange
    // Act
    serial.erase(serial.size());

    // Assert
    EXPECT_EQ(serial.size(), 10);
}

// TODO сделать проверку на деструктор
/*
TEST(SerialContainer, Destructor){
    // Arrange
    SerialContainer<int> serial;
    for(int i = 0; i < 10; i++){
        serial.push_back(i);
    }

    int *firstElem = serial.getStart();

    // Act
    std::cout << "Ptr class Serial Container before: " << *firstElem++ << std::endl;
    serial.SerialContainer::~SerialContainer();
    std::cout << "Ptr class Serial Container after: " << *firstElem++ << std::endl;

    // Assert
    EXPECT_TRUE(serial.size() == 10);
}
*/

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

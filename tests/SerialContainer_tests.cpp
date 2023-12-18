#pragma once
#include <gtest/gtest.h>
#include "../SerialContainer.hpp"
#include <iostream>

const int SIZE = 100;

struct SerialContainerFixtureInt : public testing::Test{
    SerialContainer<int> serial{SerialContainer<int>()};

    void SetUp() override{
        for(int i = 0; i < SIZE; i++){
            serial.push_back(i);
        }
    }
};

TEST(SerialContainerInt, CreateContainer) {
    // Arrange
    SerialContainer<int> pSerial{SerialContainer<int>()};

    // Act

    // Assert
    EXPECT_EQ(pSerial.size(), 0);
}
TEST(SerialContainerInt, PushBack){
    // Arrange
    SerialContainer<int> serial{SerialContainer<int>()};

    // Act
    for(int i = 0; i < SIZE; i++){
        serial.push_back(i);
    }

    // Assert
    EXPECT_EQ(serial.size(), SIZE);
}
TEST(SerialContainerInt, PushFront){
    // Arrange
    SerialContainer<int> serial{SerialContainer<int>()};

    // Act
    for(int i = 0; i < SIZE; i++){
        serial.insert(0, i);
    }

    // Assert
    EXPECT_EQ(serial.size(), SIZE);
}
TEST_F(SerialContainerFixtureInt, Size){
    // Arrange
    // Act
    // Assert
    ASSERT_EQ(serial.size(), SIZE);
}
TEST_F(SerialContainerFixtureInt, InsertMiddle){
    // Arrange
    const int position = 3;

    // Act
    for(int i = 0; i < SIZE; i++){
        serial.insert(position, i);
        EXPECT_EQ(i, serial[position]);
        }

    // Assert
    EXPECT_EQ(serial.size(), SIZE * 2);
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
    EXPECT_EQ(serial.size(), SIZE - 1);
    EXPECT_EQ(middle_pos, temp);
}
TEST_F(SerialContainerFixtureInt, PopMiddleCountN){
    // Arrange
    int position = 3;
    // Act
    for(int i = 0; i < SIZE - 4; i++){
        serial.erase(position);
    }
    // Assert
    EXPECT_EQ(serial.size(), 4);
}
TEST_F(SerialContainerFixtureInt, GetElement){
    // Arrange
    // Act

    // Assert
    for(int i = 0; i < SIZE; i++){
        EXPECT_EQ(i, serial[i]);
    }

}
TEST_F(SerialContainerFixtureInt, CopyContainer){
    // Arrange
    SerialContainer<int> serialTwo{SerialContainer<int>()};
    serialTwo = serial;
    SerialContainer<int> *pOne = &serial;
    SerialContainer<int> *pTwo = &serialTwo;

    //Act
    for(int i = 0; i < SIZE; i++){
        EXPECT_EQ(serial[i], serialTwo[i]);
    }

    //Assert
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
    EXPECT_EQ(serial.size(), SIZE);
}
TEST_F(SerialContainerFixtureInt, EraseElemMoreContainerSize){
    // Arrange
    // Act
    serial.erase(serial.size() + 1);

    // Assert
    EXPECT_EQ(serial.size(), SIZE);
}
TEST_F(SerialContainerFixtureInt, InsertElemLessContainerSize){
    // Arrange

    // Act
    serial.insert(-1, 11);

    // Assert
    EXPECT_EQ(serial.size(), SIZE);
}
TEST_F(SerialContainerFixtureInt, InsertElemMoreContainerSize){
    // Arrange
    // Act
    serial.erase(serial.size());

    // Assert
    EXPECT_EQ(serial.size(), SIZE);
}

/*
TEST(SerialContainerInt, Destructor){
    // Arrange
    SerialContainer<int> *ptr;
    ptr = new SerialContainer<int>();

    for(int i = 0; i < SIZE; i++){
        ptr->push_back(i);
    }

    // Act

    // Assert
    EXPECT_TRUE(ptr != nullptr);

}
*/
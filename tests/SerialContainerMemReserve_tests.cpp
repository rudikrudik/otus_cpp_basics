#pragma once
#include "gtest/gtest.h"
#include "../SerialContainerMemReserve.hpp"

const int SIZE = 100;

int get_capacity(){
    int capacity = 2;

    while(capacity < SIZE){
        capacity *= 2;
    }
    return capacity;
}

struct SerialContainerMemReserveIntFixture : testing::Test{
    SerialContainerMR<int> serialMR;

    void SetUp() override {
        for(int i = 0; i < SIZE; i++){
            serialMR.push_back(i);
        }
    }

};

TEST(SerialContainerMemReserveInt, CreateContainer){
    // Arrange
    SerialContainerMR<int> *ptr = nullptr;

    // Act
    ptr = new SerialContainerMR<int>;

    // Assert
    EXPECT_TRUE(ptr != nullptr);
    EXPECT_EQ(ptr->size(), 0);
    EXPECT_EQ(ptr->capacity(), 1);
}
TEST(SerialContainerMemReserveInt, PushBack){
    // Arrange
    SerialContainerMR<int> serialMR = SerialContainerMR<int>();

    // Act
    for(int i = 0; i < SIZE; i++){
        serialMR.push_back(i);
    }

    // Assert
    EXPECT_EQ(serialMR.size(), SIZE);
    EXPECT_EQ(serialMR.capacity(), get_capacity() - SIZE);
}
TEST(SerialContainerMemReserveInt, PushFront){
    // Arrange
    bool flag = true;
    SerialContainerMR<int> serialMR = SerialContainerMR<int>();

    // Act
    for(int i = 0; i < SIZE; i++){
        serialMR.insert(0, i);
        if(serialMR[0] != i){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(serialMR.size(), SIZE);
    EXPECT_EQ(serialMR.capacity(), get_capacity() - SIZE);
}
TEST_F(SerialContainerMemReserveIntFixture, Size){
    // Arrange
    // Act
    // Assert
    EXPECT_EQ(serialMR.size(), SIZE);
}
TEST_F(SerialContainerMemReserveIntFixture, Capacity){
    // Arrange
    // Act
    // Assert
    EXPECT_EQ(serialMR.capacity(), get_capacity() - SIZE);
}
TEST_F(SerialContainerMemReserveIntFixture, CheckElements){
    // Arrange
    bool flag = true;

    // Act
    for(int i = 0; i < SIZE; i++){
        if(serialMR[i] != i){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
}
TEST_F(SerialContainerMemReserveIntFixture, InsertMiddle){
    // Arrange
    const int position = 3;
    bool flag = true;

    // Act
    for(int i = 0; i < SIZE; i++){
        serialMR.insert(position, i);
        if(serialMR[position] != i){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
}
TEST_F(SerialContainerMemReserveIntFixture, PopBack){
    // Arrange
    // Act
    for(int i = 0; i < SIZE; i++){
        serialMR.erase(serialMR.size() - 1);
    }
    // Assert
    EXPECT_EQ(serialMR.size(), 0);
}
TEST_F(SerialContainerMemReserveIntFixture, PopFront){
    // Arrange
    //Act
    for(int i = 0; i < SIZE; i++){
        serialMR.erase(0);
    }
    //Assert
    EXPECT_EQ(serialMR.size(), 0);
}
TEST_F(SerialContainerMemReserveIntFixture, PopMiddle){
    // Arrange
    const int middle_pos = 4;
    int temp = serialMR[middle_pos];

    //Act
    serialMR.erase(middle_pos);

    //Assert
    EXPECT_EQ(serialMR.size(), SIZE - 1);
    EXPECT_EQ(middle_pos, temp);
}
TEST_F(SerialContainerMemReserveIntFixture, PopMiddleCountN){
    // Arrange
    int position = 3;
    // Act
    for(int i = 0; i < SIZE - 4; i++){
        serialMR.erase(position);
    }
    // Assert
    EXPECT_EQ(serialMR.size(), 4);
}
TEST_F(SerialContainerMemReserveIntFixture, GetElement){
    // Arrange
    bool flag = true;
    // Act
    for(int i = 0; i < SIZE; i++){
        if(serialMR[i] != i){
            flag = false;
        }
    }
    // Assert
    EXPECT_TRUE(flag);
}
TEST_F(SerialContainerMemReserveIntFixture, CopyContainer){
    // Arrange
    SerialContainerMR<int> serialTwoMR;
    serialTwoMR = serialMR;
    SerialContainerMR<int> *pOne = &serialMR;
    SerialContainerMR<int> *pTwo = &serialTwoMR;

    bool flag = true;
    //Act
    for(int i = 0; i < SIZE; i++){
        if(serialMR[i] != serialTwoMR[i]){
            flag = false;
        }
    }

    //Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(serialMR.size(), serialTwoMR.size());
    EXPECT_NE(pOne, pTwo);
    EXPECT_EQ(serialMR.capacity(), serialTwoMR.capacity());
}
TEST_F(SerialContainerMemReserveIntFixture, GetElementLessContainerSize){
    // Arrange
    int FirstElem = serialMR[0];

    // Act
    int ElemLessSize = serialMR[-1];
    int ElemGreatLessSize = serialMR[-100];

    // Assert
    EXPECT_EQ(FirstElem, ElemLessSize);
    EXPECT_EQ(FirstElem, ElemGreatLessSize);
}
TEST_F(SerialContainerMemReserveIntFixture, GetElementMoreContainerSize){
    // Arrange
    int elemLastInContainer = serialMR[serialMR.size() - 1];

    // Act
    int elemMoreContSize = serialMR[serialMR.size()];
    int elemGreatMoreLastInContainer = serialMR[serialMR.size() + 10];

    // Assert
    EXPECT_EQ(elemLastInContainer, elemMoreContSize);
    EXPECT_EQ(elemLastInContainer, elemGreatMoreLastInContainer);
}
TEST_F(SerialContainerMemReserveIntFixture, EraseElemLessContainerSize){
    // Arrange
    int capacity = serialMR.capacity();

    // Act
    serialMR.erase(-1);

    // Assert
    EXPECT_EQ(serialMR.size(), SIZE);
    EXPECT_EQ(capacity, serialMR.capacity());
}
TEST_F(SerialContainerMemReserveIntFixture, EraseElemMoreContainerSize){
    // Arrange
    int cap = serialMR.capacity();

    // Act
    serialMR.erase(serialMR.size() + 1);

    // Assert
    EXPECT_EQ(serialMR.size(), SIZE);
    EXPECT_EQ(cap, serialMR.capacity());
}
TEST_F(SerialContainerMemReserveIntFixture, InsertElemLessContainerSize){
    // Arrange
    int cap = serialMR.capacity();

    // Act
    serialMR.insert(-1, 11);

    // Assert
    EXPECT_EQ(serialMR.size(), SIZE);
    EXPECT_EQ(cap, serialMR.capacity());
}
TEST_F(SerialContainerMemReserveIntFixture, InsertElemMoreContainerSize){
    // Arrange
    int cap = serialMR.capacity();

    // Act
    serialMR.insert(SIZE + 1, SIZE);

    // Assert
    EXPECT_EQ(serialMR.size(), SIZE);
    EXPECT_EQ(cap, serialMR.capacity());
}

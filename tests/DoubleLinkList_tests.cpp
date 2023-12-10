#pragma once
#include "gtest/gtest.h"
#include "../DoubleLinkList.hpp"

const int SIZE = 100;

struct DoubleLinkListIntFixture : public testing::Test{
    DoubleLinkedList<int> d_list;

    void SetUp() override {
        for(int i = 0; i < SIZE; i++) {
            d_list.push_back(i);
        }
    }
};

TEST(DoubleLinkListInt, CreateContainer){
    // Arrange
    DoubleLinkedList<int> *pD_list = nullptr;

    // Act
    pD_list = new DoubleLinkedList<int>;

    // Assert
    EXPECT_TRUE(pD_list != nullptr);
    EXPECT_EQ(pD_list->size(), 0);
}
TEST(DoubleLinkListInt, PushBack){
    // Arrange
    DoubleLinkedList<int> d_list = DoubleLinkedList<int>();
    // Act
    for(int i = 0; i < SIZE; i++){
        d_list.push_back(i);
    }
    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
}
TEST(DoubleLinkListInt, PushFront){
    // Arrange
    DoubleLinkedList<int> d_list = DoubleLinkedList<int>();
    // Act
    for(int i = 0; i < SIZE; i++){
        d_list.push_front(i);
    }
    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
}
TEST_F(DoubleLinkListIntFixture, Size){
    // Arrange
    // Act
    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
}
TEST_F(DoubleLinkListIntFixture, InsertMiddle){
    // Arrange
    const int position = 3;

    // Act
    for(int i = 0; i < SIZE; i++){
        d_list.insert(position, i);
    }

    // Assert
    EXPECT_EQ(d_list.size(), SIZE * 2);
}
TEST_F(DoubleLinkListIntFixture, CheckElements){
    // Arrange
    bool flag = true;

    // Act
    for(int i = 0; i < SIZE; i++){
        if(d_list[i] != i){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
}
TEST_F(DoubleLinkListIntFixture, PopBack) {
    // Arrange
    int lastElemD_list = 0;
    bool flag = true;

    // Act
    for (int i = SIZE; i > 0; i--) {
        lastElemD_list = d_list.pop_back();
        if (lastElemD_list != i -1) {
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(d_list.size(), 0);
}
TEST_F(DoubleLinkListIntFixture, PopFront){
    // Arrange
    int firstElem = 0;
    bool flag = true;

    // Act
    for(int i = 0; i < SIZE; i++){
        firstElem = d_list.pop_front();
        if(firstElem != i){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(d_list.size(), 0);

}
TEST_F(DoubleLinkListIntFixture, PopMiddle){
    // Arrange
    bool flag = true;
    int position = SIZE / 2;
    int elemMiddle = 0;

    // Act
    for(int i = position; i < SIZE; i++){
        elemMiddle = d_list.erase(position);
        if(elemMiddle != i){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(d_list.size(), position);
}
TEST_F(DoubleLinkListIntFixture, CopyContainer){
    // Arrange
    bool flag = true;
    DoubleLinkedList<int> d_listTwo;

    for(int i = 0; i < SIZE / 2; i++){
        d_listTwo.push_back(i);
    }

    d_listTwo = d_list;

    // Act
    for(int i = 0; i < SIZE; i++){
        if(d_listTwo[i] != d_list[i]){
            flag = false;
        }
    }

    // Assert
    EXPECT_TRUE(flag);
    EXPECT_EQ(d_list.size(), d_listTwo.size());
}
TEST_F(DoubleLinkListIntFixture, GetElementLessContainerSize){
    // Arrange
    int firstElem = d_list[0];

    // Act
    int elem = d_list[-1];

    // Assert
    EXPECT_EQ(firstElem, elem);
}
TEST_F(DoubleLinkListIntFixture, GetElementMoreContainerSize){
    // Arrange
    int lastElem = d_list[SIZE -1];

    // Act
    int elem = d_list[SIZE];
    int elemMore = d_list[SIZE + 1];

    // Assert
    EXPECT_EQ(lastElem, elem);
    EXPECT_EQ(lastElem, elemMore);
}
TEST_F(DoubleLinkListIntFixture, EraseElemLessContainerSize){
    // Arrange

    // Act
    int elem = d_list.erase(-1);

    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
    EXPECT_EQ(elem, NULL);

}
TEST_F(DoubleLinkListIntFixture, EraseElemMoreContainerSize){
    // Arrange
    // Act
    int lastElem = d_list.erase(SIZE);

    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
    EXPECT_EQ(lastElem, NULL);

}
TEST_F(DoubleLinkListIntFixture, InsertElemLessContainerSize){
    // Arrange

    // Act
    d_list.insert(-1, SIZE);

    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
}
TEST_F(DoubleLinkListIntFixture, InsertElemMoreContainerSize){
    // Arrange
    // Act
    d_list.insert(SIZE, SIZE);

    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
}
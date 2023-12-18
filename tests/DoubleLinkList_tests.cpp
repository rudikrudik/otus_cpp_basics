#pragma once
#include "gtest/gtest.h"
#include "../DoubleLinkList.hpp"

const int SIZE = 1000;

struct DoubleLinkListIntFixture : public testing::Test{
    DoubleLinkedList<int> d_list{DoubleLinkedList<int>()};

    void SetUp() override {
        for(int i = 0; i < SIZE; i++) {
            d_list.push_back(i);
        }
    }
};

TEST(DoubleLinkListInt, CreateContainer){
    // Arrange

    // Act
    DoubleLinkedList<int> pD_list{DoubleLinkedList<int>()};

    // Assert
    EXPECT_EQ(pD_list.size(), 0);
}
TEST(DoubleLinkListInt, PushBack){
    // Arrange
    DoubleLinkedList<int> d_list{DoubleLinkedList<int>()};

    // Act
    for(int i = 0; i < SIZE; i++){
        d_list.push_back(i);
    }

    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
}
TEST(DoubleLinkListInt, PushFront){
    // Arrange
    DoubleLinkedList<int> d_list{DoubleLinkedList<int>()};
    // Act
    for(int i = 0; i < SIZE; i++){
        d_list.push_front(i);
    }
    // Assert
    EXPECT_EQ(d_list.size(), SIZE);
}
TEST(DoubleLinkListInt, Destructor){
    // Arrange
    DoubleLinkedList<int> d_list{DoubleLinkedList<int>()};

    for(int i = 0; i < SIZE; i++){
        d_list.push_back(i);
    }

    int destructorCountBefore = d_list.size();

    // Act
    d_list.~DoubleLinkedList();
    int destructorCountAfter = d_list.size();

    // Assert
    EXPECT_EQ(destructorCountBefore, SIZE);
    EXPECT_EQ(destructorCountAfter, 0);
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

    // Act

    // Assert
    for(int i = 0; i < SIZE; i++){
        EXPECT_EQ(i, d_list[i]);
    }
}
TEST_F(DoubleLinkListIntFixture, PopBack) {
    // Arrange

    // Act
    for (int i = SIZE; i > 0; i--) {
        EXPECT_EQ(d_list.pop_back(), i - 1);
    }

    // Assert
    EXPECT_EQ(d_list.size(), 0);
}
TEST_F(DoubleLinkListIntFixture, PopFront){
    // Arrange

    // Act
    for(int i = 0; i < SIZE; i++){
        EXPECT_EQ(d_list.pop_front(), i);
    }

    // Assert
    EXPECT_EQ(d_list.size(), 0);
}
TEST_F(DoubleLinkListIntFixture, PopMiddle){
    // Arrange
    int position = SIZE / 2;

    // Act
    for(int i = position; i < SIZE; i++){
        EXPECT_EQ(d_list.erase(position), i);
    }

    // Assert
    EXPECT_EQ(d_list.size(), position);
}
TEST_F(DoubleLinkListIntFixture, CopyContainer){
    // Arrange
    DoubleLinkedList<int> d_listTwo{DoubleLinkedList<int>()};

    for(int i = 0; i < SIZE / 2; i++){
        d_listTwo.push_back(i);
    }

    d_listTwo = d_list;

    // Act
    for(int i = 0; i < SIZE; i++){
        EXPECT_EQ(d_listTwo[i], d_list[i]);
    }

    // Assert
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

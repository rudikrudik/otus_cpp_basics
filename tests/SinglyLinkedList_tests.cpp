#pragma once
#include "gtest/gtest.h"
#include "../SinglyLinkedList.hpp"

const int SIZE = 100;

struct SinglyLinkedListIntFixture : public testing::Test{
    SinglyLinkedList<int> list{SinglyLinkedList<int>()};

    void SetUp() override {
        for (int i = 0; i < SIZE; i++) {
            list.push_back(i);
        }
    }
};

TEST(SinglyLinkedListInt, CreateContainer){
    // Arrange
    SinglyLinkedList<int> list {SinglyLinkedList<int>()};
    // Act

    // Assert
    EXPECT_EQ(list.size(), 0);
}
TEST(SinglyLinkedListInt, PushBack){
    // Arrange
    SinglyLinkedList<int> list {SinglyLinkedList<int>()};
    // Act
    for(int i = 0; i < SIZE; i++){
        list.push_back(i);
    }
    // Assert
    EXPECT_EQ(list.size(), SIZE);
}
TEST(SinglyLinkedListInt, PushFront){
    // Arrange
    SinglyLinkedList<int> list{SinglyLinkedList<int>()};

    // Act
    for(int i = 0; i < SIZE; i++){
        list.insert(0, i);
    }

    // Assert
    EXPECT_EQ(list.size(), SIZE);
}
TEST(SinglyLinkedListInt, Destructor){
    // Arrange
    SinglyLinkedList<int> list {SinglyLinkedList<int>()};

    for(int i = 0; i < SIZE; i++){
        list.push_back(i);
    }

    int destructorCountBefore = list.size();

    // Act
    list.~SinglyLinkedList();
    int destructorCountAfter = list.size();

    // Assert
    EXPECT_EQ(destructorCountBefore, SIZE);
    EXPECT_EQ(destructorCountAfter, 0);
}
TEST_F(SinglyLinkedListIntFixture, Size){
    // Arrange
    // Act
    // Assert
    EXPECT_EQ(list.size(), SIZE);
}
TEST_F(SinglyLinkedListIntFixture, PushMiddle){
    // Arrange

    // Act
    for (int i = 0; i < SIZE; i++){
        list.insert(3, i);
    }

    // Assert
    EXPECT_EQ(list.size(), SIZE * 2);
}
TEST_F(SinglyLinkedListIntFixture, PopBack){
    // Arrange

    // Act
    for(int i = 0; i < SIZE; i++){
        list.erase(list.size() - 1);
    }

    // Assert
    EXPECT_EQ(list.size(), 0);
}
TEST_F(SinglyLinkedListIntFixture, PopFront){
    // Arrange
    // Act
    for(int i = 0; i < SIZE; i++){
        list.erase(0);
    }

    // Assert
    EXPECT_EQ(list.size(), 0);
}
TEST_F(SinglyLinkedListIntFixture, CheckElements){
    // Arrange
    // Act
    for(int i = 0; i < SIZE; i++){
        EXPECT_EQ(i, list[i]);
    }
    // Assert
}
TEST_F(SinglyLinkedListIntFixture, CopyContainer){
    // Arrange
    SinglyLinkedList<int> listTwo{SinglyLinkedList<int>()};

    for(int i = 0; i < SIZE / 2; i++){
        listTwo.push_back(i);
    }

    listTwo = list;

    // Act
    for(int i = 0; i < SIZE; i++){
        EXPECT_EQ(list[i], listTwo[i]);
    }

    // Assert
    EXPECT_EQ(list.size(), listTwo.size());
}
TEST_F(SinglyLinkedListIntFixture, GetElementLessContainerSize){
    // Arrange
    int firstElem = list[0];

    // Act
    int elem = list[-1];

    // Assert
    EXPECT_EQ(firstElem, elem);
}
TEST_F(SinglyLinkedListIntFixture, GetElementMoreContainerSize){
    // Arrange
    int lastElem = list[SIZE -1];

    // Act
    int elem = list[SIZE];
    int elemMore = list[SIZE + 1];

    // Assert
    EXPECT_EQ(lastElem, elem);
    EXPECT_EQ(lastElem, elemMore);
}
TEST_F(SinglyLinkedListIntFixture, EraseElemLessContainerSize){
    // Arrange

    // Act
    list.erase(-1);

    // Assert
    EXPECT_EQ(list.size(), SIZE);
}
TEST_F(SinglyLinkedListIntFixture, EraseElemMoreContainerSize){
    // Arrange
    // Act
    list.erase(SIZE);

    // Assert
    EXPECT_EQ(list.size(), SIZE);
}
TEST_F(SinglyLinkedListIntFixture, InsertElemLessContainerSize){
    // Arrange

    // Act
    list.insert(-1, SIZE);

    // Assert
    EXPECT_EQ(list.size(), SIZE);
}
TEST_F(SinglyLinkedListIntFixture, InsertElemMoreContainerSize){
    // Arrange
    // Act
    list.insert(SIZE, SIZE);

    // Assert
    EXPECT_EQ(list.size(), SIZE);
}
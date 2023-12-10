#pragma once
#include "gtest/gtest.h"
#include "../SinglyLinkedList.hpp"
#include <iostream>

const int SIZE = 10;

struct SinglyLinkedListIntFixture : public testing::Test{
    const int size = 10;
    SinglyLinkedList<int> list;

    void SetUp() override {
        for (int i = 0; i < size; i++) {
            list.push_back(i);
        }
    }
};

TEST(SinglyLinkedListInt, CreateContainer){
    // Arrange
    SinglyLinkedList<int> *pList = nullptr;
    // Act
    pList = new SinglyLinkedList<int>;
    // Assert
    EXPECT_TRUE(pList != nullptr);
    EXPECT_EQ(pList->size(), 0);
}
TEST(SinglyLinkedListInt, PushBack){
    // Arrange
    SinglyLinkedList<int> list;
    // Act
    for(int i = 0; i < SIZE; i++){
        list.push_back(i);
    }
    // Assert
    EXPECT_EQ(list.size(), 10);
}
TEST(SinglyLinkedListInt, PushFront){
    // Arrange
    SinglyLinkedList<int> list = SinglyLinkedList<int>();
    // Act
    for(int i = 0; i < SIZE; i++){
        list.insert(0, i);
    }
    // Assert
    EXPECT_EQ(list.size(), 10);
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
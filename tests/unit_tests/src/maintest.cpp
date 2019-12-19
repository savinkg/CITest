#include "maintest.h"
#include "impl.h"
#include <iostream>

TEST(Lab7,CopyConstructor)
{
    LinkedList<int> myList{2,3,4};
    LinkedList<int> expectedList{1,2,3,4};
    LinkedList<int> clone = myList;
    myList.insertAt(0,1);

    ASSERT_EQ(myList,expectedList);
}

LinkedList<int> Copy()
{
    LinkedList<int> r = {1,2,3};
    return r;
}

TEST(Lab7,MoveConstructor)
{
    LinkedList<int> expectedList{1,2,3};
    LinkedList<int> clone = std::move(LinkedList<int>{1,2,3});

    ASSERT_EQ(clone,expectedList);
}


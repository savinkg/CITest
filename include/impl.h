#pragma once
#include <iostream>
#include <functional>

template <typename T>
class LinkedList
{
private:
	struct Node
	{
        T value;
		Node *next;
	};
    Node* _first {nullptr};
    int linkSize {0};

public:
    LinkedList();
    LinkedList(std::initializer_list<T> list);
    LinkedList(const LinkedList<T> &src);
    LinkedList(LinkedList &&src);
    virtual ~LinkedList();
    void insertAt(int index,T value);
    void removeAt(int index);
    int getLength() const;
    void findNode(int index, Node **previousNode, Node **currentNode);

    void sort(std::function<bool(T,T)>);

    template<typename M>
    friend bool operator==(const LinkedList<M>&op1,const LinkedList<M>&op2);
    template<typename M>
    friend std::ostream& operator<<(std::ostream& os,const LinkedList<M> &list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os,const LinkedList<T> &list);

template <typename T>
bool operator==(const LinkedList&op1,const LinkedList<T>&op2);

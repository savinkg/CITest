#include "impl.h"

template <typename T>
LinkedList<T>::LinkedList<T>()
{
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> list)
{
    int nodeNumber {0};

    for(T element:list)
    {
        insertAt(nodeNumber,element);
        nodeNumber ++;
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &src)
{
    int nodeNumber  {0};
    Node *curNodeSrc {src._first};

    while(curNodeSrc)
    {
        insertAt(nodeNumber ,curNodeSrc->value);
        curNodeSrc = curNodeSrc->next;
        nodeNumber++;
    }
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList &&src)
{
    _first = src._first;
    linkSize = src.linkSize;
    src._first = nullptr;
    src.linkSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node *curNode {_first};
    Node *prevNode {nullptr};

    while(curNode)
    {
        prevNode = curNode;
        curNode = curNode->next;
        delete prevNode;
    }
}

template <typename T>
void LinkedList<T>::removeAt(int index)
{
    if ((index >= 0) && (index <= linkSize))
    {
        Node *currentNode {_first};
        Node *previousNode {nullptr};

        if (index>0)
        {
            findNode(index, &previousNode, &currentNode);
            previousNode->next = currentNode->next;
            delete currentNode;
        }
        else
        {
            _first = currentNode->next;
            delete currentNode;
        }
        linkSize--;
    }
}

template <typename T>
void LinkedList<T>::insertAt(int index,T value)
{
    if ((index >= 0) && (index <= linkSize))
    {
        Node *n = new Node;
        Node *currentNode {_first};
        Node *previousNode {nullptr};

        if (index>0)
        {
            findNode(index, &previousNode, &currentNode);
            previousNode->next = n;
        }
        else
        {
            _first = n;
        }
        n->next = currentNode;
        n->value = value;
        linkSize++;
    }
}

template <typename T>
int LinkedList<T>::getLength() const
{
    return linkSize;
}

template <typename T>
void LinkedList<T>::findNode(int index, Node **previousNode, Node **currentNode)
{
    for(int ii=0; ii<index; ii++)
    {
        *previousNode = *currentNode;
        *currentNode = (*currentNode)->next;
    }
}

template <typename T>
void LinkedList::sort(std::function<bool(T,T)>)
{

}

template <typename T>
bool operator==(const LinkedList<T>&op1,const LinkedList<T>&op2)
{
    LinkedList<T>::Node *Node1 {op1._first};
    LinkedList<T>::Node *Node2 {op2._first};

    while (Node1 && Node2 && (Node1->value == Node2->value))
    {
        Node1 = Node1->next;
        Node2 = Node2->next;
    }

    return (Node1 == nullptr) && (Node2 == nullptr);

}

template<typename T>
std::ostream& operator<<(std::ostream& os,const LinkedList<T> &list)
{
    LinkedList<T>::Node *currentNode {list._first};
    while (currentNode)
    {
        os << currentNode->value;
        currentNode = currentNode->next;
    }
 return os;
}


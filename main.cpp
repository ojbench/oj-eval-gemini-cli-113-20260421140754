#include <iostream>
#include "src.hpp"

using namespace std;

int main() {
    LinkedList<int> * list = new LinkedList<int>;
    LinkedList<int> * stack = new Stack<int>;
    LinkedList<int> * queue = new Queue<int>;
    
    cout << "LinkedList" << endl;
    list->pushFront(1);
    list->pushBack(2);
    list->pushBack(3);
    list->pushFront(4);
    list->print();
    list->popFront();
    list->popBack();
    list->print();
    cout << list->size() << endl;
    
    cout << stack->name() << endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    cout << stack->peak() << endl;
    stack->pop();
    cout << stack->pop() << endl;
    cout << stack->peak() << endl;
    
    cout << queue->name() << endl;
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    cout << queue->peak() << endl;
    queue->pop();
    cout << queue->pop() << endl;
    cout << queue->peak() << endl;
    
    cout << "Testing Copy Constructor" << endl;
    LinkedList<int> list2(*list);
    list2.print();
    list->pushBack(10);
    list->print();
    list2.print();

    cout << "Testing Empty List" << endl;
    LinkedList<int> emptyList;
    cout << "Size: " << emptyList.size() << endl;
    emptyList.popFront();
    emptyList.popBack();
    emptyList.print();

    delete list;
    delete stack;
    delete queue;

    return 0;
}
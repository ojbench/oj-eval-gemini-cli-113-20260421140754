#ifndef SRC_HPP
#define SRC_HPP

#include <cstdio>
#include <iostream>

template <typename T>
class LinkedList {
protected:
    struct Node {
        T data;
        Node *prev, *next;
        Node(const T& d, Node* p = nullptr, Node* n = nullptr) : data(d), prev(p), next(n) {}
    };
    Node *head, *tail;
    int _size;

public:
    LinkedList() : head(nullptr), tail(nullptr), _size(0) {}
    
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), _size(0) {
        Node* curr = other.head;
        while (curr) {
            pushBack(curr->data);
            curr = curr->next;
        }
    }

    virtual ~LinkedList() {
        clear();
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        _size = 0;
    }

    void pushFront(T val) {
        Node* newNode = new Node(val, nullptr, head);
        if (head) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        _size++;
    }

    void pushBack(T val) {
        Node* newNode = new Node(val, tail, nullptr);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        _size++;
    }

    T popFront() {
        if (!head) return T();
        Node* temp = head;
        T val = temp->data;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        _size--;
        return val;
    }

    T popBack() {
        if (!tail) return T();
        Node* temp = tail;
        T val = temp->data;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        _size--;
        return val;
    }

    int size() const {
        return _size;
    }

    void print() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    virtual const char* name() { return "LinkedList"; }
    virtual T peak() { return T(); }
    virtual T pop() { return T(); }
    virtual void push(T val) {}
};

template <typename T>
class Stack : public LinkedList<T> {
public:
    const char* name() override { return "Stack"; }
    T peak() override {
        return this->head->data;
    }
    T pop() override {
        return this->popFront();
    }
    void push(T val) override {
        this->pushFront(val);
    }
};

template <typename T>
class Queue : public LinkedList<T> {
public:
    const char* name() override { return "Queue"; }
    T peak() override {
        return this->head->data;
    }
    T pop() override {
        return this->popFront();
    }
    void push(T val) override {
        this->pushBack(val);
    }
};

#endif

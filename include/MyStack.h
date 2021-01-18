// Copyright 2021 Kartseva Mariya
#pragma once
#define MY_STACK_H
#ifdef MY_STACK_H
#include <iostream>
template <class T>
class MyStack {
 public:
    explicit MyStack(int size) {
        this->head = 0;
        this->size = size;
        this->stack = new T[size];
    }
    MyStack(const MyStack& Stack) {
        this->head = Stack.head;
        this->size = Stack.size;
        this->stack = new T[Stack.size];

        for (int i = 0; i < this->size; i++) {
            this->stack[i] = Stack.stack[i];
        }
    }
    ~MyStack() {
        delete[] stack;
    }

    T get() const {
        if (!isEmpty()) {
            return this->stack[this->head - 1];
        }
        std::cout << "Stack is empty!\n";
        return -1;
    }

    T pop() {
        if (!isEmpty()) {
            this->head--;
            T value = this->stack[this->head];
            return value;
        }
        std::cout << "Stack is empty!\n";
        return -1;
    }
    void push(T new_elem) {
        if (!isFull()) {
            this->stack[this->head] = new_elem;
            this->head++;
        } else {
            std::cout << "Stack is empty!\n";
        }
    }
    bool isFull() const {
        return (head == size);
    }
    bool isEmpty() const {
        return (head == 0);
    }

 private:
    int head{};
    int size{};
    T* stack;
};
#endif  // MY_STACK_H

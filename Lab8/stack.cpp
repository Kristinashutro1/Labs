#include "stack.h"
#include <algorithm>

Stack::Stack() : memo(10), topIndex(0) {      //память под 10 элементов
    data = new int[memo];
}


Stack::Stack(const Stack& other)  : memo(other.memo), topIndex(other.topIndex) {
    data = new int[memo];
    std::copy(other.data, other.data + topIndex, data);
}



Stack::~Stack() {
    delete[] data;
}


void Stack::resize(int newMemo) {
    int* newData = new int[newMemo];
    std::copy(data, data + topIndex, newData);
    delete[] data;
    data = newData;
    memo = newMemo;
}


void Stack::push(const int& value) {
    if (topIndex >= memo) {
        resize(memo * 2);
    }
    data[topIndex++] = value;
}


int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return data[--topIndex];
}

bool Stack::isEmpty() const {
    return topIndex == 0;
}

int Stack::size() const {
    return topIndex;
}

void Stack::clear() {
    topIndex = 0;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        memo = other.memo;
        topIndex = other.topIndex;
        data = new int[memo];
        std::copy(other.data, other.data + topIndex, data);
    }
    return *this;
}

Stack&::operator<<(Stack& stack, int value) {
    stack.push(value);
    return stack;
}


Stack& ::operator>>(Stack& stack, int& value) {
    value = stack.pop();
    return stack;
}


bool Stack::operator<(const Stack& other) const {
    return size() < other.size();
}
bool Stack::operator==(const Stack& other) const {
    return size() == other.size();
}

 int Stack::operator[](int index) const {
    if (index >= topIndex) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

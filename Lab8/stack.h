#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>  

class Stack {
private:
    int* data;                //указатель на массив
    int memo;                 //вместимость массива 
    int topIndex;             //индекс верхнего элемента
    
   void resize(int newMemo);

public:
    Stack();                    //по умолчанию
    Stack(const Stack& other);  //копирования
                                //деструктор
    ~Stack();
    
    //методы
    void push(const int& value);   //добавление
    int pop();                     // удаление 
                                             
    bool isEmpty() const;            //проверка на пустоту
    int size() const;                 //возврат размера
    void clear();                     //удаление всех элементов
    
    
    Stack& operator=(const Stack& other); //
    
    friend Stack& operator << (Stack& stack, int value);    //добавление 
    friend Stack& operator >> (Stack& stack, int& value);    //из ятие
    
     bool operator<(const Stack& other) const; //сравнение
     bool operator==(const Stack& other) const; 
    
    
    int operator[](int index) const;       //просмотр элемента
};

#endif // STACK_H

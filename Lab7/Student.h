#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
public:
    Student() = delete;   //запрет вызова конструктора без параметров

    //конструктор с параметрами
    Student(const char* name, int course, const std::string& group, const std::string& gradebook);

    //конструктор копирования
    Student(const Student& other);

    //get меоды
    unsigned long getId() const;
    const char* getName() const;
    int getCourse() const;
    const std::string& getGroup() const;
    const std::string& getGradebook() const;

    //set методы
    void setName(const char* name);
    void setCourse(int course);
    void setGroup(const std::string& group);

    //метод для подсчёта среднего балла (виртуальный)
    virtual double average() const;

    //перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Student& s);

protected:
    void copyName(const char* src);
    void freeName();

private:
    //уникальный идентификатор
    const unsigned long id;

    //имя студента
    char* name;

    //курс
    int course;

    //группа
    std::string group;

    //номер зачётки
    const std::string gradebook;

    //создание различных id
    static unsigned long nextId();
    static unsigned long s_counter;
};

#endif // STUDENT_H

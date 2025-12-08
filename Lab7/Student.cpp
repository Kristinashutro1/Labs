#include "Student.h"
#include <cstring> 


unsigned long Student::s_counter = 0;
unsigned long Student::nextId() {
    return ++s_counter;
}

//конструктор с параметрами
Student::Student(const char* name, int course, const std::string& group, const std::string& gradebook)
    : id(nextId()), name(nullptr), course(course), group(group), gradebook(gradebook)
{
    copyName(name);
}

//конструктор копирования
Student::Student(const Student& other)
    : id(nextId()), name(nullptr), course(other.course), group(other.group), gradebook(other.gradebook)
{
    copyName(other.name);
}

//деструктор
Student::~Student() {
    freeName();
}

//гет методы
unsigned long Student::getId() const { return id; }
const char* Student::getName() const { return name; }
int Student::getCourse() const { return course; }
const std::string& Student::getGroup() const { return group; }
const std::string& Student::getGradebook() const { return gradebook; }

//сет методы
void Student::setName(const char* newName) { 
    freeName(); 
    copyName(newName); 
}
void Student::setCourse(int c) { course = c; }
void Student::setGroup(const std::string& g) { group = g; }

//редний балл, пока у студента нет оценок
double Student::average() const {
    return 0.0;
}

//п+ерегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Студент[ID=" << s.id
       << ", Имя=" << (s.name ? s.name : "(нет)")
       << ", Курс=" << s.course
       << ", Группа=" << s.group
       << ", Зачетка=" << s.gradebook
       << "]";
    return os;
}


void Student::copyName(const char* src) {
    if (!src) {
        name = nullptr;
        return;
    }
    size_t len = std::strlen(src);
    name = new char[len + 1];
    std::strcpy(name, src);
}

void Student::freeName() {
    delete[] name;
    name = nullptr;
}
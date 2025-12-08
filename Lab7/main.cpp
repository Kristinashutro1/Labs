#include <iostream>
#include <vector>
#include "Student.h"
#include "AfterFirstSession.h"
#include "AfterSecondSession.h"

int main() {
    //cоздаём студентов
    Student* sBase = new Student("Kristina1", 1, "4", "yuriet");
    AfterFirstSession* s1 = new AfterFirstSession("Kristina2", 1, "4", "fhjgkl", {8, 9, 7, 10});
    AfterSecondSession* s2 = new AfterSecondSession("Kristina3", 1, "4", "dbfhjg", {9, 9, 8, 7}, {10, 9, 8, 9, 7});

    //vассив указателей
    std::vector<Student*> arr { sBase, s1, s2 };

    //выводим студентов
    std::cout << *sBase << "\n";
    std::cout << *s1 << "\n";
    std::cout << *s2 << "\n\n";

    //средние баллы
    std::cout << "average of Kristina2: " << s1->average() << "\n";
    std::cout << "average of Kristina3: " << s2->average() << "\n";

    //щсвобождаем память
    for (auto* p : arr) delete p;

    return 0;
}
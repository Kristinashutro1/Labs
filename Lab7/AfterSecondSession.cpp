#include "AfterSecondSession.h"
#include <stdexcept>
#include <numeric>


AfterSecondSession::AfterSecondSession(const char* name, int course, const std::string& group, const std::string& gradebook,
                                       const std::array<int, 4>& firstGrades,
                                       const std::array<int, 5>& secondGrades)
    : AfterFirstSession(name, course, group, gradebook, firstGrades),
      secondSessionGrades(secondGrades)
{}


AfterSecondSession::AfterSecondSession(const AfterSecondSession& other)
    : AfterFirstSession(other), secondSessionGrades(other.secondSessionGrades)
{}

//плучение оценки второй сессии
int AfterSecondSession::getSecondGrade(size_t index) const {
    if (index >= secondSessionGrades.size()) throw std::out_of_range("error");
    return secondSessionGrades[index];
}


void AfterSecondSession::setSecondGrade(size_t index, int value) {
    if (index >= secondSessionGrades.size()) throw std::out_of_range("error");
    secondSessionGrades[index] = value;
}

//cредний балл (по 9 оценкам)
double AfterSecondSession::average() const {
    double sumFirst = 0.0;
    for (int g : firstSessionGrades) sumFirst += g;

    double sumSecond = 0.0;
    for (int g : secondSessionGrades) sumSecond += g;

    return (sumFirst + sumSecond) / 9.0;
}


std::ostream& operator<<(std::ostream& os, const AfterSecondSession& s) {
    os << static_cast<const AfterFirstSession&>(s) << " | Оценки второй сессии: [";
    for (size_t i = 0; i < s.secondSessionGrades.size(); ++i) {
        os << s.secondSessionGrades[i];
        if (i + 1 < s.secondSessionGrades.size()) os << ", ";
    }
    os << "]";
    return os;
}
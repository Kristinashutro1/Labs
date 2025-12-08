#include "AfterFirstSession.h"
#include <stdexcept>
#include <numeric>

AfterFirstSession::AfterFirstSession(const char* name, int course, const std::string& group, const std::string& gradebook,
                                     const std::array<int, 4>& grades)
    : Student(name, course, group, gradebook), firstSessionGrades(grades)
{}

AfterFirstSession::AfterFirstSession(const AfterFirstSession& other)
    : Student(other), firstSessionGrades(other.firstSessionGrades)
{}

int AfterFirstSession::getGrade(size_t index) const {
    if (index >= firstSessionGrades.size()) throw std::out_of_range("error");
    return firstSessionGrades[index];
}

void AfterFirstSession::setGrade(size_t index, int value) {
    if (index >= firstSessionGrades.size()) throw std::out_of_range("error");
    firstSessionGrades[index] = value;
}

double AfterFirstSession::average() const {
    double sum = std::accumulate(firstSessionGrades.begin(), firstSessionGrades.end(), 0);
    return sum / firstSessionGrades.size();
}

std::ostream& operator<<(std::ostream& os, const AfterFirstSession& s) {
    os << static_cast<const Student&>(s) << " | First session grades: [";
    for (size_t i = 0; i < s.firstSessionGrades.size(); ++i) {
        os << s.firstSessionGrades[i];
        if (i + 1 < s.firstSessionGrades.size()) os << ", ";
    }
    os << "]";
    return os;
}
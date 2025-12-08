#ifndef AFTER_FIRST_SESSION_H
#define AFTER_FIRST_SESSION_H

#include "Student.h"
#include <array>

//класс "Студент после первой сессии"
class AfterFirstSession : public Student {
public:
    AfterFirstSession() = delete;

    AfterFirstSession(const char* name, int course, const std::string& group, const std::string& gradebook,
                      const std::array<int, 4>& grades);

    AfterFirstSession(const AfterFirstSession& other);

    int getGrade(size_t index) const;
    void setGrade(size_t index, int value);

    double average() const override;

    friend std::ostream& operator<<(std::ostream& os, const AfterFirstSession& s);

protected:
    std::array<int, 4> firstSessionGrades; //оценки первой сессии
};

#endif // AFTER_FIRST_SESSION_H
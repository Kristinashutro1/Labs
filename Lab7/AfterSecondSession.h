#ifndef AFTER_SECOND_SESSION_H
#define AFTER_SECOND_SESSION_H

#include "AfterFirstSession.h"
#include <array>

//класс "Студент после второй сессии"
class AfterSecondSession : public AfterFirstSession {
public:
    AfterSecondSession() = delete;

    AfterSecondSession(const char* name, int course, const std::string& group, const std::string& gradebook,
                       const std::array<int, 4>& firstGrades,
                       const std::array<int, 5>& secondGrades);

    AfterSecondSession(const AfterSecondSession& other);

    int getSecondGrade(size_t index) const;
    void setSecondGrade(size_t index, int value);

    double average() const override;

    friend std::ostream& operator<<(std::ostream& os, const AfterSecondSession& s);

private:
    std::array<int, 5> secondSessionGrades; //оценки второй сессии
};

#endif // AFTER_SECOND_SESSION_H
#include "student.h"

void printStudent(student *p)
{
    cout << "学号: " << p->id << '\n';
    cout << "姓名: " << p->name << '\n';
    cout << "数学: " << p->math << '\n';
    cout << "英语: " << p->english << '\n';
    cout << "语文: " << p->chinese << '\n';
    cout << "总分: " << p->sum << '\n';
    cout << "排名: " << p->rank << '\n';
}
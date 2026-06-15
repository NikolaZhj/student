#include "student.h"

void f3() {
    string name;
    cout << "输入你要查找的学生姓名" << '\n';
    cin >> name;

    student *p = head;
    bool found = false;


    while (p) {

        if (p->name == name) {

                cout << "查找到学生信息；\n";
                printStudent(p);

                found = true;

        }

        p = p->r;
    }

    if (!found) {

        cout << "未查询到该学生信息，请检查输入信息是否正确\n";
    
    }
}
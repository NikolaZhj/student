/*按照姓名查找学生的成绩信息*/

#include "student.h"

void f3()
{
    string name;
    cout << "请输入要查找的学生姓名:\n";
    cin >> name;

    student *p = head;
    bool found = false;

    while (p)
    {
        if (p->name == name)
        {
            cout << "查找到学生信息:\n";
            cout << "学号: " << p->id << '\n';
            cout << "姓名: " << p->name << '\n';
            cout << "数学: " << p->math << '\n';
            cout << "英语: " << p->english << '\n';
            cout << "语文: " << p->chinese << '\n';
            cout << "总分: " << p->sum << '\n';
            cout << "排名: " << p->rank << '\n';
            found = true;
        }

        p = p->r;
    }

    if (!found)
    {
        cout << "没有找到该生信息，请检查输入是否存在问题\n";
    }
}
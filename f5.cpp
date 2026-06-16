/*按照排名查找学生成绩信息*/
#include "student.h"

void f5()
{
    int targetRank;

    cout << "请输入要查找的排名:\n";
    cin >> targetRank;

    if (targetRank <= 0)
    {
        cout << "格式错误 请输入正整数\n";
        return;
    }

    student *p = head;

    while (p)
    {
        if (p->rank == targetRank)
        {
            cout << "查找到学生信息:\n";
            cout << "学号: " << p->id << '\n';
            cout << "姓名: " << p->name << '\n';
            cout << "数学: " << p->math << '\n';
            cout << "英语: " << p->english << '\n';
            cout << "语文: " << p->chinese << '\n';
            cout << "总分: " << p->sum << '\n';
            cout << "排名: " << p->rank << '\n';
            return;
        }

        p = p->r;
    }

    cout << "没有找到该生信息，请检查输入是否存在问题\n";
}
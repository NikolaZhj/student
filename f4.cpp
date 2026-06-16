/*按照学号查询*/
#include "student.h"

void f4()
{
    string id;
    cout << "请输入要查找的学生学号:\n";
    cin >> id;

    bool ok = true;

    if (id.length() != 9)
    {
        ok = false;
    }

    for (int i = 0; i < id.length(); i++)
    {
        if (id[i] < '0' || id[i] > '9')
        {
            ok = false;
            break;
        }
    }

    if (!ok)
    {
        cout << "学号格式错误，请输入9位数字\n";
        return;
    }

    student *p = head;

    while (p)
    {
        if (p->id == id)
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
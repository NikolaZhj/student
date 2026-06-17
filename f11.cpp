#include "student.h"
void f11()
{
    cout << "当前学生人数：\n";
    if (!rear)
    {
        cout << 0 << '\n';
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    else
    {
        cout << rear->rank << '\n';
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
}

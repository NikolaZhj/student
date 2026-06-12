#include "student.h"
void f11()
{
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

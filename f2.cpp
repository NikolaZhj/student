#include "student.h"

void f2() {
    student *p = head;
    if (!p) {
        cout << "当前没有学生数据！\n";
        system("pause");
        return;
    }
    cout << "输出：\n";
    while (p) {
        cout << p->id << ' ' << p->name << " " << p->rank << "\n";
        p = p->r;
    }
    cout << "\n按任意键继续...\n";
    system("pause");
}

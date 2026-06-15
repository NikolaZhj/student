#include "student.h"

void f4 () {

    string id;
    cout << "请输入要查找的学生学号:\n";
    cin >> id;

    bool ok = true;

    if (id.length() != 9) {
        ok = false;
    }

    for (int i = 0; i < id.length(); i++) {

        if (id[i] < '0' || id[i] > '9') {
            
            ok = false;
            break;

        }
    }

    if (!ok) {

        cout << "学号格式错误，学号应为9位数字\n";
        return;

    }

    student *p = head;

    while (p) {

        if (p->id == id) {

            cout << "查找到学生信息:\n";
            printStudent(p);
            return;

        }

        p = p->r;

    }

    cout << "没有找到该学号的学生,请检查输入是否存在问题\n";
}
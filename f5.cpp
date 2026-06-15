#include "student.h"

void f5 () {

    int rank;

    cout << "输入排名：\n";

    if (!(cin >> rank)) {

        cout << "格式错误 请输入正整数\n";
        
        // cin.clear();
        // cin.ignore(numeric_limits<streamsize>::max(),'\n');

        return;

    }

    if (rank < 0) {

        cout << "格式错误 请输入正整数\n";
        return;

    }

    student *p = head;

    while (p) {
    
        if (p->rank == rank) {

            cout << "查询到学生信息：\n";
            printStudent(p);
            return;

        }

        p = p->r;

    }

    cout << "没有找到该生信息，请检查输入是否存在问题\n";

}

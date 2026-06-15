#include "student.h"

void f1() {
    cout << "请输入学生信息:\n格式:学生id  学生姓名  数学  英语  语文\n";
    while (1) {
        string s;
        cin >> s;
        if (s == "q") {
            ofstream file("student.txt");

            student *p = head;
            int n = 0;
            
            if (rear) {
                n = rear->rank;
            }
            file << n << '\n';

            p = head;

            while (p) {
                file << right << setw(15) << p->id;
                file << right << setw(15) << p->name;
                file << right << setw(15) << p->math;
                file << right << setw(15) << p->english;
                file << right << setw(15) << p->chinese;
                file << '\n';
                p = p->r;
            }
            file.close();
            return;
        }
        bool ok = true;

        if (s.length() != 9) {
            ok = false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] < '0' || s[i] > '9') {
            ok = false;
            break;
            }
        }

        if (!ok) {
            cout << "学号格式错误，请重新输入\n";
            
            continue;
        }

        student *p = new student;
        p->id = s;
        cin >> p->name >> p->math >> p->english >> p->chinese;

        p->sum = p->math + p->chinese + p->english;

        insertStudent(p);
    }
}

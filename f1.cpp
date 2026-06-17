#include "student.h"

void f1() {
    cout << "输入学生信息 (输入 'q' 结束): ";
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
        if (s.length() > 9 || s.length() < 9) {
            cout << "学号格式错误，请重新输入\n";
            continue;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                cout << "学号格式错误，请重新输入\n";
                continue;
            }
        }
        student *p = new student;
        p->id = s;
        cin >> p->name >> p->math >> p->english >> p->chinese;
        p->sum = p->math + p->chinese + p->english;
        student *q = head;
        if (!q) {
            p->l = NULL;
            p->r = NULL;
            head = p;
            rear = p;
            p->rank = 1;
        } else {
                    int d = 1;
        while (q && (q->sum > p->sum || (q->sum == p->sum && q->id < p->id)))
        {
            q = q->r;
            d++;
        }
        if (!q)
        {
            p->r = NULL;
            p->l = rear;
            if (rear) {
                rear->r = p;
            }
            if (!head) {
                head = p;
            }
            rear = p;
        } else {
            p->r = q;
            p->l = q->l;
            if (q->l) {
                q->l->r = p;
            } else {
                head = p;
            }
            q->l = p;
        }
        p->rank = d;
        student *t = p->r;
        while (t) {
            t->rank++;
            t = t->r;
        }
        }
    }
}
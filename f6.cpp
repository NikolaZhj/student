#include "student.h"

void f6() {
    cout << "请输入学生信息:\n格式:学生id  学生姓名  数学  英语  语文\n";
    string id, name;
    float math, english, chinese;
    cin >> id >> name >> math >> english >> chinese;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "输入无效，请确保学号和姓名为字符串，成绩为数字！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    student *p = new student;
    p->id = id;
    p->name = name;
    p->math = math;
    p->english = english;
    p->chinese = chinese;
    p->sum = math + english + chinese;
    student *q = head;
    int d = 1;
    while (q && (q->sum > p->sum || (q->sum == p->sum && q->id < p->id))) {
        q = q->r;
        d++;
    }
    if (!q) {
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
    cout << "已插入学生: " << p->id << " " << p->name << " (排名:" << p->rank << ")\n";
    cout << "\n按任意键继续...\n";
    system("pause");
}

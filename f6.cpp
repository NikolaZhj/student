#include "student.h"  
void f6() {
    cout << "请输入要插入的学生位置(排名): ";
    int pos;
    cin >> pos;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "输入无效，请输入一个整数！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    int maxRank = (rear ? rear->rank : 0);
    if (pos < 1 || pos > maxRank + 1) {
        cout << "位置不合法！当前共有 " << maxRank << " 名学生，位置应在 1~" << maxRank + 1 << " 之间。\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
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
    if (!head) {
        p->l = NULL;
        p->r = NULL;
        head = p;
        rear = p;
        p->rank = 1;
    } else if (pos == 1) {
        p->r = head;
        p->l = NULL;
        head->l = p;
        head = p;
        p->rank = 1;
        student *q = p->r;
        while (q) {
            q->rank++;
            q = q->r;
        }
    } else {
        student *q = head;
        int d = 1;
        while (q && d < pos) {
            q = q->r;
            d++;
        }
        if (!q) {
            p->r = NULL;
            p->l = rear;
            rear->r = p;
            rear = p;
        } else {
            p->r = q;
            p->l = q->l;
            q->l->r = p;
            q->l = p;
        }
        p->rank = pos;
        student *r = p->r;
        while (r) {
            r->rank++;
            r = r->r;
        }
    }
    cout << "已插入学生: " << p->id << " " << p->name << " (排名:" << p->rank << ")\n";
    cout << "\n按任意键继续...\n";
    system("pause");
}


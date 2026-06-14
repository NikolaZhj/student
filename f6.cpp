#include "student.h"  
void f6() {
  if (!head) {
        cout << "当前没有学生数据！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    cout << "请输入要删除的学生位置(排名): ";
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
    if (pos < 1 || pos > rear->rank) {
        cout << "位置不合法！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    student *p = head;
    while (p && p->rank != pos) {
        p = p->r;
    }
    if (!p) {
        cout << "未找到该位置的学生！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    cout << "已删除学生: " << p->id << " " << p->name << " (排名:" << p->rank << ")\n";
    if (p == head && p == rear) {
        head = NULL;
        rear = NULL;
    } else if (p == head) {
        head = head->r;
        head->l = NULL;
    } else if (p == rear) {
        rear = rear->l;
        rear->r = NULL;
    } else {
        p->l->r = p->r;
        p->r->l = p->l;
    }
    student *q = p->r;
    while (q) {
        q->rank--;
        q = q->r;
    }
    delete p;
    cout << "\n按任意键继续...\n";
    system("pause"); 
          }  

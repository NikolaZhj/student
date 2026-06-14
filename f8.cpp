#include "student.h"  
void f8() {if (!head) {
        cout << "当前没有学生数据！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    cout << "请输入要删除的学生学号: ";
    string id;
    cin >> id;
    student *p = head;
    student *target = NULL;
    while (p) {
        if (p->id == id) {
            target = p;
            break;
        }
        p = p->r;
    }
    if (!target) {
        cout << "未找到学号为 \"" << id << "\" 的学生！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    cout << "已删除学生: " << target->id << " " << target->name << " (排名:" << target->rank << ")\n";
    if (target == head && target == rear) {
        head = NULL;
        rear = NULL;
    } else if (target == head) {
        head = head->r;
        head->l = NULL;
    } else if (target == rear) {
        rear = rear->l;
        rear->r = NULL;
    } else {
        target->l->r = target->r;
        target->r->l = target->l;
    }
    student *q = target->r;
    while (q) {
        q->rank--;
        q = q->r;
    }
    delete target;
    cout << "\n按任意键继续...\n";
    system("pause"); }  

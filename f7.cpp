#include "student.h"  
void f7() {if (!head) {
        cout << "当前没有学生数据！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    cout << "请输入要删除的学生姓名: ";
    string name;
    cin >> name;
    student *p = head;
    student *target = NULL;
    int count = 0;
    while (p) {
        if (p->name == name) {
            target = p;
            count++;
        }
        p = p->r;
    }
    if (count == 0) {
        cout << "未找到姓名为 \"" << name << "\" 的学生！\n";
        cout << "\n按任意键继续...\n";
        system("pause");
        return;
    }
    if (count > 1) {
        cout << "找到 " << count << " 个同名学生，请输入学号确认要删除的学生: ";
        string id;
        cin >> id;
        p = head;
        target = NULL;
        while (p) {
            if (p->name == name && p->id == id) {
                target = p;
                break;
            }
            p = p->r;
        }
        if (!target) {
            cout << "未找到该学号对应的学生！\n";
            cout << "\n按任意键继续...\n";
            system("pause");
            return;
        }
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

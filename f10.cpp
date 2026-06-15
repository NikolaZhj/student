#include "student.h"
void f10() {
    if (!head) {
        cout << "当前没有学生数据！\n";
        system("pause");
        return;
    }
    cout << "请输入要修改成绩的学号：";
    string id;
    cin >> id;
    student *p = head;
    while (p && p->id != id) p = p->r;
    if (!p) {
        cout << "未找到学号 " << id << " 的学生！\n";
        system("pause");
        return;
    }
    cout << "学生：" << p->name << "（" << p->id << "）\n";
    cout << "当前成绩 —— 数学:" << p->math << "  英语:" << p->english
         << "  语文:" << p->chinese << "  总分:" << p->sum << "\n";
    cout << "修改选项：1.数学  2.英语  3.语文  4.全部  请选择：";
    int ch;
    cin >> ch;
    switch (ch) {
        case 1: cout << "新数学成绩："; cin >> p->math; break;
        case 2: cout << "新英语成绩："; cin >> p->english; break;
        case 3: cout << "新语文成绩："; cin >> p->chinese; break;
        case 4:
            cout << "新数学："; cin >> p->math;
            cout << "新英语："; cin >> p->english;
            cout << "新语文："; cin >> p->chinese;
            break;
        default:
            cout << "无效选择，取消修改。\n";
            system("pause");
            return;
    }
    p->sum = p->math + p->english + p->chinese;
    // 从链表中摘出该节点，重新按排名规则插回
    if (p->l) p->l->r = p->r; else head = p->r;
    if (p->r) p->r->l = p->l; else rear = p->l;
    p->l = p->r = NULL;
    student *q = head;
    if (!q) {
        head = rear = p;
    } else {
        while (q && q->sum > p->sum) q = q->r;
        while (q && q->id < p->id)   q = q->r;
        if (!q) {
            p->r = NULL; p->l = rear; rear->r = p; rear = p;
        } else if (!q->l) {
            p->r = q; p->l = NULL; q->l = p; head = p;
        } else {
            p->r = q; p->l = q->l; q->l->r = p; q->l = p;
        }
    }
    // 从头全量重新计算排名，避免节点向后移动时前段排名出错
    q = head;
    int r = 1;
    while (q) { q->rank = r++; q = q->r; }
    cout << "修改成功！新总分：" << p->sum << "，新排名：第" << p->rank << "名\n";
    // 将更新后的链表写回 student.txt
    ofstream file("student.txt");
    int n = rear ? rear->rank : 0;
    file << n << '\n';
    q = head;
    while (q) {
        file << right << setw(15) << q->id
             << right << setw(15) << q->name
             << right << setw(15) << q->math
             << right << setw(15) << q->english
             << right << setw(15) << q->chinese
             << '\n';
        q = q->r;
    }
    file.close();
    cout << "修改成功，已保存到文件。\n";
    cout << "\n按任意键继续...\n";
    system("pause");
}

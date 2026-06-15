#include "student.h"
void f9() {
    if (!head) {
        cout << "当前没有学生数据！\n";
        system("pause");
        return;
    }
    cout << "请输入要删除的位置（从1开始）：";
    int pos;
    cin >> pos;
    if (pos < 1) {
        cout << "位置无效！\n";
        system("pause");
        return;
    }
    student *p = head;
    for (int i = 1; i < pos && p; i++) p = p->r;
    if (!p) {
        cout << "位置 " << pos << " 超出范围！\n";
        system("pause");
        return;
    }
    cout << "已删除第" << pos << "位学生：" << p->id << " " << p->name
         << "  总分：" << p->sum << "\n";
    if (p->l) p->l->r = p->r; else head = p->r;
    if (p->r) p->r->l = p->l; else rear = p->l;
    delete p;
    // 重新计算所有节点排名
    student *q = head;
    int r = 1;
    while (q) { q->rank = r++; q = q->r; }
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
    cout << "删除成功，已保存到文件。\n";
    cout << "\n按任意键继续...\n";
    system("pause");
}

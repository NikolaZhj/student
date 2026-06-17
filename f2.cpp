#include "student.h"

// 计算字符串的显示宽度（中文=2，ASCII=1）
int displayWidth(const string& s) {
    int w = 0;
    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = s[i];
        if (c < 0x80) { w += 1; i += 1; }          // ASCII字符
        else         { w += 2; i += 3; }          // UTF-8中文字符(3字节)
    }
    return w;
}

// 按显示宽度右对齐输出字符串
void printCol(const string& s, int totalWidth) {
    int dw = displayWidth(s);
    int pad = totalWidth > dw ? totalWidth - dw : 0;
    cout << string(pad, ' ') << s;
}

void f2() {
    student *p = head;
    if (!p) {
        cout << "当前没有学生数据！\n";
        system("pause");
        return;
    }
    cout << "输出：\n";
    
    const int W = 12;
    
    // 表头行（使用printCol处理中文）
    printCol("学号", W); cout << ' ';
    printCol("姓名", W); cout << ' ';
    printCol("数学", W); cout << ' ';
    printCol("英语", W); cout << ' ';
    printCol("语文", W); cout << ' ';
    printCol("总分", W); cout << ' ';
    printCol("排名", W); cout << '\n';
    
    // 数据行
    while (p) {
        printCol(p->id, W);   cout << ' ';           // 学号
        printCol(p->name, W); cout << ' ';           // 姓名（可能含中文）
        cout << right << setw(W) << fixed << setprecision(1) << p->math    << ' ';  // 数学
        cout << right << setw(W) << fixed << setprecision(1) << p->english << ' ';  // 英语
        cout << right << setw(W) << fixed << setprecision(1) << p->chinese << ' ';  // 语文
        cout << right << setw(W) << fixed << setprecision(1) << p->sum     << ' ';  // 总分
        cout << right << setw(W) << p->rank << '\n';                                 // 排名
        p = p->r;
    }
    
    cout << "\n按任意键继续...\n";
    system("pause");
}

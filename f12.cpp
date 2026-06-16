#include "student.h"
// 各科成绩统计分析
void f12() {
    if (!head) {
        cout << "当前没有学生数据！\n";
        system("pause");
        return;
    }
    float msum=0, esum=0, csum=0;
    float mmax=-1,emax=-1,cmax=-1;
    float mmin=1e9,emin=1e9,cmin=1e9;
    int mfail=0,efail=0,cfail=0;
    int cnt=0;
    for (student *p=head; p; p=p->r) {
        cnt++;
        msum+=p->math;   esum+=p->english;  csum+=p->chinese;
        if(p->math>mmax)    mmax=p->math;
        if(p->english>emax) emax=p->english;
        if(p->chinese>cmax) cmax=p->chinese;
        if(p->math<mmin)    mmin=p->math;
        if(p->english<emin) emin=p->english;
        if(p->chinese<cmin) cmin=p->chinese;
        if(p->math<60)    mfail++;
        if(p->english<60) efail++;
        if(p->chinese<60) cfail++;
    }
    cout << "\n===== 成绩统计分析（共" << cnt << "人）=====\n";
    cout << left << setw(10) << ""
         << right << setw(8) << "数学"
         << setw(8) << "英语"
         << setw(8) << "语文" << "\n";
    cout << string(34, '-') << "\n";
    cout << left << setw(10) << "平均分"
         << right << fixed << setprecision(1)
         << setw(8) << msum/cnt << setw(8) << esum/cnt << setw(8) << csum/cnt << "\n";
    cout << left << setw(10) << "最高分"
         << right << setw(8) << mmax << setw(8) << emax << setw(8) << cmax << "\n";
    cout << left << setw(10) << "最低分"
         << right << setw(8) << mmin << setw(8) << emin << setw(8) << cmin << "\n";
    cout << left << setw(10) << "不及格人数"
         << right << setw(8) << mfail << setw(8) << efail << setw(8) << cfail << "\n";
    cout << left << setw(10) << "及格率"
         << right << setw(7) << fixed << setprecision(1)
         << (cnt-mfail)*100.0/cnt << "%"
         << setw(7) << (cnt-efail)*100.0/cnt << "%"
         << setw(7) << (cnt-cfail)*100.0/cnt << "%\n";
    cout << "\n按任意键继续...\n";
    system("pause");
}

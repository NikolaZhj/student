#ifndef STUDENT_H
#define STUDENT_H

#include<bits/stdc++.h>
using namespace std;

struct student{
    string name;
    string id;
    float math, english, chinese;
    float sum;
    int rank;
    student *l, *r;
};
extern student *head, *rear;
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();
void f8();
void f9();
void f10();
void f11();

#endif
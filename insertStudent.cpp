#include "student.h"

void insertStudent(student *p)
{
    p->l = NULL;
    p->r = NULL;

    student *q = head;

    while (q && (q->sum > p->sum || (q->sum == p->sum && q->id < p->id)))
    {
        q = q->r;
    }

    if (!q)
    {
        // 插到链表尾部
        p->l = rear;
        p->r = NULL;

        if (rear)
        {
            rear->r = p;
        }
        else
        {
            // 原链表为空
            head = p;
        }

        rear = p;
    }
    else
    {
        // 插到 q 前面
        p->r = q;
        p->l = q->l;

        if (q->l)
        {
            q->l->r = p;
        }
        else
        {
            // q 原来是头结点
            head = p;
        }

        q->l = p;
    }

    updateRank();
}
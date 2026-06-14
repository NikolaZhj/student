#include "student.h"

void updateRank()
{
    int k = 1;
    student *p = head;

    while (p)
    {
        p->rank = k;
        k++;
        p = p->r;
    }
}
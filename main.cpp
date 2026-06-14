#include "student.h"

student *head, *rear;

int main()
{
    head = NULL;
    rear = NULL;
    ifstream file("student.txt");
    if (!file.is_open())
    {
        cout << "打开失败\n";
        return 0;
    }
    int n;
    file >> n;
    for (int i = 0; i < n; i++)
    {
        student *p = new student;

        file >> p->id >> p->name >> p->math >> p->english >> p->chinese;

        p->sum = p->chinese + p->english + p->math;
        

        insertStudent(p);
    }
    file.close();
    while (1)
    {
        cout << "-------------------------------------------\n";
        cout << "| 0:退出系统                              |\n";
        cout << "| 1:逐个输入学生信息,按'q'退出            |\n";
        cout << "| 2:显示所有学生信息                      |\n";
        cout << "| 3:根据姓名查找学生                      |\n";
        cout << "| 4:根据学号查找学生                      |\n";
        cout << "| 5:按排名查找学生                        |\n";
        cout << "| 6:插入到表中指定位置                    |\n";
        cout << "| 7:按姓名删除学生                        |\n";
        cout << "| 8:按学号删除学生                        |\n";
        cout << "| 9:按位置删除学生                        |\n";
        cout << "| 10:按学号修改信息                       |\n";
        cout << "| 11:统计学生人数                         |\n";
        cout << "-------------------------------------------\n";
        cout << "请输入一个数字(0~11):\n";
        int x;
        cin >> x;
        switch (x)
        {
        case 0:
            return 0;
        case 1:
            f1();
            break;
        case 2:
            f2();
            break;
        case 3:
            f3();
            break;
        case 4:
            f4();
            break;
        case 5:
            f5();
            break;
        case 6:
            f6();
            break;
        case 7:
            f7();
            break;
        case 8:
            f8();
            break;
        case 9:
            f9();
            break;
        case 10:
            f10();
            break;
        case 11:
            f11();
            break;
        default:
            cout << "请输入正确的数字\n";
            break;
        }
    }
}

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private:
     int age, id, score1, score2, score3, score4;
     char name[25], temp;
     double average;
    public:
    void input() {
        int top = 0;
        while (scanf("%c", &temp) && temp != ',') name[top++] = temp;
        name[top] = '\0';
        scanf("%d,%d,%d,%d,%d,%d", &age, &id, &score1, &score2, &score3, &score4);
    }

    void calculate() {
        average = (score1 + score2 + score3 + score4) / 4.0;
    }

    void output() {
        printf("%s,%d,%d,", name, age, id);
        cout << average;
    }
};

int main() {
    Student student;        // 定义类的对象
    student.input();        // 输入数据
    student.calculate();    // 计算平均成绩
    student.output();       // 输出数据
}

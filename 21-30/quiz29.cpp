#include <iostream>
#include <string>
using namespace std;
template <class T1, class T2>
T1 Filter(T1 begin, T1 end, T1 dst, T2 check) {
    T1 ret = dst;
    for (T1 p = begin; p != end; ++p) {
        if (check(*p)) *(ret++) = *p;
    }
    return ret;
}
bool LargerThan2(int n)
{
    return n > 2;
}
bool LongerThan3(string s)
{
    return s.length() > 3;
}

string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
string as2[5];
int  a1[5] = { 1,2,3,4,5};
int a2[5];
int main() {
    string * p = Filter(as1,as1+5,as2,LongerThan3);
    for(int i = 0;i < p - as2; ++i)
        cout << as2[i];
    cout << endl;
    int * p2 = Filter(a1,a1+5,a2,LargerThan2);
    for(int i = 0;i < p2-a2; ++i)
        cout << a2[i] << ",";
    return 0;
}

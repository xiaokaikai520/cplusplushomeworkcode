#include <iostream>
#include <string>
using namespace std;
template <class T1, class T2>
void MyForeach(T1 begin, T1 end, T2 op) {
    for (T1 p = begin; p != end; ++p)
        op(*p);
}
void Print(string s)
{
    cout << s;
}
void Inc(int & n)
{
    ++ n;
}
string array[100];
int a[100];
int main() {
    int m,n;
    while(cin >> m >> n) {
        for(int i = 0;i < m; ++i)
            cin >> array[i];
        for(int j = 0; j < n; ++j)
            cin >> a[j];
        MyForeach(array,array+m,Print);
        cout << endl;
        MyForeach(a,a+n,Inc);
        for(int i = 0;i < n; ++i)
            cout << a[i] << ",";
        cout << endl;
    }
    return 0;
}

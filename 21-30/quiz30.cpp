#include <iostream>
using namespace std;
class MyCin
{
int flag;
public:
    MyCin() {
        flag = 1;
    }
    operator bool() {
        return flag;
    }
    MyCin & operator>>(int & x) {
        if (!flag) return *this;
        cin >> x;
        if (x == -1) flag = 0;
        return *this;
    }
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2)
        cout  << n1 << " " << n2 << endl;
    return 0;
}

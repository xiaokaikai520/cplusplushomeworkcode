#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
int m, n;
    int **p;
    public:
        Array2() {}
        Array2(int m, int n): m(m), n(n) {
            if (m && n) {
                p = new int * [m];
                for (int i = 0; i < m; ++i)
                    p[i] = new int[n];
            }
        }
        int * operator[](const int & i) {
            return p[i];
        }
        int & operator()(const int & i, const int & j) {
            return p[i][j];
        }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

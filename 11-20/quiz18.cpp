#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt {
int len, num[210];
public:
    CHugeInt() {}
    CHugeInt(const char * s) {
        len = strlen(s);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < len; ++i)
            num[i] = s[len - 1 - i] - '0';
    }
    CHugeInt(const int & x) {
        len = 0;
        memset(num, 0, sizeof(num));
        int tmp = x;
        while (tmp) {
            num[len++] = tmp % 10;
            tmp /= 10;
        }
    }
    CHugeInt operator+(const CHugeInt & rhs) const {
        CHugeInt ans;
        ans.len = len;
        if (rhs.len > ans.len) ans.len = rhs.len;
        memset(ans.num, 0, sizeof(ans.num));
        for (int i = 0; i < ans.len; ++i) {
            ans.num[i] += num[i] + rhs.num[i];
            if (ans.num[i] > 9) {
                ++ans.num[i + 1];
                ans.num[i] -= 10;
            }
        }
        if (ans.num[ans.len]) ++ans.len;
        return ans;
    }
    friend CHugeInt operator+(const CHugeInt & lhs, const int & rhs) {
        return lhs + CHugeInt(rhs);
    }
    friend CHugeInt operator+(const int & lhs, const CHugeInt & rhs) {
        return CHugeInt(lhs) + rhs;
    }
    CHugeInt operator++() {
        *this = *this + CHugeInt(1);
        return *this;
    }
    CHugeInt operator++(int k) {
        CHugeInt ans(*this);
        ++(*this);
        return ans;
    }
    CHugeInt operator+=(const int & x) {
        *this = *this + CHugeInt(x);
        return *this;
    }
    friend ostream & operator<<(ostream & out, const CHugeInt & c) {
        for (int i = c.len - 1; i >= 0; --i) {
            out << c.num[i];
        }
        return out;
    }
};
int  main()
{
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}

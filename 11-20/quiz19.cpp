#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s)
{   int i = 0;
    for(; s[i]; ++i);
    return i;
}
void strcpy(char * d,const char * s)
{
    int i = 0;
    for( i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;

}
int strcmp(const char * s1,const char * s2)
{
    for(int i = 0; s1[i] && s2[i] ; ++i) {
        if( s1[i] < s2[i] )
            return -1;
        else if( s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char * d,const char * s)
{
    int len = strlen(d);
    strcpy(d+len,s);
}
class MyString
{
char * p;
public:
    MyString() {
        p = NULL;
    }
    MyString(const char * s) {
        if (s) {
            p = new char[strlen(s + 1)];
            strcpy(p, s);
        }
        else p = NULL;
    }
    MyString(const MyString & ms) {
        if (ms.p) {
            p = new char[strlen(ms.p + 1)];
            strcpy(p, ms.p);
        }
        else p = NULL;
    }
    ~MyString() {
        if (p) delete [] p;
    }
    friend ostream & operator<<(ostream & out, const MyString & ms) {
        if (ms.p) out << ms.p;
        return out;
    }
    MyString & operator=(const MyString & ms) {
        if (p) delete [] p;
        if (ms.p) {
            p = new char[strlen(ms.p) + 1];
            strcpy(p, ms.p);
        } else p = NULL;
        return *this;
    }
    MyString operator+(const MyString & ms) {
        MyString ans;
        if (p || ms.p) {
            ans.p = new char[strlen(p) + strlen(ms.p) + 1];
            strcpy(ans.p, p);
            strcat(ans.p, ms.p);
        } else ans.p = NULL;
        return ans;
    }
    char & operator[](const int & k) {
        return p[k];
    }
    MyString & operator=(const char * s) {
        if (p) delete [] p;
        if (s) {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        } else p = NULL;
        return *this;
    }
    MyString operator+(const char * s) {
        return *this + MyString(s);
    }
    friend MyString operator+(const char * s, const MyString & ms) {
        return MyString(s) + ms;
    }
    MyString operator+=(const char * s) {
        *this = *this + s;
        return *this;
    }
    bool operator<(const MyString & ms) const {
        for (int i = 0; p[i]; ++i)
            if (p[i] != ms.p[i]) return p[i] < ms.p[i];
        return strlen(p) < strlen(ms.p);
    }
    bool operator>(const MyString & ms) const {
        return ms < *this;
    }
    bool operator==(const MyString & ms) const {
        return !(*this < ms) && !(*this > ms);
    }
    MyString operator()(const int & s, const int & l) {
        MyString ans;
        ans.p = new char[l + 1];
        for (int i = 0; i < l; ++i)
            ans.p[i] = p[s + i];
        ans.p[l] = '\0';
        return ans;
    }
};


int CompareString( const void * e1, const void * e2)
{
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )
    return -1;
    else if( *s1 == *s2)
    return 0;
    else if( *s1 > *s2 )
    return 1;
}
int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString),CompareString);
    for( int i = 0;i < 4;i ++ )
    cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}

#include <iostream>
#include <set>
#include <string>

using namespace std;

const int MAXN = 1e5 + 5;

multiset<int> ms;
int vis[MAXN];

int main() {
    int n;
    cin >> n;
    while (n--) {
        string cmd;
        cin >> cmd;
        int x;
        cin >> x;
        if (cmd == "add") {
            ms.insert(x);
            vis[x] = 1;
            cout << ms.count(x) << endl;
        }
        else if (cmd == "del") {
            cout << ms.count(x) << endl;
            while (ms.count(x)) ms.erase(ms.find(x));
        }
        else if (cmd == "ask") {
            cout << vis[x] << " " << ms.count(x) << endl;
        }
    }
    return 0;
}

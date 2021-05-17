#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<int, int> mp;

int main() {
    mp.insert(make_pair(1e9, 1));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int id, power;
        cin >> id >> power;
        map<int, int>::iterator it1, it2;
        it1 = mp.lower_bound(power);
        if (it1 != mp.begin()) --it1;
        it2 = mp.upper_bound(power);
        if (it2 == mp.end()) {
           cout << id << " " << it1 -> second << endl;
           continue;
        }
        int l = abs(power - (it1 -> first)), r = abs((it2 -> first) - power);
        if (l <= r) cout << id << " " << it1 -> second << endl;
        else cout << id << " " << it2 -> second << endl;
        mp.insert(make_pair(power, id));
    }
    return 0;
}

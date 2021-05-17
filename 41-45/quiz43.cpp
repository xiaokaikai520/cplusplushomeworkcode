#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

multimap<int, int> mp;

int main() {
    mp.insert(make_pair(1e9, 1));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int id, power;
        scanf("%d%d", &id, &power);
        multimap<int, int>::iterator it1, it2;
        it1 = mp.lower_bound(power);
        it2 = mp.upper_bound(power);
        if ((it1 -> first) == power) {
            int old_id = it1 -> second;
            ++it1;
            while (it1 != it2) {
                if ((it1 -> second) < old_id) old_id = it1 -> second;
                ++it1;
            }
            printf("%d %d\n", id, old_id);
            mp.insert(make_pair(power, id));
            continue;
        }
        if (it1 == mp.begin()) {
            int r = abs(power - (it2 -> first));
            int rr = it2 -> second;
            ++it2;
            while (it2 != mp.end() && abs(power - (it2 -> first)) == r) {
                if ((it2 -> second) < rr) rr = it2 -> second;
                ++it2;
            }
            printf("%d %d\n", id, rr);
            mp.insert(make_pair(power, id));
            continue;
        }
        if (it2 == mp.end()) {
            int l = abs(power - (it1 -> first));
            int ll = it1 -> second;
            if (it1 != mp.begin()) {
                --it1;
                while (abs(power - (it1 -> first)) == l) {
                    if ((it1 -> second) < ll) ll = it1 -> second;
                    if (it1 == mp.begin()) break;
                    --it1;
                }
            }
            printf("%d %d\n", id, ll);
            mp.insert(make_pair(power, id));
            continue;
        }
        --it1;
        int l = abs(power - (it1 -> first)), r = abs(power - (it2 -> first));
        int ll = it1 -> second, rr = it2 -> second;
        if (it1 != mp.begin()) {
            --it1;
            while (abs(power - (it1 -> first)) == l) {
                if ((it1 -> second) < ll) ll = it1 -> second;
                if (it1 == mp.begin()) break;
                --it1;
            }
        }
        ++it2;
        while (it2 != mp.end() && abs(power - (it2 -> first)) == r) {
            if ((it2 -> second) < rr) rr = it2 -> second;
            ++it2;
        }
        if (l == r) {
            if (ll < rr) printf("%d %d\n", id, ll);
            else printf("%d %d\n", id, rr);
        }
        else if (l < r) printf("%d %d\n", id, ll);
        else printf("%d %d\n", id, rr);
        mp.insert(make_pair(power, id));
    }
    return 0;
}

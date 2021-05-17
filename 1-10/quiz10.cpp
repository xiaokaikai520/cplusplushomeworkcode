#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string rname[10] = {"", "iceman", "lion", "wolf", "ninja", "dragon"};
const string bname[10] = {"", "lion", "dragon", "ninja", "iceman", "wolf"};
const string wapon[3] = {"sword", "bomb", "arrow"};

int rh[10], bh[10], rn[10], bn[10];

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int rm, bm, dragon, ninja, iceman, lion, wolf;
        cin >> rm >> dragon >> ninja >> iceman >> lion >> wolf;
        bm = rm;
        memset(rn, 0, sizeof(rn));
        memset(bn, 0, sizeof(bn));
        rh[1] = iceman, rh[2] = lion, rh[3] = wolf, rh[4] = ninja, rh[5] = dragon;
        bh[1] = lion, bh[2] = dragon, bh[3] = ninja, bh[4] = iceman, bh[5] = wolf;

        cout << "Case:" << i << endl;
        int flag1 = 0, flag2 = 0, rp = 1, bp = 1, rN = 0, bN = 0;
        for (int j = 0; ; ++j) {
            if (flag1 && flag2) break;
            if (!flag1) {
                if (rm < rh[1] && rm < rh[2] && rm < rh[3] && rm < rh[4] && rm < rh[5]) {
                    cout << setw(3) << setfill('0') << j;
                    cout << " red headquarter stops making warriors" << endl;
                    flag1 = 1;
                } else {
                    while (rm < rh[rp]) {
                        ++rp;
                        if (rp > 5) rp -= 5;
                    }
                    rm -= rh[rp];
                    cout << setw(3) << setfill('0') << j;
                    cout << " red " << rname[rp] << " " << ++rN << " born with strength " << rh[rp] << "," << ++rn[rp] << " " << rname[rp] << " in red headquarter" << endl;
                    if (rname[rp] == "dragon") {
                        cout << "It has a " << wapon[rN % 3] << ",and it's morale is " << fixed << setprecision(2) << 1.0 * rm / rh[rp] << endl;
                    }
                    else if (rname[rp] == "ninja") {
                        cout << "It has a " << wapon[rN % 3] << " and a " << wapon[(rN + 1) % 3] << endl;
                    }
                    else if (rname[rp] == "iceman") {
                        cout << "It has a " << wapon[rN % 3] << endl;
                    }
                    else if (rname[rp] == "lion") {
                        cout << "It's loyalty is " << rm << endl;
                    }
                    ++rp;
                    if (rp > 5) rp -= 5;
                }
            }
            if (!flag2) {
                if (bm < bh[1] && bm < bh[2] && bm < bh[3] && bm < bh[4] && bm < bh[5]) {
                    cout << setw(3) << setfill('0') << j;
                    cout << " blue headquarter stops making warriors" << endl;
                    flag2 = 1;
                } else {
                    while (bm < bh[bp]) {
                        ++bp;
                        if (bp > 5) bp -= 5;
                    }
                    bm -= bh[bp];
                    cout << setw(3) << setfill('0') << j;
                    cout << " blue " << bname[bp] << " " << ++bN << " born with strength " << bh[bp] << "," << ++bn[bp] << " " << bname[bp] << " in blue headquarter" << endl;
                    if (bname[bp] == "dragon") {
                        cout << "It has a " << wapon[bN % 3] << ",and it's morale is " << fixed << setprecision(2) << 1.0 * bm / bh[bp] << endl;
                    }
                    else if (bname[bp] == "ninja") {
                        cout << "It has a " << wapon[bN % 3] << " and a " << wapon[(bN + 1) % 3] << endl;
                    }
                    else if (bname[bp] == "iceman") {
                        cout << "It has a " << wapon[bN % 3] << endl;
                    }
                    else if (bname[bp] == "lion") {
                        cout << "It's loyalty is " << bm << endl;
                    }
                    ++bp;
                    if (bp > 5) bp -= 5;
                }
            }
        }

    }
    return 0;
}

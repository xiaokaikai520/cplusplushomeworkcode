#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class MyList {
public:
    vector<int> v;

    void add(int num) {
        v.push_back(num);
    }

    void merge(MyList & l) {
        for (vector<int>::iterator it = l.v.begin(); it != l.v.end(); ++it)
            v.push_back(*it);
        l.v.clear();
    }

    void unique() {
        sort(v.begin(), v.end());
        vector<int>::iterator e = std::unique(v.begin(), v.end());
        while (v.end() != e) v.pop_back();
    }

    void out() {
        sort(v.begin(), v.end());
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};

map<int, MyList> p;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "new") {
            int id;
            cin >> id;
            p.insert(make_pair(id, MyList()));
        }
        else if (op == "add") {
            int id, num;
            cin >> id >> num;
            p[id].add(num);
        }
        else if (op == "merge") {
            int id1, id2;
            cin >> id1 >> id2;
            if (id1 == id2) continue;
            p[id1].merge(p[id2]);
        }
        else if (op == "unique") {
            int id;
            cin >> id;
            p[id].unique();
        }
        else if (op == "out") {
            int id;
            cin >> id;
            p[id].out();
        }
    }
    return 0;
}

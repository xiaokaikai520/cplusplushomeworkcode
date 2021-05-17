#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// 红蓝方制造顺序
const int RED[5] = {2, 3, 4, 1, 0};
const int BLUE[5] = {3, 0, 1, 2, 4};

// 存放五种武士的数据
const string Name[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Health[5];
int Attack[5];

// 武器类
class Weapon {
    int number; // 表示武器编号
    int used; // 记录使用次数
public:
    // 构造函数
    Weapon() {}
    Weapon(int number) {
        this -> number = number;
        this -> used = 0;
    }

    // 增加使用次数
    void use() {
        if (number) ++used;
    }

    // 判断是否用完
    bool isDisappear() {
        return (number == 1 && used == 1) || (number == 2 && used == 2);
    }

    // 重载小于运算符用于比较
    bool operator < (const Weapon & rhs) const {
        if (number == rhs.number) return used < rhs.used;
        return number < rhs.number;
    }

    // 返回武器类型
    int type() {
        return number;
    }
};

// 武士类
class Warriors {
    int id, health; // 记录武士种类和生命值
    int loyalty; // lion 特有的忠诚度
    Weapon weapon[15]; // 保存持有的武器
    int cnt; // 记录持有武器数量
public:
    // 构造函数
    Warriors() {}
    Warriors(int id, int loyalty=-1) {
        this -> id = id;
        this -> health = Health[id];
        this -> cnt = 0;
        this -> loyalty = loyalty;
    }

    // 获取武器
    void getWeapon(Weapon w) {
        if (cnt >= 10) return;
        weapon[++cnt] = w;
    }

    // 被夺走武器
    void lostWeapon(Warriors & w) {
        if (!cnt) return;
        sort(weapon, weapon + cnt);
        int minNumber = weapon[0].type(), index = 0;
        while (weapon[index].type() == minNumber) {
            w.getWeapon(weapon[index++]);
            --cnt;
        }
        for (int i = 0; i < cnt; ++i)
            weapon[i] = weapon[index + i];
    }

    // 攻击
    void hit(Warriors & enemy) {
        sort(weapon, weapon + cnt);
        if (weapon[0].type() == 0) {
            enemy.health -= Attack[id] * 2 / 10;
            weapon[0].use();
            if (weapon[0].isDisappear()) {
                weapon[0] = weapon[cnt - 1];
                --cnt;
            }
        }
        else if (weapon[0].type() == 1) {
            int delta = Attack[id] * 4 / 10;
            enemy.health -= delta;
            health -= delta / 2;
            weapon[0].use();
            if (weapon[0].isDisappear()) {
                weapon[0] = weapon[cnt - 1];
                --cnt;
            }
        }
        else if (weapon[0].type() == 2) {
            enemy.health -= Attack[id] * 3 / 10;
            weapon[0].use();
            if (weapon[0].isDisappear()) {
                weapon[0] = weapon[cnt - 1];
                --cnt;
            }
        }
    }

    int getId() {
        return id;
    }

    int getLoyalty() {
        return loyalty;
    }
} Red[25], Blue[25];

// 司令部类
class Headquarters {
    int fund, cnt; // 生命元和已经制造的武士数量
    int warriors[5], next_warrior; // 该司令部制造武士的顺序及接下来应该制造的武士
public:
    // 构造函数
    Headquarters(int fund, const int * warriors) {
        this -> fund = fund;
        this -> cnt = 0;
        for (int i = 0; i < 5; ++i) (this -> warriors)[i] = warriors[i];
        this -> next_warrior = 1;
    }

    // 制造武士函数
    bool produce(Warriors & w) {
        // 判断是否还能继续制造武士
        int flag = 0;
        for (int i = 0; i < 5; ++i) {
            if (fund > Health[i]) {
                flag = 1;
                break;
            }
        }
        if (!flag) return false;

        while (fund < Health[warriors[next_warrior]]) {
            ++next_warrior;
            if (next_warrior > 4) next_warrior -= 5;
        }

        ++cnt;
        fund -= Health[warriors[next_warrior]];
        if (warriors[next_warrior] == 3) w = Warriors(warriors[next_warrior], fund);
        else w = Warriors(warriors[next_warrior]);
        if (w.getId() == 0) w.getWeapon(cnt % 3);
        else if (w.getId() == 1) w.getWeapon(cnt % 3), w.getWeapon((cnt + 1) % 3);
        else if (w.getId() == 2) w.getWeapon(cnt % 3);
        else if (w.getId() == 3) w.getWeapon(cnt % 3);
        // {"dragon", "ninja", "iceman", "lion", "wolf"};

        return true;
    }

    int getNumber() {
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case " << tt << ":" << endl;
        int M, N, K, T;
        cin >> M >> N >> K >> T;
        for (int i = 0; i < 5; ++i) cin >> Health[i];
        for (int i = 0; i < 5; ++i) cin >> Attack[i];
        Headquarters red(M, RED), blue(M, BLUE);
        int h = 0, m = 0;
        while (true) {
            if (h * 60 + m > T) break; // 判断是否超时
            red.produce(Red[0]);
            cout << setw(3) << h << ":" << setw(2) << " red "
            << Name[Red[0].getId()] << " " << red.getNumber() << " born" << endl;
            if (Red[0].getId() == 3)
                cout << "Its loyalty is " << Red[0].getLoyalty() << endl;
            blue.produce(Blue[N + 1]);
            cout << setw(3) << h << ":" << setw(2) << " blue "
            << Name[Blue[0].getId()] << " " << blue.getNumber() << " born" << endl;
            if (Blue[0].getId() == 3)
                cout << "Its loyalty is " << Blue[0].getLoyalty() << endl;
        }
    }
    return 0;
}

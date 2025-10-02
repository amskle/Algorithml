#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000

struct SqList {
    int xishu[MAX];
    int zhi[MAX];
    int length;
};

void init(SqList &arr) {
    arr.length = 0;
    fill(arr.xishu, arr.xishu + MAX, 0);
    fill(arr.zhi, arr.zhi + MAX, 0);
}

void add(SqList &arr, int coef, int exp) {
    // 检查是否已经存在相同指数
    for (int i = 0; i < arr.length; i++) {
        if (arr.zhi[i] == exp) {
            arr.xishu[i] += coef;
            return;
        }
    }
    // 否则新增
    arr.xishu[arr.length] = coef;
    arr.zhi[arr.length] = exp;
    arr.length++;
}

// 按指数降序排序
void sortList(SqList &arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        for (int j = i + 1; j < arr.length; j++) {
            if (arr.zhi[i] < arr.zhi[j]) {
                swap(arr.zhi[i], arr.zhi[j]);
                swap(arr.xishu[i], arr.xishu[j]);
            }
        }
    }
}

SqList Add(SqList &a, SqList &b) {
    SqList c;
    init(c);
    for (int i = 0; i < a.length; i++) add(c, a.xishu[i], a.zhi[i]);
    for (int i = 0; i < b.length; i++) add(c, b.xishu[i], b.zhi[i]);
    sortList(c);
    return c;
}

SqList Multiply(SqList &a, SqList &b) {
    SqList c;
    init(c);
    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < b.length; j++) {
            add(c, a.xishu[i] * b.xishu[j], a.zhi[i] + b.zhi[j]);
        }
    }
    sortList(c);
    return c;
}

void print(SqList &arr) {
    bool flag = false;
    for (int i = 0; i < arr.length; i++) {
        if (arr.xishu[i] != 0) {
            if (flag) cout << " ";
            cout << arr.xishu[i] << " " << arr.zhi[i];
            flag = true;
        }
    }
    if (!flag) cout << "0 0";
    cout << endl;
}

int main() {
    SqList a, b;
    init(a); init(b);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int coef, exp;
        cin >> coef >> exp;
        add(a, coef, exp);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int coef, exp;
        cin >> coef >> exp;
        add(b, coef, exp);
    }

    SqList prod = Multiply(a, b);
    SqList sum = Add(a, b);

    print(prod);
    print(sum);

    return 0;
}

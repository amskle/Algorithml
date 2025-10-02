#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000

struct SqList {
    int xishu;
    int zhi;
};
void add(vector<SqList> &arr, int coef, int exp) {
    if (coef != 0) {
        arr.push_back({coef, exp});
    }
}

bool cmp(SqList &arr, SqList &brr) {
    return arr.zhi > brr.zhi;
}

vector<SqList> Add(vector<SqList> &a, vector<SqList> &b) {
    vector<SqList> r;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].zhi > b[j].zhi) {
            r.push_back(a[i]);
            i++;
        } 
        else if (a[i].zhi < b[j].zhi) {
            r.push_back(b[j]);
            j++;
        } 
        else { // 指数相等
            int sum = a[i].xishu + b[j].xishu;
            if (sum != 0) {
                r.push_back({sum, a[i].zhi});
            }
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        r.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        r.push_back(b[j]);
        j++;
    }
    return r;
}

vector<SqList> chen(vector<SqList> &a, vector<SqList> &b) {
    vector<SqList> temp_r;
    for (auto &i : a) {
        for (auto &j : b) {
            if (i.xishu * j.xishu != 0) {
                temp_r.push_back({i.xishu * j.xishu, i.zhi + j.zhi});
            }
        }
    }
    sort(temp_r.begin(), temp_r.end(), cmp);
    if (temp_r.empty()) {
        return temp_r;
    }
    
    vector<SqList> r;
    int current_coef = temp_r[0].xishu;
    int current_exp = temp_r[0].zhi;
    
    for (size_t i = 1; i < temp_r.size(); ++i) {
        if (temp_r[i].zhi == current_exp) {
            current_coef += temp_r[i].xishu;
        } 
        else {
            if (current_coef != 0) {
                r.push_back({current_coef, current_exp});
            }
            current_coef = temp_r[i].xishu;
            current_exp = temp_r[i].zhi;
        }
    }
    if (current_coef != 0) {
        r.push_back({current_coef, current_exp});
    }
    return r;
}

void print(vector<SqList> &arr) {
    bool f = true;
    for (auto &t : arr) {
        if (t.xishu != 0) {
            if (!f) {
                cout << " ";
            }
            cout << t.xishu << " " << t.zhi;
            f = false;
        }
    }
    if (f) {
            cout << "0 0";
        }
    cout << endl;
}

int main() {
   
    int n, m;
    cin >> n;
    vector<SqList> arr;
    for (int i = 0; i < n; i++) {
        int coef, exp;
        cin >> coef >> exp;
        add(arr, coef, exp);
    }
    sort(arr.begin(), arr.end(), cmp);
    vector<SqList> brr;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int coef, exp;
        cin >> coef >> exp;
        add(brr, coef, exp);
    }
    sort(brr.begin(), brr.end(), cmp);
    vector<SqList> a = Add(arr, brr);
    print(a);
    return 0;
}

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
typedef struct {
    int *zhi;
    int *xishu;
    int length;
}SqList;
void init(SqList &arr) {
    arr.xishu = new int[MAX]();
    arr.zhi = new int[MAX]();
    arr.length = 0;
}
void add(SqList &arr, int value, int zhi) {
    if (arr.length >= MAX) {
        return;
    }
    arr.xishu[arr.length] = value;
    arr.zhi[arr.length] = zhi;
    arr.length++;

}
void sortList(SqList &arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        for (int j = i + 1; j < arr.length; j++) {
            // 如果后一项的指数大于前一项，则交换，实现降序
            if (arr.zhi[i] < arr.zhi[j]) { 
                swap(arr.zhi[i], arr.zhi[j]);
                swap(arr.xishu[i], arr.xishu[j]);
            }
        }
    }
}
SqList Add(SqList &arr, SqList &brr) {
    SqList crr;
    init(crr);
    int i = 0, j = 0;
    while (i < arr.length && j < brr.length) {
        if (arr.zhi[i] > brr.zhi[j]) {
            add(crr, arr.xishu[i], arr.zhi[i]);
            i++;
        }
        else if (arr.zhi[i] < brr.zhi[j]) {
            add(crr, brr.xishu[j], brr.zhi[j]);
            j++;
        }
        else {
            int sum = arr.xishu[i] + brr.xishu[j];
            if (sum != 0) {
                add(crr, sum, arr.zhi[i]);
            }
            i++;
            j++;
        }
    }
    while (i < arr.length) {
        if (arr.xishu[i] != 0) {
            add(crr, arr.xishu[i], arr.zhi[i++]);
        }
        
    }
    while (j < brr.length) {
        if (brr.xishu[j] != 0) {
            add(crr, brr.xishu[j], brr.zhi[j++]);
        }
    }
    return crr;
}
SqList chen(SqList &arr, SqList &brr) {
    SqList crr;
    init(crr);
    for (int i = 0; i < arr.length; i++) {
        for (int j = 0; j < brr.length; j++) {
            int c = arr.xishu[i] * brr.xishu[j];
            int s = arr.zhi[i] + brr.zhi[j];
            bool found = false;
            for (int k = 0; k < crr.length; k++) {
                if (crr.zhi[k] == s) {
                    crr.xishu[k] += c;
                    found = true;
                    break;
                }
            }
            if (!found && c != 0) {
                add(crr, c, s);
            }
        }
    }
    sortList(crr);
    return crr;
}
void print(SqList &arr) {
    bool hasOutput = false;
    for (int i = 0; i < arr.length; i++) {
        if (arr.xishu[i] != 0) {
            if (hasOutput) cout << " ";
            cout << arr.xishu[i] << " " << arr.zhi[i];
            hasOutput = true;
        }
    }
    if (!hasOutput) cout << "0 0";
    cout << endl;
}

void destroy(SqList &arr) {
    delete[] arr.zhi;
    delete[] arr.xishu;
    arr.length = 0;
}
int main() {
    SqList arr;
    init(arr);
    SqList brr;
    init(brr);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(arr, x, y);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        add(brr, x, y);
    }
    sortList(arr);
    sortList(brr);
    SqList x = Add(arr, brr);
    SqList y = chen(arr, brr);
    print(y);
    print(x);
    
}
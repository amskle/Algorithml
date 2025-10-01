#include<iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
typedef struct {
    string *data;
    int length;
}SqList;
void init(SqList &arr) {
    arr.data = new string[MAX];
    arr.length = 0;
}
void add(SqList &arr, string value) {
    arr.data[arr.length] = value;
    arr.length++;
    if (arr.length >= MAX) {
        return;
    }
}
// void insert(SqList &arr, int value) {
//     int i = 0;
//     while (i < arr.length && arr.data[i] < value) {
//         i++;
//     }
//     for (int j = arr.length; j > i; j--) {
//         arr.data[j] = arr.data[j - 1];
//     }
//     arr.data[i] = value;
//     arr.length++;
// }
// void delet(SqList &brr, SqList &arr, int x, int y) {
//     //创建一个顺序表来存储筛选的数据
//     // for (int i = 0; i < arr.length; i++) {
//     //     if (arr.data[i] < x || arr.data[i] > y) {
//     //         brr.data[brr.length++] = arr.data[i];
//     //     }
//     // }
//     //直接在原有的顺序表上筛选
//     // int i, j;
//     // for (i = 0, j = 0; i < arr.length; i++) {
//     //     int c = 0;
//     //     if (arr.data[i] < x || arr.data[i] > y) {
//     //         arr.data[j] = arr.data[i];
//     //         j++;
//     //     }
//     // }
//     // arr.length = j;
// }
// int getmax(SqList &arr) {
//     if (arr.length == 0) {
//         return 0;
//     }
//     //Kadane算法
//     int sum_t = arr.data[0];
//     int sum_m = arr.data[0];
//     for (int i = 1; i < arr.length; i++) {
//         sum_t = max(arr.data[i], sum_t + arr.data[i]);
//         sum_m = max(sum_m, sum_t);
//     }
//     return sum_m;
// }
// void move(SqList &brr, SqList &arr, int n) {
//     for (int i = 0; i < arr.length; i++) {
//         brr.data[(i + n) % arr.length] = arr.data[i];
//         brr.length++;
//     }
// }
void reS(string &a, int l, int r) {
    while (l < r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}
void reverse(SqList &arr) {
    for (int i = 0; i < arr.length; i++) {
        string &s = arr.data[i];
        int start = 0;
        for (int j = 0; j <= s.size(); j++) {
            if (j == s.size() || s[j] == ' ') {
                reS(s, start, j - 1);
                start = j + 1;
            }
        }
    }
}
void printSentence(string &s) {
    int start = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            for (int j = start; j < i; j++) {
                cout << s[j];
            }
            start = i + 1;
            if (i != s.size()) cout << " "; // 不是最后一个单词才加空格
        }
    }
    cout << endl;
}

void destroy(SqList &arr) {
    delete[] arr.data;
    arr.length = 0;
}
int main() {
    int n;
    cin >> n;
    // int m;
    // cin >> m;
    cin.ignore();
    SqList arr;
    init(arr);
    for (int i = 0; i < n; i++) {
        string x;
        getline(cin, x);
        add(arr, x);
    }
    reverse(arr);
    // SqList brr;
    // init(brr);
    // int x, y;
    // cin >> x >> y;
    // delet(brr, arr, x, y);
    // int m;
    // cin >> m;
    // insert(arr, m);
    // move(brr, arr, m);
    for (int i = 0; i < arr.length; i++) {
        printSentence(arr.data[i]);
}

    // cout << getmax(arr) << endl;
    destroy(arr);
}
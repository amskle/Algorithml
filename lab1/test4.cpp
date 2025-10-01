#include<iostream>
#include <algorithm>
using namespace std;
#define MAX 10000
typedef struct {
    int *data;
    int length;
}SqList;
void init(SqList &arr) {
    arr.data = new int[MAX];
    arr.length = 0;
}
void add(SqList &arr, int value) {
    arr.data[arr.length] = value;
    arr.length++;
    if (arr.length >= MAX) {
        return;
    }
}
void insert(SqList &arr, int value) {
    int i = 0;
    while (i < arr.length && arr.data[i] < value) {
        i++;
    }
    for (int j = arr.length; j > i; j--) {
        arr.data[j] = arr.data[j - 1];
    }
    arr.data[i] = value;
    arr.length++;
}
void delet(SqList &brr, SqList &arr, int x, int y) {
    //创建一个顺序表来存储筛选的数据
    // for (int i = 0; i < arr.length; i++) {
    //     if (arr.data[i] < x || arr.data[i] > y) {
    //         brr.data[brr.length++] = arr.data[i];
    //     }
    // }
    //直接在原有的顺序表上筛选
    int i, j;
    for (i = 0, j = 0; i < arr.length; i++) {
        int c = 0;
        if (arr.data[i] < x || arr.data[i] > y) {
            arr.data[j] = arr.data[i];
            j++;
        }
    }
    arr.length = j;
}
int getmax(SqList &arr) {
    if (arr.length == 0) {
        return 0;
    }
    //Kadane算法
    int sum_t = arr.data[0];
    int sum_m = arr.data[0];
    for (int i = 1; i < arr.length; i++) {
        sum_t = max(arr.data[i], sum_t + arr.data[i]);
        sum_m = max(sum_m, sum_t);
    }
    return sum_m;
}
void print(SqList &arr) {
    for (int i = 0; i < arr.length; i++) {
        if (i == 0) {
            cout << arr.data[i];
        }
        else {
            cout << " " << arr.data[i];
        }
        
    }
}
void destroy(SqList &arr) {
    delete[] arr.data;
    arr.length = 0;
}
int main() {
    int n;
    cin >> n;
    SqList arr;
    init(arr);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(arr, x);
    }

    // SqList brr;
    // init(brr);
    // int x, y;
    // cin >> x >> y;
    // delet(brr, arr, x, y);
    // int m;
    // cin >> m;
    // insert(arr, m);
    print(arr);
    cout << getmax(arr) << endl;
    destroy(arr);
}
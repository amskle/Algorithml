#include<iostream>
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
}
void insert(SqList &arr, int value) {
    int i = 0;
    while (arr.data[i] < value && i < arr.length) {
        i++;
    }
    for (int j = arr.length; j > i; j--) {
        arr.data[j] = arr.data[j - 1];
    }
    arr.data[i] = value;
    arr.length++;
}
void print(SqList &arr) {
    for (int i = 0; i < arr.length; i++) {
        cout << arr.data[i] << ",";
    }
}
void destroy(SqList &arr) {
    delete[] arr.data;
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
    int m;
    cin >> m;
    insert(arr, m);
    print(arr);
    destroy(arr);
}
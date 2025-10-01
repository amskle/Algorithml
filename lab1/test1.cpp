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
void print(SqList &arr) {
    for (int i = 0; i < arr.length; i++) {
        if (i == 0) {
            cout << arr.data[i] << ",";
        }
        else {
            cout << " " << arr.data[i];
        }
    }
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
    print(arr);
}
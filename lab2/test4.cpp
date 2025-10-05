#include<iostream>
using namespace std;
typedef struct Node{
    int id;
    struct Node *next;
}*SList;
void init(SList &arr) {
    arr = new Node;
    arr->next = arr;
}
SList add(int n) {
    SList arr;
    init(arr);
    SList r = arr;
    for (int i = 0; i < n; i++) {
        SList p = new Node;
        p->id = i + 1;
        p->next = arr;
        r->next = p;
        r = p;
    }
    return arr;
}
void iss(SList arr, int n, int m) {
    SList p = arr->next;
    SList prev = arr;
    while (n > 0) {
        for (int i = 1; i < m; i++) {
            prev = p;
            p = p->next;
            if (p == arr) {
                p = p->next;
            }
        }
        cout << p->id;
        if (n > 1) {
            cout << " ";
        }
        prev->next = p->next;
        delete p;
        p = prev->next;
        if (p == arr) {
            p = p->next;
        }
        n--;
    }
    cout << endl;
}
void print(Node* head, int n) {
    SList p = head->next;
    while (p != head) {
        cout << p->id;
        if (p->next != head) {
            cout << " ";
        }
        p = p->next;
    }
}
void destroy(SList &arr) {
    SList p = arr;
    while (p != nullptr) {
        SList t = p;
        p = p->next;
        delete t;
    }
}
int main() {
    int n, p;
    cin >> n >> p;
    SList arr;
    arr = add(n);
    iss(arr, n, p);
    // print(arr);
}
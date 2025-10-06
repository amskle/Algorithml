#include<iostream>
using namespace std;
typedef struct test1
{
    int data;
    struct test1 *next;
}*SList, Node;
void init(SList &arr) {
    arr = new Node;
    arr->next = nullptr;
}
SList add(int n) {
    int x;
    SList L;
    init(L);
    SList r = L;
    for (int i = 0; i < n; i++) {
        cin >> x;
        SList p = new Node;
        p->data = x;
        p->next = nullptr;
        r->next = p;
        r = p;
    }
    return L;
}
void print(Node* head) {
    Node* p = head->next;
    while (p) {
        cout << p->data;
        if (p->next) cout << " ";
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
    int n;
    cin >> n;
    SList a = add(n);
    print(a);
}
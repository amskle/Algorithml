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
SList add() {
    int x;
    SList L;
    init(L);
    SList r = L;
    while (cin >> x && x != -1) {
        SList p = new Node;
        p->data = x;
        p->next = nullptr;
        r->next = p;
        r = p;
    }
    return L;
}
SList reverse(SList arr) {
    SList prev = nullptr;
    SList crr = arr;
    while (crr) {
        SList node = crr->next;
        crr->next = prev;
        prev = crr;
        crr = node;
    }
    return prev;
}
void print(Node* head) {
    Node* p = head;
    while (p->next) {
        cout << p->data;
        if (p->next->next) {
            cout << " ";
        }
        p = p->next;
    }
    cout << endl;
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
    for (int i = 0; i < n; i++) {
        SList a = add();
        a = reverse(a);
        print(a);
        destroy(a);
    }
}
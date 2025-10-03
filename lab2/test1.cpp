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
SList heb(SList &arr, SList &brr) {
    SList crr;
    init(crr);
    SList t = crr;
    SList p = arr->next;
    SList q = brr->next;
    while (p && q) {
        SList node;
        init(node);
        if (p->data <= q->data) {
            node->data = p->data;
            p = p->next;
        }
        else {
            node->data = q->data;
            q = q->next;
        }
        t->next = node;
        t = node;
    }
    while (p) {
        SList node = new Node{p->data, nullptr};
        t->next = node;
        t = node;
        p = p->next;
    }
    while (q) {
        SList node = new Node{q->data, nullptr};
        // SList node = new Node;
        // node->data = q->data;
        // node->next = nullptr;
        t->next = node;
        t = node;
        q = q->next;
    }
    return crr;
}
void print(Node* head) {
    if (!head->next) { cout << "NULL"; return; }
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
    SList a = add();
    SList b = add();
    SList finall = heb(a, b);
    print(finall);
}
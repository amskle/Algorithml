#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef struct test1
{
    string data;
    string data_next;
    int len;
    struct test1 *next;
}*SList, Node;
void init(SList &arr) {
    arr = new Node;
    arr->next = nullptr;
}
SList add(string m, int n) {
    map<string, SList> table;
    for (int i = 0; i < n; i++) {
        string data, data_next;
        int len;
        cin >> data >> len >> data_next;
        SList p = new Node;
        p->data = data;
        p->data_next = data_next;
        p->len = len;
        p->next = nullptr;
        table[data] = p;
    }
    SList L;
    init(L);
    SList r = L;
    string t = m;
    while (t != "-1")
    {
        if (table.count(t)) {
            SList p = table[t];
            r->next = p;
            r = p;
            t = p->data_next;
        }
        else {
            break;
        }
    }
    r->next = nullptr;
    return L;
    
}
void print(Node* head) {
    Node* p = head->next;
    while (p) {
        cout << p->data << " " << p->len << " " << p->data_next;
        p = p->next;
        cout << endl;
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
SList reverse(SList arr) {
    SList p = nullptr;
    SList c = arr;
    while (c) {
        SList node = c->next;
        c->next = p;
        p = c;
        c = node;
    }
    return p;
}

SList ww = nullptr;
SList tail = nullptr;
void inii() {
    ww = new Node;
    ww->next = nullptr;
    tail = ww;
}
SList dei(SList &arr) {
    map<int, bool> t;
    SList p = arr;
    SList L = arr->next;
    while (L) {
        if (t.count(abs(L->len))) {
            p->next = L->next;
            SList temp = L;
            L = L->next;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
        }
        else {
            t[abs(L->len)] = true;
            p = L;
            L = L->next;
        }
    }
    return arr;
}
void updateDataNext(SList head) {
    SList p = head->next;
    while (p && p->next) {
        p->data_next = p->next->data; // 下一个节点的地址
        p = p->next;
    }
    if (p) p->data_next = "-1"; // 最后一个节点
}

int main() {
    string temp;
    inii();
    int n;
    cin >> temp >> n;
    SList arr = add(temp, n);
    arr = dei(arr);
    updateDataNext(arr);
    print(arr);
    updateDataNext(ww);
    print(ww);
    destroy(arr);
}
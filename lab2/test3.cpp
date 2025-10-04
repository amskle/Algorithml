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
    if (!head->next) { cout << "NULL"; return; }
    Node* p = head->next;
    while (p) {
        cout << p->data << " " << p->len << " " << p->data_next;
        if (p->next) cout << " ";
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
SList reverse(SList head) {
    SList prev = nullptr;
    SList curr = head;
    while (curr) {
        SList nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// 折叠重排
SList foldList(SList head) {
    if (!head || !head->next || !head->next->next) return head; // 小于3节点直接返回

    // 1. 找中点
    SList slow = head->next, fast = head->next;
    SList prev = nullptr; // 记录中点前一个节点
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr; // 断开前半段

    // 2. 翻转后半段
    SList second = reverse(slow);

    // 3. 折叠两个链表
    SList dummy;
    init(dummy);
    SList p = dummy;
    SList first = head->next;
    while (first || second) {
        if (second) {
            p->next = second;
            p = p->next;
            second = second->next;
        }
        if (first) {
            p->next = first;
            p = p->next;
            first = first->next;
        }
    }
    p->next = nullptr;
    head->next = dummy->next;
    return head;
}
int main() {
    string temp;
    int n;
    cin >> temp >> n;
    SList arr = add(temp, n);
    arr = foldList(arr);
    print(arr);
    destroy(arr);
}
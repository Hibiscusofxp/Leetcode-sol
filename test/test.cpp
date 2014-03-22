#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


class LRUCache{
    struct ListNode {
        int key;
        int value;
        ListNode *pre, *next;
        ListNode (int keyin, int valuein) : key(keyin), value(valuein) {};
    };

    unordered_map <int, ListNode*> hashkv;
    int cap;
    ListNode *head, *tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = NULL;
        tail = NULL;
    }
    

    ListNode* removeNode (ListNode *node) {
        if (node == NULL)
            return NULL;
        if (node != head) {
            node->pre->next = node->next;
        } else {
            head = node->next;
        };
        if (node != tail) {
            node->next->pre = node->pre;
        } else {
            tail = node->pre;
        };
        node->next = NULL;
        node->pre = NULL;
        return node;
    }

    void insertFront (ListNode *node) {
        if (node == NULL)
            return;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->pre = node;
            head = node;
        }
    }

    void moveToFront (ListNode *node) {
        ListNode *tmp = removeNode(node);
        insertFront(tmp);
    }

    int get(int key) {
        if (hashkv.find(key) == hashkv.end())
            return -1;
        moveToFront(hashkv[key]);
        return (hashkv[key]->value);
    }
    
    void set(int key, int value) {
        if (hashkv.find(key) != hashkv.end()) {
            hashkv[key]->value = value;
            moveToFront(hashkv[key]);
        } else {
            if (hashkv.size() == cap) {
                hashkv.erase(tail->key);
                removeNode(tail);
            };
            ListNode *newHead = new ListNode(key, value);
            hashkv[key] = newHead;
            insertFront(newHead);
        }
        
    }
};

int main() {
    LRUCache sol(1);
    sol.set(2,1);
    cout << sol.get(2) << endl;
    return 0;
}

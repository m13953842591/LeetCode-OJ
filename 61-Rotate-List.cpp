#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    int n, i;
    ListNode * p;
    for(n = 0, p = head; p != NULL; p = p->next, n++);
    if(n == 0) return head;
    k = k % n;
    int v[n];
    
    for( i = k, p = head; p != NULL; p = p->next, i = (i + 1)%n)
    {
        v[i] = p->val;
    }
    for(i = 0, p = head; p != NULL; p = p->next, i++)
    {
        p->val = v[i];
    }
    return head;
}

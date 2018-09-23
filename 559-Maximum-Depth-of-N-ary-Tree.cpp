#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        queue<Node *> q;
        queue<int> l;
        q.push(root);
        l.push(1);
        Node * tmp;
        int level;
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            level = l.front();
            l.pop();
            if(!tmp->children.empty())
                for(auto ch : tmp->children)
                {
                    if(!ch) continue;
                    q.push(ch);
                    l.push(level + 1);
                }
        }
        return level;
    }
};
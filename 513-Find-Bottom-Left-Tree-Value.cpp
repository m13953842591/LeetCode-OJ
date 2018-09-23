#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        queue<int> l;
        q.push(root);
        l.push(1);
        TreeNode *leftMostNode, *tmp;
        int level = 0;
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            if(level < l.front())
                leftMostNode = tmp;
            level = l.front();
            l.pop();
            if(tmp->left != NULL)
            {
                q.push(tmp->left);
                l.push(level + 1);
            }
            if(tmp->right != NULL)
            {
                q.push(tmp->left);
                l.push(level + 1);
            }
        }
        return leftMostNode->val;
    }
};
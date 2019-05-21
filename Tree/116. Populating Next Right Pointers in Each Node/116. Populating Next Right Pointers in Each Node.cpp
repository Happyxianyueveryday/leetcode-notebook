/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/


class Solution {
public:
    Node* connect(Node* root) {
        if(root)
        __realconnect(root->left, root->right);

        return root;
    }

    void __realconnect(Node *root1, Node *root2)
    {
        if(root1&&root2)
        {
            // 1. 首先将两个树的根结点相连
            root1->next=root2;

            // 2. 然后分别将root1的左子树和root1的右子树，root1的右子树和root2的左子树，root2的左子树和root2的右子树进行递归地相连
            __realconnect(root1->left, root1->right);
            __realconnect(root1->right, root2->left);
            __realconnect(root2->left, root2->right);
        }
    }
};
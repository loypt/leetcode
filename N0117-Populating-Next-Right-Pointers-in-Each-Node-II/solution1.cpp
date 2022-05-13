/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *curParent = root, *baseChild, *curChild, *nextChild;
        while(curParent){
            while(curParent->next && !curParent->left && !curParent->right){
                curParent = curParent->next;
            }
            curChild = baseChild = curParent->left ? curParent->left : curParent->right;
            while(curChild){
                if(curParent->right && curChild != curParent->right){
                    nextChild = curParent->right;
                }else{
                    curParent = curParent->next;
                    while(curParent && !curParent->left && !curParent->right){
                        curParent = curParent->next;
                    }
                    nextChild = curParent ? curParent->left ? curParent->left : curParent->right : curParent;
                }
                curChild->next = nextChild;
                curChild = nextChild;
            }
            curParent = baseChild;
        }
        return root;
    }
};

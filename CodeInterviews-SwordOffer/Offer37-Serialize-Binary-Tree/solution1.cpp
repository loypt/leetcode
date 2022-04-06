/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void myserialize(TreeNode* root , string& str){
        if (root == nullptr){
            str += "#,";
        }else{
            str += to_string(root->val)+",";
            myserialize(root->left, str);
            myserialize(root->right, str);
        }
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        myserialize(root,res);
        return res;
    }

    TreeNode* mydeserialize(list<string>& datalist){
        if (datalist.front() == "#") {
            datalist.erase(datalist.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(datalist.front()));
        datalist.erase(datalist.begin());
        root->left = mydeserialize(datalist);
        root->right = mydeserialize(datalist);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string str;
        list<string> datalist;
        for (auto& ch:data) {
            if (ch == ','){
                datalist.push_back(str);
                str.clear();
            }else{
                str.push_back(ch);
            }
        }
        if (!str.empty()){
            datalist.push_back(str);
            str.clear();
        }
        return mydeserialize(datalist);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

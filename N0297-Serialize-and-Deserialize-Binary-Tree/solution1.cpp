//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <list>

using namespace std;
using namespace std::chrono;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


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
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nodeval = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* nodeA = new TreeNode(nodeval[0]);
    TreeNode* nodeB = new TreeNode(nodeval[1]);
    TreeNode* nodeC = new TreeNode(nodeval[2]);
    TreeNode* nodeD = new TreeNode(nodeval[3]);
    TreeNode* nodeE = new TreeNode(nodeval[4]);
    TreeNode* nodeF = new TreeNode(nodeval[5]);
    TreeNode* nodeG = new TreeNode(nodeval[6]);
    TreeNode* nodeH = new TreeNode(nodeval[9]);
    TreeNode* nodeI = new TreeNode(nodeval[10]);
    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->left = nodeF;
    nodeC->right = nodeG;
    nodeE->left = nodeH;
    nodeE->right = nodeI;
    TreeNode *head = nodeA;
    Codec ser, deser;
    string nodestr = ser.serialize(head);
    cout << "Node Serialize : " << nodestr << endl;
    deser.deserialize(nodestr);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


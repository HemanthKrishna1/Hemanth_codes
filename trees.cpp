#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void __printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        if(i==arr.size()-1) cout << arr[i];
        else cout << arr[i] << " ";
    }
}

void __printTree(Node* root){
    cout << "root is: " << root->data << endl;
    cout << "root->left->" << root->left->data << " root->right->" << root->right->data << endl;
}

void preOrderTraversal(Node* root, vector<int> &res){
    if(!root) return;
    res.push_back(root->data);
    preOrderTraversal(root->left, res);
    preOrderTraversal(root->right, res);
}

vector<int> preOrderTraversalIterative(Node* root){
    vector<int> res;
    if(!root) return res;
    stack<Node* > st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        res.push_back(root->data);
        if(root->left) st.push(root->left);
        if(root->right) st.push(root->right);
    }
    return res;
}

vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<Node* > qu;
    qu.push(root);
    while(!qu.empty()){
        int size = qu.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* node = qu.front();
            qu.pop();
            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
            level.push_back(node->data);
        }
        res.push_back(level);
    }
    return res;
}

int heightOfBinaryTree(Node* root){
    if(!root) return 0;
    return 1 + max(heightOfBinaryTree(root->left ), heightOfBinaryTree(root->right));
}

void postOrderTraversal(Node* root, vector<int> &res){
    if(!root) return;
    preOrderTraversal(root->left, res);
    preOrderTraversal(root->right, res);
    res.push_back(root->data);
}

void inOrderTraversal(Node* root, vector<int> &res){
    if(!root) return;
    preOrderTraversal(root->left, res);
    res.push_back(root->data);
    preOrderTraversal(root->right, res);
}

vector<vector<int>> zigZagTraversal(Node* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<Node* > qu;
    qu.push(root);
    bool leftToRight = true;

    while (!qu.empty()){
        int size = qu.size();
        vector<int> lvl(size);
        for(int i=0;i<size;i++){
            Node* node = qu.front();
            qu.pop();
            int index = leftToRight ? i : (size - i - 1);
            lvl[index] = node->data;

            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
        }
        res.push_back(lvl);
        leftToRight = !leftToRight;
    }
    return res;
}

void rightViewHelper(Node* root, int level, vector<int> &arr){
    if(!root) return;
    if(level == arr.size()) arr.push_back(root->data);
    rightViewHelper(root->right, level+1, arr);
    rightViewHelper(root->left, level+1, arr);
}

vector<int> rightView(Node* root){
    vector<int> arr;
    rightViewHelper(root, 0, arr);
    return arr;
}

void leftViewHelper(Node* root, int level, vector<int> &arr){
    if(!root) return;
    if(level == arr.size()) arr.push_back(root->data);
    leftViewHelper(root->left, level+1, arr);
    leftViewHelper(root->right, level+1, arr);
}

vector<int> leftView(Node* root){
    vector<int> arr;
    leftViewHelper(root, 0, arr);
    return arr;
}

vector<int> topView(Node* root){
    vector<int> ans;
    if(!root) return ans;

    map<int,int> mpp;
    queue<pair<Node*, int>> qu;

    qu.push({root, 0});
    while(!qu.empty()){
        auto it = qu.front();
        qu.pop();
        int line = it.second;
        Node* node = it.first;
        if(mpp.find(line) == mpp.end()) mpp[line] = node->data;

        if(node->left) qu.push({node->left, it.second-1});
        if(node->right) qu.push({node->right, it.second+1});
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(!root) return ans;

    map<int,int> mpp;
    queue<pair<Node* , int>> qu;
    qu.push({root, 0});

    while(!qu.empty()){
        auto it = qu.front();
        qu.pop();
        int line = it.second;
        Node* node = it.first;
        mpp[line] = node->data;
        if(node->left) qu.push({node->left, line-1});
        if(node->right) qu.push({node->right, line+1});
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

void printBT(const string& prefix, const Node* node, bool isLeft){
    if( node != nullptr ){
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node->data << std::endl;
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

int main(){
    int x;
    cin>>x;
    cout << "x is: " << x << endl;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->left = new Node(10);
    root->right->right = new Node(11);

//             1
//     2               3
// 7       8       10      11
    // int ans = heightOfBinaryTree(root);
    // cout << "height : " << ans << endl;
    // vector<vector<int>> ans = zigZagTraversal(root);
    // for(auto it: ans){
    //     for(auto zt : it){
    //         cout << zt << " ";
    //     }
    //     cout <<  endl;
    // }

    // vector<int> ans = bottomView(root);
    // for(auto it: ans){
    //     cout << it << " ";
    // }
    printBT("", root, false);
}
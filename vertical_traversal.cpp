// Method 1-The above solution uses preorder traversal and Hashmap to store nodes according to horizontal distances. 
// Since above approach uses preorder traversal, nodes in a vertical line may not be prined in same order as they appear in tree
void vertical_order(struct Node *root,int hd,map <int,vector<int>> &mp){
    if(root==NULL)
        return ;
    mp[hd].push_back(root->data);
    vertical_order(root->left,hd-1,mp);
    vertical_order(root->right,hd+1,mp);
}
vector<int> verticalOrder(Node *root){
    map <int,vector<int>> mp;
    int hd=0;
    vertical_order(root,hd,mp);
    vector <int> vec;
    for(auto it=mp.begin();it!=mp.end();it++){
        vector <int> v=it->second;
        for(int i=0;i<v.size();i++)
            vec.push_back(v[i]);
    }
    return vec;
}

// Method 2-Level Order Traversal

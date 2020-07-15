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
vector<int> verticalOrder(Node *root){
    vector <int> vec;
    if(root==NULL)
        return vec;
    map <int,vector<int>> mp;
    int hd=0;
    queue <pair<struct Node*,int>> q;
    q.push(make_pair(root,hd));
    while(!q.empty()){
        struct Node *temp=q.front().first;
        hd=q.front().second;
        q.pop();
        mp[hd].push_back(temp->data);
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        vector <int> v=it->second;
        for(int i=0;i<v.size();i++)
            vec.push_back(v[i]);
    }
    return vec;
}


// Method 1-O(n) using BFS
void level_order_traversal(struct Node *root,unordered_map<int,int> &mp){
    queue <struct Node*> q;
    q.push(root);
    mp[root->data]=-1;
    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        if(temp->left){
            mp[temp->left->data]=temp->data;
            q.push(root->left);
        }
        if(temp->right){
            mp[temp->right->data]=temp->data;
            q.push(root->right);
        }
    }
}
int kthAncestor(Node *root, int k, int x){
    if(root==NULL)
        return -1;
    unordered_map <int,int> ump;
    level_order_traversal(root,ump);
    while(x!=-1){
        x=ump[x];
        k--;
        if(k==0)
            break;
    }
    return x;
}
// Method 2-Using Backtracking
bool kth(struct Node *root,int x,vector <int> &vec){
     if (root==NULL) 
        return false; 
        
     vec.push_back(root->data);
     
     if(root->data==x)
        return true;
        
     if(kth(root->left,x,vec) || kth(root->right,x,vec))
        return true;
     vec.pop_back();
     return false;
}
int kthAncestor(Node *root, int k, int node){
    vector <int> vec;
    kth(root,node,vec);
    if(k>vec.size()-1 || k<=0)
        return -1;
    int idx=vec.size()-1-k;
    return vec[idx];
}

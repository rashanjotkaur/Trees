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

struct Node *LCA(struct Node *root,int a,int b){
    if(root==NULL)  
        return root;
    if(root->data==a || root->data==b)
        return root;
    struct Node *l=LCA(root->left,a,b);
    struct Node *r=LCA(root->right,a,b);
    if(l && r)
        return root;
    return l ? l : r;
}
void turns(struct Node *root,int x,int &max,int count,int left,int right){
    if(root==NULL)
        return ;
    if(root->data==x){
        if(max<count)
            max=count;
    }
    int temp=(right?count+1:count);
    turns(root->left,x,max,temp,1,0);
    temp=(left?count+1:count);
    turns(root->right,x,max,temp,0,1);
}
int dis(struct Node *lca,int x){
    int max=0,count=0,left=0,right=0;
    turns(lca,x,max,count,left,right);
    return max;
}
int NumberOFTurns(struct Node* root,int a,int b){
    if(root==NULL)
        return -1;
    if(a==b)
        return -1;
    struct Node *lca=LCA(root,a,b);
    if(a==lca->data)
        return dis(lca,b);
    if(b==lca->data)
        return dis(lca,a);
    return dis(lca,a)+dis(lca,b)+1;
}

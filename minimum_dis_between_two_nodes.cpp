struct Node *LCA(struct Node *root,int a,int b){
    if(root==NULL)
        return root;
    if(root->data==a || root->data==b)
        return root;
    struct Node *l=LCA(root->left,a,b);
    struct Node *r=LCA(root->right,a,b);
    if(l && r)
        return root;
    return l ? l : r ;
}
void find(Node *root, int a, int b, Node* &r1, Node* &r2){
    if(root==NULL)
        return ;
    if(root->data==a)
        r1 = root;
    if(root->data==b)
        r2 = root;
    find(root->left,a,b,r1,r2);
    find(root->right,a,b,r1,r2);
}
void level(Node *root,int a,int b,int lca,int &ha,int &hb,int &hlca,int d){
    if(root==NULL)
        return ;
    level(root->left,a,b,lca,ha,hb,hlca,d+1);
    level(root->right,a,b,lca,ha,hb,hlca,d+1);
    if(root->data==a)
        ha=d;
    if(root->data==b)
        hb=d;
    if(root->data==lca)
        hlca=d;
}
int findDist(Node* root, int a, int b){
    if(root==NULL)
        return 0;
    struct Node *A=NULL, *B=NULL, *lca=NULL;
    find(root,a,b,A,B);
    if(A==NULL || B==NULL)
        return 0;
    lca = LCA(root,a,b);
    int ha=0,hb=0,hlca=0,d=0;
    level(root,A->data,B->data,lca->data,ha,hb,hlca,d);
    return (ha+hb-2*hlca);
}

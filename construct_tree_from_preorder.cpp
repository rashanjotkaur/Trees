struct Node *newNode(int x){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct Node *construct(struct Node *root,int pre[],char preLN[],int &i,int n){
    if(i>=n)
        return root;
    root=newNode(pre[i]);
    if(preLN[i]=='N'){
        i++;
        root->left=construct(root->left,pre,preLN,i,n);
        i++;
        root->right=construct(root->right,pre,preLN,i,n);
        return root;
    }
    if(preLN[i]=='L')
        return root;
}
struct Node *constructTree(int n, int pre[], char preLN[]){
    struct Node *root=NULL;
    if(n==0)
        return root;
    int i=0;
    return construct(root,pre,preLN,i,n);
}

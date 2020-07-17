// Method 1
void insert(struct Node **root,int x,int parent[],unordered_map <int,struct Node*> &created){
    if(created[x]!=NULL)
        return ;
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    created[x]=temp;
    
    if(parent[x]==-1){
        *root=temp;
        return;
    }
    
    if(created[parent[x]]==NULL)
        insert(&(*root),parent[x],parent,created);
        
    struct Node *temp0=created[parent[x]];
    if(temp0->left==NULL)
        temp0->left=temp;
    else 
        temp0->right=temp;
    
}
Node *createTree(int parent[], int n){
    unordered_map <int,struct Node*> created;
    for(int i=0;i<n;i++)
        created[i]=NULL;
        
    struct Node *root=NULL;
    for(int i=0;i<n;i++)
        insert(&root,i,parent,created);
    return root;
}

// Method 2
Node *createTree(int parent[], int n){
    unordered_map <int,struct Node*> ump;
    for(int i=0;i<n;i++){
        struct Node *temp=new Node(i);
        ump[i]=temp;
    }
    int root;
    for(int i=0;i<n;i++){
        if(parent[i]==-1)
            root=i;
        if(parent[i]!=-1 && ump[parent[i]]->left==NULL)
            ump[parent[i]]->left=ump[i];
        else if(parent[i]!=-1 && ump[parent[i]]->right==NULL)
            ump[parent[i]]->right=ump[i];
    }
    return ump[root];
}

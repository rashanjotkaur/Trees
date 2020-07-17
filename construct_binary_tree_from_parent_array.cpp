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
    vector <struct Node*> vec;
    for(int i=0;i<n;i++){
        struct Node *temp=new Node(i);
        vec.push_back(temp);
    }
    int root;
    for(int i=0;i<n;i++){
        if(parent[i]==-1)
            root=i;
        if(parent[i]!=-1 && vec[parent[i]]->left==NULL)
            vec[parent[i]]->left=vec[i];
        else if(parent[i]!=-1 && vec[parent[i]]->right==NULL)
            vec[parent[i]]->right=vec[i];
    }
    return vec[root];
}

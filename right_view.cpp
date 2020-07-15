// Using Queue
void rightView(Node *root){
    if(root==NULL)  
        return ;
    queue <struct Node*> q;
    q.push(root);
    q.push(NULL);
    struct Node *temp;
    while(q.front()!=NULL){
        while(q.front()!=NULL){
            temp=q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            q.pop();
        }
        cout<<temp->data<<" ";
        q.push(NULL);
        q.pop();
    }
}

// Using Recursion
void rightView_helper(struct Node *root,int level,int &max_level){
    if(root==NULL)  
        return ;
    if(max_level<level){
        cout<<root->data<<" ";
        max_level=level;
    }
    rightView_helper(root->right,level+1,max_level);
    rightView_helper(root->left,level+1,max_level);
}
void rightView(Node *root){
    int max_level=0;
    rightView_helper(root,1,max_level);
}

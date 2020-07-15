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

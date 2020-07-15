// Iterative Method using queue
void leftView(Node *root){
    if(root==NULL) 
        return; 
    q.push(root); 
    q.push(NULL);       // Delimiter
  
    while (!q.empty()) { 
        struct Node* temp = q.front(); 
        if(temp){ 
            cout<<temp->data<<" "; 
            while(q.front()!=NULL){
                if (temp->left) 
                    q.push(temp->left); 
                if (temp->right) 
                    q.push(temp->right); 
                q.pop(); 
                temp = q.front(); 
            } 
            q.push(NULL); 
        } 
        q.pop(); 
    } 
}

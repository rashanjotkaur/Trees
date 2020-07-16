// Method1:
bool isIdentical(struct Node *r1,struct Node *r2){
    if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL || r2==NULL)
        return false;
    if(r1->data!=r2->data)
        return false;
    bool l=isIdentical(r1->left,r2->left);
    bool r=isIdentical(r1->right,r2->right);
    return l & r;
}
void mirror(struct Node **root){
    if(*root==NULL) return ;
    swap((*root)->left,(*root)->right);
    mirror(&((*root)->left));
    mirror(&((*root)->right));
}
int areMirror(Node* a, Node* b) {
    mirror(&a);
    return isIdentical(a,b);
}

// Method 2-Best Approach
int areMirror(Node* a, Node* b) {
    if(a==NULL && b==NULL)
        return 1;
    if(a==NULL || b==NULL)
        return 0;
    if(a->data!=b->data)
        return 0;
    int l=areMirror(a->left,b->right);
    int r=areMirror(a->right,b->left);
    return l & r;
}

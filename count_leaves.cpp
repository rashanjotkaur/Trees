int countLeaves(Node* root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int count=countLeaves(root->left)+countLeaves(root->right);
    return count;
}

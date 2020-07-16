bool hasPathSum(Node *root, int sum) {
    if((root==NULL && sum!=0) || (root && sum==0))
        return false;
    if(root==NULL && sum==0)
        return true;
    bool l=hasPathSum(root->left,sum-root->data);
    bool r=hasPathSum(root->right,sum-root->data);
    return l | r;
}

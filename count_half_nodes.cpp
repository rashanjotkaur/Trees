int count_half_nodes(Node* root){          //nodes with only one child
    if(root==NULL)
        return 0;
    if((root->left==NULL && root->right) || 
        (root->left && root->right==NULL))
        return 1;
    int count=count_half_nodes(root->left)+count_half_nodes(root->right);
    return count;
}

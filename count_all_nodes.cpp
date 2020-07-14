int countNodes(Node* root){
    if(root==NULL)
         return 0;
    if(root->left==NULL && root->right==NULL)
         return 1;
    int count=1+countNodes(root->left)+countNodes(root->right);
         return count;
}

int dia(Node *root,int &ans){
    if(root==NULL)
        return 0;
    int l=dia(root->left,ans);
    int r=dia(root->right,ans);
    ans=max(ans,1+l+r);
    return max(l,r)+1;
}
int diameter(Node* root) {
    if(root==NULL)
        return 0;
    int ans=INT_MIN;
    dia(root,ans);
    return ans;
}

bool isIsomorphic(Node *r1,Node *r2){
    if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL || r2==NULL)
        return false;
    if(r1->data!=r2->data)
        return false;
    bool mirror1=isIsomorphic(r1->left,r2->right);
    bool mirror2=isIsomorphic(r1->right,r2->left);
    
    bool identical1=isIsomorphic(r1->left,r2->left);
    bool identical2=isIsomorphic(r1->right,r2->right);

    return (mirror1 & mirror2) | (identical1 & identical2);
}

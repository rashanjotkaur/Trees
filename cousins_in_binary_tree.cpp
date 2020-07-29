// Method 1-Level Order Traversal
#include<bits/stdc++.h>
    typedef pair<struct TreeNode*,struct TreeNode*> pi;
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        pi p1,p2;
        p1.first=NULL;
        p1.second=NULL;
        p2.first=NULL;
        p2.second=NULL;
        queue <pi> q;
        q.push({root,NULL});
        q.push({NULL,NULL});
        int level=0;
        int l1,l2;
        while(!q.empty()){
            struct TreeNode *temp=q.front().first;
            if(temp->val==x){
                p1=q.front();
                l1=level;
            }
            else if(temp->val==y){
                p2=q.front();
                l2=level;
            }
            q.pop();
            if(temp->left)
                    q.push({temp->left,temp});
            if(temp->right)
                    q.push({temp->right,temp});
            if(q.front().first==NULL && q.front().second==NULL){
                q.pop();
                level++;
                if(!q.empty())
                    q.push({NULL,NULL});
            }
            
        }
        if(p1.first==NULL || p2.first==NULL)   
            return false;
        if(p1.second==NULL || p2.second==NULL)
            return false;
        if(p1.second->val!=p2.second->val && l1==l2)
            return true;
        return false;
    }
// Method 2-using traversal
TreeNode* x_par;
    TreeNode* y_par;
    int x_level, y_level;
    void check(TreeNode* root,int x,int y,int level,TreeNode* par){
        if (root==NULL) 
            return;
        if (x == root->val){
            x_par = par;
            x_level = level;
        }
        if (y == root->val){
            y_par = par;
            y_level = level;
        }
        check(root->left, x, y, level+1, root);
        check(root->right, x, y, level+1, root);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if (x == y || root==NULL) 
            return false;
        x_level = y_level = 0;
        x_par = y_par = NULL;
        check(root, x, y, 0, NULL);        
        if (x_par == y_par) 
            return false;
        if (x_level != y_level) 
            return false;
        return true;
    }

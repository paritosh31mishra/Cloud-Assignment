#include<bits/stdc++.h>
#include<string>
#include<ctype.h>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node *right;

    Node(int data){
        this->val=data;
        this->left=this->right=NULL;
    }
};

// FindMax Added by Tapesh Sharma
int findMax(Node* root)
{
    if (root == NULL)
        return INT_MIN;
    int res = root->val;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}
void inorder(Node* root, vector<int> &ans)
{
    // root is null
  if(root== NULL)
       return;

    // for left child
    inorder(root->left, ans);
    ans.push_back(root->val);
    // for right child
    inorder(root->right, ans);
}

int main(){
    Node *root=new Node(3);
    root->left=new Node(9);
    root->left->left=new Node(4);
    root->left->left->right=new Node(5);
    root->left->left->left=new Node(4);
    root->left->right=new Node(5);  
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    root->right->right->left=new Node(7);
    root->right->right->left->left=new Node(6);
    
    int result=findMax(root);
    cout<<"Max Value in Tree:"<< result<<endl;
    vector<int> ans;
     inorder(root, ans);
     cout<<"inorder traversal is:  ";
    //print all elements
       for(int i = 0;i<11;i++)
        {
           cout<<ans[i]<<" ";
        }
    cout<<endl;
        
            
}

#include "bst_header.h"
TreeNode* BST::insert(TreeNode *root,string n,int a,int tn,string tc)
{
    TreeNode* newnode = new TreeNode();
    newnode->name = n;
    newnode->age = a;
    newnode->ticket_number = tn;
    newnode->travel_class = tc;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
        cout<<"\nPassenger details inserted.\n\n";
    }
    else
    {
        TreeNode *parent = NULL;
        TreeNode *temp = root;
        while(temp != NULL)
        {
            parent = temp;
            if(newnode->ticket_number < temp->ticket_number)
                temp = temp->left;
            else if(newnode->ticket_number > temp->ticket_number)
                temp = temp->right;
            else
                temp = NULL;
        }
        if(parent->ticket_number < newnode->ticket_number)
        {
            parent->right = newnode;
            cout<<"\nPassenger details inserted.\n\n";
        }
        else if(parent->ticket_number > newnode->ticket_number)
        {
            parent->left = newnode;
            cout<<"\nPassenger details inserted.\n\n";
        }
        else
            cout<<"\nDuplicate details.\n\n";
    }
    return root;
}
TreeNode* BST::insert_recursion(TreeNode *root,string n,int a,int tn,string tc)
{
    TreeNode *temp = root;
    if(root==NULL)
    {
        TreeNode *newnode = new TreeNode();
        newnode->name = n;
        newnode->age = a;
        newnode->ticket_number = tn;
        newnode->travel_class = tc;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if(tn < temp->ticket_number)
        temp->left = insert_recursion(temp->left,n,a,tn,tc);
    else if(tn > temp->ticket_number)
        temp->right = insert_recursion(temp->right,n,a,tn,tc);
    return root;
}
TreeNode* BST::search(TreeNode *root,int tn)
{
    TreeNode *temp = root;
    while(temp != NULL)
    {
        if(temp->ticket_number == tn)
            return temp;
        if(tn < temp->ticket_number)
            temp = temp->left;
        else
            temp = temp->right;
    }
}
TreeNode* BST::search_recursion(TreeNode *root,int tn)
{
    TreeNode *temp = root;
    if(temp==NULL || temp->ticket_number == tn)
        return temp;
    else if(temp->ticket_number < tn)
        search_recursion(temp->right,tn);
    else if(temp->ticket_number > tn)
        search_recursion(temp->left,tn);
}
TreeNode* BST::findMin(TreeNode *root)
{
    TreeNode *temp = root;
    if(temp == NULL)
        return NULL;
    if(temp->left != NULL)
        findMin(temp->left);
    else
        return temp;
}
TreeNode* BST::findMax(TreeNode *root)
{
    TreeNode *temp = root;
    if(temp == NULL)
        return NULL;
    if(temp->right != NULL)
        findMax(temp->right);
    else
        return temp;
}
void BST::inorder(TreeNode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<"\nName : "<<root->name<<endl;
        cout<<"Age : "<<root->age<<endl;
        cout<<"Ticket Number : "<<root->ticket_number<<endl;
        cout<<"Travel Class : "<<root->travel_class<<endl;
        inorder(root->right);
    }
}
void BST::preorder(TreeNode *root)
{
    if(root != NULL)
    {
        cout<<"\nName : "<<root->name<<endl;
        cout<<"Age : "<<root->age<<endl;
        cout<<"Ticket Number : "<<root->ticket_number<<endl;
        cout<<"Travel Class : "<<root->travel_class<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void BST::postorder(TreeNode *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<"\nName : "<<root->name<<endl;
        cout<<"Age : "<<root->age<<endl;
        cout<<"Ticket Number : "<<root->ticket_number<<endl;
        cout<<"Travel Class : "<<root->travel_class<<endl;
    }
}
TreeNode* BST::delete_recursion(TreeNode *root,int tn)
{
    TreeNode *parent = root;
    TreeNode *min;
    if(parent==NULL)
        return parent;
    else if(tn < parent->ticket_number)
        parent->left = delete_recursion(parent->left,tn);
    else if(tn > parent->ticket_number)
        parent->right = delete_recursion(parent->right,tn);
    else
    {
        if(parent->left == NULL)
        {
            TreeNode* temp = parent->right;
            free(parent);
            return temp;
        }
        else if(parent->right == NULL)
        {
            TreeNode* temp = parent->left;
            free(parent);
            return temp;
        }
        else
        {
            min = findMin(parent->right);
            parent->name = min->name;
            parent->age = min->age;
            parent->ticket_number = min->ticket_number;
            parent->travel_class = min->travel_class;
            parent->right = delete_recursion(parent->right,min->ticket_number);
        }
    }
    return root;
}
#include <iostream>
#include <cstdlib>
using namespace std;
class TreeNode
{
    public:
        int age,ticket_number;
        string name,travel_class;
        TreeNode *left;
        TreeNode *right;
};
class BST
{
    public:
        TreeNode* insert(TreeNode *root,string n,int a,int tn,string tc); 
        TreeNode* insert_recursion(TreeNode *root,string n,int a,int tn,string tc);
        TreeNode* search(TreeNode *root,int tn);
        TreeNode* search_recursion(TreeNode *root,int tn);
        TreeNode* findMax(TreeNode *root);
        TreeNode* findMin(TreeNode *root);
        void inorder(TreeNode *root);
        void preorder(TreeNode *root); 
        void postorder(TreeNode *root);
        TreeNode* delete_recursion(TreeNode *root,int tn);
};
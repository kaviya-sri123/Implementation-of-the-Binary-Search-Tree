#include "bst_header.h"
int main()
{
    int ch;
    int a,tn;
    string n,tc;
    BST *b = new BST();
    TreeNode *root=NULL;
    do
    {
        cout<<"\t==========MENU==========\n";
    	cout<<"\t1.Insert\n";
    	cout<<"\t2.Insert Recursion\n";
    	cout<<"\t3.Search\n";
        cout<<"\t4.Search Recursion\n";
    	cout<<"\t5.First Passenger Details\n";
    	cout<<"\t6.Last Passenger Details\n";
    	cout<<"\t7.Inorder Traversal\n";
    	cout<<"\t8.Preorder Traversal\n";
    	cout<<"\t9.Postorder Traversal\n";
    	cout<<"\t10.Delete\n";
    	cout<<"\t11.Exit\n";
    	cout<<"\t========================\n";
    	cout<<"\nEnter your choice : ";
    	cin>>ch;
        switch(ch)
        {
            case 1:
            	cout<<"\nEnter the Passenger Name : ";
            	cin>>n;
            	cout<<"Enter the Passenger Age : ";
            	cin>>a;
            	cout<<"Enter the ticket number : ";
            	cin>>tn;
            	cout<<"Enter the travelling class : ";
            	cin>>tc;
            	root = b->insert(root,n,a,tn,tc);
            	break;
            case 2:
            	cout<<"\nEnter the Passenger Name : ";
            	cin>>n;
            	cout<<"Enter the Passenger Age : ";
            	cin>>a;
            	cout<<"Enter the ticket number : ";
            	cin>>tn;
            	cout<<"Enter the travelling class : ";
            	cin>>tc;
            	root = b->insert_recursion(root,n,a,tn,tc);
                cout<<"\nPassenger details inserted.\n\n";
            	break;
            case 3:
                int key;
                TreeNode *t;
                cout<<"\nEnter the Ticket Number to search : ";
                cin>>key;
                t = b->search(root,key);
                if(t == NULL)
                    cout<<"\nPassenger not found.\n\n";
                else
                    cout<<"\nPassenger found.\n\n";
                break;
            case 4:
                cout<<"\nEnter the Ticket Number to search : ";
                cin>>key;
                t = b->search_recursion(root,key);
                if(t == NULL)
                    cout<<"\nPassenger not found.\n\n";
                else
                    cout<<"\nPassenger found.\n\n";
                break;
            case 5:
                TreeNode *minimum;
                minimum = b->findMin(root);
                if(minimum==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n====FIRST PASSENGER DETAILS====";
                    cout<<"\nName : "<<minimum->name<<endl;
                    cout<<"Age : "<<minimum->age<<endl;
                    cout<<"Ticket Number : "<<minimum->ticket_number<<endl;
                    cout<<"Travel Class : "<<minimum->travel_class<<endl;
                    cout<<"===============================\n\n";
                }
                break;
            case 6:
                TreeNode *maximum;
                maximum = b->findMax(root);
                if(maximum==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=====LAST PASSENGER DETAILS====";
                    cout<<"\nName : "<<maximum->name<<endl;
                    cout<<"Age : "<<maximum->age<<endl;
                    cout<<"Ticket Number : "<<maximum->ticket_number<<endl;
                    cout<<"Travel Class : "<<maximum->travel_class<<endl;
                    cout<<"===============================\n\n";
                }
                break;
            case 7:
                if(root==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=======PASSENGER DETAILS=======";
                    b->inorder(root);
                    cout<<"===============================\n\n";
                }
                break;
            case 8:
                if(root==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=======PASSENGER DETAILS=======";
                    b->preorder(root);
                    cout<<"===============================\n\n";
                }
                break;
            case 9:
                if(root==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                {
                    cout<<"\n\n=======PASSENGER DETAILS=======";
                    b->postorder(root);
                    cout<<"===============================\n\n";
                }
                break;
            case 10:
                int num;
                cout<<"\nEnter the Ticket Number to be deleted : ";
                cin>>num;
                root = b->delete_recursion(root,num);
                cout<<"\nPassenger details deleted.\n\n";
                break;
            case 11:
                break;
            default:
                cout<<"\n\nEnter a valid choice.\n";
                break;
        }
    }while(ch != 11);
    return 0;
}
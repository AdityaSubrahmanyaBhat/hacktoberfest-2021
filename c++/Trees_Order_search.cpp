#include<iostream>

using namespace std;
class node
{
    public:
	    node *left;
	    int data;
	    node *right;

        node()
        {

        }
		node(int n)
		{ 
            data=n; 
            left= NULL;
            right=NULL;
        }

};
class tree:public node
{
	
public:
		node *root;
		void preorder(node *currentnode);
   		void inorder(node *currentnode); 
   		void postorder(node *currentnode);
		tree()
		{
         root=NULL; 
        }
		void create();
		void preorder();
		void inorder();
		void postorder();
		void insert(char c);
		void Delete(char c);
		int totalnodes();
		int leafnodes();
		void mirror(tree &);
		void copy(tree &);


};
void tree::create()
	{
		node *temp, *newnode;
		int c, choice;
		char ans;
		
		do
		{
		cout<<"Enter Elements to be attached: ";
		cin>>c;
		newnode= new node(c);
		
		if(root==NULL)
		root=newnode;
		
		else
		{
			temp=root;
			
			while(1)
			{
				cout<<"Left or Right (l/r) of "<<temp->data;
				cin>>ans;
				
				if(ans=='l')
				{	
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
				
					else
					temp=temp->left;

				}
				
				else
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						break;
					}
				
					else
					temp=temp->right;
				}
			}
		}
		cout<<"Do u want to insert more nodes(1/0)?: ";
		cin>>choice;
		
		}while(choice==1);
		}
void tree::preorder()
{
	preorder(root);
	
}
void tree::preorder(node *currentnode)
{
	if (currentnode!=NULL)
	{
		cout<<currentnode->data;
		cout<<"	";
		preorder(currentnode->left);
		preorder(currentnode->right);
	}
	
}
void tree::postorder()
{
	postorder(root);
	
}
void tree::postorder(node *currentnode)
{
	if (currentnode!=NULL)
	{
		postorder(currentnode->left);
		postorder(currentnode->right);
		cout<<currentnode->data;
		cout<<"	";
	}
	
}
void tree::inorder()
{
	inorder(root);
	
}
void tree::inorder(node *currentnode)
{
	if (currentnode!=NULL)
	{
		inorder(currentnode->left);
		cout<<currentnode->data;
		cout<<"	";
		inorder(currentnode->right);
		
	}
	
}
		
int main()
{
	tree k;
	int p=1,ch;
    while (p==1)
    {
        cout<<"\n Enter choice \n 1-create\n 2-preorder\n 3-Inorder\n 4-postorder\n ";
        
        cin>>ch;
        switch(ch)
        {
            case 1:
                k.create();
                break;
            case 2:
            	 k.preorder();
                break;
			case 3:
				k.inorder();
				break;
			case 4:
				k.postorder();
				break;
	
        }
		    cout<<"\n Press 1 to continue \n";
   			cin>>p;
	}
}


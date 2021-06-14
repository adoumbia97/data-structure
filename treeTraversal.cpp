#include<iostream>
using namespace std;

/*
  Declaration of the struct node (root)
  The type of the tree is binary search tree (left and right)
*/
struct node {
   int data;
   struct node *left;
   struct node *right;
};

//Creation of the object the root of the tree
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}


//Traverse the tree in order procedure
void inorder(struct node *root) {
   if (root != NULL) {
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
   }
}

//Traverse the tre in preorder
void preorder(struct node *root) {
   if (root != NULL) {
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}
/*
  Procedure of traversing the tree in postorder
  Parameter needed is the root of the node
*/
void postorder(struct node *root) {
   if (root != NULL) {
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
   }
}

/*
  Procedure of insertion node in the tree
  Parameter needed is the root and the value of the node to enter
*/

struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}



/*
  Function TreeOrder : Called from the main program
  Offer the possibility to buit the tree and choose the type of traversal the user wants
  Contains a sub menu which can manage the tree and the traversals:

*/

int TreeOrder() {
    writeTitle("Welcome to Tree traversal");
    struct node *root = NULL;                   //Creation of the tree with no value
    int n;                                       //Number of the elements the user want to built the tree 
    string choice;
    int target;
    cout <<"\t \t \t \t Enter the number of Element in the table\n";
    cin >>n;
    int arr[n];                                         //Declaration of the array with n given by the user
    
    do
    {
        writeChoice("1","Create the table");
        writeChoice("2","traversal through In order");
        writeChoice("3","traversal through Pre order ");
        writeChoice("4","traversal through Post order");
        writeChoice("5","Exit");
        cin >>choice;

        //Treatemen of the choice of the user
        if(choice=="1")                                                                       
        {
            cout <<"\t \t \t \t Enter the "<<n<<" value  of the table: \n";
            for (int i = 0; i < n; ++i)
            {
                int value;
                cin >> value;
                if(i==0){root=insertNode(root, value);}
                else {insertNode(root,value); }
            }

        }

        else if(choice=="2")
        {
          cout<<"In-Order traversal of the Binary Search Tree is: ";
          inorder(root);
        }
        else if(choice=="3")
        {
            cout<<"Pre-order traversal of the Binary Search Tree is: ";
            preorder(root);
        }
        else if(choice=="4")
        {
            cout<<"Post order traversal of the Binary Search Tree is: ";
            postorder(root);
        }

        /* code */
    } while (choice!="5");

   
   return 0;
}
#include<iostream>
using namespace std;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}

void inorder(struct node *root) {
   if (root != NULL) {
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
   }
}

void preorder(struct node *root) {
   if (root != NULL) {
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}

void postorder(struct node *root) {
   if (root != NULL) {
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
   }
}

struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}





int TreeOrder() {
      cout <<"\t \t \t \t ----------- --------------------\n" ;
      cout <<"\t \t \t \t "<< "Welcome to Tree traversal \n" ;
      cout <<"\t \t \t \t ----------- --------------------\n" ;
    struct node *root = NULL;
    int n;
    string choice;
    int target;
    cout <<"\t \t \t \t Enter the number of Element in the table\n";
    cin >>n;
    int arr[n];
    
    do
    {
        cout <<"\t \t \t \t \n 1 - Create the table \n";
        cout <<"\t \t \t \t \n 2 - traversal through In order \n";
        cout <<"\t \t \t \t \n 3 - traversal through Pre order \n";
        cout <<"\t \t \t \t \n 4 - traversal through Post order \n";
        

        cout <<"\t \t \t \t \n 5 - Exit \n";
        cin >>choice;

        if(choice=="1")   //Creation of the table in 
        {
            cout <<"\t \t \t \t Enter the "<<n<<" value  of the table: \n";
            for (int i = 0; i < n; ++i)
            {

                int value;
                cin >> value;
                if(i==0){root=insertNode(root, value);}
                else {insertNode(root,value); }
                               
                /* code */
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

   
   


   root = insertNode(root, 4);
   insertNode(root, 5);
   insertNode(root, 2);
   insertNode(root, 9);
   insertNode(root, 1);
   insertNode(root, 3);
  
   return 0;
}
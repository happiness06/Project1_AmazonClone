#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this-> left=NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){

    int val;
    cout<<"Enter the value : ";
    cin>>val;
    root = new node(val);
    
    if(val == -1){
        return NULL;
    }

    cout<<endl<<"Enter value for inserting in left node of "<<val<<endl;
    root->left = buildTree(root->left);
    cout<<endl<<"Enter value for inserting in right node of "<<val<<endl;
    root->right = buildTree(root->right);

    cout<<endl;
    return root;
    
}

void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    

    while(!q.empty()){
        node* tmp = q.front();
        
        q.pop();

        if(tmp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<tmp->data<<" ";
            if(tmp->left != NULL){
                q.push(tmp->left);
            }
            
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
        }
    }
}

void createLevelordertraversal(node* &root){
    queue<node*> q;
    int data;
    cout<<"Enter data for the root : ";
    cin>>data;
    root = new node(data);
    q.push(root);
    // q.push(NULL);

    while(!q.empty()){
        node* tmp = q.front();
        q.pop();

        int leftData;
        cout<<endl<<"Enter value for the left node for "<<tmp->data<<" : ";
        cin>>leftData;

        if(leftData != -1){
            tmp->left = new node(leftData);
            q.push(tmp->left);
        }

        int rightData;
        cout<<endl<<"Enter the value of the right node for "<<tmp->data<<" : ";
        cin>>rightData;

        if(rightData != -1){
            tmp->right = new node(rightData);
            q.push(tmp->right);
        }
    }
}

// void reverseordertraversal(node* root){
//     stack<node*> s;
//     s.push(root);
//     s.push(NULL);

//     node* tmp = s.top();

    
// }

void inorder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    node* root = NULL;
    //root = buildTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    createLevelordertraversal(root);
    levelordertraversal(root);

    return 0;
}

// HW
// 1. reverse level order traversal
// 2. iterative function for inorder, preorder, and postorder
// 

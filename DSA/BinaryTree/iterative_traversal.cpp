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

void preorder_iterative(node* root){

    stack<node*> st;
    st.push(root);

    while(!st.empty()){
        node* tmp = st.top();
        cout<<tmp->data;
        st.pop();

        st.push(tmp->left);
        st.push(tmp->right);

    }

}


int main(){

    node* root = NULL;
    //root = buildTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    buildTree(root);
    

    return 0;
}

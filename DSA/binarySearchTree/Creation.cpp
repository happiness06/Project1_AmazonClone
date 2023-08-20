#include<iostream>
#include<queue>
using namespace std;


class node{
    public:
        int val;
        node* left;
        node*right;

        node(int d){
            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }


};

node* InsertNode(int d, node* &root){

    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->val){
        root->right = InsertNode(d, root->right);
    }

    else{
        root->left = InsertNode(d, root->left);
    }

    return root;
}

void dataEntry(node* &root){

    int data;
    cin>>data;

    while(data != -1){
        root = InsertNode(data, root);
        cin>>data;
    }
    
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
            cout<<tmp->val<<" ";
            if(tmp->left != NULL){
                q.push(tmp->left);
            }
            
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
        }
    }
}


void inorder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    cout<<root->val<<" ";
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
    cout<<root->val<<" ";
}

node* min(node* root){

    node* tmp = root;

    while(tmp->left != NULL){
        tmp = tmp->left;

    }
    return tmp;

}

node* max(node* root){

    node* tmp = root;
    while(tmp->right != NULL){
        tmp=tmp->right;
    }

    return tmp;
}

node* deletion(node* &root, int x){
    if(root == NULL){
        return root;
    }

    if(root->val > x){
        deletion(root->left, x);
        return root;
    }

    if(root->val < x){
        deletion(root->right, x);
        return root;
    }

    
    if(root->val == x){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left != NULL && root->right == NULL){
            node* tmp = root->left;
            delete root;
            return tmp;
        }

        //right child
        if(root->right != NULL && root->left == NULL){
            node* tmp = root->right;
            delete root;
            return tmp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = min(root->right)->val;
            root->val = mini;
            root->right = deletion(root->right, mini);
            return root;

        }

    }  

}

node* inorderSuc(node* root, int key){
    node* Suc = root;
    if(root == NULL){
        return root;
    }

    if(root->val > key){
        root->left = inorderSuc(root->left, key);
        return root;
    }

    if(root->val < key){
        root->right = inorderSuc(root->right, key);
        return root;
    }

    else{
        node* tmp = root->right;
        while(tmp->left != NULL){
            tmp=tmp->left;
        }

        return tmp;
    }

}


int main(){

    node* root = NULL;
    cout<<"Enter data : ";
    dataEntry(root);

    cout<< endl<<"Printing the BST : "<<endl;
    levelordertraversal(root);

    cout<<"Inorder traversal : ";
    inorder(root);

    cout<<endl<<"Preorder traversal : ";
    preorder(root);

    cout<<endl<<"postorder traversal : ";
    postorder(root);

    cout<<endl<<"Minimum value in The BST : "<<min(root)->val;
    

    cout<<endl<<"Maximum value in The BST : "<<max(root)->val;

    deletion(root, 20);
    cout<<endl<<"After deletion : "<<endl;
    levelordertraversal(root);
    //10 8 21 7 27 5 4 3 -1
    return 0;

}
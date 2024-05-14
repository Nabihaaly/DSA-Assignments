// Binary Serach Tree

#include<bits/stdc++.h>
using namespace std;

struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;
};
BSTNode* insert(BSTNode *node,int value);
void search(BSTNode *node,int value);
void inOrderTrav(BSTNode *node);
void preOrderTrav(BSTNode *node);
void postOrderTrav(BSTNode *node);
BSTNode* findMin(BSTNode *node);
BSTNode* findMax(BSTNode *node);
BSTNode* deleteNode(BSTNode *node,int toDel);

            int valu[]={99,88,77,66};

int main(){
    BSTNode *root=nullptr;
    BSTNode* nodeMinn;
    BSTNode* maxNode;
    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform? \npress1 to insert value\npress2 to search\npress3 to inOrderTrav\npress4 to PreOrderTrav\npress5 to PostOrderTrav\npress6 to findMin\npress7 to findMax\npress8 to delete\npress 0 to exit."<<endl<<"Enter Value: ";
        cin>>task;

        switch(task)
        {
        case 1:
            // int value;
            // cout<<"Enter Value to Insert: ";
            // cin>>value;

            for(int i: valu){
                root=insert(root,i);
            }
            break;

        case 2:
            int toSearch;
            cout<<"Enter Value to Search: ";
            cin>>toSearch;
            search(root,toSearch);
            break;

        case 3:
            inOrderTrav(root);
            break;
        case 4:
            preOrderTrav(root);
            break;
        case 5:
            postOrderTrav(root);
            break;
        case 6:
            nodeMinn = findMin(root);
            cout<<nodeMinn->data;
            break;
        case 7:
            maxNode=findMax(root);
            cout<<maxNode->data;
            break;
        case 8:
            int toDel;
            cout<<"Enter Value to Delete: ";
            cin>>toDel;
            deleteNode(root,toDel);
            break;
        

        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }
    return 0;
}

BSTNode* insert(BSTNode *node,int value){
    if(node==nullptr){
        node=(BSTNode*)malloc(sizeof(BSTNode));
        node->data=value;
        node->left=node->right=nullptr;
        return node;
    }
    if(value<node->data){
        node->left=insert(node->left,value);
        return node;
    }
    else{
        node->right=insert(node->right,value);
        return node;
    }
}
void search(BSTNode *node,int value){
    if(node==nullptr){
        cout<<"Value Not Found"<<endl;
    }
    else if(node->data==value){
        cout<<"Value Found"<<endl;
    }
    else if(value<node->data){
        search(node->left,value);
    }
    else{
        search(node->right,value);
    }
}

void inOrderTrav(BSTNode *node){
    if(node!=nullptr){
        inOrderTrav(node->left);
        cout<<node->data<<" ";
        inOrderTrav(node->right);
    }
}

void preOrderTrav(BSTNode *node){
    if(node!=nullptr){
        cout<<node->data<<" ";
        inOrderTrav(node->left);
        inOrderTrav(node->right);
    }
}

void postOrderTrav(BSTNode *node){
    if(node!=nullptr){
        inOrderTrav(node->left);
        inOrderTrav(node->right);
        cout<<node->data<<" ";
    }
}

BSTNode* findMin(BSTNode *node){
    while(node->left!=nullptr){
        node=node->left;
    }
    return node;
}

BSTNode* findMax(BSTNode *node){
    while(node->right!=nullptr){
        node=node->right;
    }
    return node;
}

BSTNode* deleteNode(BSTNode *node,int toDel){
    if(node==nullptr){
        cout<<"Not Exist";
        return node;
    }
    if(toDel<node->data){
        node->left=deleteNode(node->left,toDel);
        return node;
    }
    else if(toDel>node->data){
        node->right=deleteNode(node->right,toDel);
        return node;
    }
    else{
        if(node->left==nullptr){
            BSTNode* temp=node->right;
            free(node);
            cout<<"\n"<<"Deleted";
            return temp;
        }
        else if(node->right==nullptr){
            BSTNode* temp=node->left;
            free(node);
            cout<<"\n"<<"Deleted";
            return temp;
        }
        else{
            BSTNode* temp=findMax(node->left);
            node->data=temp->data;
            node->left=deleteNode(node->left,temp->data);            
            return node;
        }
    }
}

#include<bits/stdc++.h>
using namespace std;

struct node{
    int roll;
    node *left,*right;
    node(){
        left=NULL,right=NULL;
    }
};
node *root=NULL;
void add(int roll){
    if(root==NULL){
            //cout << "LOL";
        root=new node;
        root->roll=roll;
    }
    else{
        node *current=root,*parent;
        while(current!=NULL){
            if(roll<current->roll){
                parent=current;
                current=current->left;
            }
            else{
                parent=current;
                current=current->right;
            }
        }
        node *newnode=new node();
        newnode->roll=roll;
        if(newnode->roll<parent->roll)parent->left=newnode;
        else parent->right=newnode;
    }
}
void print(node *current){ //if(current == NULL)cout << "BAAL";
    if(current==NULL)return;
    cout<<current->roll<<endl;
    print(current->left);
    print(current->right);
}
int main(){
    add(12);
    add(14);
    add(13);
    print(root);
}

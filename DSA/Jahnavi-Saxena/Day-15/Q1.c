#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int x){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->left = new->right = NULL;
    return new;
}

int height(struct node *root){
    if(root == NULL){
        return -1;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if(leftheight> rightheight){
        return leftheight + 1;
    }
    else{
        return rightheight + 1;
    }
}

void main(){
    struct node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(7);
    root->left->right = newNode(12);

    printf("Height of the tree is %d\n", height(root));

}

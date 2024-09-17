#include <stdlib.h>
#include <stdio.h>

typedef struct _node{
    int data;
    struct _node *left;
    struct _node *right;
} Node;

typedef struct _tree
{
    int count;
    Node* root;
} Tree;

Node* create_node(int val) {
    
    Node* n0;
    n0 = NULL;
    n0 = (Node*)malloc(sizeof(Node)); 
    n0->data = val;
    n0->left = NULL;
    n0->right = NULL;
    return n0;
} 


Tree* create_tree() {
    Tree* my_new_tree = (Tree*)malloc(sizeof(Tree)); 
    my_new_tree->count = 0;
    my_new_tree->root = NULL;
    return my_new_tree;
} 
int add2node(Node **tmp, Node* n)
{
    if (*tmp == NULL){
        *tmp = n;
        return 0;
    }
    if ((*tmp)->data < n->data)
        return add2node(&(*tmp)->right, n);
    else
        return add2node(&(*tmp)->left, n);
}
int add_node(Tree* t, Node* n) {
    if (t == NULL)
        return -1;
    if (t->root == NULL) {
        t->root = n;
        ++t->count;  
        return 0;
    }
    Node* tmp = t->root;
    
        if (n->data > tmp->data) {
            add2node(&tmp->right, n);
            
        }
        else
            add2node(&tmp->left, n);
        
        ++t->count;
        return 0;
    

}

int main() {

    Tree* tree = create_tree();
    Node* n1 = create_node(4);
    
    add_node(tree, n1);
    add_node(tree, create_node(7));
    add_node(tree, create_node(9));
    add_node(tree, create_node(3));
    add_node(tree, create_node(8));
    add_node(tree, create_node(6));
    add_node(tree, create_node(-3));


    return 0;
}
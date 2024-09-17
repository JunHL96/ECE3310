#include <stdlib.h>
#include <stdio.h>

#define NOT_FOUND 8

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

int print_tree(Tree* my_tree) {
    if(my_tree == NULL || my_tree->root == NULL)
        return 0;

    Tree* tmpLeft = create_tree();
    Tree* tmpRight = create_tree();

    tmpLeft->root = my_tree->root->left;
    print_tree(tmpLeft);

    printf(" %d ", my_tree->root->data);

    tmpRight->root = my_tree->root->right;
    print_tree(tmpRight);

    return 0;
}

int print_tree2(Node* root) {
    if(root == NULL)
        return 0;

    print_tree2(root->right);
    printf(" %d ", root->data);
    print_tree2(root->left);

    return 0;
}

int sum_tree(Node* root) {
    if(root == NULL)
        return 0;

    return sum_tree(root->right) + root->data + sum_tree(root->left);
}

int sum_tree_educational(Node* root) {
    if(root == NULL)
        return 0;

    int sum = 0;
    sum = sum + sum_tree(root->right);
    sum = sum + sum_tree(root->left);
    sum = sum + root->data;

    return sum;
}

int remove_node(Tree* t, int val) {
    if (t == NULL)
        return 0;
    if (t->root == NULL)
        return 0;

    Node** pre = &t->root;
    Node* item = t->root;

    while(item->data != val && item != NULL) {
        if(val > item->data) {
            pre = &item->right;
            item = item->right;
        } else {
            pre = &item->left;
            item = item->left;
        }
    }

    if(item == NULL)
        return NOT_FOUND;

    --t->count;

    if(item->left == NULL && item->right == NULL) {
        *pre = NULL;
        free(item);
        return 0;
    }

    if(item->left == NULL) {
        *pre = item->right;
        free(item);
        return 0;
    }

    if(item->right == NULL) {
        *pre = item->left;
        free(item);
        return 0;
    }

    Node** preMinNode = &item->right;
    Node* minNode = item->right;

    while(minNode->left != NULL) {
        preMinNode = &minNode->left;
        minNode = minNode->left;
    }

    *preMinNode = minNode->right;
    *pre = minNode;
    minNode->left = item->left;
    minNode->right = item->right;

    free(item);

    return 0;
}

int get_max_depth(Node* n) {
    if(n==NULL)
        return 0;

    int left = get_max_depth(n->left);
    int right = get_max_depth(n->right);

    if(left > right)
        return 1 + left;

    return 1+ right;
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
    add_node(tree, create_node(9));
    add_node(tree, create_node(15));

    printf("\n\n");
    int maxDepth = get_max_depth(tree->root);
    printf("tree max depth = %d", maxDepth);

    remove_node(tree, 7);

    printf("\n\n");
    int sum = sum_tree_educational(tree->root);
    printf(" %d ", sum);
    
    printf("\n\n");
    print_tree2(tree->root);
    
    printf("\n\n");
    print_tree(tree);

    printf("\n\n");



    return 0;
}
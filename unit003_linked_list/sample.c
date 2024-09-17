#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} Node;

Node* create_new_node() {
    Node* n0;
    n0 = NULL;
    /** malloc will allocate memory for usin the .heap memory segment
    * malloc - is defined in the stdlib library
    * malloc has one argument that represents the number of bytes to be allocated
    * malloc will return the address where the free space was found and allocated for us OR -1 if it fails
    * malloc returns a pointer to void (void *)
    * */
    n0 = (Node*)malloc(sizeof(Node)); 
    (*n0).data = 0;
    //n0->data = 0;
    n0->next = NULL;
    return n0;
} 

Node* create_node(int val) {
    Node* result = create_new_node();
    result->data = val;
    return result;
}

int main() {
    Node* n0 = create_node(4);
    Node* n1 = create_node(9);


    free(n0);
    free(n1);
    return 0;
}
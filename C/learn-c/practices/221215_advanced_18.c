#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node_t;

void insert(node_t * tree, int val);
// void print_tree(node_t * current);
void printDFS(node_t * current);

int main(){
    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    /* set values explicitly, alternative would be calloc() */
    test_list->val = 0;
    test_list->left = NULL;
    test_list->right = NULL;

    insert(test_list,5);
    insert(test_list,8);
    insert(test_list,4);
    insert(test_list,3);

    printDFS(test_list);
    printf("\n");
}

void insert(node_t * tree, int val){
    if (tree->val == 0){
        tree->val = val;
    } else {
        if (val < tree->val){
            if (tree->left == NULL){
                tree->left = (node_t *) malloc(sizeof(node_t));
                tree->left->val = val;
                tree->left->left = NULL;
                tree->left->right = NULL;
            } else{
                insert(tree->left, val);
            }            
        } else {
            if (tree->right == NULL){
                tree->right = (node_t *) malloc(sizeof(node_t));
                tree->right->val = val;
                tree->right->left = NULL;
                tree->right->right = NULL;
            } else {
                insert(tree->right, val);
            }
        }
    }
}

void printDFS(node_t * current){
    if (current == NULL) return;
    printf("%d ", current->val);
    printDFS(current->left);
    printDFS(current->right);
}
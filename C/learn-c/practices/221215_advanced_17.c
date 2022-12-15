#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_linked_list(node_t * l){
    printf("[ ");
    while (l) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("]\n");
}

node_t * generate_linked_list(int x){
    node_t * new_head = (node_t *) malloc(sizeof(node_t *));
    new_head->val = x;
    new_head->next = NULL;
    return new_head;
}

void add_first(node_t ** head, int x){
    node_t * new_head = (node_t *) malloc(sizeof(node_t *));
    new_head->val = x;
    new_head->next = *head;
    *head = new_head;
}

void add_last(node_t * head, int x){
    node_t * new_tail = (node_t *) malloc(sizeof(node_t *));
    new_tail->val = x;
    new_tail->next = NULL;

    node_t * curr = head;
    while (curr->next){
        curr = curr->next;
    }

    curr->next = new_tail;
}

int delete_first(node_t ** head){
    node_t * new_head;
    new_head = (*head)->next;    

    int result = (*head)->val;
    free(*head);
    
    *head = new_head;
    return result;
}

int delete_last(node_t * head){
    node_t * curr = head;
    while (curr->next->next) {
        curr = curr->next;
    }
    int result = curr->next->val;
    free(curr->next);
    curr->next = NULL;
    return result;
}

void linked_list_test(){
    node_t * l1 = generate_linked_list(0);
    print_linked_list(l1);

    int i;
    for (i=0; i<5; i++){
        add_first(&l1, -1-i);
        printf("add_first : ");
        print_linked_list(l1);
    }

    for (i=0; i<5; i++){
        add_last(l1, i+1);
        printf("add_last : ");
        print_linked_list(l1);
    }

    for (i=0; i<5; i++){
        printf("deleted : %d, list : ", delete_first(&l1));
        print_linked_list(l1);
    }

    for (i=0; i<5; i++){
        printf("deleted : %d, list : ", delete_last(l1));
        print_linked_list(l1);
    }
}


///////////////////////////////////////////////////////////////////////////


void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
    
    if ((*head)->val == val) {
        return pop(head);
    }    
    
    node_t * curr = *head;
    
    while (curr->next) {
        // printf("curr : %d, next : %d\n", curr->val, curr->next->val);
        if (curr->next->val == val) {
            node_t * deleted = curr->next;
            curr->next = deleted->next;
            free(deleted);
            return val;
        }
        curr = curr->next;
    }
    
    return -1;
}

void learning_c_problem(){

    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    print_list(test_list);

    remove_by_value(&test_list, 3);

    print_list(test_list);

}

int main() {
    // linked_list_test();
    learning_c_problem();
}
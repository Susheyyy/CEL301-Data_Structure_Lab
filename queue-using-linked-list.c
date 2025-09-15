#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
    int data;
    struct node *next;
};

void traverse(struct node *start)
{
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty.");
        return;
    }

    ptr = start;
    while (ptr->next != start) {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d", ptr->data);
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL) {
        new_node->next = new_node;
        start = new_node;
        return start;
    }

    ptr = start;
    while (ptr->next != start) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL) {
        new_node->next = new_node;
        start = new_node;
        return start;
    }

    ptr = start;
    while (ptr->next != start) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *PTR;
    if (start == NULL) {
        printf("\nList is empty. Cannot delete.");
        return start;
    }

    PTR = start;
    while (PTR->next != start)
        PTR = PTR->next;

    if (start == PTR) { // only one node
        free(start);
        start = NULL;
    } else {
        PTR->next = start->next;
        free(start);
        start = PTR->next;
    }
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    if (start == NULL) {
        printf("\nList is empty. Cannot delete.");
        return start;
    }

    ptr = start;
    if (ptr->next == start) { // only one node
        free(start);
        start = NULL;
        return start;
    }

    while (ptr->next != start) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);
    return start;
}

int main()
{
    struct node *start = NULL;
    int option, sub_option;

    do {
        printf("\nOptions: \n1. Insert \n2. Delete \n3. Traverse \n4. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("\nInsert: \n");
            printf("1. Insert at Beginning \n");
            printf("2. Insert at End\n");
            printf("\nEnter your choice: ");
            scanf("%d", &sub_option);
            if (sub_option == 1)
                start = insert_beg(start);
            else if (sub_option == 2)
                start = insert_end(start);
            else
                printf("\nInvalid choice.");
            break;

        case 2:
            printf("\nDelete: \n");
            printf("1. Delete from Beginning\n");
            printf("2. Delete from End\n");
            printf("\nEnter your choice: ");
            scanf("%d", &sub_option);
            if (sub_option == 1)
                start = delete_beg(start);
            else if (sub_option == 2)
                start = delete_end(start);
            else
                printf("\nInvalid choice.");
            break;

        case 3:
            printf("\nTraversing the list: \n");
            traverse(start);
            printf("\n");
            break;

        case 4:
            break;

        default:
            printf("\nInvalid option. Try again.");
        }

    } while (option != 5);

    return 0;
}

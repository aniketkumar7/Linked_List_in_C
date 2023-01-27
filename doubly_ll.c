#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next, *prev;
};
struct node *start = NULL;

// to insert at beginning of linked list
void insertbeginning(void)
{
    struct node *New;
    New = (struct node *)malloc(sizeof (struct node));
    printf("Enter the value of the node : ");
    scanf("%d",&New->info);
    New ->next = start;
    start -> prev = New;
    start = New;
    New -> prev = NULL;
}

// to insert at last of linked list
void insertlast(void)
{
    struct node *New , *ptr;
    New = (struct node *)malloc(sizeof (struct node));
    printf("Enter the value of the node : ");
    scanf("%d",&New->info);
    New -> next = NULL;
    if(start == NULL)
    {
        start = New;
        New ->prev = NULL;
    }
    else
    {
        ptr = start;
        while(ptr ->next != NULL)
        ptr = ptr -> next;
        ptr -> next = New;
        New -> prev = ptr;
    }
}


// to insert at specific position in linked list
void insertspecific(void)
{
    struct node *New, *ptr;
    int i, pos;
    New = (struct node *)malloc(sizeof (struct node));
    printf("Enter the value of the node : ");
    scanf("%d",&New->info);
    printf("Enter the position : ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        New -> next = start;
        start -> prev = New;
        start = New;
        New -> prev = NULL;
    }
    else
    {
        ptr = start;
        for(i=0; i<(pos-2); i++)
        {
            ptr = ptr -> next;
            if(ptr == NULL)
            printf("List is small \n");
        }
        New -> next = ptr -> next;
        New -> prev = ptr;
        ptr -> next -> prev = New;
        ptr -> next = New;
    }
}


// to delete from beginning of linked list
void deletebeginning(void)
{
    struct node *ptr;
    if(start == NULL)
    printf("Underflow\n");
    else
    {
        ptr = start;
        printf("%d is deleted\n", ptr -> info);
        start = start -> next;
        start -> prev = NULL;
        free(ptr);
    }
}


// to delete from last of the linked list
void deletelast(void)
{
    struct node *ptr, *loc;
    if(start == NULL)
    printf("Underflow\n");
    else if(start -> next == NULL)
    {
        ptr = start;
        start = NULL;
        printf("%d is deleted\n", ptr -> info);
        free(ptr);
    }
    else
    {
        ptr = start;
        while(ptr -> next != NULL)
        {
            loc = ptr;
            ptr = ptr -> next;
        }
        loc -> next = NULL;
        printf("%d is deleted\n", ptr -> info);
        free(ptr);
    }
}


// to delete from specific position in the linked list
void deletespecific(void)
{
    struct node *ptr, *loc;
    int i, pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(start == NULL)
    printf("Underflow\n");
    else if(pos == 1)
    {
        ptr = start;
        start = start -> next;
        start -> prev = NULL;
        printf("%d is deleted", ptr -> info);
        free(ptr);
    }
    else
    {
        ptr = start;
        for(i=0; i<(pos - 1); i++)
        {
            loc = ptr;
            ptr = ptr -> next;
            if(ptr == NULL)
            printf("List is small\n");
        }
        loc -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;
        printf("%d is deleted", ptr -> info);
        free(ptr);
    }
}


// to display the elements in the linked list
void display(void)
{
    struct node *ptr;
    if (start == NULL)
        printf("Linked List is empty : ");
    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->info);
            ptr = ptr->next;
        }
    }
}


// main function
int main()
{
    int a;
    char c = 'y';

    while (c == 'y' || c == 'Y')
    {
        printf("Enter 1 for Insert at Beginning :  ");
        printf("\n");
        printf("Enter 2 for Insert at Last :  ");
        printf("\n");
        printf("Enter 3 for Insert at Specific Position :  ");
        printf("\n");
        printf("Enter 4 for Delete from Beginning :  ");
        printf("\n");
        printf("Enter 5 for Delete from Last :  ");
        printf("\n");
        printf("Enter 6 for Delete from Specific Position  :  ");
        printf("\n");
        printf("Enter 7 for Display the Linked List :  ");
        printf("\n");
        printf("Enter the choice : ");
        scanf("%d", &a);
        switch(a)
        {
        case 1:
            insertbeginning();
            break;

        case 2:
            insertlast();
            break;

        case 3:
            insertspecific();
            break;

        case 4:
            deletebeginning();
            break;

        case 5:
            deletelast();
            break;

        case 6:
            deletespecific();
            break;

        case 7:
            display();
            break;

        default:
            printf("Enter the correct choice  \n");
        }
        printf("Enter y or Y for continue : ");
        scanf("%s", &c);  
        printf("\n");
    }
    return 0;
}

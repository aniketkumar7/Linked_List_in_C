//This is a C program of implementation of Simple Linked List

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL, *head;

// insert at the beginning of linked list

void insertbeginning(void)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of new node : ");
    scanf("%d", &new->info);
    new->next = start;
    start = new;
}

// insert at the last of the linked list

void insertlast(void)
{
    struct node *ptr, *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the node : ");
    scanf("%d", &new->info);
    new->next = NULL;
    if (start == NULL)
        start = new;
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

// insert at the specific position in linked list

void insertspeific(void)
{
    struct node *new, *ptr;
    int pos, i;
    printf("Enter the position where you want to insert : ");
    scanf("%d", &pos);
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the node : ");
    scanf("%d", &new->info);
    if (pos == 1)
    {
        new->next = start;
        start = new;
    }
    else
    {
        ptr = start;
        for (i = 1; i < (pos - 1); i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Linked List is small");
                printf("\n");
                break;
            }
        }
        new->next = ptr->next;
        ptr->next = new;
    }
}
// delete from beginning of linked list

void deletebeginning(void)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("No element is present to delete");
        printf("\n");
    }
    else
    {
        ptr = start;
        printf("%d is deleted ", start->info);
        printf("\n");
        start = start->next;
        free(ptr);
    }
}

// delete from the last of linked list

void deletelast(void)
{
    struct node *ptr, *loc;
    if (start == NULL)
    {
        printf("List is empty");
        printf("\n");
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            loc = ptr;
            ptr = ptr->next;
        }
        printf("%d is deleted", ptr->info);
        loc->next = NULL;
        printf("\n");
        free(ptr);
    }
}

// delete from specific position in linked list

void deletespecific(void)
{
    struct node *ptr, *loc;
    int i, pos;
    printf("Enter the position which you want to delete : ");
    scanf("%d", &pos);
    if (start == NULL)
    {
        printf("Linked List is empty ");
        printf("\n");
    }
    else if (pos == 1)
    {
        ptr = start;
        start = start->next;
        printf("%d is deleted", ptr->info);
        printf("\n");
        free(ptr);
    }
    else
    {
        for (i = 2; i <= pos; i++)
        {
            ptr = start;
            loc = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Linked List is small");
                printf("\n");
                break;
            }
        }
        loc->next = ptr->next;
        printf("%d is deleted ", ptr->info);
        printf("\n");
        free(ptr);
    }
}

// display the linked list

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
            printf("%d\t", ptr->info);
            printf("\n");
            ptr = ptr->next;
        }
    }
}

// reverse the linked list

void reverse(void)
{
    struct node *p, *q, *r;
    if(start == NULL || start ->next == NULL)
    printf("No need to Reverse the Linked List  \n ");
    else
    {
        p = start;
        q = p -> next;
        r = q -> next;
        while(r!=NULL)
        {
            q ->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q -> next = p;
        start ->next = NULL;
        start = q;
        printf("The Linked List is Reversed , now display the Linked List\n");
    }    
}

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
        printf("Enter 8 to reverse the Linked List : ");
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
            insertspeific();
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

        case 8:
            reverse();
            break;

        default:
            printf("Enter the correct choice  \n");
        }
        printf("Enter y or Y for continue : ");
        fflush(stdin);
        scanf("%s", &c);  
        printf("\n");
    }
    return 0;
}

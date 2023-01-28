#include<stdio.h>
#include<stdlib.h>

struct  node
{
    int info;
    struct node *next, *prev;
};
struct node *start = NULL, *last;

// to insert in beginning of linked list
void insertbeginning()
{
    struct node *new;
    new = (struct node *)malloc(sizeof (struct node));
    printf("Enter the value of the node :\t ");
    scanf("%d",&new->info);
    if(last == NULL)
    {
        last = new;
        new -> next = new;
        new -> prev = new;
    }
    else
    {
        new -> next = last -> next;
        new -> prev = last;
        last -> next -> prev = new;
        last -> next = new;
    }
}

// to insert at last in the linked list
void insertlast(void)
{
     struct node *new;
    new = (struct node *)malloc(sizeof (struct node));
    printf("Enter the value of the node : \t");
    scanf("%d",&new->info);
    if(last == NULL)
    {
        last = new;
        new -> next = new;
        new -> prev = new;
    }
    else
    {
        new -> next = last -> next;
        new -> prev = last;
        last -> next -> prev = new;
        last -> next = new;
        last = new;
    }
}

// to insert at specific postion in the linked list
void insertspecific(void)
{
    struct node *ptr, *new;
    int i, pos;
    printf("Enter the position : \n");
    scanf("%d", &pos);
    new = (struct node *)malloc(sizeof (struct node));
    printf("Enter the value of the node : \t");
    scanf("%d",&new->info);
    if((pos == 1) && (last == NULL))
    {
        last = new;
        new -> next = new;
        new -> prev = new;
    }
    else if ((pos == 1) && (last != NULL))
    {
        new -> next = last -> next;
        new -> prev = last;
        last -> next -> prev = new;
        last -> next = new;
    }
    else
    {
        ptr = last -> next;
        for(i=2; i<pos; i++)
        {
            ptr = ptr -> next;
            if(ptr == NULL)
            {
                printf("List is empty \n");
            }            
        }
        if(ptr == last)
        {
            new -> next = last -> next;
            new -> prev = last;
            last -> next -> prev = new;
            last -> next = new;
            last = new;
        }
        else
        {
            new -> next = ptr -> next;
            ptr -> next -> prev = new;
            ptr -> next = new;
            new -> prev = ptr;
        }
    }
}

void deletebeginning(void)
{
    struct node *ptr;
    if(last == NULL)
    printf("Underflow\n");
    else
    {
        ptr = last -> next;
        printf("%d is deleted\n", ptr->info);
        if(last == last ->next)
        {
            last = NULL;
            free(ptr);
        }
        else
        {
            last -> next = ptr -> next;
            ptr -> next ->prev = last;
            free(ptr);
        }
    }    
}



void deletelast(void)
{
    struct node *ptr, *loc;
    if(last == NULL)
    printf("Underflow\n");
    else
    {
        ptr = last;
        loc = last -> next;
        printf("%d is deleted\n", ptr ->info);
        if(last == last -> next)
        {
            last  = NULL;
            free(ptr);
        }
        else
        {
            while(loc -> next != last)
            loc = loc -> next;
            loc -> next = last -> next;
            last -> next -> prev = loc;
            last = loc;
            free(ptr);
        }
    }
}


void deletespecific(void)
{
    struct node *ptr, *loc;
    int i, pos;
    printf("Enter the postion : ");
    scanf("%d",&pos);
    if(last == NULL)
    printf("Underflow\n");
    else
    {
        ptr = last -> next;
        if(pos == 1 && last == last -> next)
        {
            last = NULL;
            printf("%d is deleted\n", ptr-> info);
            free(ptr);
        }
        else if(pos == 1 && last != last -> next)
        {
            last -> next = ptr -> next;
            ptr -> next -> prev = last;
            printf("%d is deleted\n",ptr->info);
            free(ptr);
        }
        else
        {
            for(i=0; i<pos -1; i++)
            {
                loc = ptr;
                ptr = ptr -> next;
                if(ptr == last -> next)
                {
                    printf("List is small\n");
                    break;
                }
            }
            loc -> next = ptr -> next;
            ptr -> next -> prev = loc;
            printf("%d is deleted\n",ptr->info);
            if(ptr == last)
            last = loc;
            free(ptr);
        }
    }
}


void display(void)
{
    struct node *ptr;
    if(last == NULL)
    printf("List is empty\n");
    else
    {
        ptr = last -> next;
        printf("%d\n", ptr -> info);
        ptr = ptr ->next;
        while(ptr != last -> next)
        {
            printf("%d\n", ptr -> info);
            ptr = ptr -> next;
        }
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

#include<stdio.h>
#include<stdlib.h>

struct  node
{
    int info;
    struct node *Next;
};
struct node *start, *Last;


// insert in beginning in circular linked list

void insertbeg(void)
{
    struct node *New;
    New = (struct node *)malloc (sizeof (struct node));
    printf("Enter the value of the node : ");
    scanf("%d", &New ->info );
    if(Last == NULL)
    {
        Last = New ;
        New -> Next = Last;
    }
    else
    {
        New -> Next = Last -> Next;
        Last -> Next = New;
    }
}

// insert at the last in the circular linked list 

void insertlast(void)
{
    struct node *New;
    New = (struct node *)malloc (sizeof (struct node));
    printf("Enter the value of the node : ");
    scanf("%d", &New ->info );
    if(Last == NULL)
    {
        Last = New ;
        New -> Next = Last;
    }
    else
    {
        New -> Next = Last -> Next;
        Last -> Next = New;
        Last = New;
    }
}

// insert at specific position in circular linkedlist

void insertsp(void)
{
    struct node *New, *Ptr;
    int pos, i;
    New = (struct node *)malloc(sizeof(struct node));
    if (New == NULL)
        printf("Overflow\n");
    else
    {
        printf("Enter the position of the node : ");
        scanf("%d", &pos);
        printf("Enter the value of the node : ");
        scanf("%d", &New->info);
        if ((pos == 1) && (Last == NULL))
        {
            New->Next = New;
            Last = New;
        }
        else if ((pos == 1) && (Last != NULL))
        {
            New->Next = Last->Next;
            Last->Next = New;
        }
        else
        {
            Ptr = Last->Next;
            for (i = 2; i < pos; i++)
            {
                Ptr = Ptr->Next;
                if (Ptr == Last->Next)
                {
                    printf("List is small\n");
                    break;
                }
            }
            New->Next = Ptr->Next;
            Ptr->Next = New;
            if(Ptr == Last)
            Last = New;
        }
    }
}
// delete from beginning of circular linkedlist 

void deletebeg(void)
{
    struct node *Ptr;
    if (Last == NULL)
    {
        printf(" Underflow \n");
    }
    else
    {
        Ptr = Last -> Next;
        printf("%d is deleted \n", Ptr -> info);
        if(Last == Last -> Next)
        Last = NULL;
        else
        Last -> Next = Ptr ->Next;
        free(Ptr);
    }    
}

// delete from last of circular linkedlist

void deletelast(void)
{
    struct node *Ptr, *Loc;
    if (Last == NULL)
    {
        printf(" Underflow ");
    }
    else
    {
        Ptr = Last;
        Loc = Last -> Next;
        printf(" %d is deleted\n",Ptr->info);
        if(Last == Last-> Next)
        Last = NULL;
        else
        {
            while(Loc ->Next != Last)
            Loc = Loc ->Next;
            Loc -> Next = Last -> Next;
            Last = Loc;
        }
        free(Ptr);
    }
}

// delete from specific position  in circular linkedlist

void deletespecific(void)
{
    struct node *ptr, *loc;
    int i, pos;
    printf("Enter the position which you want to delete : ");
    scanf("%d", &pos);
    if (Last == NULL)
        printf("Underflow\n");
    else
    {
        ptr = Last->Next;
        if (Last == Last->Next && pos == 1)
        {
            printf("%d is deleted\n", ptr->info);
            Last = NULL;
            free(ptr);
        }
        else if (pos == 1 && Last != Last->Next)
        {
            Last->Next = ptr->Next;
            printf("%d is deleted\n", ptr->info);
            free(ptr);
        }
        else
        {
            for (i = 2; i <= pos; i++)
            {
                loc = ptr;
                ptr = ptr->Next;
                if (ptr == Last->Next)
                {
                    printf("List is small\n");
                    return;
                }
            }
            loc->Next = ptr->Next;
            printf("%d is deleted\n", ptr->info);
            if (ptr == Last)
                Last = loc;
            free(ptr);
        }
    }
}

// to display the linkedlist

void display(void)
{
    struct node *ptr;
    if(Last == NULL)
    printf("List is empty\n");
    else
    {
        ptr = Last -> Next;
        do
        {
            printf("%d\t",ptr->info);
            printf("\n");
            ptr = ptr -> Next;
        }while(ptr != Last -> Next);
            
    }
}

//main function

int main()
{
    int a;
    int c =10;
    while(c == 10)
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
            insertbeg();
            break;
                
            case 2:
            insertlast();
            break;

            case 3:
            insertsp();
            break;

            case 4:
            deletebeg();
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
            printf("Enter the correct choice \n");
        }
        printf("Enter 10 for continue : ");
        scanf("%d", &c);
        printf("\n");            
    }
    return 0;
}



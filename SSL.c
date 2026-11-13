#include <stdio.h>
#include <stdlib.h>

struct node
{   
    int data;
    struct node *next;
}

struct node *start = NULL;
struct node *curr = NULL;

void Create_SLL()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->next = NULL;

    printf("Enter the data: ");
    scanf("%d", &nn->data);
    
    if (start == NULL)
    {
        start = nn;
        curr = nn;
    }
    else
    {
        curr->next = nn;
        curr = nn;
    }
    printf("Node Created\n");
}

void Insertion_front()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->next = NULL;

    printf("Enter the data: ");
    scanf("%d", &nn->data);
    
    if (start == NULL)
    {
        start = nn;
        curr = nn;
    }
    else
    {
        nn->next = start;
        start = nn;
    }
    printf("Inserted at front successfully\n");
}

void Insertion_Middle()
{
    int pos, i;
    struct node *nn, *temp;
    
    printf("Enter position after which you want to insert: ");
    scanf("%d", &pos);

    nn = (struct node *)malloc(sizeof(struct node));
    nn->next = NULL;
    printf("Enter the data: ");
    scanf("%d", &nn->data);

    temp = start;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Previous position not found\n");
        free(nn);
    }
    else
    {
        nn->next = temp->next;
        temp->next = nn;
        if (nn->next == NULL)
        {
            curr = nn;
        }
        printf("Inserted in middle successfully\n");
    }
}

void Insertion_End()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->next = NULL;
    
    printf("Enter the Value: ");
    scanf("%d", &nn->data);

    if (start == NULL)
    {
        start = nn;
        curr = nn;
    }
    else
    {
        curr->next = nn;
        curr = nn;
    }
    printf("Inserted at end successfully\n");
}

void display()
{
    struct node *temp = start;
    
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List 6: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch;
    
    while(1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create \n2. Insertion_Front \n3. Insertion_Middle \n4. Insertion_End \n5. Display \n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: Create_SLL();
                break;
            case 2: Insertion_front();
                break;
            case 3: Insertion_Middle();
                break;
            case 4: Insertion_End();
                break;
            case 5:  display();
                break;
            case 6: printf("Exiting...\n");
                exit(0);
            default: printf("The Value is Invalid....\n");
                break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *curr = NULL;

void Create_DLL()
{
    struct node *nn;
    int choice;
    do
    {
        nn = (struct node*)malloc(sizeof(struct node));
        nn->next = NULL;
        nn->prev = NULL;
        printf("Enter the Data : ");
        scanf("%d", &nn->data);

        if (start == NULL)
        {
            start = nn;
            curr = nn;
        }
        else
        {
            curr->next = nn;
            nn->prev = curr;
            curr = nn;
        }
        printf("Do you want to add another node? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);
}

void Insertion_DLL_begin()
{
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->prev = NULL;
    printf("Enter the Data : ");
    scanf("%d", &nn->data);

    if (start == NULL)
    {
        start = nn;
        curr = nn;
    }
    else
    {
        nn->next = start;
        start->prev = nn;
        start = nn;
    }
}

void Insertion_DLL_mid()
{
    int pos, i = 1;
    printf("Enter the Position to insert : ");
    scanf("%d", &pos);

    if (pos <= 1 || start == NULL)
    {
        Insertion_DLL_begin();
        return;
    }

    struct node *temp = start;
    while (i < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL)
    {
        struct node *nn = (struct node*)malloc(sizeof(struct node));
        printf("Enter the Data : ");
        scanf("%d", &nn->data);
        nn->next = NULL;
        nn->prev = temp;
        temp->next = nn;
        curr = nn;
        return;
    }

    struct node *nn = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Data : ");
    scanf("%d", &nn->data);

    struct node *temp1 = temp->next;
    temp->next = nn;
    nn->prev = temp;
    nn->next = temp1;
    temp1->prev = nn;
}

void Insertion_DLL_end()
{
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->prev = NULL;
    printf("Enter the Data : ");
    scanf("%d", &nn->data);

    if (start == NULL)
    {
        start = nn;
        curr = nn;
    }
    else
    {
        curr->next = nn;
        nn->prev = curr;
        curr = nn;
    }
}

void Deletion_Begin()
{
    if (start == NULL)
    {
        printf("Linked list is Empty..\n");
        return;
    }

    struct node *temp = start;
    if (start == curr)
    {
        start = NULL;
        curr = NULL;
    }
    else
    {
        start = start->next;
        start->prev = NULL;
    }
    free(temp);
    printf("Deleted from beginning.\n");
}

void Deletion_mid()
{
    if (start == NULL)
    {
        printf("Linked list is Empty..\n");
        return;
    }

    int pos, i = 1;
    printf("Enter the Position to delete : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        Deletion_Begin();
        return;
    }

    struct node *temp = start;
    while (i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid Position!\n");
        return;
    }

    if (temp == curr)
    {
        curr = curr->prev;
        curr->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Deleted node at position %d.\n", pos);
}

void Deletion_end()
{
    if (curr == NULL)
    {
        printf("Linked list is Empty..\n");
        return;
    }

    struct node *temp = curr;
    if (start == curr)
    {
        start = NULL;
        curr = NULL;
    }
    else
    {
        curr = curr->prev;
        curr->next = NULL;
    }
    free(temp);
    printf("Deleted from end.\n");
}

void display()
{
    struct node *temp = start;
    if (temp == NULL)
    {
        printf("Linked list is Empty..\n");
        return;
    }

    printf("List: NULL <-> ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Create_DLL\n2. Insertion_Front\n3. Insertion_Middle\n4. Insertion_End\n");
        printf("5. Deletion_Front\n6. Deletion_Middle\n7. Deletion_End\n8. Display\n9. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: Create_DLL();
                break;

            case 2: Insertion_DLL_begin();
                break;

            case 3: Insertion_DLL_mid();
                break;

            case 4: Insertion_DLL_end();
                break;

            case 5: Deletion_Begin();
                break;

            case 6: Deletion_mid();
                break;

            case 7: Deletion_end();
                break;

            case 8: display();
                break;

            case 9: printf("Exiting the Program..\n");
                exit(0);

            default: printf("Choice Invalid..\n");
                break;
        }
    }
    return 0;
}
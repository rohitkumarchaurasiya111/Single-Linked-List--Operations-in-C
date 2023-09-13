// C program which contains all the Operations on Single Linked List.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linkedlist(struct Node *head)
{
    int ch;
    printf("Number of Nodes\n1.Known\n2.Unknown\n");
    printf("Enter Choice: ");
    scanf("%d", &ch);
    struct Node *temp, *p;
    switch (ch)
    {
    case 1:
        printf("No. of Data: ");
        int n;
        scanf("%d", &n);
        head = NULL;
        printf("Enter the values: ");
        for (int i = 0; i < n; i++)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            scanf("%d", &(temp->data));
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                p = head;
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = temp;
            }
        }
        break;
    case 2:
    {
        int num;
        struct Node *new_node, *ptr;
        printf("Enter -1 to end\n");
        printf("Enter the data : ");
        scanf("%d", &num);

        while (num != -1)
        {
            new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = num;
            new_node->next = NULL;

            if (head == NULL)
            {
                head = new_node;
            }
            else
            {
                ptr = head;
                while (ptr->next != NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
            }
            scanf("%d", &num);
        }
        return head;
        break;
    }
    default:
        break;
    }
    return head;
}
void display(struct Node *head)
{
    struct Node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
struct Node *insert(struct Node *head)
{
    int ch;
    printf("MENU\n1.Insert at First\n2.Insert at the End\n3.Insert in Between\n");
    printf("Enter choice: ");
    scanf("%d", &ch);
    struct Node *element;
    element = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    switch (ch)
    {
    case 1:
        printf("Enter element to insert: ");
        scanf("%d", &(element->data));
        // printf("%d", (element->data));
        element->next = head;
        head = element;
        return head;

        break;
    case 2:
        printf("Enter the element to insert at last: ");
        scanf("%d", &(element->data));
        element->next = NULL;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = element;
        return head;
        break;
    case 3:
        printf("Enter the Position : ");
        int position;
        scanf("%d", &position);
        printf("Enter the element  : ");
        scanf("%d", &(element->data));
        if (position == 1)
        {
            element->next = head;
            head = element;
        }
        else
        {
            for (int i = 1; i != position - 1; i++)
            {
                p = p->next;
            }
            element->next = p->next;
            p->next = element;
        }
        return head;
        break;
    default:
        free(element);
        break;
    }
}
struct Node *delete(struct Node *head)
{
    int ch;
    struct Node *ptr;
    printf("MENU\n1.First Node\n2.Last Node\n3.Between\n");
    printf("Enter Choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        ptr = head;
        head = head->next;
        free(ptr);
        break;
    case 2:
        ptr = head;
        struct Node *q;
        q = head->next;
        while (q->next != NULL)
        {
            ptr = ptr->next;
            q = q->next;
        }
        ptr->next = q->next;
        free(q);
        break;
    case 3:
        printf("Enter position: ");
        int position;
        scanf("%d", &position);
        if (position == 1)
        {
            ptr = head;
            head = head->next;
            free(ptr);
        }
        else
        {
            struct Node *q;
            ptr = head;
            q = head->next;
            for (int i = 1; i != position - 1; i++)
            {
                ptr = ptr->next;
                q = q->next;
            }
            ptr->next = q->next;
            free(q);
        }
        break;

    default:
        break;
    }
    return head;
}
void count(struct Node *head)
{
    int count = 0;
    struct Node *ptr;
    ptr = head;
    while (ptr != 0)
    {
        ptr = ptr->next;
        count++;
    }
    printf("There are %d Nodes\n", count);
}
struct Node *reverse(struct Node *head)
{
    // printf("\nMENU\n1.Iterative Method\n2.Recursive Method\n");
    // printf("Enter Choice: ");
    // int ch;
    // scanf("%d", &ch);
    // switch (ch)
    // {
    // case 1:
    {
        struct Node *current, *next, *previous = NULL;
        current = head;
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
        return head;
    }
    // case 2:
    // {
    // here i have tried to call a function
    //     recursive_reverse(head);
    // inside the function reverse but it is not allowed to use nested function in C programming...
    // }
    // break;
    // default:
    //     break;
    // }
}
struct Node *recursive_reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *new_node = recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    head = new_node;
    return head;
}
void find_max(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    int max = INT_MIN;

    do
    {
        ptr = ptr->next;
        if (ptr->data > max)
        {
            max = ptr->data;
        }
    } while (ptr->next != NULL);

    printf("Max Value is %d\n", max);
}
int main()
{
    struct Node *head = NULL;
    head = create_linkedlist(head);
    display(head);
    printf("MENU\n1.Insertion\n2.Deletion\n3.Count\n4.Reverse\n5.Max.Element\n6.Recursive Reverse\n");
    printf("Enter your Choice: ");
    int choice;
    scanf("%d", &choice);
    printf("\n");
    switch (choice)
    {
    case 1:
        head = insert(head);
        break;
    case 2:
        head = delete (head);
        break;
    case 3:
        count(head);
        break;
    case 4:
        head = reverse(head);
        break;
    case 5:
        find_max(head);
        break;
    case 6:
        head = recursive_reverse(head);
        break;
    default:
        break;
    }
    display(head);
    return 0;
}
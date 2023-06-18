#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int value;
    struct Node *next;

} Node;

Node *CreateNode()
{
    // Membuat Node Baru
    Node *newNode = malloc(sizeof(Node)); // Mengembalikan alamat memori pertama dari node yang dialokasikan
    printf("Masukkan Value : ");
    scanf("%d", &(newNode->value));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode; // Mengembalikan value newNode yang berupa alamat memori dari alokasi malloc
}

Node *InsertNode(Node *node)
{
    Node *newNode = CreateNode();

    if (node == NULL)
    { // Kondisi node bernilai null atau pertama kali membuat node
        node = newNode;
    }
    else
    { // Kondisi ketika ingin insert node baru
        Node *tmp = node;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        newNode->prev = tmp;
        tmp->next = newNode;
    }

    return node;
}

void show(Node *node)
{
    if (node != NULL)
    {
        while (node->next != NULL)
        {
            printf("[%d] ", node->value);
            node = node->next;
        }
        printf("[%d]\n", node->value);
    }
    else
    {
        printf("[ ]\n");
    }
}

Node *InsertBefore(Node *node)
{
    int findValue;
    printf("Insert Before What Value? ");
    scanf("%d", &findValue);
    Node *tmp = node;
    while (tmp->value != findValue && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if (tmp->value == findValue)
    {
        Node *NewNode = CreateNode();
        tmp->prev->next = NewNode;
        NewNode->prev = tmp->prev;
        tmp->prev = NewNode;
        NewNode->next = tmp;
        return node;
    }
    else
    {
        printf("Value Not Found\n");
        system("pause");
        return node;
    }
}

void showdescending(Node *node)
{
    if (node != NULL)
    {
        while (node->next != NULL)
        {
            node = node->next;
        }
        while (node->prev != NULL)
        {
            printf("[%d] ", node->value);
            node = node->prev;
        }
        printf("[%d] ", node->value);
    }
    else
    {
        printf("[ ]\n");
    }
    system("pause");
}

Node *DeleteNode(Node *node)
{
    int findValue;
    printf("Delete Before What Value? ");
    scanf("%d", &findValue);
    Node *tmp = node;
    while (tmp->value != findValue && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if (tmp->value == findValue)
    {
        if (tmp->prev == node)
        {
            Node *tmp = node;
            node = tmp->next;
            free(tmp);
            return node;
        }
        else if (tmp == node)
        {
            printf("can't delete null value\n");
            system("pause");
            return node;
        }
        else
        {
            Node *tmp2 = tmp->prev;
            tmp->prev->prev->next = tmp;
            tmp->prev = tmp->prev->prev;
            free(tmp2);

            return node;
        }
    }
    else
    {
        printf("Value Not Found\n");
        system("pause");
        return node;
    }
}

int main()
{

    Node *head = NULL;
    int choice;
    do
    {
        show(head);
        printf("Menu : \n");
        printf("1. Insert Node\n");
        printf("2. Show Descending\n");
        printf("3. Insert Before\n");
        printf("4. Delete Before\n");
        printf("0. Exit\n");
        printf("Masukkan Pilihan : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            system("cls");
            head = InsertNode(head);
        }
        else if (choice == 2)
        {
            showdescending(head);
        }
        else if (choice == 3)
        {
            head == InsertBefore(head);
        }
        else if (choice == 4)
        {
            head = DeleteNode(head);
        }
        system("cls");
    } while (choice != 0);
}

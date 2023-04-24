#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    struct node* prev;
    struct node* next;

}node;

int n;
node* head;
node* tail;

void init()
{
    head = (node*)malloc(sizeof(node*));
    tail = (node*)malloc(sizeof(node*));
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
}

void insert(char i)
{
    node* t = (node*)malloc(sizeof(node*));
    t->c = i;
    if (head->next->c >= i)
    {
        head->next->prev = t;
        t->next = head->next;
        head->next = t;
        t->prev = head;
    }
    else
    {
        tail->prev->next = t;
        t->prev = tail->prev;
        tail->prev = t;
        t->next = tail;
    }
}

void printall(void)
{
    node* t = head->next;
    while (t != tail)
    {
        printf("%c", t->c);
        t = t->next;
    }
}

void delete(void)
{
    node* d= head->next;
    node* t;
    while (d != tail)
    {
        t = d;
        d = d->next;
        free(t);
    }

    head->next = tail;
    tail->prev = head;
}

int main(void) {
    int t;
    char c;
    scanf("%d", &t);
    init();

    for (int i = 0; i < t; i++)
    {
        scanf("%d ", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &c);
            getchar();
            insert(c);
        }
        printall();
        printf("\n");
        delete();
    }

    free(head);
    free(tail);
    return 0;
}
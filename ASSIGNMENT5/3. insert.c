#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist
{
    int dat;
    struct linkedlist *nxt;
} ll;
void insert_at_beginning (ll **start, int data)
{
    if (start == NULL)
        return;
    ll *newNode = malloc (sizeof (ll));
    newNode->dat = data;
    newNode->nxt = *start;
    *start = newNode;
    return;
}
void print_list (ll *p)
{
    while (p != NULL)
    {
        printf ("%d -> ", p->dat);
        p = p->nxt;
    }
    printf ("(null)\n");
}
void insert (ll **start, int data, int insert_data)
{
    if (NULL == start || NULL == *start)
        return;
    ll *trav = *start;
    ll *newNode = malloc (sizeof (ll));
    newNode->dat = insert_data;
    if (trav->dat == data)
    {
        newNode->nxt = trav;
        *start = newNode;
        return;
    }
    while (trav->nxt != NULL && trav->nxt->dat != data)
        trav = trav->nxt;
    if (NULL == trav->nxt)
        return;
    newNode->nxt = trav->nxt;
    trav->nxt = newNode;
    return;
}
int main ()
{
    ll *start = NULL;
    insert_at_beginning (&start, 10);
    insert_at_beginning (&start, 20);
    insert_at_beginning (&start, 30);
    insert_at_beginning (&start, 40);
    insert_at_beginning (&start, 50);
    print_list (start);
    insert (&start, 50, 51);
    print_list (start);
    insert (&start, 10, 11);
    print_list (start);
    insert (&start, 0, 1);
    print_list (start);
    return 0;
}
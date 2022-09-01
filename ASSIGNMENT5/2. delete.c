#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist
{
    int dat;
    struct linkedlist *nxt;
} ll;
void insert (ll **start, int data)
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
void delete (ll *start, int data)
{
    if (NULL == start)
        return;
    while (start != NULL && start->dat != data)
        start = start->nxt;
    if (NULL == start || NULL == start->nxt)
        return;
    ll *temp = start->nxt;
    start->nxt = temp->nxt;
    free (temp);
    return;
}
int main ()
{
    ll *start = NULL;
    insert (&start, 10);
    insert (&start, 20);
    insert (&start, 30);
    insert (&start, 40);
    insert (&start, 50);
    print_list (start);
    delete (start, 10);
    delete (start, 15);
    delete (start, 20);
    print_list (start);
    
    return 0;
}
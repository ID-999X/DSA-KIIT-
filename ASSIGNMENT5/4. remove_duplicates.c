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
void remove_duplicates (ll *start)
{
    ll *curr = start, *last = NULL;
    while (curr != NULL)
    {
        if (last != NULL)
        {
            if (curr->dat == last->dat)
            {
                ll *temp = curr;
                curr = curr->nxt;
                last->nxt = curr;
                free (temp);
                continue;
            }
        }
        last = curr;
        curr = curr->nxt;
    }
}
int main ()
{
    ll *start = NULL;
    insert_at_beginning (&start, 10);
    insert_at_beginning (&start, 10);
    insert_at_beginning (&start, 10);
    insert_at_beginning (&start, 10);
    insert_at_beginning (&start, 10);
    insert_at_beginning (&start, 20);
    insert_at_beginning (&start, 30);
    insert_at_beginning (&start, 40);
    insert_at_beginning (&start, 40);
    insert_at_beginning (&start, 40);
    insert_at_beginning (&start, 40);
    insert_at_beginning (&start, 45);
    insert_at_beginning (&start, 50);
    insert_at_beginning (&start, 50);
    print_list (start);
    remove_duplicates (start);
    print_list (start);
    return 0;
}
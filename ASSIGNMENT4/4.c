#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
struct Term
{
    int coeff;
    int deg;
};

struct Polynomial
{
    int size;
    struct Term *arr;
};

struct Polynomial *substract_polynomial (struct Polynomial *p1, struct Polynomial *p2)
{
    struct Polynomial *sum = malloc (sizeof (struct Polynomial));
    sum->size = p1->size + p2->size;
    sum->arr = malloc (sum->size * sizeof (struct Term));
    int i = 0, j = 0, k = 0;
    while (i < p1->size && j < p2->size)
    {
        if (p1->arr[i].deg > p2->arr[j].deg)
        {

            sum->arr[k].coeff = p1->arr[i].coeff;
            sum->arr[k++].deg = p1->arr[i++].deg;
        }
        else if (p1->arr[i].deg == p2->arr[j].deg)
        {
            sum->arr[k].deg = p1->arr[i].deg;
            sum->arr[k++].coeff = p1->arr[i++].coeff - p2->arr[j++].coeff;
        }
        else
        {
            sum->arr[k].coeff = -1 * p2->arr[j].coeff;
            sum->arr[k++].deg = p2->arr[j++].deg;
        }
    }
    while (i < p1->size)
    {
        sum->arr[k].coeff = p1->arr[i].coeff;
        sum->arr[k++].deg = p1->arr[i++].deg;
    }
    while (j < p2->size)
    {
        sum->arr[k].coeff = -1 * p2->arr[j].coeff;
        sum->arr[k++].deg = p2->arr[j++].deg;
    }
    sum->size = k;
    return sum;
}

void scan_polynomial (struct Polynomial **p)
{
    printf ("enter size: ");
    scanf("%d", &((*p)->size));
    (*p)->arr = malloc ((*p)->size * sizeof (struct Term));
    printf("enter coefficients and degrees (with degrees in decreasing order):\n");
    for (int i = 0; i < (*p)->size; i++)
    {
        scanf("%d%d", &((*p)->arr[i].coeff), &((*p)->arr[i].deg));
    }
    return;
}

void print_polynomial (struct Polynomial *p)
{
    struct Term *cur = p->arr;
    for (int i = 0; i < p->size; i++)
    {
        if (i == 0)
        {

        }
        if (cur[i].coeff < 0)
        {
            if (i != 0)
                printf ("\e[33m - \e[m");
            else
                printf ("\e[33m-\e[m");
            printf ("%d\e[35mx\e[m^(\e[31m%d\e[m)", -1 * cur[i].coeff, cur[i].deg);
        }
        else
        {
            if (i != 0)
                printf ("\e[33m + \e[m");
            printf ("%d\e[35mx\e[m^(\e[31m%d\e[m)", cur[i].coeff, cur[i].deg);
        }
    }
    printf ("\n");
}

void generate_polynomial (struct Polynomial **p, int size) // do not write
{
    int r = 0, s = 0;
    (*p) = malloc (sizeof (struct Polynomial));
    (*p)->arr = malloc (size * sizeof (struct Term));
    for (int i = 0; i < size; i++)
    {
        r = rand () % 100;
        if (r < 50)
        {// create term;
            (*p)->arr[s].deg = size - 1 - i;
            (*p)->arr[s++].coeff = rand () % 100 - 50;
        }
    }
    (*p)->size = s;
    (*p)->arr = realloc ((*p)->arr, s * sizeof (struct Term));
    return;
}
int main()
{
    srand (time (NULL));
    struct Polynomial *p1 = malloc (sizeof (struct Polynomial));
    struct Polynomial *p2 = malloc (sizeof (struct Polynomial));

    printf("~\e[1;3;33mPOLYNOMIAL ADDITION\e[m~\n");

    printf ("\e[4;33mpolynomial 1:\e[m\n");
    generate_polynomial (&p1, 10);
    // scan_polynomial (&p1);
    printf("first polynomial is:\n");
    print_polynomial (p1);
    
    printf ("\e[4;33mpolynomial 2:\e[m\n");
    generate_polynomial (&p2, 10);
    // scan_polynomial (&p2);
    printf("second polynomial is:\n");
    print_polynomial (p2);

    printf("difference of the two polynomials is:\n");
    print_polynomial (substract_polynomial (p1, p2));
    return 0;
}
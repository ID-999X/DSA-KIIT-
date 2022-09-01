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

void delete_polynomial (struct Polynomial **p)
{
    if (p != NULL)
    {
        if ((*p)->arr != NULL)
        {
            free ((*p)->arr);
        }
        free (*p);
    }
    *p = NULL;
    return;
}

void print_polynomial (struct Polynomial *p)
{
    struct Term *cur = p->arr;
    for (int i = 0; i < p->size; i++)
    {
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

struct Polynomial *multiply_polynomial_with_term (struct Polynomial *p, struct Term t)
{
    struct Polynomial *ans = malloc (sizeof (struct Term));
    ans->size = p->size;
    ans->arr = malloc (p->size * sizeof (struct Term));
    for (int i = 0; i < p->size; i++)
    {
        ans->arr[i].deg = p->arr[i].deg + t.deg;
        ans->arr[i].coeff = p->arr[i].coeff * t.coeff;
    }
    return ans;
}

struct Polynomial *add_polynomial (struct Polynomial *p1, struct Polynomial *p2)
{
    struct Polynomial *sum = malloc (sizeof (struct Polynomial));
    sum->size = p1->size + p2->size;
    sum->arr = malloc (sum->size * sizeof (struct Term));
    int i = 0, j = 0, k = 0;
    while (i < p1->size && j < p2->size)
    {
        if (p1->arr[i].deg > p2->arr[j].deg)
        {
            sum->arr[k++] = p1->arr[i++];
        }
        else if (p1->arr[i].deg == p2->arr[j].deg)
        {
            sum->arr[k].deg = p1->arr[i].deg;
            sum->arr[k++].coeff = p1->arr[i++].coeff + p2->arr[j++].coeff;
        }
        else
        {
            sum->arr[k++] = p2->arr[j++];
        }
    }
    while (i < p1->size)
        sum->arr[k++] = p1->arr[i++];
    while (j < p2->size)
        sum->arr[k++] = p2->arr[j++];
    sum->size = k;
    sum->arr = realloc (sum->arr, k * sizeof (struct Term));
    return sum;
}

struct Polynomial *multiply_polynomial (struct Polynomial *p1, struct Polynomial *p2)
{
    struct Polynomial *product = malloc (sizeof (struct Polynomial)), *temp1 = NULL, *temp2 = NULL;
    product->size = 0;
    product->arr = NULL;
    for (int i = 0; i < p2->size; i++)
    {
        temp1 = multiply_polynomial_with_term (p1, p2->arr[i]);
        printf ("\ttemp1: ");
        print_polynomial (temp1);
        temp2 = add_polynomial (product, temp1);
        printf ("\t\ttemp2: ");
        print_polynomial (temp2);
        delete_polynomial (&product);
        product = temp2;
        // print_polynomial (product);
    }
    return product;
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
            (*p)->arr[s++].coeff = rand () % 10 - 5;
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

    printf("~\e[1;4;33mPOLYNOMIAL MULTIPLICATION\e[m\n");

    printf ("\e[4;33mpolynomial 1:\e[m\n");
    generate_polynomial (&p1, 5);
    // scan_polynomial (&p1);
    printf("first polynomial is:\n");
    print_polynomial (p1);
    
    printf ("\e[4;33mpolynomial 2:\e[m\n");
    generate_polynomial (&p2, 5);
    // scan_polynomial (&p2);
    printf("second polynomial is:\n");
    print_polynomial (p2);

    printf("\e[4;35mproduct of the two polynomials is:\e[m\n");
    print_polynomial (multiply_polynomial (p1, p2));
    return 0;
}
#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL; // this is a global pointer

void create(int A[], int n)
{
    struct Node *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// we can also pass the parameter by value since we are not modifying it
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
void display(struct Node *p)
{

    // Iterate over the linked list
    while (p != NULL)
    { // same as 'while (p)'
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// recursive version of 'display function'
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
void recDisplay(struct Node *p)
{
    if (p != NULL)
    { // same as 'if (p)'
        printf("%d ", p->data);
        recDisplay(p->next);
    }
}

// displays the linked list data in reverse order
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
void revRecDisplay(struct Node *p)
{
    if (p != NULL)
    { // same as 'if (p)'
        revRecDisplay(p->next);
        printf("%d ", p->data);
    }
}

// counts the number of nodes in the linked list.
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
int count(struct Node *p)
{
    int l = 0; // length is initially zero
    while (p)
    { // same as 'while (p != NULL)'
        l++;
        p = p->next;
    }
    return l; // return the length
}

// recursive version of 'count function'
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
int recCount(struct Node *p)
{
    if (p) // same as 'if (p != NULL)'
        return recCount(p->next) + 1;
    else
        return 0;
}

// sums up all of the elements in the linked list
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
int sum(struct Node *p)
{
    int s = 0;
    while (p)
    { // same as 'while (p != NULL)'
        s += p->data;
        p = p->next;
    }
    return s;
}

// recursive version of 'sum function'
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
int recSum(struct Node *p)
{
    if (!p) // same as 'if (p == NULL)'
        return 0;
    else
        return recSum(p->next) + p->data;
}

// finds the maximum element in the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxElement(struct Node *p)
{
    int max = _I32_MIN; // smallest integer value
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

// recursive version of 'max function'
// Time Complexity: O(n)
// Space Complexity: O(n)
int recMaxElement(struct Node *p)
{
    if (!p)
        return _I32_MIN;
    int x = recMaxElement(p->next);
    return (x > p->data) ? x : p->data;
}

// Linear Search on a linked list
struct Node *linearSearch(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// recursive version of Linear Search on a linked list
struct Node *recLinearSearch(struct Node *p, int key)
{
    if (!p)
        return NULL;
    if (key == p->data)
        return p;
    return recLinearSearch(p->next, key);
}

// Linear Search on a linked list w/ 'Move to head'
struct Node *improvedLinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL; // a tail pointer which will follow 'p'
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Time Complexity: O(n)
void insert(struct Node *p, int index, int x)
{

    // check if the index is valid
    if (index < 0 || index > count(p))
        return;

    struct Node *t = (struct Node *)malloc(sizeof(struct Node)); //temp
    t->data = x;

    //Now we need to link the new node 't' in the linked list
    if (index == 0)
    { // if '0', insert before 'first' node
        t->next = first;
        first = t;
    }
    else
    {
        // move pointer 'p' to correct position
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Time Complexity: O(1)
// 'first' and 'last' are global pointers
void insertLast(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}

int main()
{
    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(4);
    insertLast(5);
    display(first);

    return 0;
}

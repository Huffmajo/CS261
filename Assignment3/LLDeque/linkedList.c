/* Name: Joel Huffman
 * Program: linkedList.c
 * Date: 4/24/2018
 */

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
    TYPE value;
    struct Link* next;
    struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
    int size;
    struct Link* frontSentinel;
    struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
    // FIXME: you must write this

    //allocate sentinels
    list->frontSentinel = (struct Link*) malloc(sizeof(struct Link));
    assert(list->frontSentinel != 0);
    list->backSentinel = (struct Link*) malloc(sizeof(struct Link));
    assert(list->backSentinel != 0);

    //set initial sentinel's next and prevs
    list->frontSentinel->next = list->backSentinel;
    list->frontSentinel->prev = 0;
    list->backSentinel->next = 0;
    list->backSentinel->prev = list->frontSentinel;

    //set size to 0
    list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
    // FIXME: you must write this

    //create new link to insert
    struct Link* newLink = (struct Link*) malloc(sizeof(struct Link));
    assert(newLink != 0);

    //position newLink before link
    newLink->next = link;
    newLink->prev = link->prev;
    newLink->value = value;
    link->prev->next = newLink;
    link->prev = newLink;

    //increment list's size
    list->size++;

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
    // FIXME: you must write this

    assert(!linkedListIsEmpty(list));
    link->next->prev = link->prev;
    link->prev->next = link->next;

    free(link);
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
    struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
    init(newDeque);
    return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
    while (!linkedListIsEmpty(list))
    {
        linkedListRemoveFront(list);
    }
    free(list->frontSentinel);
    free(list->backSentinel);
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
    // FIXME: you must write this

    addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
    // FIXME: you must write this

    addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
    // FIXME: you must write this

    assert(!linkedListIsEmpty(list));
    return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
    // FIXME: you must write this

    assert(!linkedListIsEmpty(list));
    return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
    // FIXME: you must write this

    assert(!linkedListIsEmpty(list));
    removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
    // FIXME: you must write this

    assert(!linkedListIsEmpty(list));
    removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
    // FIXME: you must write this

    if (list->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
    // FIXME: you must write this

    //create struct link pointer to cycle through list
    struct Link* currentLink = list->frontSentinel->next;

    while (currentLink != list->backSentinel)
    {
        printf("%d ", currentLink->value);
        currentLink = currentLink->next;
    }
    printf("\n");
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
    // FIXME: you must write this

    addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
    // FIXME: you must write this

    if (list->size == 0)
    {
        return 0;
    }

    //create struct link pointer to cycle through list
    struct Link* currentLink = list->frontSentinel->next;
    while (currentLink != list->backSentinel)
    {
        if (currentLink->value == value)
        {
            return 1;
        }

        //move to next link
        currentLink = currentLink->next;
    }
    //if value not found, return 0
    return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
    // FIXME: you must write this

    assert(linkedListContains(list, value));
    struct Link* currentLink = list->frontSentinel->next;

    while (currentLink != list->backSentinel)
    {
        if (currentLink->value == value)
        {
            removeLink(list, currentLink);
            return;
        }

        currentLink = currentLink->next;
    }
}

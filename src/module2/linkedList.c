#include "linkedList.h"
#include <stdlib.h>
#include "utility.h"

struct Node
{
  ElementType Element;
  Position Next;
}

/*
 * Make the list empty
 * We return the header node
 */
  
List MakeEmpty( List L )
{
  if( L != NULL )
  {
    DeleteList( L );
  }
  L = malloc(sizeof(struct Node));
  if ( L == NULL )
  {
    FatalError( "Out of memory!" );
  }
  L->Next = NULL;
  return L;
}

/*
 * Return true if L is empty 
 */

int IsEmpty( List L )
{
  return L->Next == NULL;
}

/*
 * Return true if P is the last position in list L
 */

int IsLast( Position P, List L )
{
  return P->next == NULL;
}

/*
 * Return Position of X in L; NULL if not found
 */

Position Find ( ElementType X, List L )
{
  Position P;

  P = L->Next;
  while( P != NULL && P->Element != X )
  {
    P = P->Next;
  }

  return P;
}

/*
 * Delete first occurrence of X from a list
 * Cell pointed to by P->Next is wiped out
 * Assume that the position is legal 
 * Assume use of a header node
 */

void Delete( ElementType X, List L)
{
  Position P, TmpCell;

  P = FindPrevious( X, L );

  if( !IsLast(P, L) )             /* Assumption of header use */
  {                               /* X is found; delete it    */
    TmpCell = P->Next;
    P->Next = TmpCell->Next;      /* Bypass deleted cell      */
    free( TmpCell );
  }
}

/*
 * If X is not found, then Next field of returned value is NULL
 * Assume a header
 */

Position FindPrevious( ElementType X, List L )
{
  Position P;

  P = L;

  while (P->Next != NULL && P->Next->Element != X)
  {
    P = P->Next;
  }

  return P;
}

/*
 * Insert (after leagal position P) *
 * Header implementation assumed
 * Parameter L is unused in this implementation
 */

void Insert( ElementType X, List L, Position P )
{
  Position TmpCell;

  TmpCell = malloc(sizeof( struct Node ));
  if ( TmpCell == NULL )
  {
    FatalError( "Out of space!!!" );
  }

  TmpCell->Next = P->Next;
  TmpCell->Element = X;
  P->Next = TmpCell;
}

/*
 * Delete the list
 */

void DeleteList( List L )
{
  Position P, TmpCell;

  P = L->Next;
  L->Next = NULL;
  
  while( P != NULL )
  {
    TmpCell = P->Next;
    free( P );
    P = TmpCell;
  }
}

/*
 * return the header node
 */

Position Header( List L )
{
  return L;
}

/*
 * return the first element of the list
 */

Position First( List L )
{
  return L->Next;
}

/*
 * return the next node of the given node P
 */

Position Advance( Position P )
{
  return P->Next;
}

/*
 * return the element in the node P
 */

ElementType Retrieve ( Position P )
{
  return P->Element;
}

#include <stdio.h>
#include <stdlib.h>

/************************
 * Macros
 ************************/

#define Error( Str )       FatalError( Str )
#define FatalError( Str )  fprintf( stderr, "%s\n", Str ), exit( 1 )


/************************
 * Utility Functions
 ************************/

/*
 * Contains utility functions used across all modules
 */

/*
 * return the max of three values
 */

int Max3( int A, int B, int C );

/*
 * return the exponentiation (raising an integer to a power)
 */

long int Pow( long int X, unsigned int N );

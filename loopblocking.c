// This c program will show that a tiled loop is faster than an un-tiled loop

#include <stdlib.h>
#include <stdio.h>

//time library
#include <time.h> 

#define MAX ( 1024*1024*32 ) //32MB 
#define REPLACE 100 
#define BLOCK ( 16*1024 )  // block size or cache size = 16KB

// declaring a fixed size array
char array[MAX];  

int main( void )
{
	
	// initialize variables
	int i,j,r;
	

	
	for( i = 0; i < MAX; i++ )
	{
		array[i] = 0; // initialize indexes to contain "0"
	
	}
	
	// to calculate time taken for tiled loop
	// shows the time taken to complete the above for loop
	clock_t t1 = clock();
	
	
	// tiled loop
	for( i = 0; i < MAX; i = i + BLOCK )
	{
		for( r = 0; r < REPLACE; r++ )
		{
			for( j = i; j < (i + BLOCK); j += 64  )
			{
				array[j] = r; 
			}
		}
	}
	
	
	// time elapsed to complete tiled loop
	clock_t t2 = clock();
	
	
	//un-tiled loop 
	for( r = 0; r < REPLACE; r++ )
	{
		for( i = 0; i < MAX; i += 64 )
		{
			array[i] = r; 

		
		}
	
	}
	
	//time elapsed to complete un-tiled loop
	clock_t t3 = clock();
	
	
	printf( "Time taken to initialize Array of size 32MB: %f s\n", (double)(t1)/CLOCKS_PER_SEC );
	
	printf( "Time taken for Optimized Loop (Tiled Loop): %f s\n", (double)(t2 - t1)/CLOCKS_PER_SEC );
	
	printf( "Time taken for Untiled Loop: %f s\n", (double)(t3 - t2)/CLOCKS_PER_SEC );
	
	printf( "array[0] = %d \n", array[0] ); //shows array[0] = 99;
	
	
	
	


}



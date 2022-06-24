// test prime program

#include <stdio.h>
#include "checkprime.c"
int main()
{
	printf(isPrime(-100) == 0 ? "Passed.\n" : "Failed.\n");
	(isPrime(2) != 0) ? (printf("Passed.\n")) : printf("Failed.\n");
	printf(isPrime(40) == 0 ? "Passed.\n" : "Failed.\n");
	(isPrime(55) == 0) ? (printf("Passed.\n")) : printf("Failed.\n");
	printf(isPrime(97) != 0 ? "Passed.\n" : "Failed.\n");
}
#include <stdio.h>

#define _EXECUTE_


// main
int main (void) {
	
	#ifndef _DEBUG_

		#define MES "Good morning\n"
		printf(MES);

		#undef MES
		#define MES "Good afternoon\n"
		printf(MES);

		#undef MES
		#define MES "Good evening\n"
		printf(MES);

	#endif


	#ifdef _DEBUG_
		printf("[program finished with exit code 0]\n");
	#endif

	return 0;
}

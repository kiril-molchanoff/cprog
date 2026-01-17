#include <stdio.h>

int main (void) {

	printf("Compiler: ");
	#ifdef __GNUC__
		puts("GCC compiler");
	#elif __clang__
		puts("Clang compiler");
	#else
		puts("*undefined*");
	#endif


	printf("Architecture: ");
	#ifdef __x86_64__
    	puts("Intel x86 64bit");
	#elif __i386__
    	puts("Intel x86 32bit");
	#else
		puts("*undefined*");
	#endif


	printf("OS: ");
	#ifdef __linux__
		puts("Linux");
	#elif __WINDOWS__
		puts("Windows");
	#else
		puts("*undefined*");
	#endif


	return 0;
}

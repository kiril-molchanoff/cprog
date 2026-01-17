#include <stddef.h>
#include <stdint.h>


extern void set_region (const char*);
extern const char* get_region (void);


void print_region() {
	printf("region: [%s]\n", get_region());
}

int main (void) {
	
	print_region();
	set_region("Slovakia");
	print_region();


	return 0;
}

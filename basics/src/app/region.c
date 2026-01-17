#include <stddef.h>


static const char* region = "Czechia";


// set 
void set_region (const char* new_region) 
	{ region = new_region; }

// get
const char* get_region (void) 
	{ return region; }

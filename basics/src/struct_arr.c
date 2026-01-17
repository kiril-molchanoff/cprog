#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


/******** PERSON ********/


//---- STRUCTS ----//


struct Company {
	int id;
	const char *name;
	const char *country;
};

struct Person {
	const char *name;
	int age;
	struct Company company;
};



//---- METHODS ----//


struct Company Company_Create (
	int id,
	const char name[],
	const char country[]
) {
	struct Company company;
	company.id = id;
	company.name = name;
	company.country = country;
	return company;
}


struct Person Person_Create (
	int age,
	const char name[],
	struct Company company
) {
	struct Person person;
	person.age = age;
	person.name = name;
	person.company = company;
	return person;
}




void Company_Display (const struct Company *company) {
	printf("Company:\n");
	printf("  id: %d\n", company->id);
	printf("  name: %s\n", company->name);
	printf("  country: %s\n", company->country);
}

void Person_Display (const struct Person *person) {
	printf("Person:\n");
	printf("  age: %d\n", person->age);
	printf("  name: %s\n", person->name);
	Company_Display(&person->company);
}



// M.A.I.N //

int main (void) {

	struct Person arr[] = {
		Person_Create(
			19,
			"John",
			Company_Create(
				1234,
				"Toyota",
				"Japan"
			)
		),
		Person_Create(
			43,
			"Bob",
			Company_Create(
				7830,
				"Motorolla",
				"USA"
			)
		),

	};
	
	const size_t n = sizeof(arr) / sizeof(*arr);


	for (size_t i = 0; i < n; ++i) {
		printf("\n[%zu]\n", i);
		Person_Display(arr + i);
	}


	return EXIT_SUCCESS;
}


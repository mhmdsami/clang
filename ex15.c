#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = { 33, 22, 45, 23, 19 };
	char *names[] = {
		"John", "Mike", "Will",
		"Harry", "Frank" };

	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	// using index
	for (i = 0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	// set pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// pointers are array :)
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// using pointers in a "stupid" way
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	return 0;
}

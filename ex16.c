#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char * argv[])
{
	struct Person *will = Person_create("William Who", 21, 167, 58);
	struct Person *john = Person_create("Johnathan", 25, 178, 63);
	printf("Will is at memory location %p:\n", will);
	Person_print(will);
	
	printf("John is at memory locaion %p:\n", john);
	Person_print(john);

	will->age += 20;
	will->height -= 2;
	will->weight += 10;
	Person_print(will);

	john->age += 20;
	john->weight -= 2;
	Person_print(john);

	Person_destroy(will);
	Person_destroy(john);
	return 0;
}

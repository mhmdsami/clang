#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

typedef int (*compare_cb) (int a, int b);

int *bubble_sort (int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));

	if (!target)
		die("Memory allcoation error.");

	memcpy(target, numbers, count * sizeof(int));
	
	for (i = 0; i < count; i++) {
		for (j = 0; j < count - 1; j++) {
			if (cmp(target[j], target[j + 1]) > 0) {
				temp = target[j + 1];
				target[j + 1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;

}

int ascending_order(int a, int b)
{
	return a - b;
}

int descending_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if (a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

void sort(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers, count, cmp);

	if (!sorted)
		die("Failed to sort");

	for (i = 0; i < count; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");

	free(sorted);
}

int main(int argc, char *argv[])
{
	if (argc < 2) 
		die("USAGE: pointers_to_function <argc> <count> <more than 2 numbers to sort>\n\t\t pointers_to_function 4 3 5 6 2");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));

	if (!numbers) die("Memory allocation error");

	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	sort(numbers, count, ascending_order);
	sort(numbers, count, descending_order);
	sort(numbers, count, strange_order);

	free(numbers);
}

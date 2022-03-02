#include <stdio.h>

int ViewList()
{
	char line[255];
	int size;
	
	FILE *fpointer = fopen("inventory.csv", "r");
	
	if (fgets(line, sizeof(line), fpointer) == NULL) {
		printf("Nothing to display");
	}
	else {
		printf("%s", line);
		
		while (fgets(line, sizeof(line), fpointer) != NULL) {
			printf("%s", line);
		}
	}
	fclose(fpointer);
}
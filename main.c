#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct process {
	int* resources;
	int arrivalTime;
	int executionTime;
};

void printArray(int* array, int length) {
	printf("\n");
	for(int i = 0; i < length; ++i) {
		printf("%i: %i\n", i, array[i]);
	}
}

int* getNumArray(int length);
int* getNumArrayFromInput(char* input, int count);

int main(int argc, char* args[]) {
	char inputResourceCount[BUFSIZ];
	char inputResourceNames[BUFSIZ];
	char inputResourceInstances[BUFSIZ];
	char inputProcessCount[BUFSIZ];
	
	int resourceCount;
	int* resourceInstances;
	int processCount;

	int resourceInstancesCount = 0;

	struct process* processes;

	printf("Number of different resource types: ");
	scanf("%[^\n]s", inputResourceCount);
	resourceCount = atoi(inputResourceCount);
	getchar();

	printf("Names of each resource type: ");
	scanf("%[^\n]s", inputResourceNames);
	getchar();

	printf("Number of instances of each resource type: ");
	scanf("%[^\n]s", inputResourceInstances);
//	resourceInstances = getNumArray(resourceCount);
	resourceInstances = getNumArrayFromInput(inputResourceInstances, resourceCount);
	printArray(resourceInstances, resourceCount);

	getchar();
	printf("Number of processes: ");
	scanf("%[^\n]s", inputProcessCount);
	processCount = atoi(inputProcessCount);

	printf("\nrc: %s\nrn: %s\nri: %s\npc: %s\n", inputResourceCount, inputResourceNames, inputResourceInstances, inputProcessCount);

	processes = malloc(sizeof(process) * processCount);
	char processInput[BUFSIZ];
	int processData[resourceCount + 2];
	for(int i = 0; i < processCount; ++i) {
		printf("Details of process %i:");
		scanf("%s[^\n]s", processInput);
		processData = getNumArrayFromInput(processInput, resourceCount + 2);
		processes[i]




	free(resourceInstances);
}

int* getNumArrayFromInput(char* input, int count) {
	int* numArray = malloc(sizeof(int) * count);
	char temp[BUFSIZ];
	int tempLen = 0;
	int current = 0;
	
	for(int i = 0; i < strlen(input); ++i) {
		if(isdigit(input[i])) {
			temp[tempLen] = input[i];
			tempLen++;
		} else if(isspace(input[i]) || iscntrl(input[i])) {
			if(tempLen != 0) {
				numArray[current] = atoi(temp);
				current++;
				tempLen = 0;
				memset(temp,0,sizeof(temp)); 
			}
		}
	}
	if(current <= count && tempLen != 0) {
		numArray[current] = atoi(temp);
	}

	return numArray;
}

int* getNumArray(int length) {
	int* array = malloc(length * sizeof(int));
	for(int i = 0; i < length; ++i) {
		scanf("%d", array+i);
	}
	return array;
}



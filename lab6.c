//Author: Mikel Garner
#include <stdio.h>

int search(int numbers[], int low, int high, int value)
{
        if(low > high){ //check if low is greater than high, making the array bounds invalid
            return -1;
        }
        else if(value > numbers[(low+high)/2]){ //check if the value is greater than the value at the mid index
            return search(numbers, low+1, high, value); //if so, increment low and call the function again
        }
        else if(value < numbers[(low+high)/2]){//check if the value is less than the value at the mid index
            return search(numbers, low, high-1, value); //if so, decrement high and call the function again
        }
        else if(value == numbers[(low+high)/2]){ //check if value equals the value at the mid index
            return (low+high)/2; //if so, return mid to indicate the index where the value was found
        }
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}

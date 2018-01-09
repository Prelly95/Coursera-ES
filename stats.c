/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Patrick Prell>
 * @date <08/01/2018>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {
	printf("\n\n");
	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
								114, 88,   45,  76, 123,  87,  25,  23,
								200, 122, 150, 90,   92,  87, 177, 244,
								201,   6,  12,  60,   8,   2,   5,  67,
								7,  87, 250, 230,  99,   3, 100,  90};

	quick_sort(test, 0, SIZE-1);
	print_array(test, SIZE, 4);
	print_statistics(test, SIZE);
	/* Statistics and Printing Functions Go Here */
	printf("\n\n");
}

/* Add other Implementation File Code Here */
void print_array(unsigned char* arrayPtr, int arraySize, int wrap) {

	int i;
	int j = wrap;

	for(i = 0; i < arraySize; i++)
	{
		if(0 < (j--)) {
			printf("%i,\t", arrayPtr[i]);
		}
		else {
			printf("\n");
			i--;
			j = wrap;
		}
	}
}

void print_statistics(unsigned char* arrayPtr, int arraySize) {

	unsigned char min	= find_minimum(arrayPtr, arraySize);
	unsigned char max	= find_maximum(arrayPtr, arraySize);
	float mean			= find_mean(arrayPtr, arraySize);
	float median		= find_median(arrayPtr, arraySize);

	printf("\n\n");
	printf("Minimum:\t%i\n",	min);
	printf("Maximum:\t%i\n",	max);
	printf("Mean:\t\t%.2f\n",	mean);
	printf("Median:\t\t%.2f\n",	median);
	printf("\n");

}

unsigned char find_minimum(unsigned char* arrayPtr, int arraySize) {

	unsigned char min = arrayPtr[0];
	int i;

	for(i = 0; i < arraySize; i++) {
		if(arrayPtr[i] < min) {
			min = arrayPtr[i];
		}
	}

	return min;
}

unsigned char find_maximum(unsigned char* arrayPtr, int arraySize) {

	unsigned char max = arrayPtr[0];
	int i;

	for(i = 0; i < arraySize; i++) {
		if(arrayPtr[i] > max) {
			max = arrayPtr[i];
		}
	}

	return max;
}

float find_median(unsigned char* arrayPtr, int arraySize) {

	float median;

	quick_sort(arrayPtr, 0, arraySize-1);
	if(arraySize%2 == 0) {
		median = ((float)arrayPtr[arraySize/2]+(float)arrayPtr[(arraySize/2)-1])/2;
	}
	else {
		median = arrayPtr[arraySize/2];
	}
	return median;
}

float find_mean(unsigned char* arrayPtr, int arraySize) {

	float sum = 0;
	int i;

	for(i = 0; i < arraySize; i++) {
		sum += arrayPtr[i];
	}

	return sum/arraySize;
}

void quick_sort(unsigned char* arrayPtr, int left, int right) {

	if(left >= right) {
		return;
	}

	unsigned char pivot;
	int index;

	pivot = arrayPtr[(left+right)/2];
	index = partition(arrayPtr, left, right, pivot);

	quick_sort(arrayPtr, left, index - 1);
	quick_sort(arrayPtr, index, right);

}

unsigned char partition(unsigned char* arrayPtr, int left, int right, int pivot) {
	while(left <= right) {
		while(arrayPtr[left] > pivot) {
		left++;
		}
		while(arrayPtr[right] < pivot) {
			right--;
		}
		if(left <= right) {
			swap(arrayPtr, left, right);
			left++;
			right--;
		}
	}
	return left;
}

void swap(unsigned char* arrayPtr, int left, int right) {

	unsigned char temp;

	temp = arrayPtr[left];
	arrayPtr[left] = arrayPtr[right];
	arrayPtr[right] = temp;
}
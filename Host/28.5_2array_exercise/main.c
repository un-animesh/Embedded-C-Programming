/*
 * main.c
 *
 *  Created on: 05-Nov-2026
 *      Author: animesh
 */

#include<stdio.h>
#include<stdint.h>

void display_array(uint32_t const *const array, uint32_t aSize);
void swap_arrays(uint32_t *array1,uint32_t *array2,uint32_t aSize1, uint32_t aSize2);

int main()
{
    uint32_t aSize1, aSize2;
    printf("Two Array Swapping Program\n");
    printf("Enter the length of Array_1:\n");
    scanf("%d",&aSize1);
    printf("Enter the length of Array_2:\n");
    scanf("%d",&aSize2);

    if((aSize1 <= 0) || (aSize2 <= 0))
    {
    	printf("Element should not be negative or Zero\n");
    	return 0;
    }

    uint32_t array1[aSize1];
    uint32_t array2[aSize2];

    for (uint32_t i = 0 ; i < aSize1 ; i ++)
    {
        printf("Enter array 1 element %d\n",i);
        scanf("%d",&array1[i]);
    }
    for (uint32_t i = 0 ; i < aSize2 ; i ++)
    {
        printf("Enter array 2 element %d\n",i);
        scanf("%d",&array2[i]);
    }

    printf("Contents of Array before swap\n");
    display_array(array1,aSize1);
    printf("\n");
    display_array(array2,aSize2);
    printf("\n");

    printf("Content of array after swap:\n");

    swap_arrays(array1, array2, aSize1, aSize2);

    display_array(array1,aSize1);
    printf("\n");
    display_array(array2,aSize2);
    printf("\n");

    return 0;
}

void display_array(uint32_t const *const array, uint32_t aSize)
	{
	for(uint32_t i = 0 ; i < aSize ; i ++){
			printf("%.4d\t",array[i]);
		}
	}

void swap_arrays(uint32_t *array1,uint32_t *array2,uint32_t aSize1, uint32_t aSize2)
{
	uint32_t len = aSize1 < aSize2 ? aSize1 : aSize2;
	for(uint32_t i = 0 ; i < len ; i ++){
		int32_t temp = array1[i];
		array1[i] = array2[i];
		array2[i] = temp;
	}
}







/*
 * main.c
 *
 *  Created on: 26-Oct-2026
 *      Author: animesh
 */

#include <stdio.h>
#include <stdint.h>

void wait_for_user_input();

struct carModel
{
		uint32_t carNumber;
		uint32_t carPrice;
		uint8_t carMaxSpeed;
		float carWeight;
};


int main(void){

	struct carModel const carBMW = {2021,15000,220,1330};  		//C89 method here the Order is Important
	printf("Size of struct carModel is: %lu\n\n", /*sizeof(carBMW)*/ sizeof(struct carModel));

	wait_for_user_input();
	return 0;
}

void wait_for_user_input(void)
{
	printf("Press Enter to Exit the application");
	while(getchar() != '\n');
}

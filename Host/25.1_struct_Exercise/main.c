/*
 * main.c
 *
 *  Created on: 26-Oct-2026
 *      Author: animesh
 *
 * Write a program to create a carModel structure discussed and create 2 variables of type carModel.
 * Initialize the variables with the below given data and then print them
 * a. 2021,15000,220,1330
 * b. 4031,35000,160,1900.96
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
	struct carModel carMustang = {.carWeight=1900.96, .carNumber=4031, .carMaxSpeed=160, .carPrice=35000};
															// C99 method Order is not Important
	printf("The details of car BWM is as follows:\n"
			"Car Number = %u \nCar Price = %u$ \nCar Maximum Speed =%u  \nCar Weight = %.2f\n\n"
			,carBMW.carNumber,carBMW.carPrice,carBMW.carMaxSpeed, carBMW.carWeight);

	carMustang.carMaxSpeed = 240; // It can be changed like this

	printf("The details of car Mustang is as follows:\n"
				"Car Number = %u \nCar Price = %u$ \nCar Maximum Speed =%u  \nCar Weight = %.2f\n\n"
				,carMustang.carNumber,carMustang.carPrice,carMustang.carMaxSpeed, carMustang.carWeight);

	wait_for_user_input();
	return 0;
}

void wait_for_user_input(void)
{
	printf("Press Enter to Exit the application");
	while(getchar() != '\n');
}

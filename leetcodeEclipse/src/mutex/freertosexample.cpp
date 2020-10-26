/*
 * freertosexample.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: rehanashraf
 */

#include<stdio.h>
typedef int xSemaphoreHandle;
int xSemaphoreCreateMutex(){return 0;}
void vSemaphoreCreateBinary(xSemaphoreHandle n){}
void vTaskDelay(int n){}
void xSemaphoreGive(xSemaphoreHandle n){}
int xSemaphoreTake(xSemaphoreHandle n, int m){return 1;}
#define portMAX_DELAY 10000000

xSemaphoreHandle gatekeeper = 0;
xSemaphoreHandle employee_signal = 0;

int freertosmain(void)
{
	gatekeeper = xSemaphoreCreateMutex();
	vSemaphoreCreateBinary(employee_signal);
	return 0;
}

void access_precious_resource()
{

}
void employee_task()
{

}

// Mutex Example
void user_1(void *p)
{
	while (1)
	{
		if (xSemaphoreTake(gatekeeper, 1000))
		{
			puts("User 1 got access");
			access_precious_resource();
			xSemaphoreGive(gatekeeper);
		}
		else
		{
			puts("User 1 failed to get the resource within 1 second");
		}
	}
	vTaskDelay(1000);
}

void user_2(void *p)
{
	while (1)
	{
		if (xSemaphoreTake(gatekeeper, 1000))
		{
			puts("User 2 got access");
			access_precious_resource();
			xSemaphoreGive(gatekeeper);
		}
		else
		{
			puts("User 2 failed to get the resource within 1 second");
		}
	}
	vTaskDelay(1000);
}

// Sempahore Example
void boos(void *p)
{
	while(1)
	{
		xSemaphoreGive(employee_signal);
		vTaskDelay(2000);
	}
}

void employee(void *p)
{
	while(1)
	{
		if (xSemaphoreTake(employee_signal, portMAX_DELAY))
			employee_task();
		puts("Employee Finished his task");
	}
}


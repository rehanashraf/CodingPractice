/*
 * freertosexample.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: rehanashraf
 */

#include<stdio.h>
typedef int xSemaphoreHandle;
int xSemaphoreCreateMutex(){return 0;}
void vSemaphoreCreateBinary(xSemaphoreHandle n){return;}
void vTaskDelay(int n){return;}
void xSemaphoreGive(xSemaphoreHandle n){}
int xSemaphoreTake(xSemaphoreHandle n, int m){return 1;}
void taskYIELD(){};
#define portMAX_DELAY 10000000

xSemaphoreHandle gatekeeper = 0;
xSemaphoreHandle employee_signal = 0;
xSemaphoreHandle xMutex = 0;

int freertosmain(void)
{
	gatekeeper = xSemaphoreCreateMutex();
	vSemaphoreCreateBinary(employee_signal);
	xMutex = xSemaphoreCreateMutex();
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


static void write_task_1(void *pvParameters);
static void write_task_2(void *pvParameters);

/*!
 * @brief Write Task 1 function
 */
static void write_task_1(void *pvParameters) {
	while (1) {
		xSemaphoreTake(xMutex, portMAX_DELAY);
		printf("Hello, this is the ");
		taskYIELD();
		printf("first task \r\n");
		xSemaphoreGive (xMutex);
		taskYIELD();
	}
}
/*!
 * @brief Write Task 2 function
 */
static void write_task_2(void *pvParameters) {
	while (1) {
		xSemaphoreTake(xMutex, portMAX_DELAY);
		printf("And now this is the ");
		taskYIELD();
		printf(" second task\r\n");
		xSemaphoreGive (xMutex);
		taskYIELD();
	}
}



#include <stdio.h>
#include "volatile.h"

typedef struct Sensor {
	int sensor_flag;
	int data;
} Sensor;


int optimized_sensor_test() {
	Sensor* sensor;

	while (!(sensor->sensor_flag)) {}  // Automatically optimized into : if (!(sensor->sensor_flag)) { while (1) {} }
	printf("%d", sensor->data);

}

int volatile_sensor_test() {
	volatile Sensor* sensor;

	while (!(sensor->sensor_flag)) {}
	printf("%d", sensor->data);

}
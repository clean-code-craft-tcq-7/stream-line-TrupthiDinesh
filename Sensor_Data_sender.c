#include "Sensor_Data_sender.h"

void generateSenderData(BatteryParameters *ptr_BatteryParam){
	for(int index = 0; index < NUM_OF_READINGS; index++){
		ptr_BatteryParam->temperature[index] = (rand()%(TEMP_MAX - TEMP_MIN + 1)) + TEMP_MIN;
		ptr_BatteryParam->soc[index] = (rand()%(SOC_MAX - SOC_MIN + 1)) + SOC_MIN;
	}
}

void displaySenderData(status *ptr_Status, BatteryParameters BatteryParam){
	*ptr_Status = NOT_OK;
	int index = 0;
	for(index = 0; index < NUM_OF_READINGS; index++){
		printf("%.f,%.f\n",BatteryParam.temperature[index],BatteryParam.soc[index]);
	}
	*ptr_Status = OK;
}

status sendBatteryParameters(void){
	BatteryParameters BatteryParam;
	status operationStatus = NOT_OK;
	//Generate data for Battery parameters and print to console
	generateSenderData(&BatteryParam);
	displaySenderData(&operationStatus, BatteryParam);
	return operationStatus;
}

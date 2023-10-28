#include "MODBUS-LUNA2000.h"

void update_modbus_registers_luna2000()
{
    //Updata for ModbusRTU Server for Luna2000
    handle_update_data_modbus30101();
    handle_update_data_modbus30159();
    handle_update_data_modbus30860();
    handle_update_data_modbus30877();
    handle_update_data_modbus31565();
    handle_update_data_modbus31590();
    handle_update_data_modbus32051(); //Battery related
    handle_update_data_modbus32081();
    handle_update_data_modbus32201();
    handle_update_data_modbus32231();
    handle_update_data_modbus32351();
    handle_update_data_modbus32381();
    handle_update_data_modbus32434();
    handle_update_data_modbus39500(); //Battery related
    handle_update_data_modbus40601(); //WRITE
    handle_update_data_modbus41001();
    handle_update_data_modbus41023(); //Length of read varies (broken CRC?)
    handle_update_data_modbus49009(); //WRITE
    handle_update_data_modbus49013(); //WRITE
}

void handle_update_data_modbus30101() {
  // Store the data into the array
  static uint16_t system_data[11];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  system_data[6] = 0;
  system_data[7] = 0;
  system_data[8] = 0;
  system_data[9] = 0;
  system_data[10] = 0;
  static uint16_t i = 101;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus30159() {
  // Store the data into the array
  static uint16_t system_data[7];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  system_data[6] = 0;
  static uint16_t i = 159;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus30860() {
  // Store the data into the array
  static uint16_t system_data[1];
  system_data[0] = 16;
  static uint16_t i = 860;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus30877() {
  // Store the data into the array
  static uint16_t system_data[1];
  system_data[0] = 0;
  static uint16_t i = 877;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus31565() {
  // Store the data into the array
  static uint16_t system_data[6];
  system_data[0] = 426;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  static uint16_t i = 1565;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus31590() {
  // Store the data into the array
  static uint16_t system_data[6];
  system_data[0] = 19541; //Values taken from 66%SOC
  system_data[1] = 20033;
  system_data[2] = 12848;
  system_data[3] = 12336;
  system_data[4] = 11573;
  system_data[5] = 19287;
  system_data[6] = 11587;
  system_data[7] = 12288;
  system_data[8] = 0;
  system_data[9] = 0;
  system_data[10] = 0;
  system_data[11] = 0;
  system_data[12] = 0;
  system_data[13] = 0;
  system_data[14] = 0;
  static uint16_t i = 1590;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus32051() {
  // Store the data into the array
  static uint16_t system_data[9];
  system_data[0] = 1;
  system_data[1] = 534;                 //Goes between 534-498 depending on SOC
  system_data[2] = 110;                 //Goes between 110- -107 [NOTE, SIGNED VALUE]
  system_data[3] = 0;                   //Goes between 0 and -1  [NOTE, SIGNED VALUE]
  system_data[4] = 616;                 //Goes between 616- -520 [NOTE, SIGNED VALUE]
  system_data[5] = temperature_max;     //Temperature max?
  system_data[6] = temperature_min;     //Temperature min?
  system_data[7] = (SOC/100);           //SOC 0-100%, no decimals 
  system_data[8] = 98;                  //Always 98 in logs
  static uint16_t i = 2051;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus32201() {
  // Store the data into the array
  static uint16_t system_data[9];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  system_data[6] = 0;
  system_data[7] = 0;
  system_data[8] = 0;
  static uint16_t i = 2201;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus32081() {
  // Store the data into the array
  static uint16_t system_data[27];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  system_data[6] = 0;
  system_data[7] = 0;
  system_data[8] = 0;
  system_data[9] = 0;
  system_data[10] = 0;
  system_data[11] = 0;
  system_data[12] = 0;
  system_data[13] = 0;
  system_data[14] = 0;
  system_data[15] = 0;
  system_data[16] = 0;
  system_data[17] = 0;
  system_data[18] = 0;
  system_data[19] = 0;
  system_data[20] = 0;
  system_data[21] = 0;
  system_data[22] = 0;
  system_data[23] = 0;
  system_data[24] = 0;
  system_data[25] = 0;
  system_data[26] = 0;
  system_data[27] = 0;
  static uint16_t i = 2081;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus32231() {
  // Store the data into the array
  static uint16_t system_data[27];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  system_data[6] = 0;
  system_data[7] = 0;
  system_data[8] = 0;
  system_data[9] = 0;
  system_data[10] = 0;
  system_data[11] = 0;
  system_data[12] = 0;
  system_data[13] = 0;
  system_data[14] = 0;
  system_data[15] = 0;
  system_data[16] = 0;
  system_data[17] = 0;
  system_data[18] = 0;
  system_data[19] = 0;
  system_data[20] = 0;
  system_data[21] = 0;
  system_data[22] = 0;
  system_data[23] = 0;
  system_data[24] = 0;
  system_data[25] = 0;
  system_data[26] = 0;
  system_data[27] = 0;
  static uint16_t i = 2231;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus32351() {
  // Store the data into the array
  static uint16_t system_data[9];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  system_data[6] = 0;
  system_data[7] = 0;
  system_data[8] = 0;
  static uint16_t i = 2351;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus32381() {
  // Store the data into the array
  static uint16_t system_data[27];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  system_data[5] = 0;
  system_data[6] = 0;
  system_data[7] = 0;
  system_data[8] = 0;
  system_data[9] = 0;
  system_data[10] = 0;
  system_data[11] = 0;
  system_data[12] = 0;
  system_data[13] = 0;
  system_data[14] = 0;
  system_data[15] = 0;
  system_data[16] = 0;
  system_data[17] = 0;
  system_data[18] = 0;
  system_data[19] = 0;
  system_data[20] = 0;
  system_data[21] = 0;
  system_data[22] = 0;
  system_data[23] = 0;
  system_data[24] = 0;
  system_data[25] = 0;
  system_data[26] = 0;
  system_data[27] = 0;
  static uint16_t i = 2381;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus32434() {
  // Store the data into the array
  static uint16_t system_data[1];
  system_data[0] = 0;
  static uint16_t i = 2434;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus39500() {
  // Store the data into the array
  static uint16_t system_data[26];
  system_data[0] = 0;
  system_data[1] = capacity_Wh_startup; //Capacity? 5000 with 5kWh battery
  system_data[2] = 0;
  system_data[3] = capacity_Wh_startup; //Capacity? 5000 with 5kWh battery
  system_data[4] = 0;       
  system_data[5] = 2500;                //Rated_Charge_Power???
  system_data[6] = 0;
  system_data[7] = 2500;                //Rated_Discharge_Power???
  system_data[8] = (SOC/100);           //SOC 0-100%, no decimals 
  system_data[9] = 1;                   //Running status, equiv to register 37762, 0 = Offline, 1 = Standby,2 = Running, 3 = Fault, 4 = sleep mode
  system_data[10] = battery_voltage;    //Battery bus voltage (766.5V = 7665)
  system_data[11] = 9;                  //TODO, GOES LOWER WITH LOW SOC
  system_data[12] = 0;                
  system_data[13] = 699;                //TODO, GOES LOWER WITH LOW SOC
  system_data[14] = 1;                  //Always 1 in logs
  system_data[15] = 18;                 //Always 18 in logs
  system_data[16] = 8066;               //TODO, GOES HIGHER WITH LOW SOC (max allowed charge W?)
  system_data[17] = 17;       
  system_data[18] = 44027;              //TODO, GOES LOWER WITH LOW SOC
  system_data[19] = 0;
  system_data[20] = 435;                //Always 435 in logs
  system_data[21] = 0;
  system_data[22] = 0;
  system_data[23] = 0;
  system_data[24] = (SOC/10);           //SOC 0-100.0%, 1x decimal 
  system_data[25] = 0;
  system_data[26] = 1;                  //Always 1 in logs
  static uint16_t i = 9500;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus40601() {
  // Store the data into the array
  static uint16_t system_data[6];
  system_data[0] = 0;
  system_data[1] = 100;
  system_data[2] = 0;
  system_data[3] = 2500;
  system_data[4] = 7650;
  system_data[5] = 7650;
  static uint16_t i = 10601;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus41001() {
  // Store the data into the array
  static uint16_t system_data[5];
  system_data[0] = 14445; //Values are same at high/low SOC
  system_data[1] = 17280; //Values are same at high/low SOC
  system_data[2] = 0;     //Values are same at high/low SOC
  system_data[3] = 18;    //Values are same at high/low SOC
  system_data[4] = 1;     //Values are same at high/low SOC
  static uint16_t i = 11001;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus41023() {
  // Store the data into the array
  static uint16_t system_data[5];
  system_data[0] = 0;
  system_data[1] = 0;
  system_data[2] = 0;
  system_data[3] = 0;
  system_data[4] = 0;
  static uint16_t i = 11023;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus49009() {
  // Store the data into the array
  static uint16_t system_data[1];
  system_data[0] = 8164;      //(goes between 8164 and 7500)
  static uint16_t i = 19009;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}

void handle_update_data_modbus49013() {
  // Store the data into the array
  static uint16_t system_data[2];
  system_data[0] = 1000;
  system_data[0] = 0;
  static uint16_t i = 19013;
  memcpy(&mbPV[i], system_data, sizeof(system_data));
}
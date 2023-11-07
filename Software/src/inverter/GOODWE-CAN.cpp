#include "GOODWE-CAN.h"
#include "../devboard/can/ESP32CAN.h"
#include "../lib/ThomasBarth-ESP32-CAN-Driver/CAN_config.h"

/* Do not change code below unless you are sure what you are doing */
static unsigned long previousMillis1s = 0; // will store last time a 2s CAN Message was send
static const int interval1s = 1000; // interval (ms) at which send CAN Messages

//Actual content messages
CAN_frame_t GOODWE_453 = {.FIR = {.B = {.DLC = 8,.FF = CAN_frame_std,}},.MsgID = 0x453,.data = {0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
CAN_frame_t GOODWE_455 = {.FIR = {.B = {.DLC = 8,.FF = CAN_frame_std,}},.MsgID = 0x455,.data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
CAN_frame_t GOODWE_456 = {.FIR = {.B = {.DLC = 8,.FF = CAN_frame_std,}},.MsgID = 0x456,.data = {0xF1, 0x0E, 0x64, 0x00, 0xFA, 0x00, 0x1D, 0x0C}};
CAN_frame_t GOODWE_457 = {.FIR = {.B = {.DLC = 8,.FF = CAN_frame_std,}},.MsgID = 0x457,.data = {0xC1, 0x1B, 0x34, 0x21, 0x00, 0x00, 0x00, 0x00}};
CAN_frame_t GOODWE_458 = {.FIR = {.B = {.DLC = 8,.FF = CAN_frame_std,}},.MsgID = 0x458,.data = {0x55, 0x0E, 0x00, 0x00, 0xC5, 0x00, 0x00, 0x00}};
CAN_frame_t GOODWE_45A = {.FIR = {.B = {.DLC = 8,.FF = CAN_frame_std,}},.MsgID = 0x45A,.data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
CAN_frame_t GOODWE_460 = {.FIR = {.B = {.DLC = 2,.FF = CAN_frame_std,}},.MsgID = 0x460,.data = {0x00, 0x00}};
CAN_frame_t GOODWE_425 = {.FIR = {.B = {.DLC = 8,.FF = CAN_frame_std,}},.MsgID = 0x425,.data = {0x55, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00}};

static int discharge_current = 0;
static int charge_current = 0;
static int temperature_average = 0;

static int inverter_voltage = 0;
static int inverter_current = 0;

void update_values_can_goodwe()
{ //This function maps all the values fetched from battery CAN to the correct CAN messages
  //Calculate values
  charge_current = ((max_target_charge_power*10)/max_volt_goodwe_can); //Charge power in W , max volt in V+1decimal (P=UI, solve for I)
  //The above calculation results in (30 000*10)/3700=81A
  charge_current = (charge_current*10); //Value needs a decimal before getting sent to inverter (81.0A)

  discharge_current = ((max_target_discharge_power*10)/max_volt_goodwe_can); //Charge power in W , max volt in V+1decimal (P=UI, solve for I)
  //The above calculation results in (30 000*10)/3700=81A
  discharge_current = (discharge_current*10); //Value needs a decimal before getting sent to inverter (81.0A)

  temperature_average = ((temperature_max + temperature_min)/2);
  
  //Map values to CAN messages
  //Charge voltage (eg 400.0V = 4000 , 16bits long)
  GOODWE_456.data.u8[0] = (max_volt_goodwe_can >> 8);
  GOODWE_456.data.u8[1] = (max_volt_goodwe_can & 0x00FF);
  //Maximum charge current allowed (Unit: A+1)
  GOODWE_456.data.u8[2] = (charge_current >> 8);
  GOODWE_456.data.u8[3] = (charge_current & 0x00FF);
  //Maximum discharge current allowed (Unit: A+1)
  GOODWE_456.data.u8[4] = (discharge_current >> 8);
  GOODWE_456.data.u8[5] = (discharge_current & 0x00FF);
  //Discharge voltage (eg 300.0V = 3000 , 16bits long)
  GOODWE_456.data.u8[6] = (min_volt_goodwe_can >> 8);
  GOODWE_456.data.u8[7] = (min_volt_goodwe_can & 0x00FF); 
  
  //SOC (100.00%)
  GOODWE_457.data.u8[0] = (SOC >> 8);
  GOODWE_457.data.u8[1] = (SOC & 0x00FF);
  //StateOfHealth (100.00%)
  GOODWE_457.data.u8[2] = (StateOfHealth >> 8);
  GOODWE_457.data.u8[3] = (StateOfHealth & 0x00FF);

  //Battery Voltage (ex 370.0)
  GOODWE_458.data.u8[0] = (battery_voltage >> 8);
  GOODWE_458.data.u8[1] = (battery_voltage & 0x00FF);
  //Current (ex 81.0A)
  GOODWE_458.data.u8[2] = (battery_current >> 8);
  GOODWE_458.data.u8[3] = (battery_current & 0x00FF);
  //Temperature average
  GOODWE_458.data.u8[4] = (temperature_average >> 8);
  GOODWE_458.data.u8[5] = (temperature_average & 0x00FF);
}

void receive_can_goodwe(CAN_frame_t rx_frame)
{
  switch (rx_frame.MsgID)
  {
    case 0x420: //Message originating from GW6000-EH. Indicates timeout
		//Todo, add USB debug message if this happens?
    break;
	case 0x425: //Inverter Vbat, Ibat
		//inverter_voltage = frame0 and frame 1
		//inverter_current = frame2 and frame 3
	break;
    default:
    break;
  }
}

void send_can_goodwe()
{
  unsigned long currentMillis = millis();

	// Send 1s CAN Message
	if (currentMillis - previousMillis1s >= interval1s)
	{
	  previousMillis1s = currentMillis;

	  ESP32Can.CANWriteFrame(&GOODWE_453);
	  ESP32Can.CANWriteFrame(&GOODWE_455);
	  ESP32Can.CANWriteFrame(&GOODWE_456);
	  ESP32Can.CANWriteFrame(&GOODWE_457);
	  ESP32Can.CANWriteFrame(&GOODWE_458);
	  ESP32Can.CANWriteFrame(&GOODWE_45A);
	  ESP32Can.CANWriteFrame(&GOODWE_460);
	}
}


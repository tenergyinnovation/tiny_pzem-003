/***********************************************************************
 * Project      :     tiny32_pzem003_resetEnergy
 * Description  :     Reset Engergy value to PZEM-003 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/04/2022
 * Revision     :     1.1
 * Rev1.0       :     Origital
 * Rev1.1       :     Add Relay On, Show Library version
 *                    Add PZEM_003_begin
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32.h>

tiny32 mcu; //define object

uint8_t id = 1; //Address if PZEM-003, You can change here if it differance

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem003_resetEnergy ****\r\n");
  mcu.PZEM_003_begin(RXD3,TXD3);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{

  if(mcu.PZEM_003_ResetEnergy(id)) //function return: true=success, false=unsuccess
  {
    Serial.printf("Info: Success reset engergy :)\r\n");
  }
  else
  {
    Serial.printf("Error: Can't reset engergy :)\r\n");
  }

  vTaskDelay(5000);

}
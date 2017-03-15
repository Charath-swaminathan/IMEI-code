/* 
 * AUTHOR : Charath  
 * DATE:  15/02/17
 *
 * CODE PURPOSE:  To extract the IMEI number of the sim card inserted in A6/A7 GSM modem
*/

/*    
      HARDWARE INTERFACE
      *****************************************************************************************************
      A6/A7 MODULE  |    UTXD          |  URXD          |  GND    | 5V  
                    |                  |                |         |
      MEGA 2560     |    RX_3 (PIN 15) |  TX_3 (PIN 14  |  GND    | 5V
      ******************************************************************************************************
*/

#include <SoftwareSerial.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);             
  Serial3.begin(9600);                      // Serial3 indicates GSM and its baud rate

  Serial.println("AT+CREG=1");                
  Serial3.println("AT+CREG=1");               // Instructs the gsm module to register the sim card in the respective network
  Serial.println(Serial3.readString());       

  Serial3.println("ATE0");                    // this disenable the ECHO from GSM  module ( 0 refers to disenable mode )
  Serial.println(Serial3.readString());

  Serial.println("AT+CREG?");                  
  Serial3.println("AT+CREG?");                // Checks the network registration of the sim card
  Serial.println(Serial3.readString());       // the normal response should be +CREG: 1,1  ( network registered and home network )
  
  Serial3.println("AT+CMGF=1");               // Instructs the gsm module to turn on the TEXT mode
  Serial.println("AT+CMGF=1");

  Serial.println(Serial3.readString());

  Serial3.println("AT+GSN");             // Instructs to read (2) the IMEI number of current sim card and  
  String imei_no = Serial3.readString();
  
  imei_no.remove(0,8);                        // removes the unwanted part of the string
  imei_no.remove(16,50);
  Serial.print("The IMEI number is "); Serial.println(imei_no);
    
}

void loop() {
  // put your main code here, to run repeatedly:

}

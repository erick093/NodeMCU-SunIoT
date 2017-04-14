#include <SoftwareSerial.h>
#define VOLTAGE_MAX 2.991
#define VOLTAGE_MAXCOUNTS 1001
//float voltage;
float Sensibilidad=0.03688;
void setup() {
  // put your setup code here, to run once:
  Serial.begin ( 115200 );

}
void loop() {
  
  float voltajeSensor =get_voltage(1000);//obtenemos voltaje del sensor(10000 muestras) 
  Serial.print("Corriente: ");
  Serial.println(voltajeSensor ,3);     
}
/*void loop() {
  // put your main code here, to run repeatedly:
  float sensorValue = analogRead(A0);
  Serial.print("Sensor Value(0-1023): ");
  Serial.println(sensorValue,5);
  voltage = (sensorValue-498) * (VOLTAGE_MAX / VOLTAGE_MAXCOUNTS);
  Serial.print("Voltage: ");
  Serial.println(voltage,5);
  float I=voltage/sensibilidad;
  Serial.print("Corriente: ");
  Serial.println(I,5);
  delay(500);
}
*/


float get_voltage(int n_muestras)
{
  float voltage=0;
  float corriente;
  
  for(int i=0;i<n_muestras;i++)
  {
    voltage =(analogRead(A0)-499) * (VOLTAGE_MAX/ VOLTAGE_MAXCOUNTS);    
    corriente=corriente+voltage/Sensibilidad;
  }
  Serial.println(analogRead(A0));
  corriente=corriente/n_muestras;
  return(corriente);
}

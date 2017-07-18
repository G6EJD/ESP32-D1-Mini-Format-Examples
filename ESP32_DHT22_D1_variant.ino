// DHT11 Temperature and Humidity Sensors Example
#include "DHT.h"         //include DHT library
#define DHTPIN 16        //define as DHTPIN the Pin 16 used to connect the Sensor
#define DHTTYPE DHT22    //define the sensor used(DHT11)
DHT dht(DHTPIN, DHTTYPE);//create an instance of DHT
/*setup*/
void setup() {
  Serial.begin(115200);    //initialize the Serial communication
  delay(6000);           //wait 6 seconds
  Serial.println("Temperature and Humidity test!");//print on Serial monitor
  Serial.println("T(C) \tH(%)");                   //print on Serial monitor
  dht.begin();           //initialize the Serial communication
}
/*loop*/
void loop() {
 
  float h = dht.readHumidity();    // reading Humidity 
  float t = dht.readTemperature(); // read Temperature as Celsius (the default)
  // check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print(t, 2);    //print the temperature
  Serial.print("\t");
  Serial.println(h, 2);  //print the humidity
  delay(2000);           //wait 2 seconds
}

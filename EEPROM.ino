#include <EEPROM.h>
int address = 0;
int value;
void setup()
{
 Serial.begin(9600);
}
void loop()
{
   String input="";
   input= Serial.readString();
   if(input.startsWith("write"))
   {
        address = input.substring(6,7).toInt();
        value = input.substring(8,input.length()).toInt();
        Serial.print("Write Address:");
        Serial.println(address);
        Serial.print("Data Write:");
        Serial.println(value);
        EEPROM.write(address, value);
        Serial.println("Written successfully");
    }
   else if(input.startsWith("read"))
   {
        address = input.substring(input.indexOf(' ') + 1).toInt();
        Serial.print("Read Address:");
        Serial.println(address);
        Serial.print("Data is:");
        Serial.println(EEPROM.read(address));
        Serial.println("Data read succesfully");
    }
   
}

/**
 * @file SerialReceiver.cpp
 * @author SilentInt
 * @brief 接受主控板上ESP01s通过串口发送的数据结构体
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(1, 2);
struct ConData
{
    char mac[18];
    double humid;
};
ConData mydata;
uint8_t cdata[sizeof(ConData)];
void setup()  
{
    Serial.begin(115200);
    mySerial.begin(115200);
}

void loop()
{
    mySerial.readBytes(cdata, sizeof(ConData));
    while (mySerial.read() >= 0)
    {
    }
    Serial0.print("Hello");
    memcpy(&mydata, cdata, sizeof(ConData));
    Serial.print("mac:");
    Serial.println(mydata.mac);
    Serial.print("humid:");
    Serial.println(mydata.humid);
    Serial.println("");
    delay(2000);
}
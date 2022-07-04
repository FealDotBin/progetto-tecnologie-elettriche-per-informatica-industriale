#include <OpenGarden.h>

#include <Wire.h>

DateTime myTime;
int flag = 0; // auxiliar variable

void setup() {
  Serial.begin(9600);
  OpenGarden.initSensors(); //Initialize sensors power
  OpenGarden.sensorPowerON(); //Turn On the sensors
  delay(500);
  OpenGarden.initRF();
  OpenGarden.initRTC();
  OpenGarden.initIrrigation(1); //Initialize irrigation 1
  OpenGarden.initIrrigation(2); //Initialize irrigation 2
  OpenGarden.initIrrigation(3); //Initialize irrigation 3
}

void loop() {
  myTime = OpenGarden.getTime();
  OpenGarden.receiveFromNode();
  int luminosity0 = OpenGarden.readLuminosity();

  //Get Node Sensors
  Payload node1Packet = OpenGarden.getNodeData(node1);
  Payload node2Packet = OpenGarden.getNodeData(node2);
  Payload node3Packet = OpenGarden.getNodeData(node3);

  int soilMoisture1 = node1Packet.moisture;
  float airTemperature1 = node1Packet.temperature;
  float airHumidity1 = node1Packet.humidity;
  int luminosity1 = node1Packet.light;
  int battery1 = node1Packet.supplyV;

  int soilMoisture2 = node2Packet.moisture;
  float airTemperature2 = node2Packet.temperature;
  float airHumidity2 = node2Packet.humidity;
  int luminosity2 = node2Packet.light;
  int battery2 = node2Packet.supplyV;

  int soilMoisture3 = node3Packet.moisture;
  float airTemperature3 = node3Packet.temperature;
  float airHumidity3 = node3Packet.humidity;
  int luminosity3 = node3Packet.light;
  int battery3 = node3Packet.supplyV;

  OpenGarden.printTime(myTime);
  Serial.println("*********");
  Serial.println("Node 1:");
  OpenGarden.printNode(node1Packet);
  Serial.println("*********");
  Serial.println("Node 2:");
  OpenGarden.printNode(node2Packet);
  Serial.println("*********");
  Serial.println("Node 3:");
  OpenGarden.printNode(node3Packet);
  Serial.println("*********");

  //NODO 1
  //MAG-GIU-LUG-AGO-SET
  if (myTime.month > 4 && myTime.month < 10) {
    if (soilMoisture1 < 350 && airTemperature1 > 14 && airTemperature1 < 29 && airHumidity1 < 50 &&
      luminosity0 > 40) {
      OpenGarden.irrigationON(1); //Turn ON the irrigation number 1 (insert 1,2 or 3)
      Serial.println("Irrigation 1: ON");
      delay(5000)
      OpenGarden.irrigationOFF(1); //Turn OFF the irrigation number 1 (insert 1,2 or 3)
      Serial.println("Irrigation 1: OFF");
    }
  }
  //GEN-FEB-MAR-APR-OTT-NOV-DIC
  if (myTime.month > 9 && myTime.month < 5) {
    if (myTime.day % 2 == 0) {

      if (soilMoisture1 < 250 && airTemperature1 > 15 && airHumidity1 < 50 && luminosity0 > 40) {
        OpenGarden.irrigationON(1); //Turn ON the irrigation number 1 (insert 1,2 or 3)
        Serial.println("Irrigation 1: ON");
        delay(5000)
        OpenGarden.irrigationOFF(1); //Turn OFF the irrigation number 1 (insert 1,2 or 3)
        Serial.println("Irrigation 1: OFF");
      }
    }
  }

  //NODO 2
  if (myTime.month > 4 && myTime.month < 10) {
    if (soilMoisture2 < 350 && airTemperature2 > 14 && airTemperature2 < 29 && airHumidity2 < 50 && luminosity0 > 40) {
      OpenGarden.irrigationON(2); //Turn ON the irrigation number 1 (insert 1,2 or 3)
      Serial.println("Irrigation 1: ON");
      delay(5000)
      OpenGarden.irrigationOFF(2); //Turn OFF the irrigation number 1 (insert 1,2 or 3)
      Serial.println("Irrigation 1: OFF");
    }
  }

  if (myTime.month > 9 && myTime.month < 5) {
    if (myTime.day % 2 == 0) {

      if (soilMoisture2 < 250 && airTemperature2 > 15 && airHumidity2 < 50 && luminosity0 > 40) {
        OpenGarden.irrigationON(2); //Turn ON the irrigation number 1 (insert 1,2 or 3)
        Serial.println("Irrigation 1: ON");
        delay(5000)
        OpenGarden.irrigationOFF(2); //Turn OFF the irrigation number 1 (insert 1,2 or 3)
        Serial.println("Irrigation 1: OFF");
      }
    }
  }
  //NODO 3
  if (myTime.month > 4 && myTime.month < 10) {
    if (soilMoisture3 < 350 && airTemperature3 > 14 && airTemperature3 < 29 && airHumidity3 < 50 && luminosity0 > 40) {
      OpenGarden.irrigationON(3); //Turn ON the irrigation number 1 (insert 1,2 or 3)
      Serial.println("Irrigation 1: ON");
      delay(5000)
      OpenGarden.irrigationOFF(3); //Turn OFF the irrigation number 1 (insert 1,2 or 3)
      Serial.println("Irrigation 1: OFF");
    }
  }

  if (myTime.month > 9 && myTime.month < 5) {
    if (myTime.day % 2 == 0) {

      if (soilMoisture3 < 250 && airTemperature3 > 15 && airHumidity3 < 50 && luminosity0 > 40) {
        OpenGarden.irrigationON(3); //Turn ON the irrigation number 1 (insert 1,2 or 3)
        Serial.println("Irrigation 1: ON");
        delay(5000)
        OpenGarden.irrigationOFF(3); //Turn OFF the irrigation number 1 (insert 1,2 or 3)
        Serial.println("Irrigation 1: OFF");
      }
    }
  }

  delay(60000);
}
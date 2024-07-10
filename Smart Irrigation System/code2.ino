// #include <Adafruit_BMP280.h>
#include <SFE_BMP180.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3wWv6VFvh"
#define BLYNK_TEMPLATE_NAME "Smart Irrigation"
#define BLYNK_AUTH_TOKEN "m9yQSLYz4Y9YN4vYy6boSN3M0Rnaz0At"
#include <BlynkSimpleEsp8266.h>

const int soilMoisturePin = A0;
const int relay = D5; // gpio pin 16 = D0
const int rainfallPin = D4;
const int dhtPin = D3;

DHT dht(dhtPin, DHT11);
SFE_BMP180 bmp;
double T, P;
char status;
// WiFiClient client;

char auth[] = BLYNK_AUTH_TOKEN;
String wApiKey = "";      //  Enter your Write API key from ThingSpeak
const char *rApiKey = ""; //  Enter your Write API key from ThingSpeak
const long channelId = 2316440;

const char *ssid = "Disconnected"; // replace with your wifi ssid and wpa2 key
const char *pass = "12345678";

int pump = 0;
int r = 0;
int soilmoisture = 0;
float h = 0;
float t = 0;

BLYNK_WRITE(V0)
{
  t = param.asFloat();
}
BLYNK_WRITE(V1)
{
  h = param.asFloat();
}
BLYNK_WRITE(V2)
{
  P = param.asDouble();
}
BLYNK_WRITE(V3)
{
  r = param.asInt();
}
BLYNK_WRITE(V4)
{
  pump = param.asInt();
}

void setup()
{
  pinMode(relay, OUTPUT);
  Serial.begin(115200);
  delay(10);
  bmp.begin();
  Wire.begin();
  dht.begin();
  WiFi.begin(ssid, pass);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop()
{
  // BMP180 sensor
  status = bmp.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = bmp.getTemperature(T);

    status = bmp.startPressure(3); // 0 to 3
    if (status != 0)
    {
      delay(status);
      status = bmp.getPressure(P, T);
      if (status != 0)
      {
      }
    }
  }

  // DHT11 sensor
  h = dht.readHumidity();
  t = dht.readTemperature();

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    delay(1000);
    return;
  }

  // Rain sensor
  r = digitalRead(rainfallPin);
  r = !r;

  // moisture sensor
  soilmoisture = analogRead(soilMoisturePin);
  soilmoisture = map(soilmoisture, 0, 1023, 100, 0);

  if (soilmoisture < 25 || pump == 1 || !rain)
  {
    digitalWrite(relay, 1);
    Blynk.virtualWrite(V4, 1);
  }
  else
  {
    digitalWrite(relay, 0);
    Blynk.virtualWrite(V4, 0);
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("*C");
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Pressure: ");
  Serial.print(P, 2);
  Serial.println("mb");
  Serial.print("Rain: ");
  Serial.println(r);
  Serial.print("Soil Moisture: ");
  Serial.println(soilmoisture);
  Serial.println("\n");

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  P = P / 1000;
  Blynk.virtualWrite(V2, P);
  Blynk.virtualWrite(V3, r);

  delay(3000);
}
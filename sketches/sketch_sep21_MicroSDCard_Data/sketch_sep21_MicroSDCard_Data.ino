/* 
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 */

#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <SD.h>

RTC_DS3231 rtc;
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

File dataFile;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  dht.begin();
  
  // Inicialize o cartão microSD - Rótulos da coleta de dados
  if (SD.begin(4)) {
    Serial.println("Cartão SD inicializado com sucesso!");
    dataFile = SD.open("dados.txt", FILE_WRITE);
    if (dataFile) {
      dataFile.print("Data");
      dataFile.print(", ");
      dataFile.print("Temperatura °C");
      dataFile.print(", ");
      dataFile.println("Humidade %");
      dataFile.close();
    } else {
      Serial.println("Erro ao abrir o arquivo!");
    }
  } else {
    Serial.println("Falha ao inicializar o cartão SD!");
  }
  delay(5000); // Aguarda 5 segundos antes de gravar novamente
}

void loop() {
  // Lê a temperatura e umidade
  double temperature = dht.readTemperature();
  double humidity = dht.readHumidity();

  // Abre o arquivo para adicionar os dados
  dataFile = SD.open("dados.txt", FILE_WRITE);
  if (dataFile) {
    DateTime now = rtc.now();
    dataFile.print(now.day(), DEC);
    dataFile.print('/');
    dataFile.print(now.month(), DEC);
    dataFile.print('/');
    dataFile.print(now.year(), DEC);
    dataFile.print(' ');
    dataFile.print(now.hour() < 10 ? "0" : ""); // Adiciona um zero à esquerda se a hora for menor que 10
    dataFile.print(now.hour(), DEC); // Exibe a hora no formato de 24 horas
    dataFile.print(':');
    dataFile.print(now.minute() < 10 ? "0" : ""); // Adiciona um zero à esquerda se os minutos forem menores que 10
    dataFile.print(now.minute(), DEC);
    dataFile.print(':');
    dataFile.print(now.second() < 10 ? "0" : ""); // Adiciona um zero à esquerda se os segundos forem menores que 10
    dataFile.print(now.second(), DEC);
    dataFile.print(", ");
    dataFile.print(temperature);
    dataFile.print(", ");
    dataFile.println(humidity);
    dataFile.close();
    Serial.println("Dados gravados com sucesso!");
  } else {
    Serial.println("Erro ao abrir o arquivo!");
  }
  delay(60000); // Aguarda 1 minuto antes de gravar novamente
}
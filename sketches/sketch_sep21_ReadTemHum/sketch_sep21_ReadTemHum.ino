#include <DHT.h>

#define DHTPIN 2  // Pino de dados do DHT11 conectado ao pino 2 do Arduino
#define DHTTYPE DHT11  // Tipo do sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Aguarda 2 segundos entre leituras

  float temperatura = dht.readTemperature();  // Lê a temperatura em Celsius
  float umidade = dht.readHumidity();  // Lê a umidade relativa

  // Verifica se a leitura foi bem-sucedida
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler o sensor DHT!");
    return;
  }

  Serial.print(temperatura);
  Serial.print(", ");
  Serial.println(umidade);
}
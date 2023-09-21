#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  // Se você deseja definir a hora e a data manualmente, descomente a linha abaixo
  // e insira a data e a hora desejadas no formato: ano, mês, dia, hora, minuto, segundo
  // rtc.adjust(DateTime(ano, mês, dia, hora, minuto, segundo));
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');

    // Verifique se a entrada começa com 'S' para definir a hora e a data
    if (input.startsWith("S")) {
      input = input.substring(1); // Remova o 'S' da entrada
      
      // A entrada deve estar no formato "ano, mês, dia, hora, minuto, segundo"
      int ano, mes, dia, hora, minuto, segundo;
      sscanf(input.c_str(), "%d,%d,%d,%d,%d,%d", &ano, &mes, &dia, &hora, &minuto, &segundo);

      // Defina a hora e a data no RTC
      rtc.adjust(DateTime(ano, mes, dia, hora, minuto, segundo));
      Serial.println("Hora e data ajustadas com sucesso!");
    }
  }

  // Exiba a hora atual no monitor serial
  DateTime now = rtc.now();
  Serial.print("Data e hora atuais: ");
  Serial.print(now.year());
  Serial.print("-");
  Serial.print(now.month());
  Serial.print("-");
  Serial.print(now.day());
  Serial.print(" ");
  Serial.print(now.hour() < 10 ? "0" : ""); // Adiciona um zero à esquerda se a hora for menor que 10
  Serial.print(now.hour()); // Exibe a hora no formato de 24 horas
  Serial.print(":");
  Serial.print(now.minute() < 10 ? "0" : ""); // Adiciona um zero à esquerda se os minutos forem menores que 10
  Serial.print(now.minute());
  Serial.print(":");
  Serial.print(now.second() < 10 ? "0" : ""); // Adiciona um zero à esquerda se os segundos forem menores que 10
  Serial.println(now.second());


  delay(1000);
}
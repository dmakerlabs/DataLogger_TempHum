Usando um **módulo microSD** para armazenamento de dados e precisa registrar a data e a hora com precisão, é importante considerar o uso de baterias ou módulos com baterias para manter o relógio em tempo real (**RTC** - Real-Time Clock) funcionando mesmo quando o dispositivo estiver desligado. Aqui estão algumas opções para implementar isso:

1. **# Módulo RTC Integrado:** o Arduino, tem uma tolerância pior do que os módulos RTC, e ainda está sugeito às variações de tensão e temperatura. Não recomendado!

2. **# Módulo RTC Externo:** Adicionar um módulo RTC externo, como o DS3231 (**Módulo RTC DS3231**). Esses módulos também são alimentados por baterias e oferecem alta precisão na manutenção da data e hora.

**Fator:**
- Ser preciso na marcação do tempo.
- Manter o tempo salvo mesmo quando o sistema estiver desligado.

**A escolha:**
1. **Módulo RTC DS3231** O DS3231 é um RTC de alta precisão e baixo consumo de energia. O módulo possui um sensor de temperatura de fábrica e também um oscilador para melhorar ainda mais a sua exatidão. Funciona tanto no formato 12 horas como 24 horas, e as informações de meses com menos de 30/31 dias e anos bissextos são corrigidos automaticamente pelo módulo.


# **Datasheet**
[**Módulo RTC DS3231**](https://www.analog.com/media/en/technical-documentation/data-sheets/ds3231.pdf)
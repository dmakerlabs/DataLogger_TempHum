# Instruções de Configuração

Este documento fornece instruções detalhadas sobre como configurar o hardware e software do Data Logger de Temperatura e Humidade do Ambiente.

## Hardware

Para configurar o hardware necessário para o projeto, siga estas etapas:

1. **Montagem do Sensor:** Conecte o sensor de temperatura e umidade ao seu dispositivo de medição de acordo com as instruções do fabricante.

2. **Alimentação:** Certifique-se de que o sensor esteja devidamente alimentado. Verifique a voltagem e a corrente de acordo com as especificações do sensor.

3. **Conexão com o Dispositivo:** Conecte o sensor ao dispositivo que executará o software do Data Logger. Isso pode ser feito por meio de uma porta USB, conexão sem fio ou outro meio de comunicação suportado.

## Software

A configuração do software envolve a instalação e configuração do aplicativo Data Logger. Siga estas etapas:

1. **Clonagem do Repositório:** Clone este repositório em sua máquina local usando o seguinte comando:

git clone https://github.com/dmakerlabs/DataLogger_TempHum.git


2. **Instalação das Dependências:** Navegue até o diretório do projeto e instale as dependências necessárias usando o seguinte comando:

npm install

Certifique-se de que o Node.js e o npm estejam instalados em seu sistema.

3. **Configuração:** Edite o arquivo de configuração (`config.json` ou outro arquivo relevante) para definir as configurações específicas do sensor, como portas, taxas de amostragem e outras opções relevantes.

4. **Início do Aplicativo:** Execute o aplicativo com o seguinte comando:

npm start


O aplicativo Data Logger agora estará funcionando e registrando dados de temperatura e umidade do ambiente.

## Teste

Para verificar se a configuração foi feita corretamente, siga estas etapas:

1. Monitore os dados de temperatura e umidade na interface do aplicativo.
2. Certifique-se de que os valores exibidos estão dentro das faixas esperadas.
3. Realize testes adicionais, se necessário, para garantir a precisão da medição.

Isso completa o processo de configuração do Data Logger de Temperatura e Humidade do Ambiente. Você agora está pronto para usar o projeto.

Se você tiver problemas de configuração ou dúvidas adicionais, consulte a seção de Contato no arquivo README ou entre em contato com a equipe de suporte.
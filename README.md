# Detector de presença com transmissão de alerta via Wi-Fi

Projeto desenvolvido para a disciplina Objetos Inteligentes Conectados do 5º semestre do curso de Tecnologia em Análise e Desenvolvimento de Sistemas da Universidade Presbiteriana Mackenzie.

## Introdução e Objetivos

<p>A internet das coisas têm diversos campos de aplicação que vão desde aplicações nas indústrias da saúde, agricultura até a  automação de casas, por exemplo. No que concerne a indústria de automação de casas, o conceito de IoT pode ser aplicado para transformar as casas em ambientes mais inteligentes e seguros. Casas inteligentes são aquelas onde os eletrodomésticos e outros aparelhos domésticos podem ser controlados e monitorados. Dessa forma, o conceito de IoT vem para possibilitar a automação desses dispositivos de forma eficiente e conveniente, permitindo a construção de ambientes residenciais mais confortáveis e seguros. </p>
<p>O presente trabalho propõe a criação de um dispositivo de automação domiciliar cujo objetivo é monitorar a presença de indivíduos através de um sensor de movimento. O monitoramento dispara um alarme sonoro através de um buzzer e envia uma notificação por wi-fi via protocolo MQTT.</p>

## Materiais e Métodos

<p> Para a construção do dispositivo IoT, foram utilizados os seguintes materiais:</p>

* Módulo de desenvolvimento ESP32-WROOM-32
* Sensor de presença HC-SR501 PIR
* Buzzer ativo
* Jumpers
* Cabo micro usb
* Protoboard

## Instruções para Reprodução

<p>Primeiramente, é necessário fazer a conexão entre a placa ESP32 , o sensor PIR e o buzzer. A placa de desenvolvimento será alimentada pela USB(5V) e o pino “Vin” irá alimentar o módulo HC-SR501 e sua saída será ligada ao pino 27 da placa.   Para o buzzer, o pino positivo será ligado ao pino D18 da placa e o pino negativo do buzzer é ligado ao ground da placa.</p>
<p> Em seguida, é feita a instalação da Arduíno IDE e do plugin da ESP32.</p>
<p>Para que seja possível o envio dos dados por wi-fi, será utilizado o protocolo MQTT. Para utilizar o MQTT, primeiramente é necessário instalar a biblioteca PubSubClient. Um cliente MQTT com ESP32 deve ser criado para publicar leituras de sensores e subscrever diferentes tópicos. Foi utilizado HiveMQ, mas outros brokers podem ser utilizados. O objetivo é criar um cliente MQTT que será capaz de se inscrever em tópicos MQTT e publicar leituras de sensores em tópicos MQTT.5 Será usada a biblioteca PubSubClient para conectar a placa de desenvolvimento ESP32 com o broker via MQTT. Na página do Broker são criados os tópicos com os nomes que foram incluídos no código.</p>
<p> O código para funcionamento está disponível nesse repositório. </p>







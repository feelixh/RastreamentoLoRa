// Comunicação LoRa com Arduino 
// Definicao das bibliotecas a serem utilizadas no projeto
#include <SPI.h>             
#include <LoRa.h>
#include <HardwareSerial.h>
#include<TinyGPS.h> 
#include <TinyGPS++.h>
#include <AES.h>

#define RXD 16
#define TXD 17
int porta = 15;

TinyGPS GPS;  
TinyGPSPlus gps;   

float lat, lon, vel;
unsigned long data, hora;
unsigned short sat;

// Definicacao de constantes
const int csPin = 5;         // Chip Select (Slave Select do protocolo SPI) do modulo Lora
const int resetPin = 0;       // Reset do modulo LoRa
const int irqPin = 4;         // Pino DI0
 
String outgoing;              // outgoing message
 
<<<<<<< Updated upstream
byte localAddress = 0xCC;     // Endereco deste dispositivo LoRa
=======
byte localAddress = 0xFF;     // Endereco deste dispositivo LoRa
>>>>>>> Stashed changes
byte msgCount = 0;            // Contador de mensagens enviadas
byte destination = 0xBB;      // Endereco do dispositivo para enviar a mensagem (0xFF envia para todos devices)
long lastSendTime = 0;        // TimeStamp da ultima mensagem enviada
int interval = 5000;          // Intervalo em ms no envio das mensagens (inicial 5s)


AES aes;//Cria a classe aes.
byte key[16], out[16], inp[32];//Cria arrays (vetores) para a chave, input e output de dados.
const char pass[] = "abc";//Define a chave usada, neste exemplo usamos AES128, então precisa ser <= 16 Bytes.
 
void enc128(const char txt[], bool db);

void setup() {

//In the set-up function
Serial.begin(115200);
Serial2.begin(9600 ,SERIAL_8N1, RXD, TXD);
<<<<<<< Updated upstream

Serial.println(" Comunicacao LoRa Duplex - Ping&Pong ");
 
  // override the default CS, reset, and IRQ pins (optional)
  LoRa.setPins(csPin, resetPin, irqPin);// set CS, reset, IRQ pin
 
  // Inicializa o radio LoRa em 915MHz e checa se esta ok!
  if (!LoRa.begin(915E6)){             
    Serial.println(" Erro ao iniciar modulo LoRa. Verifique a coenxao dos seus pinos!! ");
    while (true);                      
  }
 
  Serial.println(" Modulo LoRa iniciado com sucesso!!!");
  Serial.println("Setup Completado!");


//enc128("vida de silicio", 1);//Faz a função de encriptação e retorna o HEX encriptado.


=======
>>>>>>> Stashed changes

Serial.println(" Comunicacao LoRa Duplex - Ping&Pong ");
 
  // override the default CS, reset, and IRQ pins (optional)
  LoRa.setPins(csPin, resetPin, irqPin);// set CS, reset, IRQ pin
 
  // Inicializa o radio LoRa em 915MHz e checa se esta ok!
  if (!LoRa.begin(915E6)){             
    Serial.println(" Erro ao iniciar modulo LoRa. Verifique a coenxao dos seus pinos!! ");
    while (true);                      
  }
 
  Serial.println(" Modulo LoRa iniciado com sucesso!!!");
  Serial.println("Setup Completado!");


<<<<<<< Updated upstream

void loop() {
  while (Serial2.available()) {    
     gps.encode(Serial2.read());
    Serial.print("SATELITES= "); Serial.println(gps.satellites.value());
  }


 /* if (gps.altitude.isUpdated()){
=======
//enc128("vida de silicio", 1);//Faz a função de encriptação e retorna o HEX encriptado.

}
unsigned long calcDistance(){
  unsigned long distanceKmToLondon =
    (unsigned long)TinyGPSPlus::distanceBetween(
      gps.location.lat(),
      gps.location.lng(),
      -27.852606, 
      -54.491972);
      Serial.println("Distancia entre a sala do jean até: "+String(distanceKmToLondon));
      return distanceKmToLondon;
}
void loop() {
  while (Serial2.available()) {    
     gps.encode(Serial2.read());
     //Serial.println(gps.satellites.value());
  }


  if (gps.altitude.isUpdated()){
>>>>>>> Stashed changes
      Serial.print("LATITUDE= "); Serial.println(gps.location.lat(), 6);
      Serial.print("LONGITUDE= "); Serial.println(gps.location.lng(), 6);
      Serial.print("ALTITUDE EM METROS= "); Serial.println(gps.altitude.meters());
      Serial.print("DATA= "); Serial.print(gps.date.day()); Serial.print("/"); Serial.print(gps.date.month()); Serial.print("/"); Serial.println(gps.date.year());
      Serial.print("HORA= "); Serial.print(gps.time.hour()); Serial.print(":"); Serial.print(gps.time.minute()); Serial.print(":"); Serial.println(gps.time.second());
      Serial.print("VELOCIDADE KM/H= "); Serial.println(gps.speed.kmph());
      Serial.print("SATELITES= "); Serial.println(gps.satellites.value());
      Serial.println();

      Serial.println(String(gps.date.day())+String(gps.date.month())+String(gps.date.year()));


     }
   */ 

<<<<<<< Updated upstream

    
    /*
     * tinygps
     * if (GPS.encode(Serial2.read())) {
 
      //Hora e data
      GPS.get_datetime(&data, &hora);
      
      Serial.print("--");
      Serial.print(hora / 1000000);
      Serial.print(":");
      Serial.print((hora % 1000000) / 10000);
      Serial.print(":");
      Serial.print((hora % 10000) / 100);
      Serial.print("--");
 
      Serial.print(data / 10000);
      Serial.print("/");
      Serial.print((data % 10000) / 100);
      Serial.print("/");
      Serial.print(data % 100);
      Serial.println("--");
      
      //latitude e longitude
      GPS.f_get_position(&lat, &lon);
 
      Serial.print("Latitude: ");
      Serial.println(lat, 6);
      Serial.print("Longitude: ");
      Serial.println(lon, 6);
 
      //velocidade
      vel = GPS.f_speed_kmph();
 
      Serial.print("Velocidade: ");
      Serial.println(vel);
 
      //Satelites
      sat = GPS.satellites();
 
      if (sat != TinyGPS::GPS_INVALID_SATELLITES) {
        Serial.print("Satelites: ");
        Serial.println(sat);
      }
      
      Serial.println("");
    }*/
     // verifica se temos o intervalo de tempo para enviar uma mensagem
  if (millis() - lastSendTime > interval){
    //String mensagem = "Oi, sou o node 1!";    // Definicao da mensagem 
    String mensagem = String(gps.location.lat())+";"+String(gps.location.lng());
=======
     // verifica se temos o intervalo de tempo para enviar uma mensagem
  if (millis() - lastSendTime > interval){
    //String mensagem = "Oi, sou o node 1!";    // Definicao da mensagem 
    String mensagem = String(gps.location.lat(),6)+";"+String(gps.location.lng(),6)+ "; Distancia em metros: "+String(calcDistance());
    calcDistance();
>>>>>>> Stashed changes
    Serial.println("Enviando " + mensagem);
    sendMessage(mensagem);
    lastSendTime = millis();            // Timestamp da ultima mensagem
  }
 
  // parse for a packet, and call onReceive with the result:
  onReceive(LoRa.parsePacket());
}

void enc128(const char txt[], bool db){
   if (strlen(pass) > 16){
      if (db == true)      {
         Serial.println("Chave para AES128 <= 16 Bytes");
      }
      return;//Se a chave for maior, irá sair da função.
   }
 
   if (strlen(txt) > 16)//Verifica se o texto tem o tamanho limite de 16 caracteres.
   {
      if (db == true)      {
         Serial.println("Frase/numero para AES <= 16 Bytes / bloco");
      }
      return;//Se o texto for maior, irá sair da função.
   }
 
   for (byte i = 0; i < strlen(pass); i++)//Adiciona a chave(pass) na array key.
   {
      key[i] = pass[i];
   }
 
   for (byte i = 0; i < strlen(txt); i++)//Adiciona o texto na array input.
   {
      inp[i] = txt[i];
   }
 
   //Adiciona a chave ao algoritimo.
   if (aes.set_key(key, 16) != 0)//Verifica se a chave esta correta, caso nao, sairá da função.
   {
      if (db == true)
      {
         Serial.println("Erro ao configurar chave");
      }
      return;//Sai da função
   }
 
   //Faz a encriptação da array INPUT e retorna o HEXA na array OUTPUT.
   if (aes.encrypt(inp, out) != 0)//Verifica se a encriptação esta correta, se não, sairá da função.
   {
      if (db == true)
      {
         Serial.println("Erro ao encriptar");
      }
      return;//Sai da função
   }
 
   if (db == true)//Se o debug estiver on (1), irá mostrar o HEXA no serial monitor.
   {
      for (byte i = 0; i < 16; i++)
      {
         Serial.print(out[i], HEX);
         Serial.print(" ");
      }
      Serial.println();
   }
 
   aes.clean();//Limpa a chave e residuos sensiveis da encriptação.
}

// Funcao que envia uma mensagem LoRa
void sendMessage(String outgoing){
  LoRa.beginPacket();                   // Inicia o pacote da mensagem
  LoRa.write(destination);              // Adiciona o endereco de destino
  LoRa.write(localAddress);             // Adiciona o endereco do remetente
  LoRa.write(msgCount);                 // Contador da mensagem
  LoRa.write(outgoing.length());        // Tamanho da mensagem em bytes
  LoRa.print(outgoing);                 // Vetor da mensagem 
  LoRa.endPacket();                     // Finaliza o pacote e envia
<<<<<<< Updated upstream
  msgCount++;                           // Contador do numero de mensagnes enviadas
=======
>>>>>>> Stashed changes
}
 
// Funcao para receber mensagem 
void onReceive(int packetSize){
  if (packetSize == 0) return;          // Se nenhuma mesnagem foi recebida, retorna nada
 
  // Leu um pacote, vamos decodificar? 
  int recipient = LoRa.read();          // Endereco de quem ta recebendo
  byte sender = LoRa.read();            // Endereco do remetente
  byte incomingMsgId = LoRa.read();     // Mensagem
  byte incomingLength = LoRa.read();    // Tamanho da mensagem
 
  String incoming = "";
 
<<<<<<< Updated upstream
  while (LoRa.available())
  {
    incoming += (char)LoRa.read();
  }
 
  if (incomingLength != incoming.length()) 
  {   
=======
  while (LoRa.available())  {
    incoming += (char)LoRa.read();
  }
 
  if (incomingLength != incoming.length())   {   
>>>>>>> Stashed changes
    // check length for error
    Serial.println("erro!: o tamanho da mensagem nao condiz com o conteudo!");
    return;                        
  }
 
  // if the recipient isn't this device or broadcast,
<<<<<<< Updated upstream
  if (recipient != localAddress && recipient != 0xCC)
  {
=======
  if (recipient != localAddress && recipient != 0xFF)  {
>>>>>>> Stashed changes
    Serial.println("This message is not for me.");
    return;                             // skip rest of function
  }
 
  // Caso a mensagem seja para este dispositivo, imprime os detalhes
  Serial.println("Recebido do dispositivo: 0x" + String(sender, HEX));
  Serial.println("Enviado para: 0x" + String(recipient, HEX));
  Serial.println("ID da mensagem: " + String(incomingMsgId));
  Serial.println("Tamanho da mensagem: " + String(incomingLength));
  Serial.println("Mensagem: " + incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));
  Serial.println();
<<<<<<< Updated upstream

  
=======
>>>>>>> Stashed changes
}

//#include <TelegramCertificate.h>
#include <UniversalTelegramBot.h>


#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
//#include <UniversalTelegramBot.h>


const char* ssid = "Vamsi";
const char* password = "Vamsi@2003";


#define BOTtoken "5623192294:AAHcLr6VkB2zjczSJQsKV2sfdmUZMWuCaWo"
#define CHAT_ID "1489465834"

#define Sensor D10
#define LEDR D3
#define LEDG D9
#define bud D1
#define doore D0
#define in1 D8
#define in2 D7
#define  temp D5
#define  rain  D6
#define gas  D4

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;
int flag=1;//close
bool val;
const int ledPin = 2;
bool ledState = LOW;

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; (i<numNewMessages); i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
       
  // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "Enter /open to  open the door \n";
      welcome += "Enter /close to close the door \n";
      welcome += "Enter /state to request current door state \n";
      bot.sendMessage(chat_id, welcome, "");
      delay(10000);
       bot.sendMessage(CHAT_ID, "Somebody is at door!!", "");
    }
      val=(digitalRead(Sensor));
        if(val==LOW)
       {
        bot.sendMessage(CHAT_ID, "Somebody is at door!!", "");
       
        //return;
       }

    if ((text == "/open")&&(flag==1))
    {
      bot.sendMessage(chat_id, "door is set to opened", "");
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      digitalWrite(doore, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDR, LOW);
      delay(700);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(LEDR, HIGH);
       digitalWrite(LEDG, LOW);
      delay(700);
      flag=0;//open
      Serial.println("open condition entered");
      return;
      Serial.println("open condition entered, after return failed");
    }
    
    if ((text == "/close")&&(flag==0)) 
    {
      bot.sendMessage(chat_id, "door is set to closed", "");
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      //digitalWrite(doore, LOW);
      digitalWrite(bud,HIGH);
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, LOW);
     // digitalWrite(doore, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      delay(700);
       digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      delay(700);
      flag=1;
       Serial.println("close condition entered");
      return;
      Serial.println("close condition entered, after return failed");
    }
    
    if (text == "/state")
    {
      int sensorValue1 = digitalRead(temp);
  int sensorValue2 = digitalRead(gas);
  int sensorValue3 = digitalRead(rain);
  if (sensorValue1 == LOW) {
//digitalWrite(buzzPin, HIGH);
//digitalWrite(LED1, HIGH);
bot.sendMessage(CHAT_ID, "Fire Alert ....!!!!", "");
delay(3000);
} 

if (sensorValue2 == LOW) {
//digitalWrite(buzzPin, HIGH);
//digitalWrite(LED1, HIGH);
bot.sendMessage(CHAT_ID, "Gas Leakage ....!!!!", "");
} 
delay(3000);
if (sensorValue3 == LOW) {
//digitalWrite(buzzPin, HIGH);
//digitalWrite(LED1, HIGH);
bot.sendMessage(CHAT_ID, "It's Raining....!!!!", "");
delay(3000);
} 
      if (digitalRead(ledPin)){
        bot.sendMessage(chat_id, "door is open", "");
      }
      else{
        bot.sendMessage(chat_id, "door is closed", "");
      }
    }
       
  }
}

void setup() {
  Serial.begin(115200);
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  pinMode(Sensor, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
//  pinMode(Buzzer, OUTPUT);
   pinMode(ledPin, OUTPUT);
   pinMode(doore, OUTPUT);
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
     pinMode(temp, INPUT); 
pinMode(rain, INPUT);
pinMode(gas, INPUT);
  digitalWrite(ledPin, ledState);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int a = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    a++;
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(500);

  bot.sendMessage(CHAT_ID, "/start", "");
}
void loop() {
  /*bool value = digitalRead(Sensor);
        
        if (value == 1) {
        bot.sendMessage(CHAT_ID, "Somebody is at door!!", "");
//        value = LOW*/

  val=(digitalRead(Sensor));      
 if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages)
    {
      Serial.println("got response");
        
      handleNewMessages(numNewMessages);
       Serial.println("void loop entered again");   
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}

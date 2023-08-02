# HOME-ALARAM-SYSTEM-USING-AURDINO

ABSTRACT: 

Smart home Automation technology, lifetime is getting easier and simpler on all side in life. In the world, automatically systems are being chosen over the manual system. With the fast growth in the number of users of the internet through the past decade, the Internet has become a part and section of human life. In this study, a remotely controlled smart home automation system, for monitoring and controlling the temperature degree, humidity percentage, gas leakage, fires, and rain in the house, was developed. 
 
The developed system consists of two parts: hardware and software. The hardware consists of many units such as smartphones, personal computers, Arduino UNO, Node Mcu, IR sensor and relay board, gas, motion, flame, light and rain sensors, a buzzer and fire alarm. Arduino Mega used as the Micro-controller is the primary hardware unit connected with an Node mcu responsible for sending and receiving directives and status via the internet. The software is the second part of this system; it is Arduino IDE’s code used to connect to the telegram. The telegram connected to hardware devices and sensors through Node mcu. Moreover, it works to control and monitor this system from the Node mcu and smartphone. 
 
Finally, this system uses an internet network for communication and alerts due to its low cost and large area coverage and can control every device via the web browser and Android application anywhere and anytime. Moreover, the gas, flame, light, temperature and rain sensors work correctly with excellent results 

INTRODUCTION: 

Embedded physical devices, such as household appliances are becoming smarter and smarter, They are equipped with embedded microprocessors and wireless transceivers, offering limited communication capabilities and providing good behavior, Everyday objects fitted with small, cheap mobile processors, sensors, and actuators . Sensors and wireless sensor networks are being deployed in smart home solutions, measuring with precision the environmental conditions in the home environment, their advanced sensing functionalities and their increasing accuracy enable the development of smart home applications that offer advanced automation. Residences are transformed into a smart house, incorporating embedded sensors and actuators, and pervasive technology . 
 
Efficaciously addressing the needs within the realms of the ‘Smart Home' environment, requires a multidisciplinary collaboration. This development usually unfolds specialists from Architecture, Electrical and Electronic Engineering, Computer Science and some purpose related to the health sector may also require the participation of professionals from Social Sciences, Medicine, and Occupational Therapy. Although all people can be interested in such undesirable situations, elderly people and people with health problems, require more exclusive monitoring when they are not accompanied by a healthcare professional. 
 
It is possible for someone exhibiting early stages of cognitive impairments too; a "smart home" typically is a domestic environment that has been partially automated. Home automation includes the centralized control for lighting, air conditioning, ventilation and heating also devices controlling and others, Smart Home automation, aims to promote the comfort energy consumption efficiency and safety in domestic scenarios. 
 
Houses are equipped with autonomous control panels to control all of the systems and devices present in the home, Moreover, those control panels are overwhelmingly not regarding each other, The main aim of an intelligent house is to focus the control of all the devices into a private control unit which can be programmed to do special tasks suitable for the possessor and the house in question, The aim of a smart home is not only suitability but also to reduce the consuming of resources such as power, gas, etc. 

BACKGROUND: 

With the 1975 release of X10, a communication protocol for home automation, the smart home, once a pipe dream a la The Jetsons, came to life. X10 sends 120 kHz radio frequency bursts of digital information onto a home's existing electric wiring to programmable outlets or switches. These signals convey commands to corresponding devices, controlling how and when the devices operate. A transmitter could, for example, send a signal along the house's electric wiring, telling a device to turn on at a specific time. 
 
However, as electrical wiring isn't designed to be free from radio-band "noise," X10 was not always fully reliable. Signals would be lost and, in some cases, signals wouldn't cross circuits that were wired on different polarities, created when 220-volt service is split into a pair of 100-volt feeds, as is common in the U.S. Additionally, X10 was initially a one-way technology, so while smart devices can take commands, they cannot send data back to a central network. Later, however, two-way X10 devices became available, albeit at a higher cost. 
 
When home automation company Insteon came on the scene in 2005, it introduced technology that combined electric wiring with wireless signals. Other protocols, including ZIGBEE and Z-WAVE, have since emerged to counter the problems prone to X10, though X10 remains a widely installed communications protocol to this day. 
 
Nest labs was founded in 2010 and released its first smart product, the Nest Learning Thermostat, in 2011. The company also created smart smoke/carbon monoxide detectors and security cameras. After being acquired by Google in 2015, it became a subsidiary of Alphabet Inc. in the same year. 
 
In 2012, Smart Things Inc. launched a Kick starter campaign, raising $1.2 million to fund its smart home system. Following additional funding, the company came on the market in August 2013 and was acquired by Samsung in 2014. 
 
More recently, companies including Amazon, Apple and Google have released their own smart home products and domestics platforms, including Amazon Echo, Apple Home Kit and Google Home 
 
 Problem Definition: 
 
1.	General house hold appliances occupies a huge variety of devices which we use daily as a part of our life .A physically handicapped person cannot use these appliance to their full extent, in order to aid them we need a system that can help them in a way such that it requires minimum effort . 
 
2.	We need a smart system that monitors the entire home such as air quality, fire accidents, unprecedented rains,gas leakage and etc. 
 
3.	We need a system through which we can control devices in the house from any location in the world with simple operations and an internet facility. 
 
4.	All these things are achieved by the help of this smart home through IOT 

Objective of the Smart home: 
 
1.	It is to improve the quality of life and convenience in the home, greater security and more efficient use of energy thanks to connected, remote-controllable devices that helps in the process of the achieving the easy and efficient utilization of the household utensils and devices from anywhere around the globe with a simple internet connection between the user and the controlling unit which is placed at the house 
 
2.	The other objectives are to aid physically challenged people in using the house hold devices without much effort 
 
3.	Continuous monitoring of the house for emergency cases such as fire accidents and gas leakage 
 
4.	In order to have a continuous surveillance over the house to prevent any situations of robbery, trespassing and etc. 
 
These are the objectives of this project that are are kept in view. 

Procedure : 
 
1.1 COMPONENTS REQUIRED: 
 
 
1.	Arduino uno R3 
 
2.	ESP 8266 node mcu 
 
3.	4 channel relay module 
 
4.	IR remote and sensor 
 
5.	ultrasonic sensor 
 
6.	Fire sensor 
 
7.	MQ-2 gas and smoke sensor 
 
8.	Bread board 
 
9.	Jumpers 
10.Fan 
11.Arduino IDE 
 
 
1.2 Making process: 
 
 
 
Creating a Telegram Bot : 
 
Open Telegram and follow the steps to create a Telegram Bot. First, search for 
“botfather” and click the BotFather. Or open this link t.me/botfather in your smartphone. 
Type /newbot and follow the instructions to create your bot. Give it a name and username. 
If your bot is successfully created, you’ll receive a message with a link to access the bot and the bot token. Save the bot token because you’ll need it so that the ESP32/ESP8266 can interact with the bot 
 	8 
Anyone that knows your bot username can interact with it. To make sure that we ignore messages that are not from our Telegram account (or any authorized users), you can get your Telegram User ID. Then, when your telegram bot receives a message, the ESP can check whether the sender ID corresponds to your User ID and handle the message or ignore it. 
 
In your Telegram account, search for “IDBot” or open this link t.me/myidbot in your smartphone. 
 
Start a conversation with that bot and type /getid. You will get a reply back with your user ID. Save that user ID. 
 
 
Preparing Arduino IDE: 
 
We’ll program the ESP8266 boards using Arduino IDE, so make sure you have them installed in your Arduino IDE. 
 
Universal Telegram Bot Library 
 
To interact with the Telegram bot, we’ll use the universal telegram bot library created by Brian Lough that provides an easy interface for the Telegram Bot API. 
 
Follow the next steps to install the latest release of the library. 
 
1.	Go to Sketch > Include Library > Add.ZIP Library... 
2.	Add the library you’ve just downloaded. 
And that’s it. The library is installed. 
 
You also have to install the AeduinoJson library. Follow the next steps to install the library. 
 
1.	Go to Skech > Include Library > Manage Libraries. 
2.	Search for “ArduinoJson”. 
3.	Install the library. 
 
 
Hardware Assembly: 
 
1.	Connect the Arduino uno with the Relay Board with a breadboard and make connections accordin to the circuit diagram. 
2.	Connect the Data pin of Arduino uno with Pin 1,2,3,4 of the Relay. 
3.	Connect the ground pin of the Relay to the ground of the Arduino uno and vcc. 
4.Connect the data pin of the node mcu to the data of the Arduino uno in order to detect the sensor values from the arduino uno. 
9
 
4.	Power the Ardunio uno an node mcu with a normal low voltage phone charger and power up the Relay Board using Arduino UNO board. 
5.	Turn on the mobile hotspot whose id was used while configuring the node mcu telegram code. 
6.	Four electronic appliances can be connected since we're using 4 Relay pins but in our case, we only used one, an FAN . 
7.	Now this assembly is complete and we can use the Telegram App to turn our electrical appliances on and off with our phone. 
 
  
CIRCUIT DIAGRAM: 
 
1.	IR REMOTE CIRCUIT: 
![image](https://github.com/saikrishnareddy2002/HOME-ALARAM-SYSTEM-USING-AURDINO/assets/127223195/f82fee97-782a-407f-9d99-ed3536aae388)

2.	Peripheral circuit:

![image](https://github.com/saikrishnareddy2002/HOME-ALARAM-SYSTEM-USING-AURDINO/assets/127223195/0fb7437e-73d5-4bc1-85dd-4de03f73e1ea)

 RESULTS AND DISCUSSION: 
 
According to the proposed plan the final outcome of this paper leads to the development of a home automation. Through this project, an automation system has been created so that we can easily control home appliances like as light, fan, tube light, AC, bulb, etc. 
 
One of the objectives of this project is also to get us a smart automation and low cost. This system controlled the light and fans using IR inside the home, we can add more electrical appliances. The hardware consists of many units such as smartphones, rain sensor, fire alarm, ultrasonic sensor. Arduino uno is used as the microcontroller is the primary hardrware unit connected with Wi-Fi module for sending and receiving directives and status via telegram. Moreover, it works to control and monitor this system from the telegram and smartphone. Finally, this system uses an internet network for communication and alerts due to its low cost and large area coverage and can control every device via the telegram anywhere and anytime. Moreover, the gas, flame, light, temperature, humidity and rain sensors work correctly with excellent results. 
 
CONCLUSION: 
 
The aim of this project was to design and perform a smart home automation system by remotely controlling and monitoring electronic devices in the house and monitoring of the temperature degree & Humidity percentage, gas leakage, fires, and rain; also Automation light by using motion and light sensors inside and outside the home by using internet of things. This work used an internet network due to its low cost and coverage of a large zone. 
 
It is applied to send information to the system to control devices and receive statuses of the appliances. The target has been carried out successfully. These devices are controlled by the web browser via the internet. 
 
As a result, the system can monitor and controlled from the web browser. Moreover, the gas, flame, light, temperature & Humidity and rain sensors work correctly with excellent results. This system also uses power saving. 
 
An significant advantage of this system is that control every device via the web browser and Android application anywhere and anytime. Finally, the developed system offers a flexible, economical and remotely controllable smart home automation system. 






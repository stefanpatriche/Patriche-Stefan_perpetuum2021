#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "fDcW4I2ZI4TKj05rBxyVqh8ahm2vSC8i"; // the auth code that you got on your gmail
char ssid[] = "Home4"; // username or ssid of your WI-FI
char pass[] = "11aa22bb33"; // password of your Wi-Fi

int x = 0;
int y = 0;
int pen = 1;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE (V5) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    if (x != 40){
      x += 2;  
    } else {
      x = 40;
    }
        
    String s1 = "G1 X";
    s1.concat(x);
    String s2 = " Y";
    s2.concat(y);
    String s3 = " F3500.00";
    Serial.println(s1 + s2 + s3);
  }
}

BLYNK_WRITE (V6) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    if (x != 0){
      x -= 2;  
    } else {
      x = 0;
    }
    
    String s1 = "G1 X";
    s1.concat(x);
    String s2 = " Y";
    s2.concat(y);
    String s3 = " F3500.00";
    Serial.println(s1 + s2 + s3);
  }
}

BLYNK_WRITE (V7) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    if (y != 40){
      y += 2;  
    } else {
      y = 40;
    }
    
    String s1 = "G1 X";
    s1.concat(x);
    String s2 = " Y";
    s2.concat(y);
    String s3 = " F3500.00";
    Serial.println(s1 + s2 + s3);
  }
}

BLYNK_WRITE (V8) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    if (y != 0){
      y -= 2;  
    } else {
      y = 0;
    }
    
    String s1 = "G1 X";
    s1.concat(x);
    String s2 = " Y";
    s2.concat(y);
    String s3 = " F3500.00";
    Serial.println(s1 + s2 + s3);
  }
}

BLYNK_WRITE (V9) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    if (pen == 1) {
      pen = 0; 
      Serial.println("M300 S30");
    } else {
      pen = 1;
      Serial.println("M300 S50");
    }
  }
}

BLYNK_WRITE (V10) {
  int pinValue = param.asInt();
  x = pinValue;
  String s1 = "G1 X";
  s1.concat(x);
  String s2 = " Y";
  s2.concat(y);
  String s3 = " F3500.00";
  Serial.println(s1 + s2 + s3);
}

BLYNK_WRITE (V11) {
  int pinValue = param.asInt();
  y = pinValue;
  String s1 = "G1 X";
  s1.concat(x);
  String s2 = " Y";
  s2.concat(y);
  String s3 = " F3500.00";
  Serial.println(s1 + s2 + s3);
}

BLYNK_WRITE (V12) {
  int pinValue1 = param[0].asInt();
  int pinValue2 = param[1].asInt();

  if (y >= 40 ){
    y = 40;
  } else {
    y += pinValue2;
  }

  if (y <= 0 ){
    y = 0;
  } else {
    y += pinValue2;
  }

  if (x >= 40 ){
    x = 40;
  } else {
    x += pinValue1;
  }

  if (x <= 0 ){
    x = 0;
  } else {
    x += pinValue1;
  }
  
  String s1 = "G1 X";
  s1.concat(x);
  String s2 = " Y";
  s2.concat(y);
  String s3 = " F3500.00";
  Serial.println(s1 + s2 + s3);
}

void loop() {
  Blynk.run();
}
#include <DS3231.h>

// nastav cas otevreni HH:MM (A:B)
const int A = 8;
const int B = 0;

// nastav cas zavreni HH:MM (C:D)
const int C = 18;
const int D = 0;

// nastav cas KRMENI HH:MM (E:F)
const int E = 7;
const int F = 0;

// nastav DOBU KRMENI !MAX 59s!(G)
const int G = 30;

// nastav ZACATEK SVICENI HH:MM (H:I)
const int H = 20;
const int I = 0;

// nastav KONEC SVICENI HH:MM (J:K)
const int J = 21;
const int K = 0;

int Relay1 = 4;
int Relay2 = 5;
int Relay3 = 6;
int Relay4 = 7;

DS3231  rtc(SDA, SCL);
Time t;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, HIGH);
  pinMode(Relay3, OUTPUT);
  digitalWrite(Relay3, HIGH);
  pinMode(Relay4, OUTPUT);
  digitalWrite(Relay4, HIGH);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s),");
  Serial.print(t.sec);
  Serial.print(" second(s)");
  Serial.println(" ");
  delay (1000);
  
  if(t.hour == A && t.min == B && t.sec == 0){
    digitalWrite(Relay1,LOW);
    Serial.println("OTEVIRAM DVERE");
    }
    
    else if(t.hour == A && t.min == B && t.sec == 1){
      digitalWrite(Relay1,HIGH);
      Serial.println("OTEVRENO");
    }
    
  if(t.hour == C && t.min == D && t.sec == 0){
    digitalWrite(Relay2,LOW);
    digitalWrite(Relay3,LOW);
    Serial.println("PREPINAM RELE");
    }

  if(t.hour == C && t.min == D && t.sec == 1){
    digitalWrite(Relay1,LOW);
    Serial.println("ZAVIRAM DVERE");
    }
    
    else if(t.hour == C && t.min == D && t.sec == 2){
      digitalWrite(Relay1,HIGH);
      Serial.println("ZAVRENO");
    }
    
  if(t.hour == C && t.min == D && t.sec == 3){
    digitalWrite(Relay2,HIGH);
    digitalWrite(Relay3,HIGH);
    Serial.println("PREPINAM ZPET");
    }

  if(t.hour == E && t.min == F && t.sec == 0){
    digitalWrite(Relay4,LOW);
    Serial.println("KRMIM");
    }
    
    else if(t.hour == E && t.min == F && t.sec == G){
      digitalWrite(Relay4,HIGH);
      Serial.println("NAKRMENO");
    }    
}

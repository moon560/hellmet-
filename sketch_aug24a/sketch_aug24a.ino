#include <SoftwareSerial.h>

int Led = 3;
int FSRsensor = A0;
int sw = 7;

int speed = 6; // 모터 작동 스피드 받는 값 - 모터드라이버
int In1 = 5;
int In2 = 4;


void setup()
{
    pinMode(Led,OUTPUT);
    Serial.begin(9600);                          // 시리얼 통신 선언 (보드레이트 9600)
    pinMode(sw, INPUT); // 리드스위치 신호핀


    pinMode(speed,OUTPUT);
    pinMode(In1,OUTPUT);
    pinMode(In2,OUTPUT);

    digitalWrite(In1,HIGH); 
    digitalWrite(In2,LOW); 
    
}

void loop() 
{
    int value = analogRead(FSRsensor);
    int is_close = digitalRead(sw);
    
    
//    Serial.println("Sensor Value");
//    Serial.println(is_close);

    int brightness = map(value, 0, 1023, 0, 255);
    analogWrite(Led, brightness);      

    if(is_close && value >= 20)// 리드 스위치에 자석에 뒀는가?
      analogWrite(speed,255); // 모터 속도 지정(0~255)
    else
      analogWrite(speed,0); // 모터 속도 지정(0~255)
  
    
    // delay(50);
}

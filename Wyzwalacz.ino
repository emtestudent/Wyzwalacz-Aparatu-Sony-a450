#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int ir_pin=7;
const int execute=5;
const int clear=4;
const int confirm=3;
const int plus=2;
const int diodeIndicator=6;
void repeatCollect();
void delayCollect();
void zerowanie();
void sonyIR();
int opoznienie;
int confirmState=0;
int lastConfimState;
int clearState;
int lastClearState;
int plusRepeatState;
int lastPlusRepeatState;
int plusTimeState;
int plusTimePushCounter;
int plusRepeatPushCounter;
int lastPlusTimeState;
int confirmPushCounter;
int executeState;
int repeat;
int delayMultiplayer='60*'1000;

void setup()
{
  pinMode (ir_pin, OUTPUT);

  pinMode (clear, INPUT);
  pinMode (confirm, INPUT);
  pinMode (plus, INPUT);

  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("AutoWyzwalacz ");
  Serial.println("Nacisnij +R/+T by rozpoczac");
  lcd.setCursor(0,0);
  lcd.println("Wyzwalacz | v2.2");
  lcd.setCursor(0,1);
  lcd.println("Press + to start");
}



void loop()
{
  plusRepeatState = digitalRead(plus);
  confirmState = digitalRead(confirm);
  clearState = digitalRead(clear);
  executeState = digitalRead(execute);

  if(plusRepeatState == 1 || confirmState ==1 || clearState== 1 || executeState==1)
  {
    plusRepeatState = digitalRead(plus);
    confirmState = digitalRead(confirm);
    clearState = digitalRead(clear);
    executeState = digitalRead(execute);
    Serial.println(clearState);
    Serial.println(confirmState);
    Serial.println(plusRepeatState);
    Serial.println(executeState);
    lcd.setCursor(0,1);
    lcd.print("                          ");
    lcd.setCursor(0,1);
    lcd.print("T+: ");
    lcd.setCursor(7,1);
    lcd.print("R+: ");
    
    //zerowanie();
    

    if(plusRepeatState!=0)
    {
      digitalWrite(diodeIndicator, HIGH);
      plusRepeatPushCounter=plusRepeatPushCounter+1;
      Serial.println("REPEAT");
      Serial.println(plusRepeatPushCounter);
      lcd.setCursor(10,1);
      lcd.print(plusRepeatPushCounter);
      lcd.setCursor(3,1);
      lcd.print(confirmPushCounter);
    }
    else
    {
      digitalWrite(diodeIndicator, LOW);
    }
    lastPlusRepeatState=plusRepeatPushCounter;

/*    if(plusTimeState!=0)
    {
      digitalWrite(diodeIndicator, HIGH);
      plusTimePushCounter=plusTimePushCounter+1;
      Serial.println("TIME");
      Serial.println(plusTimePushCounter);
      lcd.setCursor(3,1);
      lcd.print(plusTimePushCounter);
    }
    else
    {
      digitalWrite(diodeIndicator, LOW);
    }
    lastPlusTimeState=plusTimePushCounter;
    */

    if(confirmState!=0)
    {
     digitalWrite(diodeIndicator, HIGH);
     confirmPushCounter=confirmPushCounter+1;
     Serial.println("TIME");
     Serial.println(confirmPushCounter);
     lcd.setCursor(3,1);
     lcd.print(confirmPushCounter);
     lcd.setCursor(10,1);
     lcd.print(plusRepeatPushCounter);
   }
   else
   {
    digitalWrite(diodeIndicator, LOW);
   }
   lastConfimState=confirmPushCounter;
  
  delay(500);

}

if(clearState!=0)
{
 digitalWrite(diodeIndicator, HIGH);
 delay(200);
 digitalWrite(diodeIndicator, LOW);
 zerowanie();
}

if(executeState!=0)
{
  lcd.setCursor(0,1);
  lcd.print("T: ");
  lcd.setCursor(3,1);
  lcd.print(confirmPushCounter);
  lcd.setCursor(7,1);
  lcd.print("R: ");
  lcd.setCursor(10,1);
  lcd.print(plusRepeatPushCounter);
  delay(5000);

  for(int i=0;i<lastPlusRepeatState;i++)
  {
    //digitalWrite(diodeIndicator, HIGH);
    digitalWrite(diodeIndicator, HIGH);
    while(repeat<=3)
    {
      sonyIR();
    }
    digitalWrite(diodeIndicator, LOW);
  repeat=0;
  opoznienie = (lastConfimState*delayMultiplayer);
  delay(opoznienie);
}

}
}

void zerowanie()
{
  clearState = digitalRead(clear);
  if(clearState!=0)
  {
    Serial.println("Zacznij od poczataku");
    confirmPushCounter=0;
    plusTimePushCounter=0;
    plusRepeatPushCounter=0;
    Serial.println("Wyzerowane");
    lcd.setCursor(0,1);
    lcd.print("Start Over");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.println("Press + to start");
  }
}

void sonyIR()
{
    digitalWrite(ir_pin, 1);    //Header
    delayMicroseconds(2250);
    digitalWrite(ir_pin, 0);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);   //0. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(700);
    digitalWrite(ir_pin, HIGH);    //1. bit
    delayMicroseconds(500);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);    //2. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(700);
    digitalWrite(ir_pin, HIGH);    //3. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);    //4. bit
    delayMicroseconds(500);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //5. bit
    delayMicroseconds(1050);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //6. bit
    delayMicroseconds(500);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //7. bit
    delayMicroseconds(500);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);      //8. bit
    delayMicroseconds(1050);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //9. bit
    delayMicroseconds(500);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //10. bit
    delayMicroseconds(1050);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //11. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(700);
    digitalWrite(ir_pin, HIGH);     //12. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //13. bit
    delayMicroseconds(500);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //14. bit
    delayMicroseconds(450);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //15. bit
    delayMicroseconds(500);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //16. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //17. bit
    delayMicroseconds(1050);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(750);
    digitalWrite(ir_pin, HIGH);     //18. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(700);
    digitalWrite(ir_pin, HIGH);     //19. bit
    delayMicroseconds(1100);
    digitalWrite(ir_pin, LOW);
    delayMicroseconds(11400);
    repeat=repeat+1;
}

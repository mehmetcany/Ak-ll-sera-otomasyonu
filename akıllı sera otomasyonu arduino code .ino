

#include <LiquidCrystal.h>
#include <dht11.h>
#define DHT11PIN 15
dht11 DHT11;

//               (Rs, E, D4, D5, D6 ,D7)
LiquidCrystal lcd(13 , 12, 11 , 10 , 9 , 8);

int motorileri = 2;
int motorhiz = 3;
int motorgeri = 4;
int buzzer = 5;
//int led = 6;
int supompasi = 18;
int toprak = 0;
int yagmur = 0;
int isitici=14;
int fan=17;

#define buton 30
#define butonn 32
#define butonm 22
#define butonb 24
#define butont 26
#define butontt 28
int i=20;
int j=28;
int x=54;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(isitici,OUTPUT);
  pinMode(fan,OUTPUT);
pinMode(buton,INPUT);
 pinMode(butonn,INPUT);
 pinMode(butonm,INPUT);
 pinMode(butonb,INPUT);
 pinMode(butont,INPUT);
 pinMode(butontt,INPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.println("  AKILLI  SERA  ");
  lcd.setCursor (0, 1);
  lcd.println("    PROJESI     ");
  delay(1000);
}
void loop() {


  int topraksensoru = analogRead(A0);
  int kapandi = 0;
  int acildi = 0;
  int manuelac =0;
  int manuelkapa =0;
 manuelac = analogRead(A4);
 manuelkapa = analogRead(A5);

  kapandi = analogRead(A1);
  acildi = analogRead(A2);

  int yagmursensoru = analogRead(A3);
  yagmur = map(abs(yagmursensoru), 0, 1024, 0, 100);
  toprak = map(abs(topraksensoru), 0, 1024, 100, 0);
  lcd.begin(16, 2);
  
  
  
  
  if (acildi > 1000)
  {
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("CATI--YAGMUR =");  lcd.print(yagmur); lcd.println("           ");
  lcd.setCursor (0, 1);
  lcd.print("ACIK--TOPRAK =");  lcd.print(toprak); lcd.println("            ");
   
  delay (100);
  analogWrite(motorhiz, 0);
  digitalWrite(motorileri, LOW);
  digitalWrite(motorgeri, LOW);
  }
  if (kapandi > 1000)
  {
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("CATI--YAGMUR =");  lcd.print(yagmur); lcd.println("           ");
  lcd.setCursor (0, 1);
  lcd.print("KAPALI-TOPRAK=");  lcd.print(toprak); lcd.println("            ");
 
  delay (100);
  analogWrite(motorhiz, 0);
  digitalWrite(motorileri, LOW);
  digitalWrite(motorgeri, LOW);
  }
  
while (manuelac > 1000)
    {
      while (acildi < 1000)

      { analogWrite(motorhiz, 255);
        digitalWrite(motorileri, LOW);
        digitalWrite(motorgeri, HIGH);
        digitalWrite(buzzer, HIGH);
        delay (50);
       digitalWrite(buzzer, LOW);
        delay (50);
       
     
        
        lcd.clear();
        lcd.setCursor (0, 0);
        lcd.print("MANUEL OLARAK   ");
        lcd.setCursor (0, 1);
        lcd.print("CATI ACILIYOR  ");
        kapandi = analogRead(A1);
        acildi = analogRead(A2);

      }
      analogWrite(motorhiz, 0);
      digitalWrite(motorileri, LOW);
      digitalWrite(motorgeri, LOW);
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print("MANUEL OLARAK   ");
      lcd.setCursor (0, 1);
      lcd.print("CATI ACILDI     ");
      delay (1000);
        digitalWrite(buzzer, LOW);
       
      manuelac = analogRead(A4);
 manuelkapa = analogRead(A5);
    }

    
    while (manuelkapa > 1000)
    {
      while (kapandi < 1000)
      { analogWrite(motorhiz, 255);
        digitalWrite(motorileri, HIGH);
        digitalWrite(motorgeri, LOW);
        digitalWrite(buzzer, HIGH);
        delay (50);
       digitalWrite(buzzer, LOW);
        delay (50);
       
        
        lcd.clear();
        lcd.setCursor (0, 0);
        lcd.print("MANUEL OLARAK   ");
        lcd.setCursor (0, 1);
        lcd.print("CATI KAPANIYOR  ");
        kapandi = analogRead(A1);
        acildi = analogRead(A2);
      }  digitalWrite(buzzer, LOW);
      analogWrite(motorhiz, 0);
      digitalWrite(motorileri, LOW);
      digitalWrite(motorgeri, LOW);
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print("MANUEL OLARAK   ");
      lcd.setCursor (0, 1);
      lcd.print("CATI KAPATILDI  ");
      delay (1000);
      manuelac = analogRead(A4);
 manuelkapa = analogRead(A5);
    }
 
 
 if (toprak <= x)
    { lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print("TOPRAK SULAMASI ");
      lcd.setCursor (0, 1);
      lcd.print("    YAPILIYOR   ");
      digitalWrite(supompasi, HIGH);

      
      
      //digitalWrite(led, HIGH);
      //    digitalWrite(buzzer, HIGH);
      
      //delay (5000);
    //  digitalWrite(supompasi, LOW);
  //    digitalWrite(buzzer, LOW);
      
      
     
//delay(2000);
      int topraksensoru = analogRead(A0);
      toprak = map(abs(topraksensoru), 0, 1024, 100, 0);
    }
   
    else
    {
      digitalWrite(supompasi, LOW);
    }
    
 
 
  if (yagmur > 30) // yagmur var
  {

    
       Serial.print("5");
      Serial.print(",");
      
    int kapandi = analogRead(A1);

    while (kapandi == 0)
    {
         lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print("YAGMUR BASLADI. ");
      lcd.setCursor (0, 1);
      lcd.print("CATI KAPANIYOR  ");
     digitalWrite(buzzer, HIGH);
        delay (50);
       digitalWrite(buzzer, LOW);
        delay (50);
      analogWrite(motorhiz, 255);
      digitalWrite(motorileri, HIGH);
      digitalWrite(motorgeri, LOW);
      
      
       
    
      kapandi = analogRead(A1);
      acildi = analogRead(A2);
    }


  }
  
 
  if (yagmur <= 30)//yagnur yok
  { 
      Serial.print("6");
      Serial.print(",");
      
    int acildi = analogRead(A2);
  
    while (acildi == 0)
    {
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print("YAGMUR DURDU.   ");
      lcd.setCursor (0, 1);
      lcd.print("CATI ACILIYOR   ");
       digitalWrite(buzzer, HIGH);
        delay (50);
       digitalWrite(buzzer, LOW);
        delay (50);
      analogWrite(motorhiz, 255);
      digitalWrite(motorileri, LOW);
      digitalWrite(motorgeri, HIGH);
     
     
      //      digitalWrite(buzzer, HIGH);
     
      kapandi = analogRead(A1);
      acildi = analogRead(A2);
    } 
    
  }
  // Bir satır boşluk bırakıyoruz serial monitörde.
  
  // Sensörün okunup okunmadığını konrol ediyoruz. 
  // chk 0 ise sorunsuz okunuyor demektir. Sorun yaşarsanız
  // chk değerini serial monitörde yazdırıp kontrol edebilirsiniz.
  int chk = DHT11.read(DHT11PIN);
  
  // Sensörden gelen verileri serial monitörde yazdırıyoruz.
  
  Serial.print((float)DHT11.humidity, 2);
  Serial.print(",");
  
  
  Serial.print((float)DHT11.temperature, 2);
  Serial.print(",");

  Serial.print(toprak);
  Serial.print(",");
  
  
  
  
if(digitalRead(buton) == 1)
  {i++;
  
  }
  if(digitalRead(butonn) == 1)
  {i--;

  
  }
  if(digitalRead(butonm) == 1)
  {j++;

  }
  if(digitalRead(butonb) == 1)
  {j--;
 
  }
  if(digitalRead(butont) == 1)
  {x++;

  }
  if(digitalRead(butontt) == 1)
  {x--;

  
  }
  

Serial.print(i);
 Serial.print(",");
 
  Serial.print(j);
 Serial.print(",");
 
Serial.print(x);
 
 Serial.println();
 delay(2000);
  

  if (DHT11.temperature<=i)
  {
    digitalWrite(isitici,HIGH);
    digitalWrite(fan,LOW);
     
    
  } 
  else if (DHT11.temperature>=j)
  {
    digitalWrite(isitici,LOW);
    digitalWrite(fan,HIGH);
    
    
    
  }
  else 
  {
    digitalWrite(isitici,LOW);
    digitalWrite(fan,LOW);
    
  }
  
 

}

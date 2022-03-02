
// include the library code:
#include <LiquidCrystal.h>
#include<EEPROM.h>
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A5, A4, A3, A2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A1, 10, 9,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Result=0,x=0,y=0;

void Adding(int x)
{
  lcd.print('+');
       x=(int)keypad.waitForKey()-48;
         Result+=x;
       lcd.setCursor(4,0);
       lcd.print(x);
}
void Subtracting(int x)
{
  lcd.print('-');
       x=(int)keypad.waitForKey()-48;
       Result-=x;
       lcd.setCursor(4,0);
      lcd.print(x);
       
}
void Multiplying(int x)
{
   lcd.print('*');
       x=(int)keypad.waitForKey()-48;
       Result*=x;
       lcd.setCursor(4,0);
       lcd.print(x);
      
}
void dividing(int x)
{
    lcd.print('/');
      x=(int)keypad.waitForKey()-48;
      lcd.setCursor(4,0);
      lcd.print(x);
      Result/=x;
}
void setup()   
{
  lcd.begin(16, 2);
  lcd.setCursor(2,0);
  lcd.print("Welcome to Our");
  lcd.setCursor(3,1);
  lcd.print("Calculator");
  delay(1000);
  lcd.clear();
}
int temp=0,count=0;
// A->>+   B->>-  C->>*  D->>/
void loop()
{
  char var=keypad.waitForKey();
   x=(int)var-48;
   if(x<=9 &&x>=0)
   {
   lcd.setCursor(0,0);
   lcd.print(x);
   lcd.setCursor(2,0);
    if(keypad.waitForKey()=='A')
    {
      Result+=x;
    Adding(x);
    }
    else if(keypad.waitForKey()=='B')
    {
      Result+=x;
    Subtracting( x);
    }
    else if(keypad.waitForKey()=='C')
    {
      Result+=x;
     Multiplying( x) ;
    }
    else if(keypad.waitForKey()=='D')
    {
      Result+=x;
     dividing(x);
    }
   }
   else
   {
    if(var=='A')
    Adding( x);
    else if(var=='B')
    Subtracting( x);
    else if(var=='C')
     Multiplying(x);
      else
      dividing(x);
   }
   delay(1000);
       lcd.setCursor(0,0);
    lcd.print("Result=");
    lcd.setCursor(8,0);
    lcd.print(Result);
    delay(1000);
    lcd.clear();
  }
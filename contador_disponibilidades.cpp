#include <LiquidCrystal.h>

#define RS 2     
#define EN 3
#define DB4 4 
#define DB5 5
#define DB6 6
#define DB7 7

int INCREMENTA = 8;
int LEITURA_INC = 0;
int DECREMENTA = 9;
int LEITURA_DEC = 0;
int contador = 0;
int limite = 10;

LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

void setup()
{
  pinMode(INCREMENTA,INPUT);
  pinMode(DECREMENTA, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Ola!");
  lcd.setCursor(0, 1);
  lcd.print("Seja Bem Vindo!");
  delay(3000);
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("TOTAL VISITANTES");
  lcd.setCursor(0, 1);    
  lcd.print("ATUALMENTE:");
  lcd.print(contador);
}
void loop() 
{
  LEITURA_INC = digitalRead(INCREMENTA);
  LEITURA_DEC = digitalRead(DECREMENTA);
  
  if(LEITURA_INC == HIGH && contador < limite)
  {
    
   	contador ++;
   
    lcd.setCursor(0, 1);
 	lcd.print("ATUALMENTE:");
    lcd.print(contador);
    lcd.print("    ");
  }
  if(LEITURA_DEC == HIGH && contador > 0)
  {
    lcd.clear();
   	contador --;
    lcd.setCursor(0, 0);
  	lcd.print("TOTAL VISITANTES");
    lcd.setCursor(0, 1);
 	lcd.print("ATUALMENTE:");
    lcd.print(contador);
    lcd.print("    ");
  }
  if(LEITURA_INC == HIGH && contador == limite)
  {
   	lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ONIBUS LOTADO");
    lcd.setCursor(0, 1);
    lcd.print(contador);
    lcd.print(" PESSOAS");
    
  }
  delay(500);
  
  
}
 
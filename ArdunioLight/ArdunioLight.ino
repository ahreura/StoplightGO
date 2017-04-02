const int button = 3;       // the Grove port No. you attached a button to
const int button2=4;
const int LEDb=2;
const int LEDg=5;       // the Grove port No. you attached an LED to
const int LEDr=6;

int btn = LOW; //read the status of the button
int btn2 = LOW;
int loopCount = 80;

void setup()
{
    pinMode(button2,INPUT);
    pinMode(button, INPUT); //set button as an INPUT device
    pinMode(LEDb, OUTPUT);   //set LED as an OUTPUT device
    pinMode(LEDg,OUTPUT);
    pinMode(LEDr,OUTPUT);
}
void loop()
{
    btn2 = digitalRead(button2);
    btn = digitalRead(button);
    btn = LOW; 
    digitalWrite(LEDg,LOW);
    digitalWrite(LEDr,HIGH);
    delay(4000);
    digitalWrite(LEDr,LOW);
    digitalWrite(LEDg,HIGH);
    delay(4000);
     btn2 = digitalRead(button2);
    if(btn2==HIGH){
      while(btn==LOW){
        
        flashes();
        if(loopCount ==0){
          loopCount = 80;
          btn2 = digitalRead(button2);
          btn = digitalRead(button);
          loop();
          
        }
      }
    }  
}
void flashes(){
  btn = digitalRead(button);
        digitalWrite(LEDb,HIGH);
        delay(100);
        btn = digitalRead(button);
        digitalWrite(LEDb,LOW);
        delay(100);
        loopCount--;
        btn = digitalRead(button);
}


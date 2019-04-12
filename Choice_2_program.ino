// Includes the Servo library
#include <Servo.h>

Servo myServo; // Creates a servo object for controlling the servo motor

int oneBPin = 1;  //B top Right
int oneAPin = 2;  //A top
int oneFPin = 3; //F top Left
int oneGPin = 4; //G middle
int oneEPin = 5; //E bot Left
int oneDPin = 6;  //D bot
int oneCPin = 7; //C bot right
int oneDPPin= 8; // DP dot
int latch = 9;
int clock = 10;
int data= 11;
bool firstFinished = false;
bool secondFinished = false;
int firstScore = 0;
int secondScore = 0;
//int player1Wins= 0;
//int player2Wins= 0;
int repeats = 0;
int goal= 14;
bool gameOver= false;
int number= 0;

void setup() 
{


  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached

  randomSeed(analogRead(0));

  pinMode(oneBPin,OUTPUT);
  pinMode(oneAPin,OUTPUT);
  pinMode(oneFPin,OUTPUT);
  pinMode(oneGPin,OUTPUT);
  pinMode(oneEPin,OUTPUT);
  pinMode(oneDPin,OUTPUT);
  pinMode(oneCPin,OUTPUT);
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);

  
  pinMode(A1,INPUT); // Configuring button 1 (START)
  pinMode(A2,INPUT); // Configuring button 2 (P1 DRAW)
  pinMode(A3,INPUT); // Configuring button 3 (P1 FINISH)
  pinMode(A4,INPUT); // Configuring button 4 (P2 DRAW)
  pinMode(A5,INPUT); // Configuring button 5 (P2 FINISH)
}


void loop() 
{

  firstFinished= false;
  secondFinished= false;
  gameOver= false;
  firstScore= 0;
  secondScore= 0;
  myServo.write(30);
  if (analogRead(A1) == 1023) 
  {
    Serial.println("start");

    while (!gameOver) 
    {
      
      if (analogRead(A2) == 1023) 
      {
        number = random(1,14);
        ShowNumber(number, 3); // 3 is registered to small 7 pin
        firstScore= firstScore+number;
        if (firstScore > 21) 
          {
          firstScore= 0;
          firstFinished= true;
          }
        ShowNumber(firstScore, 1); // 1 to first two positions on large
        delay(1000);
      }
      if (analogRead(A4) == 1023 )
      {
        number = random(1,14);
        ShowNumber(number, 3); // 3 is registered to small 7 pin
        secondScore= secondScore+number;
        if (secondScore > 21) 
          {
          secondScore= 0;
          secondFinished= true;
          }
        ShowNumber(secondScore, 2); // 2 to last two positions on large
        delay(1000);
      }
      if (analogRead(A3) == 1023) //pass mechanic p1
        firstFinished= true;


      if (analogRead(A5) == 1023) //pass mechanic p2
        secondFinished= true;

      if (firstFinished && secondFinished) //game ending condition
        gameOver= true;

    }

    if (secondScore==0 && firstScore==0)  //dealer win
    {
      myServo.write(15);
    }
    else if (secondScore> firstScore) // p1 win
    {
      myServo.write(90);
    }
    else if (firstScore>secondScore)
    {
      myServo.write(150);
    }
  
  }

}


void ShowNumber(int displayedValue, int valuePosition) 
{
  if (valuePosition=1)
  {
    number= 0;
  }
  else if (valuePosition= 2)
  {
    number= 2;

  }
  else if (valuePosition=3)
  {
    if (displayedValue==1)
      one();
    else if(displayedValue==2)
      two();
    else if (displayedValue==3)
      three();
    else if (displayedValue==4)
      four();
    else if (displayedValue==5)
      five();
    else if (displayedValue==6)
      six();
    else if(displayedValue==7)
      seven();
    else if (displayedValue==8)
      eight();
    else if (displayedValue==9)
      nine();
    else if (displayedValue==10)
      ten();
    else if (displayedValue==11)
      eleven();
    else if(displayedValue==12)
      twelve();
    else if (displayedValue==13)
      thirteen();
  }

//  if (displayedValue==0)
//    clear();
}

void one()
{
  Serial.println("one");
  ClearSmall();
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  delay(1000);
}

void two()
{
  ClearSmall();
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneEPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  delay(1000);
}

void three()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  delay(1000);
}

void four()
{
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneFPin,HIGH);
  delay(1000);
}

void five()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneFPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  delay(1000);
}

void six()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneFPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneEPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  delay(1000);
}

void seven()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  delay(1000);
}

void eight()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  digitalWrite(oneEPin,HIGH);
  digitalWrite(oneFPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  delay(1000);
}

void nine()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneFPin,HIGH);
  delay(1000);
}

void ten()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  digitalWrite(oneEPin,HIGH);
  digitalWrite(oneFPin,HIGH);
  digitalWrite(oneDPPin,HIGH);
  delay(1000);
}

void eleven()
{
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneDPPin,HIGH);
  delay(1000);
}

void twelve()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneEPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  digitalWrite(oneDPPin,HIGH);
  delay(1000);
}

void thirteen()
{
  digitalWrite(oneAPin,HIGH);
  digitalWrite(oneBPin,HIGH);
  digitalWrite(oneGPin,HIGH);
  digitalWrite(oneCPin,HIGH);
  digitalWrite(oneDPin,HIGH);
  digitalWrite(oneDPPin,HIGH);
  delay(1000);
}

void ClearSmall()
{
  digitalWrite(oneBPin,LOW);
  digitalWrite(oneAPin,LOW);
  digitalWrite(oneFPin,LOW);
  digitalWrite(oneGPin,LOW);
  digitalWrite(oneEPin,LOW);
  digitalWrite(oneDPin,LOW);
  digitalWrite(oneCPin,LOW);
  digitalWrite(oneDPPin,LOW);
}

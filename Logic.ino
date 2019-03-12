// ELEC 1100 Final Project 
// Author: Alexandra Gil & Jonathan Friend


#define pinLeftSensor A1      //pin A1
#define pinRightSensor A3     //pin A3
#define pinWallSensor A5      //pin A5

#define pinLDir 2             //pin D2
#define pinRDir 3             //pin D3

#define pinLQ0 5              //pin D5
#define pinLQ1 6              //pin D6
#define pinLQ2 7              //pin D7
#define pinLQ3 8              //pin D8

#define pinRQ0 9              //pin D9
#define pinRQ1 10             //pin D10
#define pinRQ2 11             //pin D11
#define pinRQ3 12             //pin D12


int leftSensor = 1;
int rightSensor = 1;
int wallSensor = 1;
int turn = 0;
int goBack = 0;
int start = 0;

void setup() {
  
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  pinMode(pinWallSensor, INPUT);

  pinMode(pinLDir, OUTPUT);
  pinMode(pinRDir, OUTPUT);

  pinMode(pinLQ0, OUTPUT);
  pinMode(pinLQ1, OUTPUT);
  pinMode(pinLQ2, OUTPUT);
  pinMode(pinLQ3, OUTPUT);

  pinMode(pinRQ0, OUTPUT);
  pinMode(pinRQ1, OUTPUT);
  pinMode(pinRQ2, OUTPUT);
  pinMode(pinRQ3, OUTPUT);

  // initialize output pins.
  digitalWrite(pinLDir, HIGH);        // HIGH: forward rotate
  digitalWrite(pinRDir, HIGH);        // LOW:  reverse rotate
  
  digitalWrite(pinLQ0, LOW);
  digitalWrite(pinLQ1, LOW);
  digitalWrite(pinLQ2, LOW);
  digitalWrite(pinLQ3, LOW);
  
  digitalWrite(pinRQ0, LOW);
  digitalWrite(pinRQ1, LOW);
  digitalWrite(pinRQ2, LOW);
  digitalWrite(pinRQ3, LOW);
}

void loop() {

  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  wallSensor = digitalRead(pinWallSensor); 

  if ( !wallSensor & leftSensor & rightSensor ){
    
      digitalWrite(pinLQ0, HIGH);
      digitalWrite(pinLQ1, HIGH);
      digitalWrite(pinLQ2, HIGH);
      digitalWrite(pinLQ3, HIGH);
      
      digitalWrite(pinRQ0, HIGH);
      digitalWrite(pinRQ1, HIGH);
      digitalWrite(pinRQ2, HIGH);
      digitalWrite(pinRQ3, HIGH);
      
      start++;

  }

  if ( !wallSensor & !leftSensor & !rightSensor ){

    start == 0;
    
    digitalWrite(pinLDir, LOW);
    digitalWrite(pinRDir, LOW);
    
    delay(500);
    
    digitalWrite(pinLQ0, LOW);
    digitalWrite(pinLQ1, LOW);
    digitalWrite(pinLQ2, LOW);
    digitalWrite(pinLQ3, LOW);
    
    digitalWrite(pinRQ0, LOW);
    digitalWrite(pinRQ1, LOW);
    digitalWrite(pinRQ2, LOW);
    digitalWrite(pinRQ3, LOW);
  }
  
  if ( start ){
    
    if ( leftSensor && rightSensor ) {
      
      digitalWrite(pinLDir, HIGH);
      digitalWrite(pinRDir, HIGH);
      delay(15);
    }
  
    if ( !leftSensor && rightSensor ) {
      digitalWrite(pinLDir, LOW);
      digitalWrite(pinRDir, HIGH);
      delay(15);
    }
  
    if ( leftSensor && !rightSensor ) {
        
      digitalWrite(pinLDir, HIGH);
      digitalWrite(pinRDir, LOW);
      delay(15);
      
    }
  
    if ( !leftSensor && !rightSensor ) {

      if ( turn == 2 ){
        
         digitalWrite(pinLDir, HIGH);
         digitalWrite(pinRDir, LOW);
         
        }
        
       else {  
        
          digitalWrite(pinLDir, LOW);
          digitalWrite(pinRDir, HIGH);
          turn++;
          
       }
       
       delay(250);
       
    }
  }
}

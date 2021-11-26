int Pot = A0;
int PotValue = 0;

int led1 = 3;
int led2 = 5;
int led3 = 7;
int led4 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led4, OUTPUT);
}

int Pot1(void) {
  PotValue = analogRead(Pot);
  //Serial.println(PotValue);
  return PotValue;
  }

unsigned long previousMillis = 0;

long Ontime;
long Offtime = 50;
int counter = 0;

void simplesequence(int Note1, int Note2, int Note3, int Note4, long OnTime){

  unsigned long currentMillis = millis();
  
if (currentMillis - previousMillis >= Offtime){
  if (counter == 0) {digitalWrite(led1, HIGH);} //Assuming LED pin is also used as a gate pin.. (seperate with 1k resistor)
  if (counter == 1) {digitalWrite(led2, HIGH);}
  if (counter == 2) {digitalWrite(led3, HIGH);}
  if (counter == 3) {digitalWrite(led4, HIGH);}
  }

if (currentMillis - previousMillis >= Ontime){
  if (counter == 0) {digitalWrite(led1, LOW);} //Need to write a new function based on design choice yet to be made..
  if (counter == 1) {digitalWrite(led2, LOW);} //WriteDAC function will be used here to send CV "notes" to Eurorack devices..
  if (counter == 2) {digitalWrite(led3, LOW);} //Will also need to write functions for controls to handle note input..
  if (counter == 3) {digitalWrite(led4, LOW);}

  counter++;
  
  if (counter >= 4) counter = 0;
  previousMillis = currentMillis;
  Serial.println(counter);
  }
}

int note1; // for storing note values...
int note2;
int note3;
int note4;

void loop(){
  simplesequence(note1, note2, note3, note4, (Pot1()));
  }

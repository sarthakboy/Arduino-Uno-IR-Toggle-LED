#define IRSTART 2
#define IRSTOP 3
#define LED 8
int ir1State, ir2State;
void setup() {
  // put your setup code here, to run once:
  pinMode(IRSTART, INPUT);
  pinMode(IRSTOP, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ir1State = digitalRead(IRSTART);
  ir2State = digitalRead(IRSTOP);

  if(!ir1State){
    digitalWrite(LED, HIGH);
    delay(500);
  }

  if(!ir2State){
    digitalWrite(LED, LOW);
    delay(500);
  }



}

//Handshake Serial communication for three FSRs
//"Serial1" in use instead of "Serial" to ensure communication between Arduino Micro and Adafruit Bluefruit Adapter
//Used for RGB Color Mixer V.2

int inputPin1 = 0;
int inputPin2 = 1;
int inputPin3 = 2;


int fsr1 = 0;
int fsr2 = 0;
int fsr3 = 0;
int inByte = 0;


void setup() {
  Serial1.begin(9600);
  establishContact();
}

void loop() {
  if (Serial1.available() > 0) {
 inByte = Serial1.read();
 fsr1 = analogRead(inputPin1);
 fsr2 = analogRead(inputPin2);
 fsr3 = analogRead(inputPin3);

 Serial1.print(fsr1);
 Serial1.print(",");
 Serial1.print(fsr2);
 Serial1.print(",");
Serial1.println(fsr3);
  }
}

void establishContact () {
  while (Serial1.available() <= 0) {
    //Serial1.print('A');
    Serial1.println("0,0,0");
    delay(300);
  }
}

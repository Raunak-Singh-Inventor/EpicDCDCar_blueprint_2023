int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

//uncomment if using channel B, and remove above definitions
int directionPinB = 13;
int pwmPinB = 11;
int brakePinB = 8;

//boolean to switch direction
bool directionState;

void setup() {
  Serial.begin(9600);
  //define pins
  pinMode(directionPinA, OUTPUT);
  pinMode(pwmPinA, OUTPUT);
  pinMode(brakePinA, OUTPUT);
  pinMode(directionPinB, OUTPUT);
  pinMode(pwmPinB, OUTPUT); 
  pinMode(brakePinB, OUTPUT);
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);
}

void forward() {
  digitalWrite(directionPinA, HIGH); // forward a
  digitalWrite(directionPinB, HIGH); // forward b
  analogWrite(pwmPinA, 30);
  analogWrite(pwmPinB, 30);
}

void left() {
  digitalWrite(directionPinA, HIGH);// forward a
  digitalWrite(directionPinB, LOW);// backward b
  analogWrite(pwmPinA, 30);
  analogWrite(pwmPinB, 30);
}

void right() {
  digitalWrite(directionPinA, LOW);// backward a
  digitalWrite(directionPinB, HIGH);// forward b
  analogWrite(pwmPinA, 30);
  analogWrite(pwmPinB, 30);
}

void loop() {
  int x = analogRead(A4);
  int y = analogRead(A5);
  Serial.println(x);
  Serial.println(y);
  if(y<300) {
    Serial.println("right");
    right();
  } else if(y>800) {
    Serial.println("left");
    left();
  } else {
    Serial.println("forward");
    forward();
  }
}

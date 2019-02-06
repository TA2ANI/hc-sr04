#define echoPin 7
#define trigPin 6
#define role1 10
#define role2 11

bool roledurum = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(role1, OUTPUT);
  pinMode(role2, OUTPUT);
  Serial.begin(9600);

}

void loop()
{ 
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(100);
  Serial.print(distance);
  Serial.println(" cm ");


  if (distance <= 10 && !roledurum)
  {
    digitalWrite (role1, 1);
    digitalWrite (role2, 1);
    roledurum = true;
    while (roledurum && distance <= 20)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      distance = duration / 58.2;
      delay(100);
    }
    delay (1000);
  }


  if (distance <= 10 && roledurum)
  {
    digitalWrite (role1, 0);
    digitalWrite (role2, 0);
    roledurum = false;
    while (!roledurum && distance < 20)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      distance = duration / 58.2;
      delay(100);
    }
    delay (1000);
  }
}


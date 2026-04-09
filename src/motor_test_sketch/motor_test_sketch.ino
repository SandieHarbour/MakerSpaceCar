// Motor Driver Pins
#define MOTOR_DRIVER_OUT_1 13 // D7
#define MOTOR_DRIVER_OUT_2 15 // D8
#define MOTOR_DRIVER_OUT_3 0  // D3
#define MOTOR_DRIVER_OUT_4 2  // D4

int right_motor[2] = {MOTOR_DRIVER_OUT_1, MOTOR_DRIVER_OUT_2};
int left_motor[2]  = {MOTOR_DRIVER_OUT_3, MOTOR_DRIVER_OUT_4};

void setup() 
{
  Serial.begin(115200);
  pinMode(MOTOR_DRIVER_OUT_1, OUTPUT);
  pinMode(MOTOR_DRIVER_OUT_2, OUTPUT);
  pinMode(MOTOR_DRIVER_OUT_3, OUTPUT);
  pinMode(MOTOR_DRIVER_OUT_4, OUTPUT);

  digitalWrite(MOTOR_DRIVER_OUT_1, LOW);
  digitalWrite(MOTOR_DRIVER_OUT_2, LOW);
  digitalWrite(MOTOR_DRIVER_OUT_3, LOW);
  digitalWrite(MOTOR_DRIVER_OUT_4, LOW);

  drive(left_motor, 50);
  delay(1000);
  drive(right_motor, 50);
  delay(1000);

  drive(left_motor, 0);
  delay(1000);
  drive(right_motor, 0);
  delay(1000);

  drive(left_motor, -50);
  delay(1000);
  drive(right_motor, -50);
  delay(1000);

  drive(left_motor, 0);
  delay(1000);
  drive(right_motor, 0);
  delay(1000);
}

void loop() 
{ 

}

void drive(int motor[], int v)
{
  if (v>100) v=100;
  if (v<-100) v=-100;
  if (v>0) 
  {
    digitalWrite(motor[0], HIGH);
    analogWrite(motor[1], 255-(v*2.55));
  }
    else if (v<0) {
    digitalWrite(motor[1], HIGH);
    analogWrite(motor[0], 255+((v)*2.55));
  }
  else {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], LOW);
  }
  Serial.println(v);
}

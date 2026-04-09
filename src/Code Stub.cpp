// Motor Driver Pins
#define MOTOR_DRIVER_OUT_1 13 // D7
#define MOTOR_DRIVER_OUT_2 15 // D8
#define MOTOR_DRIVER_OUT_3 0  // D3
#define MOTOR_DRIVER_OUT_4 2  // D4

int right_motor[2] = {MOTOR_DRIVER_OUT_1, MOTOR_DRIVER_OUT_2};
int left_motor[2]  = {MOTOR_DRIVER_OUT_3, MOTOR_DRIVER_OUT_4};

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

void setup() 
{
  // Begin serial communnications
  Serial.begin(115200);

  // Set the pins to OUTPUT
  pinMode(MOTOR_DRIVER_OUT_1, OUTPUT);
  pinMode(MOTOR_DRIVER_OUT_2, OUTPUT);
  pinMode(MOTOR_DRIVER_OUT_3, OUTPUT);
  pinMode(MOTOR_DRIVER_OUT_4, OUTPUT);

  // Make sure the motors are off
  digitalWrite(MOTOR_DRIVER_OUT_1, LOW);
  digitalWrite(MOTOR_DRIVER_OUT_2, LOW);
  digitalWrite(MOTOR_DRIVER_OUT_3, LOW);
  digitalWrite(MOTOR_DRIVER_OUT_4, LOW);
  
  RemoteXY_Init ();  // initialization by macros

}

void loop() 
{ 
  RemoteXYEngine.handler ();   
  // Show the variables
  Serial.print("joystick-01 [");
  Serial.print(RemoteXY.joystick_01_x);
  Serial.print(", ");
  Serial.print(RemoteXY.joystick_01_y);
  Serial.print("]");
  Serial.println();
  if (RemoteXY.connect_flag)
  {
    drive(left_motor, RemoteXY.joystick_01_y - RemoteXY.joystick_01_x);
    drive(right_motor, RemoteXY.joystick_01_y + RemoteXY.joystick_01_x);
  }
  else
  {
    drive(left_motor, 0);
    drive(right_motor, 0);
  }
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXYEngine.delay() 

}


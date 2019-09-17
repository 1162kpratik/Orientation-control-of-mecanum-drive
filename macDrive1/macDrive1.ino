//motor 1
#define pwm1 9
#define dir1 5  

// motor 2
#define pwm2 10
#define dir2 6  

// motor 3 rpm=750
#define pwm3 11
#define dir3 7

  //motor 4
#define pwm4 3
#define dir4 8 


void setup() {
  // put your setup code here, to run once:
pinMode(dir1, OUTPUT);
pinMode(pwm1, OUTPUT);

pinMode(dir2, OUTPUT);
pinMode(pwm2, OUTPUT);

pinMode(dir3, OUTPUT);
pinMode(pwm3, OUTPUT);

pinMode(dir4, OUTPUT);
pinMode(pwm4, OUTPUT);
}

void loop() {
//motor1
 analogWrite(pwm1,20);
 digitalWrite(dir1,HIGH);   //forward
// digitalWrite(dir1, LOW);  //backward

//motor2
 analogWrite(pwm2,20);
// digitalWrite(dir2+,HIGH);   //forward
 digitalWrite(dir2, LOW);  //backward

//motor3
 analogWrite(pwm3,25);
// digitalWrite(dir3,HIGH);   //forward
 digitalWrite(dir3, LOW);  //backward

//motor4
 analogWrite(pwm4,20);
 digitalWrite(dir4,HIGH);   //forward
// digitalWrite(dir4, LOW);  //backward
 
}

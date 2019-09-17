#include <Wire.h>
#include <math.h>
#define address 0x1E //0011110b, I2C 7bit address of HMC5883

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

//Initialize Serial and I2C communications
  Serial.begin(9600);
  Wire.begin();  
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
}

void loop() {
  int x,y,z; //triple axis data
  int xmin,xmax,ymin,ymax,zmin,zmax;
  xmin=0; xmax=0; ymax=0; ymin = 0; zmin=0;zmax=0;
  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();
  
 
 //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read()<<8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read()<<8; //Y msb
    y |= Wire.read(); //Y lsb
  }
  
  //Print out values of each axis
//  Serial.print("  x: ");
//  Serial.print(x);
//  Serial.print("  y: ");
//  Serial.print(y);
//  Serial.print("  z: ");
//  Serial.println(z);

  int angle =((atan2(y,x))*(180 /PI));
  Serial.print("angle:  ");
  Serial.println(angle); 

if(angle!=0)
{
      if(angle>0)
        {
          //motor1
 analogWrite(pwm1,20);
 digitalWrite(dir1,HIGH);   //forward
// digitalWrite(dir1, LOW);  //backward

//motor2
 analogWrite(pwm2,20);
// digitalWrite(dir2+,HIGH);   //forward
 digitalWrite(dir2, LOW);  //backward

//motor3
 analogWrite(pwm3,30);
// digitalWrite(dir3,HIGH);   //forward
 digitalWrite(dir3, LOW);  //backward

//motor4
 analogWrite(pwm4,20);
 digitalWrite(dir4,HIGH);   //forward
// digitalWrite(dir4, LOW);  //backward
 
            }
          else if(angle<0)
            {
              //motor1
 analogWrite(pwm1,20);
// digitalWrite(dir1,HIGH);   //forward
 digitalWrite(dir1, LOW);  //backward

//motor2
 analogWrite(pwm2,20);
 digitalWrite(dir2,HIGH);   //forward
// digitalWrite(dir2, LOW);  //backward

//motor3
 analogWrite(pwm3,25);
 digitalWrite(dir3,HIGH);   //forward
// digitalWrite(dir3, LOW);  //backward

//motor4
 analogWrite(pwm4,20);
// digitalWrite(dir4,HIGH);   //forward

 digitalWrite(dir4, LOW);  //backward
 
              }
 }
 else
  {
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    analogWrite(pwm3,0);
    analogWrite(pwm4,0);
    
    }


}

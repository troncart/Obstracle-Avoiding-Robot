/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********Obstacle Avoiding Robot/ Troncar**************
***********13-07-2019**************
*/
 int trigPin = 12;   
int echoPin = 13;    

int M21 = 10;       //reverse motion of left motor
int M22 = 5;       //forward motion of the left motor
int M11 = 9;      //REVerse motion of Right motor
int M12 = 3;      //ForWarD motion of Right motor

long duration, distance;

void setup() {
  Serial.begin(9600);
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(M21, OUTPUT);      // set Motor pins as output
  pinMode(M22, OUTPUT);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}
void forward()
{
    digitalWrite(M12, LOW);                    // move forward
    digitalWrite(M11, HIGH);
    digitalWrite(M22, LOW);                                
    digitalWrite(M21, HIGH);
}
void stop0()
{
    digitalWrite(M12,LOW);  //Stop                
    digitalWrite(M11, LOW);
    digitalWrite(M22, LOW);                                
    digitalWrite(M21, LOW);
}
void backward()
{
    digitalWrite(M12, HIGH);      //movebackword         
    digitalWrite(M11, LOW);
    digitalWrite(M22, HIGH);                                
    digitalWrite(M21, LOW);
}
void turn()
{
    digitalWrite(M12, HIGH);       
    digitalWrite(M11, LOW);   
    digitalWrite(M22, LOW);                                 
    digitalWrite(M21, HIGH);  
}
void loop() 
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = (duration*0.034)/2;   // convert to distance
  delay(10);
    Serial.println(distance);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 25)            
  forward();
  else
  {
    stop0(); 
    delay(500);
    backward(); 
    delay(500);
    stop0();
    delay(100);  
    turn();
    delay(250);
  }

}

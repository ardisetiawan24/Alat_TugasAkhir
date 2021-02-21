  /*
   * Bandar Lampung 02/22/2021
   * Bismillah Wisuada
  */
  #include <Wire.h>
  #include <Adafruit_MLX90614.h>
  
  Adafruit_MLX90614 mlx = Adafruit_MLX90614();
  const int trigPin = D5; 
  const int echoPin = D6; 
  const int relayPin = D0;
  const int floating = D3;
  String disinfektan;
  float Bacasuhu;
  const int buzzer = D6;
  
  long duration;
  int distance;
  void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(relayPin, OUTPUT);
  pinMode(floating, INPUT_PULLUP);
  digitalWrite(relayPin, HIGH);  
  mlx.begin();   
  }
  
  void loop() {
   
  
  }
  
void Sensor_Suhu(){
      
  Serial.print("Suhu Tubuh = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println("*C");
  Serial.println();
  delay(500);

  Bacasuhu = mlx.readObjectTempC();
  Serial.println(Bacasuhu);

  if (Bacasuhu > 37){
    Serial.println ("SUHU ANDA TIDAK NORMAL");
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
  }else if(Bacasuhu < 37){
    Serial.println("WELCOME");
   
  }else{
    Serial.println("Suhu Terbaca");
  }
    
    
 }
  
void Sensor_Ultrasonic(){
      // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(500);
  
      if (distance < 30){
      digitalWrite(relayPin, LOW);
      delay(5000);
       digitalWrite(relayPin, HIGH);
      delay(5000);
     }else {
      digitalWrite(relayPin, HIGH);
      delay(500);
     }  
    }
  
  
 void Sensor_Level(){
     if(digitalRead(floating) == HIGH){
      Serial.println("Disinfektan Full");
      disinfektan="Full";
    }else{
      Serial.println("Disinfektan Habis");
      disinfektan="Habis";
    }
  }


const int dry_value = 503;
const int wet_value = 260;
int interval = (dry_value - wet_value)/3;
int soil_moisture = 0;
float relative_humidity = 0;

const float trigger_level = 0.5; // percentage

const int relay_pin = 2;

void setup() {
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, HIGH);

  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

bool is_dry(float humidity){
  if (humidity < trigger_level){
    return true;
  } else {
    return false;
  }
}

bool is_wet(float humidity){
  if (humidity >= trigger_level){
    return true;
  } else {
    return false;
  }
}

void loop() {
  
  soil_moisture = analogRead(A0);  //put Sensor insert into soil
  
  relative_humidity = 1.0 - (float(soil_moisture-wet_value) / float(dry_value-wet_value));
  Serial.println(relative_humidity);
  
  if(is_dry(relative_humidity)){
    Serial.println("Dry!");
    digitalWrite(relay_pin, LOW);
  }
  
  else if (is_wet(relative_humidity)){
    Serial.println("Wet!");
    digitalWrite(relay_pin, HIGH);

  }
  
  delay(100);
}

int relayPin = 4;
int sensor_pin = A0;
int output_value;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(sensor_pin, INPUT);

  Serial.println("Initializing Automated Plant Watering System...");
  delay(2000);
  Serial.println("==========================================");
  Serial.println("Reading Moisture Levels...");
}

void loop() {
  output_value = analogRead(sensor_pin);
  output_value = map(output_value, 550, 10, 0, 100); // Map sensor value to percentage

  Serial.print("Soil Moisture: ");
  Serial.print(output_value);
  Serial.println(" %");

  if (output_value < 20) {
    digitalWrite(relayPin,LOW); // Turn ON water pump
    Serial.println("Pump Status  : ON (Watering the plant)");
  } else {
    digitalWrite(relayPin,HIGH); // Turn OFF water pump
    Serial.println("Pump Status  : OFF (Soil is moist enough)");
  }

  Serial.println("------------------------------------------");
  delay(1000);
}
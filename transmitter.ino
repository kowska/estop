void setup()
{
  Serial.begin(2400);  // Hardware supports up to 2400, but 1200 gives longer range
  delay(1000);
}

void loop()
{
  Serial.println(271);
  writeUInt(271); 
  delay(1000); 
}

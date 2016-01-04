void setup()
{
  Serial.begin(2400);  // Hardware supports up to 2400, but 1200 gives longer range
  delay(2000);
  Serial.println("ready");
}

void loop()
{
  Serial.println(readUInt(true)); 
}

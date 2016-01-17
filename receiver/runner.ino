// Julia Karkowska
// 1-16-2016
// https://github.com/kowska/estop

void setup()
{
  Serial.begin(1200);  
  while(!Serial){};
  Serial.println("ready");
}

void loop()
{
  Serial.println(readUInt(true)); 
}

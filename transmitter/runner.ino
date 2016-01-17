// RF Transmitter
// (requires transDriver.ino)
//
// Julia Karkowska
// 1-16-2016
// https://github.com/kowska/estop

int car_id[] = {1, 2, 3, 4};

void setup()
{
  Serial.begin(1200);  
  while(!Serial){};
  Serial.println("ready");
}

void loop()
{
  Serial.println();
  writeUInt(271, car_id[0]);
  delay(1000); 
}

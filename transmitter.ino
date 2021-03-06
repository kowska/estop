// Author:
// Maurice Ribble 
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// 
// Modified:
// Julia Karkowska
// 1-16-2016
// https://github.com/kowska/estop

#define NETWORK_SIG_SIZE 3
#define VAL_SIZE         2
#define CHECKSUM_SIZE    1
#define PACKET_SIZE      (NETWORK_SIG_SIZE + VAL_SIZE + CHECKSUM_SIZE)

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


// Sends an unsigned int over the RF network
void writeUInt(unsigned int val, unsigned int net_addr)
{
  byte g_network_sig[NETWORK_SIG_SIZE] = {0x8F, 0xAA, net_addr};
  byte checksum = (val/256) ^ (val&0xFF);
  Serial.write(0xF0);  // This gets reciever in sync with transmitter
  Serial.write(g_network_sig, NETWORK_SIG_SIZE);
  Serial.write((byte*)&val, VAL_SIZE);
  Serial.write(checksum); //CHECKSUM_SIZE
}




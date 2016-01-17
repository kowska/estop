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
#define NET_ADDR 1 // The network address byte can be 1 through 4

const byte g_network_sig[NETWORK_SIG_SIZE] = {0x8F, 0xAA, NET_ADDR};  // Few bytes used to initiate a transfer

// Receives an unsigned int over the RF network
unsigned int readUInt(bool wait)
{
  int pos = 0;          // Position in the network signature
  unsigned int val;     // Value of the unsigned int
  byte c = 0;           // Current byte
  
  if((Serial.available() < PACKET_SIZE) && (wait == false))
  {
    return 0xFFFF;
  }
  
  while(pos < NETWORK_SIG_SIZE)
  { 
    while(Serial.available() == 0); // Wait until something is avalible
    c = Serial.read();

    if (c == g_network_sig[pos])
    {
      if (pos == NETWORK_SIG_SIZE-1)
      {
        byte checksum;

        while(Serial.available() < VAL_SIZE + CHECKSUM_SIZE); // Wait until something is avalible
        val      =  Serial.read();
        val      += ((unsigned int)Serial.read())*256;
        checksum =  Serial.read();
        
        if (checksum != ((val/256) ^ (val&0xFF)))
        {
          // Checksum failed
          pos = -1;
        }
      }
      ++pos;
    }
    else if (c == g_network_sig[0])
    {
      pos = 1;
    }
    else
    {
      pos = 0;
      if (!wait)
      {
        return 0xFFFF;
      }
    }
  }
  return val;
}

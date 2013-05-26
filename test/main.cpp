/* 
 * File:   main.cpp
 * Author: c
 *
 * Created on May 14, 2013, 6:32 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <smpp.hpp>
#include <stdio.h>
#include <cstring>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

  std::string asd;

  uint32_t octet = 0;
  
  smpp::PDUEncoder* encoder = new smpp::PDUEncoder();

  smpp::PDU_BindTransmiter* tr = new smpp::PDU_BindTransmiter();
  tr->setSystemID("test");
  tr->setPassword("password");
  tr->encode(encoder);

  char line[17];

  uint32_t i = 0;

  std::vector<uint8_t>& data = encoder->read();
  for(; i < encoder->getLength(); i++) {

    octet = i / 16;
    if( (i%16) == 0 ) {
      printf("\n%08x\t", octet);
      memset(&line, 0x00, 17);
    }

    printf("%02x ", data.at(i));

    if( data.at(i) >= 0x21 && data.at(i) < 0x7E ) {
      line[i%16] = data.at(i);
    }
    else {
      line[i%16] = '.';
    }

    if( (i%16) == 15 ) {
      printf("\t%s", line);
    }
  }
 
  int s = 15 - (i%16);
  printf("[%d]", i%16);
  if( s > 0 && (i%16) != 0 ) {
    for(int l = 0; l < s; l++) {
      printf("   ");
    }
    printf("\t%s", line);
  }

  //encoder->

  delete tr;
  delete encoder;

  printf("\n");

  return 0;
}


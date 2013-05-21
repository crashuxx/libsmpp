/* 
 * File:   main.cpp
 * Author: c
 *
 * Created on May 14, 2013, 6:32 PM
 */

#include <cstdlib>
#include <smpp.hpp>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	smpp::PDUEncoder* encoder = new smpp::PDUEncoder();
	delete encoder;
	return 0;
}


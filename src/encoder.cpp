#include <smpp.hpp>

#ifdef __WIN32
#include <winsock2.h>
#elif __linux
#include <arpa/inet.h>
#endif


//for debug only
#include <stdio.h>

namespace smpp {
	
	PDUEncoder::PDUEncoder() {
		
		length = 0;
		id = 0;
		status = 0;
		sequence = 0;
		
		writeUInt32(length);
		writeUInt32(id);
		writeUInt32(status);
		writeUInt32(sequence);
	}
	
	PDUEncoder::~PDUEncoder() {
		
	}
	
	void PDUEncoder::write(uint32_t start, uint32_t value) {
		
		uint32_t tmp;
		uint8_t *p;
		
		tmp = htonl(value);
		p = (uint8_t*)&tmp;
		for(int i = 0; i < 4; i++) {
			data[start+i] = p[i];
		}
	}
	
	void PDUEncoder::rewriteHeader() {
		
		write(0, data.size());
		write(4, id);
		write(8, status);
		write(12, sequence);
	}
	

	std::vector<uint8_t>& PDUEncoder::read() {
		
		rewriteHeader();
		return data;
	}
	
	void PDUEncoder::dump() {
		length = data.size();
		
		std::cout << "PDU Length: " << length << std::endl;
		std::cout << "PDU ID: " << id << std::endl;
		std::cout << "PDU ID: " << SMPP_CMD_BIND_RECEIVER_RESP << std::endl;
		std::cout << "PDU Status: " << status << std::endl;
		std::cout << "PDU Sequence: " << sequence << std::endl;
		
		printf("Hex dump: \n");
		
		for(uint32_t i = 0; i < length; i++) {
			printf("%02X ", data[i]);
		}
		printf("\n");
		fflush(stdout);
	}
	
	uint32_t PDUEncoder::getLength() {
		return length = data.size();
	}
	
	void PDUEncoder::setID(uint32_t id) {
		this->id = id;
	}
	
	void PDUEncoder::setStatus(uint32_t status) {
		this->status = status;
	}
	
	void PDUEncoder::setSequence(uint32_t sequence) {
		this->sequence = sequence;
	}
	
	void PDUEncoder::writeUInt8(uint8_t value) {
		data.push_back(value);
	}
	
	void PDUEncoder::writeUInt16(uint16_t value) {
		uint16_t tmp = htonl(value);
		uint8_t *p = (uint8_t*)&tmp;
		for(size_t i = 0; i < sizeof(uint16_t); i++) {
			data.push_back(p[i]);
		}
	}
	
	void PDUEncoder::writeUInt32(uint32_t value) {
		uint32_t tmp = htonl(value);
		uint8_t *p = (uint8_t*)&tmp;
		for(int i = 0; i < 4; i++) {
			data.push_back(p[i]);
		}
	}
	
	void PDUEncoder::writeCString(uint8_t* value) {
		
		if( value != NULL ) {
		
			for(uint32_t i = 0; value[i] != 0x00 ;i++) {
				
				data.push_back(value[i]);
			}
		}
		
		data.push_back(0x00);
	}
	
	void PDUEncoder::writeCString(std::string &value) {
		writeCString( (uint8_t*)value.c_str() );
	}
}

#include <smpp.hpp>

namespace smpp {
	
	TLV_UInt8::TLV_UInt8() : TLV() {
		tag = SMPP_TLV_INTERFACE_VERSION;
		length = sizeof(uint8_t);
	}
	
	TLV_UInt8::~TLV_UInt8() {
		
	}
	
	void TLV_UInt8::encode( PDUEncoder *pdu ) {
		
		pdu->writeUInt16(tag);
		pdu->writeUInt16(length);
		pdu->writeUInt8(value);
	}
	
	void TLV_UInt8::setValue(uint8_t value) {
		this->value = value;
	}
}

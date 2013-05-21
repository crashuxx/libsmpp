#include <smpp.hpp>

namespace smpp {
	
	PDU_Unbind::PDU_Unbind() : PDU() {
	}
	
	PDU_Unbind::PDU_Unbind( PDUDecoder *pdu ) : PDU() {
		decode(pdu);
	}
	
	PDU_Unbind::~PDU_Unbind() {
	}
	
	void PDU_Unbind::decode( PDUDecoder *pdu ) {
		
		pdu->rewind();
		pdu->skipHeader();
		
		setStatus( pdu->getStatus() );
		setSequence( pdu->getSequence() );
	}
	
	void PDU_Unbind::encode( PDUEncoder *pdu ) {

		pdu->setID(SMPP_CMD_UNBIND);
		pdu->setSequence( getSequence() );
		pdu->setStatus( getStatus() );
	}
}

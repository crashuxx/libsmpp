#include <smpp.hpp>

namespace smpp {
	
	PDU_GenericNack::PDU_GenericNack() : PDU() { }
	
	PDU_GenericNack::PDU_GenericNack( PDUDecoder *decoder ) : PDU() {
		decode(decoder);
	}
	
	PDU_GenericNack::~PDU_GenericNack() { }
		
	void PDU_GenericNack::decode( PDUDecoder *pdu ) {
		
		pdu->rewind();
		pdu->skipHeader();
		
		setStatus( pdu->getStatus() );
		setSequence( pdu->getSequence() );
	}
	
	void PDU_GenericNack::encode( PDUEncoder *pdu ) {
		
		pdu->setID(SMPP_CMD_GENERIC_NACK);
		pdu->setSequence( getSequence() );
		pdu->setStatus( getStatus() );
	}
}

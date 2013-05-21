#include <smpp.hpp>

namespace smpp {
	
	PDU_UnbindResponse::PDU_UnbindResponse() : PDU() { }
	
	PDU_UnbindResponse::PDU_UnbindResponse( PDUDecoder* decoder ) : PDU() { 
		decode(decoder);
	}
	
	PDU_UnbindResponse::PDU_UnbindResponse( PDU_Unbind* pdu ) : PDU() { 
		
		if( pdu != NULL ) {
			setSequence( pdu->getSequence() );
		}
	}
	
	PDU_UnbindResponse::~PDU_UnbindResponse() { }
	
	void PDU_UnbindResponse::decode( PDUDecoder *pdu ) {
		
		pdu->rewind();
		pdu->skipHeader();
		
		setStatus( pdu->getStatus() );
		setSequence( pdu->getSequence() );
	}
	
	void PDU_UnbindResponse::encode( PDUEncoder *pdu ) {

		pdu->setID(SMPP_CMD_UNBIND_RESP);
		pdu->setSequence( getSequence() );
		pdu->setStatus( getStatus() );
	}
}

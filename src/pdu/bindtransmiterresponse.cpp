#include <smpp.hpp>

namespace smpp {

	PDU_BindTransmiterResponse::PDU_BindTransmiterResponse() : PDU() {
		tlv = NULL;
	}
	
	PDU_BindTransmiterResponse::PDU_BindTransmiterResponse( PDU_BindTransmiter* pdu ) : PDU() {
		
		tlv = NULL;
		
		if( pdu != NULL ) {
			setSequence( pdu->getSequence() );
		}
	}

	PDU_BindTransmiterResponse::~PDU_BindTransmiterResponse() {
		
		if( tlv != NULL ) {
			delete tlv;
		}
	}

	void PDU_BindTransmiterResponse::decode( PDUDecoder *pdu ) {
		
		pdu->rewind();
		pdu->skipHeader();

		setStatus( pdu->getStatus() );
		setSequence( pdu->getSequence() );
	}

	void PDU_BindTransmiterResponse::encode( PDUEncoder *pdu ) {

		pdu->setID(SMPP_CMD_BIND_TRANSMITTER_RESP);
		pdu->setSequence( getSequence() );
		pdu->setStatus( getStatus() );
		
		pdu->writeCString( system_id );
		
		if( tlv != NULL ) {
			tlv->encode(pdu);
		}
	}
	
	void PDU_BindTransmiterResponse::setSystemID(std::string value) {
		system_id = value;
	}
	
	TLV_UInt8& PDU_BindTransmiterResponse::InterfaceVersion() {
		if( tlv == NULL ) {
			tlv = new TLV_UInt8();
		}
		
		return *tlv;
	}

}
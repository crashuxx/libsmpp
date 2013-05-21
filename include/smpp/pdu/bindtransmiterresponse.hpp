/* 
 * File:   bindtransmiterresponse.hpp
 * Author: c
 *
 * Created on 1 maj 2013, 12:09
 */

#ifndef __SMPP__PDU_BINDTRANSMITERRESPONSE_HPP__
#define	__SMPP__PDU_BINDTRANSMITERRESPONSE_HPP__

#include <smpp.hpp>

namespace smpp {
	
	class PDU_BindTransmiterResponse : public PDU {
	public:
		static const uint32_t id = SMPP_CMD_BIND_TRANSMITTER_RESP;

		PDU_BindTransmiterResponse();
		PDU_BindTransmiterResponse( PDU_BindTransmiter* pdu );
		~PDU_BindTransmiterResponse();

		void decode( PDUDecoder* pdu );
		void encode( PDUEncoder* pdu );

		void setSystemID(std::string value);
		TLV_UInt8& InterfaceVersion();

	private:
		std::string system_id;
		TLV_UInt8 *tlv;

	};
}

#endif	/* __SMPP__PDU_BINDTRANSMITERRESPONSE_HPP__ */


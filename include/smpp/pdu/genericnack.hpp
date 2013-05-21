/* 
 * File:   unbind.hpp
 * Author: c
 *
 * Created on 1 maj 2013, 12:13
 */

#ifndef __SMPP__PDU_GENERICNACK_HPP__
#define	__SMPP__PDU_GENERICNACK_HPP__

#include <smpp.hpp>

namespace smpp {
	
	class PDU_GenericNack : public PDU {
	public:
		PDU_GenericNack();
		PDU_GenericNack( PDUDecoder *decoder );
		~PDU_GenericNack();
		
		void decode( PDUDecoder *pdu );
		void encode( PDUEncoder *pdu );
	};
}

#endif	/* __SMPP__PDU_GENERICNACK_HPP__ */


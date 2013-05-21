/* 
 * File:   unbind.hpp
 * Author: c
 *
 * Created on 1 maj 2013, 12:13
 */

#ifndef __SMPP__PDU_UNBIND_HPP__
#define	__SMPP__PDU_UNBIND_HPP__

#include <smpp.hpp>

namespace smpp {
	
	class PDU_Unbind : public PDU {
	public:
		PDU_Unbind();
		PDU_Unbind( PDUDecoder *pdu );
		~PDU_Unbind();
		
		void decode( PDUDecoder *pdu );
		void encode( PDUEncoder *pdu );
	};
}

#endif	/* __SMPP__PDU_UNBIND_HPP__ */


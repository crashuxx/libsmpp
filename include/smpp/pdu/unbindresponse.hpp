/* 
 * File:   unbindresponse.hpp
 * Author: c
 *
 * Created on 1 maj 2013, 12:13
 */

#ifndef __SMPP__PDU_UNBINDRESPONSE_HPP__
#define	__SMPP__PDU_UNBINDRESPONSE_HPP__

#include <smpp.hpp>

namespace smpp {
	
	class PDU_UnbindResponse : public PDU {
	public:
		PDU_UnbindResponse();
		PDU_UnbindResponse( PDU_Unbind* pdu );
		PDU_UnbindResponse( PDUDecoder* decoder );
		~PDU_UnbindResponse();
		
		void decode( PDUDecoder* pdu );
		void encode( PDUEncoder* pdu );
	};
}

#endif	/* __SMPP__PDU_UNBINDRESPONSE_HPP__ */


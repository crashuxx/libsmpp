/* 
 * File:   tlv_interfaceversion.hpp
 * Author: c
 *
 * Created on 30 kwiecień 2013, 19:41
 */

#ifndef __SMPP__TLV_UINT8_HPP__
#define	__SMPP__TLV_UINT8_HPP__

#include <smpp.hpp>

namespace smpp {
	
	class TLV_UInt8 : public TLV {
	public:
		TLV_UInt8();
		~TLV_UInt8();
		
		void setValue(uint8_t value);
		
		void encode( PDUEncoder *pdu );
			
	protected:
		uint8_t value;
	};
}

#endif	/* __SMPP__TLV_UINT8_HPP__ */


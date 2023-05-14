#pragma once

#include "pch.h"

struct NGMG_MESSAGE_STRUCT
{
	//ƒ¿ÕÕ€≈ œ–»≈Ã¿
	CString RECEIVED_DATE;
	CString RECEIVED_TIME;
	CString PORT_TYPE_IN;
	CString PORT_IN;
	//ƒ¿ÕÕ€≈ Œ“œ–¿¬ »
	CString SEND_DATE;
	CString SEND_TIME;
	CString PORT_TYPE_OUT;
	CString PORT_OUT;
	//œ¿ ≈“
	CString MAVLINK_FLAG;
	CString CONTROL_SUM_FLAG;
	CString PROTOCOL_VER;
	CString PAYLOAD_LENGTH;
	CString PACKET_SEQUENCE;
	CString SYSTEM_ID;
	CString COMPONENT_ID;
	CString MESSAGE_ID;
	CString DATA;
	CString CONTROL_SUM;

	NGMG_MESSAGE_STRUCT() :
		MAVLINK_FLAG(L""),
		CONTROL_SUM_FLAG(L""),
		PROTOCOL_VER(L""),
		PAYLOAD_LENGTH(L""),
		PACKET_SEQUENCE(L""),
		SYSTEM_ID(L""),
		COMPONENT_ID(L""),
		MESSAGE_ID(L""),
		DATA(L""),
		CONTROL_SUM(L""),
		RECEIVED_DATE(L""),
		RECEIVED_TIME(L""),
		PORT_TYPE_IN(L""),
		PORT_IN(L""),
		SEND_DATE(L""),
		SEND_TIME(L""),
		PORT_TYPE_OUT(L""),
		PORT_OUT(L"") {};
};
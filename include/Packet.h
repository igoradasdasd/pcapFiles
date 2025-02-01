/*
 * Packet.h
 *
 *  Created on: 27 янв. 2025 г.
 *      Author: Игорь
 */

#ifndef INCLUDE_PACKET_H_
#define INCLUDE_PACKET_H_

#include <cstdint>
#include <vector>

struct Packet
{
	Packet(){Packet_Data_variable_length = new uint8_t[2];};
	// данные для записи
	uint32_t Timestamp_seconds;
	uint32_t Timestamp_microseconds_or_nanoseconds;
	uint32_t Captured_Packet_Length;
	uint32_t Original_Packet_Length;
	uint8_t* Packet_Data_variable_length;
	~Packet(){delete [] Packet_Data_variable_length;};
	// данные для просмотра
	uint32_t Timestamp_seconds_v;
	uint32_t Timestamp_microseconds_or_nanoseconds_v;
	uint32_t Captured_Packet_Length_v;
	uint32_t Original_Packet_Length_v;
};



#endif /* INCLUDE_PACKET_H_ */

/*
 * decoder.h
 *
 *  Created on: 23 янв. 2025 г.
 *      Author: Игорь
 */

#ifndef INCLUDE_MERGE_H_
#define INCLUDE_MERGE_H_

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>

#include "Packet.h"

class Merge
{
public:
	Merge(std::string &file1, std::string &file2, std::string &file3):
		sfile1(file1), sfile2(file2), resultF(file3){}
	~Merge() = default;
	void work();

private:
	void prepareWork(std::ifstream & f1, std::ifstream & f2, std::ofstream & result);
	void mainWork(std::ifstream & f1, std::ifstream & f2, std::ofstream & result);
	uint32_t decoding_from_big_endian(std::ifstream & f1);
	uint32_t coding_from_big_endian(Packet &p);
	void read_packet(std::ifstream &f, Packet &p);
	void write_packet(std::ofstream &f, Packet &p);
	bool time_packet_compare();
	void write_uint_32(std::ofstream &f, uint32_t data);

//-----------------------
	void update_data_stream(std::ifstream &f, uint32_t& packed_time_sec,
							uint32_t& packed_time_msec, uint32_t& packed_lenght);
	void copy_packed(std::ifstream & f, std::ofstream & result, uint32_t packed_lenght);
//-----------------------

	uint32_t packed_time_sec_1;		// время пакета первого потока в секундах
	uint32_t packed_time_sec_2;
	uint32_t packed_time_msec_1;	// время пакета первого потока в мс или нс
	uint32_t packed_time_msec_2;
	uint32_t packed_lenght_1;		// длина пакета первого потока в байтах с заголовком
	uint32_t packed_lenght_2;

	std::string sfile1;
	std::string sfile2;
	std::string resultF;

	Packet packet_from_file1;
	Packet packet_from_file2;
};



#endif /* INCLUDE_MERGE_H_ */

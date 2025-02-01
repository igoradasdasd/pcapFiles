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
	uint32_t decoding_from_big_endian(uint32_t & in);
	void read_packet(std::ifstream &f, Packet &p);
	void write_packet(std::ofstream &f, Packet &p);
	bool time_packet_compare();

	std::string sfile1;
	std::string sfile2;
	std::string resultF;

	Packet packet_from_file1;
	Packet packet_from_file2;
};



#endif /* INCLUDE_MERGE_H_ */

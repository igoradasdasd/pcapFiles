/*
 * Merge.cpp
 *
 *  Created on: 23 янв. 2025 г.
 *      Author: Игорь
 */

#include "../include/Merge.h"

#define FILE_HEADER_LENGTH 24

// для декодирования 32 бит после чтения
uint32_t Merge::decoding_from_big_endian(uint32_t & in)
{
	uint32_t tt = 0;
	uint8_t b;
	char ff;
	for (int i = 3, y = 0; i >= 0; --i, ++y)
	{
		ff = in >> 8*i;
		b = static_cast<uint8_t>(ff);
		tt += static_cast<uint32_t>( b << 8*y);
	}
	return tt;
}

void Merge::work()
{
	std::ifstream f1;
	std::ifstream f2;
	std::ofstream resultF1;
	f1.open(sfile1, std::ios::binary);
	f2.open(sfile2, std::ios::binary);
	resultF1.open(resultF, std::ios::binary);

	prepareWork(f1, f2, resultF1);
	mainWork(f1, f2, resultF1);

	f1.close();
	f2.close();
	resultF1.close();
}

// подготоваливам файлы к обработке
void Merge::prepareWork(std::ifstream & f1_1, std::ifstream & f2_1, std::ofstream & resultF_1)
{
	uint32_t buff[6];

	f1_1.read((char*)buff, FILE_HEADER_LENGTH);
	resultF_1.write((char*)buff, FILE_HEADER_LENGTH);

	f2_1.seekg(24, std::ios::cur);
}

// основной цикл работы
void Merge::mainWork(std::ifstream & f1, std::ifstream & f2, std::ofstream & result)
{
	if (f1.tellg()>0)
		read_packet(f1, packet_from_file1);
	if (f2.tellg()>0)
		read_packet(f2, packet_from_file2);
	// пока не закончится один из исходных файлов
	while( f1.tellg()>0 && f2.tellg()>0)
	{
		if ( time_packet_compare() )
		{
			write_packet(result, packet_from_file1);
			read_packet(f1, packet_from_file1);
		}
		else
		{
			write_packet(result, packet_from_file2);
			read_packet(f2, packet_from_file2);
		}
	}
	// при необходимости, копируем остатки
	while (f1.tellg() > 0)
	{
		write_packet(result, packet_from_file1);
		read_packet(f1, packet_from_file1);
	}

	while (f2.tellg() > 0)
	{
		write_packet(result, packet_from_file2);
		read_packet(f2, packet_from_file1);
	}
}

//считываем пакет
void Merge::read_packet(std::ifstream &f, Packet &p)
{
	delete [] p.Packet_Data_variable_length;

	f.read((char*)&p.Timestamp_seconds, sizeof(uint32_t) * 4);

	p.Timestamp_seconds_v = decoding_from_big_endian(p.Timestamp_seconds);
	p.Timestamp_microseconds_or_nanoseconds_v = decoding_from_big_endian(p.Timestamp_microseconds_or_nanoseconds);
	p.Captured_Packet_Length_v = decoding_from_big_endian(p.Captured_Packet_Length);
	p.Original_Packet_Length_v = decoding_from_big_endian(p.Original_Packet_Length);

	p.Packet_Data_variable_length = new uint8_t[p.Captured_Packet_Length_v];

	f.read((char*)p.Packet_Data_variable_length, p.Captured_Packet_Length_v);
}

//записываем пакет
void Merge::write_packet(std::ofstream &f, Packet &p)
{
	f.write((char*)&p.Timestamp_seconds, sizeof(uint32_t) * 4);

	f.write((char*)p.Packet_Data_variable_length, p.Captured_Packet_Length_v);
}

// возвращает истину, если пакет потока 1 пришел раньше пакета потока 2 или в тоже время
bool Merge::time_packet_compare()
{
	if (packet_from_file1.Timestamp_seconds_v < packet_from_file2.Timestamp_seconds_v)
		return true;
	if (packet_from_file1.Timestamp_seconds_v > packet_from_file2.Timestamp_seconds_v)
		return false;
	if  (packet_from_file1.Timestamp_microseconds_or_nanoseconds_v <= packet_from_file2.Timestamp_microseconds_or_nanoseconds_v)
		return true;
	else
		return false;
}




/*
 * Merge.cpp
 *
 *  Created on: 23 янв. 2025 г.
 *      Author: Игорь
 */

#include "../include/Merge.h"

#define PACKET_HEADER_LENGHT 16		// длина заголовка пакета в байтах

// для декодирования 32 бит после чтения
uint32_t Merge::decoder(std::ifstream & f1_1)
{
	uint32_t tt = 0;
	uint8_t b;
	char ff;
	for (int i = 3; i >= 0; --i)
	{
	f1_1.read((char*)&ff, sizeof(ff));
	b = static_cast<uint8_t>(ff);
	tt += static_cast<uint32_t>( b << 8*i);
	}
	// возвращаем поток в исходное состяоние
	f1_1.seekg(-4, std::ios::cur);
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
}

// подготоваливам файлы к обработке
void Merge::prepareWork(std::ifstream & f1_1, std::ifstream & f2_1, std::ofstream & resultF_1)
{
	char ff;
	for (int i = 0; i < 24; ++i)
	{
		f1_1.read((char*)&ff, sizeof(ff));
		resultF_1.write((char*)&ff, sizeof(ff));
	}
	f2_1.seekg(24, std::ios::cur);



	/*
	char bufer;
	for (int i = 0; i < 1; ++i)
	{
		f1.read((char*)&bufer, sizeof(bufer));
		resultF.write((char*)&bufer, sizeof(bufer));
	}
*/
//	f1.seekg(24, std::ios::cur);
//	f2.seekg(24, std::ios::cur);
}

// основной цикл работы
void Merge::mainWork(std::ifstream & f1, std::ifstream & f2, std::ofstream & result)
{
	if (!f1.eof())
		update_data_stream(f1, packed_time_sec_1, packed_time_msec_1, packed_lenght_1);
	if (!f2.eof())
		update_data_stream(f2, packed_time_sec_2, packed_time_msec_2, packed_lenght_2);

	while( !f1.eof() && !f2.eof())
	{

	}

}

void Merge::update_data_stream(std::ifstream &f, uint32_t& packed_time_sec,
						uint32_t& packed_time_msec, uint32_t& packed_lenght)
{
	packed_time_sec = decoder(f);
	f.seekg(4, std::ios::cur);		// переход на поле мс
	packed_time_msec = decoder(f);
	f.seekg(4, std::ios::cur);		// переход на поле длины захваченного пакета
	packed_lenght = decoder(f) + PACKET_HEADER_LENGHT;
}


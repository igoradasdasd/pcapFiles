/*
 * main.cpp
 *
 *  Created on: 23 янв. 2025 г.
 *      Author: Игорь
 */
#include <string>
#include <fstream>
#include <stdio.h>
#include <ios>
#include "./include/decoder.h"


int main()
{
	// считывание данных
	std::string sourceFile1("./pcapFiles/1.pcap");
	std::string sourceFile2("./pcapFiles/2.pcap");
	std::string sourceFile3("./pcapFiles/result.pcap");

	Merge * merge = new Merge(sourceFile1, sourceFile2, sourceFile3 );

	/*
	std::ofstream f;
	f.open("./pcapFiles/1.txt");
	f.seekp(24, std::ios::cur);
	f.close();

//	fseek(f, 24*8, SEEK_CUR);


}




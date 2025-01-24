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
#include <iostream>
#include <memory>

#include "include/Merge.h"


int main()
{
	// считывание данных
	std::string sourceFile1("./pcapFiles/1.pcap");
	std::string sourceFile2("./pcapFiles/2.pcap");
	std::string resultFile("./pcapFiles/result.pcap");

	std::shared_ptr<Merge> merge( new Merge(sourceFile1, sourceFile2, resultFile ) );
	merge->work();


/*
	std::ifstream f11;

	std::ofstream resultF1;

	f11.open(sourceFile1, std::ios::binary);
	resultF1.open(resultFile, std::ios::binary);

	char ff;
	for (int i = 0; i < 24; ++i)
	{
		f11.read((char*)&ff, sizeof(ff));
		resultF1.write((char*)&ff, sizeof(ff));
	}
*/
//	merge->work();
/*
	f11.read((char*)&ff, sizeof(ff));
	resultF1.write((char*)&ff, sizeof(ff));

	/*
	std::ofstream f;
	f.open("./pcapFiles/1.txt");
	f.seekp(24, std::ios::cur);
	f.close();

//	fseek(f, 24*8, SEEK_CUR);
*/

}




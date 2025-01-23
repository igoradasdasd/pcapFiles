/*
 * decoder.h
 *
 *  Created on: 23 янв. 2025 г.
 *      Author: Игорь
 */

#ifndef INCLUDE_DECODER_H_
#define INCLUDE_DECODER_H_

#include <string>
#include <fstream>

class Merge
{
public:
	Merge(std::string file1, std::string file2, std::string resultFile)
	{
		f1.open(file1);
		f2.open(file2);
		resultF.open(resultFile);
		int ii;
		for (int i = 0; i < 24; ++i)
		{
			f1 >> ii;
			resultF << ii;
		}
		f1.seekg(24, std::ios::cur);
		f2.seekg(24, std::ios::cur);
	}

private:
	std::string fileName;
	int beginPacket = 0;
	int endPcket = 0;

	std::ifstream f1;
	std::ifstream f2;
	std::ofstream resultF;
};



#endif /* INCLUDE_DECODER_H_ */

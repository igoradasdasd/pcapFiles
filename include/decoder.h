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
		f1.open(file1, std::ios::binary);
		f2.open(file2, std::ios::binary);
		resultF.open(resultFile, std::ios::binary);
		char ff;
		for (int i = 0; i < 24; ++i)
		{
			f1.read((char*)&ff, sizeof(ff));
			resultF.write((char*)&ff, sizeof(ff));
		}
//		f1.seekg(24, std::ios::cur);
		f2.seekg(24, std::ios::cur);
	}
	~Merge(){f1.close(); f2.close(); resultF.close();};

private:
	std::string fileName;
	int beginPacket = 0;
	int endPcket = 0;

	std::ifstream f1;
	std::ifstream f2;
	std::ofstream resultF;
};



#endif /* INCLUDE_DECODER_H_ */

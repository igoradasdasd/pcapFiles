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
	// входные данные
	std::string sourceFile1("./pcapFiles/1.pcap");
	std::string sourceFile2("./pcapFiles/2.pcap");
	std::string resultFile("./pcapFiles/result.pcap");

	std::shared_ptr<Merge> merge( new Merge(sourceFile1, sourceFile2, resultFile ) );
	merge->work();
}




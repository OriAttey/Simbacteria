//// ConsoleApplication1.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
#include <iostream>
#include <fstream>

int totalSize = 0;
int columnSize = 0;
int rowSize = 1;
char * curGeneration = nullptr;
char * nextGeneration;
int totalGen = 0;

using namespace std;

void addCell(char newCell) {
	char *tempArr = nullptr;
	tempArr = curGeneration;

	curGeneration = nullptr;
	curGeneration = new  char[totalSize + 1];

	for (int i = 0; i < totalSize; i++) {
		*(curGeneration + i) = *(tempArr + i);
	}

	*(curGeneration + totalSize - 1) = newCell;
	*(curGeneration + totalSize) = 0;

	if (totalSize == 2) {
		tempArr = NULL;
	}
	else {
		delete[]tempArr;
		tempArr = NULL;
	}
}

void readFromFile() {
	std::ifstream fin;
	fin.open("simbac.txt");

	char nextCell;
	bool firstRow = true;

	try {
		if (fin.is_open()) {
			while (!fin.eof()) {
				nextCell = 0;
				fin >> std::noskipws >> nextCell;
				if (firstRow && nextCell != '\n') {
					columnSize++;
				}
				if (nextCell == '\n') {
					if (firstRow) {
						firstRow = false;
					}
					rowSize++;
				}
				else {
					if (nextCell == ' ' || nextCell == '*') {
						totalSize++;
						if (columnSize == 1) {
							curGeneration = new char[columnSize];
							*curGeneration = nextCell;
							*(curGeneration + 1) = 0;
						}
						else {
							addCell(nextCell);
						}
					}
				}
			}
		}
		fin.close();
	}
	catch (exception e) {
		cout << "Invalid File";
	}

}

int singleIndex(int row, int col)
 {
	return (row * columnSize) + col;
}

int checkNeighbors(int cell)
 {
	int neighbors = 0;
	int cellI, cellJ;
	int gar;

	for (int i = -1; i <= 1; i++) {
		cellI = cell / columnSize;
		cellI = cellI + i;

		for (int j = -1; j <= 1; j++) {
			cellJ = cell % columnSize;
			cellJ = cellJ + j;
			gar = singleIndex(cellI, cellJ);

			if (!(cellI < 0) && !(cellJ < 0)
				&& !(cellJ >= columnSize) && !(cellI >= rowSize)
				&& !(gar == cell)) {
				if (*(curGeneration + singleIndex(cellI, cellJ)) == '*') {
					neighbors++;
				}
			}
		}
	}
	return neighbors;
}

void printSimulation(char *printArr)
 {
	for (int i = 0; i < totalSize; i++)
      {
		if (i%columnSize == 0) {
			std::cout << std::endl;
		}
		std::cout << *(printArr + i);
	}
	std::cout << std::endl;
}

void newCell(int cell, int neighbors, bool isEmpty) {
	if (isEmpty)
      {
		if (neighbors == 3)
		{
			*(nextGeneration + cell) = '*';
		}
	}
	else {
		if (neighbors < 2 || neighbors > 3) {
			*(nextGeneration + cell) = ' ';
		}
	}
}

void printToFile()
{
	std::fstream fout;
	fout.open("simbac.txt");

	try
	{
		if (fout.is_open())
         {
			for (int i = 0; i < totalSize; i++)
			{
				if (i%columnSize == 0 && i != 0) {
					fout << std::endl;
				}
				fout << *(curGeneration + i);
			}
			fout << std::endl;
		}
		fout.close();
	}
	catch (const std::exception&)
	{
		std::cout << "Output File invalid" << std::endl;
	}
}

void simulation() {
	int curGenNum = 1;
	int neighbors = 0;
	bool isEmpty = true;

	nextGeneration = new char[totalSize];
	*(nextGeneration + totalSize) = 0;

	std::cout << "Generation: " << 0;
	printSimulation(curGeneration);

	while (curGenNum <= totalGen) {
		for (int cell = 0; cell < totalSize; cell++) {
			if (*(curGeneration + cell) == ' ') {
				isEmpty = true;
			}
			else {
				isEmpty = false;
			}

			neighbors = checkNeighbors(cell);
			*(nextGeneration + cell) = *(curGeneration + cell);
			newCell(cell, neighbors, isEmpty);
		}
		*(nextGeneration + totalSize) = 0;
		curGenNum++;
		std::cout << "Generation: " << curGenNum - 1;
		printSimulation(nextGeneration);
		//cout << "TESTING!! " <<endl;
		//printSimulation(curGeneration);
		//try {
		//	delete[] curGeneration;
		//}
		//catch (exception &e) {
		//	cout << e.what();
		//}
		curGeneration = NULL;
		curGeneration = new char;
		curGeneration = nextGeneration;
		nextGeneration = NULL;
		nextGeneration = new char[totalSize];
	}
	printToFile();
}

int main()
{
	readFromFile();

	std::cout << "How many generations required (enter a value from 1 - 10)? ";
	std::cin >> totalGen;

	while (totalGen < 1 && totalGen>10) {
		std::cout << "Invalid Input! Please re-enter total generations: ";
		std::cin >> totalGen;
	}

	simulation();

	std::cout << std::endl;
	// system("pause");
	return 0;
}


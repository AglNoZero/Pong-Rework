#pragma once

#include "Header.h"
using namespace std;

class CFile {
public:

	static void readHallOfFame(vector<string>& playerName, vector<int>& playerScore);
	static void writeHallOfFame(vector<string> playerName, vector<int> playerScore);
	static void createFakeData(vector<string>& playerName, vector<int>& playerScore);
};


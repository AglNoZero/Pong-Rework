#pragma once

#include "Header.h"
using namespace std;
class cGameData
{
private:
	string bestPlayer[5];
	string bestScore[5];
public:
	cGameData();
	~cGameData();

	void writeBestScoreToFile();

	void loadBestScoreFromFile();
};


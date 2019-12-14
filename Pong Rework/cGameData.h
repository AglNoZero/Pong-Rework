#pragma once

#include "Header.h"
using namespace std;
class cGameData
{
private:
	vector<string> bestPlayer;
	vector<string> bestScore;
public:
	cGameData();
	~cGameData();

	void writeBestScoreToFile();

	void loadBestScoreFromFile();
};


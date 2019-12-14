#pragma once

#include "Header.h"

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

	void sortByScore();
};


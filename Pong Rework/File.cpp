#include "File.h"
#define _CRT_SECURE_NO_WARNINGS

void CFile::readHallOfFame(vector<string>& playerName, vector<int>& playerScore)
{
	fstream file;
	file.open("HallOfFame.bin", ios::binary | ios::in);
	int score;
	string name;
	while(!file.eof()) {
		file >> name;
		playerName.push_back(name);
		file >> score;
		playerScore.push_back(score);
	}

	file.close();
}

void CFile::writeHallOfFame(vector<string> playerName, vector<int> playerScore)
{
	fstream file;
	file.open("HallOfFame.bin", ios::binary|ios::out);

	for (int i = 0; i < playerName.size(); i++) {
		file << playerName[i] << endl << playerScore[i];
		if (i < playerName.size()-1) {
			file << endl;
		}
	}

	file.close();
}

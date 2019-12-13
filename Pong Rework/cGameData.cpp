#include "cGameData.h"



cGameData::cGameData()
{
}


cGameData::~cGameData()
{
}

void cGameData::writeBestScoreToFile()
{
	fstream bestScoreFile;
	bestScoreFile.open("BestScore.dat", ios::app);


}

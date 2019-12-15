#ifndef FILE_H_
#define FILE_H_

#include "pre.h"
#include "Ball.h"
#include "Paddle.h"

class CFile {
    public:
        void saveGameRecord(CBall ball) {
            fstream file;
            file.open("SaveGame.bin", ios::out);
            file.write((char*) &ball, sizeof(CBall));

            file.close();
        }

        CBall readGameRecord() {
            CBall ball;
            fstream file;
            file.open("SaveGame.bin", ios::in);
            file.read((char*) &ball, sizeof(CBall));
            file.close();
            return ball;
        }
        
		void readHallOfFame(vector<string>& playerName, vector<int>& playerScore);
		void writeHallOfFame(vector<string> playerName, vector<int> playerScore);
};

#endif // !FILE_H_
/* 
 * File:   ScoreKeeper.H
 * Author: Gideon O.
 */

#ifndef SCOREKEEPER_H
#define	SCOREKEEPER_H

#include "nim.H"

class ScoreKeeperInfo {
public:
    void start();
    ScoreKeeperInfo();
    ScoreKeeperInfo(string name);
    
private:
    // you provide private instance variables and methods
    void welcome();
    void flipCoin();
    void playRepeatedly();
    void getPlayer();
    
    int wins;
    int makeRandomState();

    Player firstToPlay;

    string getFlip();
    string getToss();
    string name;
    string getPlayer(string name);
    string getGameloop();
    string gameloop();

};

#endif	/* SCOREKEEPER_H */


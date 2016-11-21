#include <iostream>
#include "utility.h"
using namespace std;

void selectAndKill(enemy* &active1, enemy* &active2,enemy* &dead);
bool InsertTower(Tower* &towerH, double TH, int TKC , double FP);
bool InsertEnemy(enemy*& enemyH,int ID, Etype TYP,
				 int T, double H, double FP, int RP, REGION R);
void moveFromTo(enemy* &list1,enemy * &list2);
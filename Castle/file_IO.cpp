#include "file_IO.h"
void LoadFile(double* Con,Tower*&THead ,enemy*&regHead,enemy* &SFH)
{
	int Index, T, ArrivalTime, ReloadPeriod, TowerHit;
	double Health, FirePower, TowerHealth, TowerFireP; char R;
	Etype Type; REGION Region;
	ifstream input("simulation input.txt", ios::in);
	if (!input.is_open()) {
		cout << "Error : input file is not found " << endl;
		return;
	}

	input >> TowerHealth >> TowerHit >> TowerFireP;
	for (int i = 0; i < 4; i++) {
		if (!InsertTower(THead, TowerHealth, TowerHit, TowerFireP)) {
			cout << "Error while inserting a tower node, check insert tower function " << endl;
			return;
		}
	}

	for (int i = 0; i < 3; i++) {
		input >> Con[i];
	}

	input >> Index; 
	while (Index != -1) {

		input>>T >> ArrivalTime >> Health >> FirePower >> ReloadPeriod >> R;
		Type = static_cast<Etype>(T);
		Region = static_cast<REGION>(R);
		//put all shield fighters in one list
		if (Type == SHLD_FITR) {
			if (!InsertEnemy(SFH, Index, Type, ArrivalTime
				, Health, FirePower, ReloadPeriod, Region)) {
				cout << "Error while inserting a Shielded Fighter node, check insert enemy function " << endl;
				return;
			}
		}
		//put all other regular fighters in a single list
		else{
			if (!InsertEnemy(regHead, Index, Type, ArrivalTime
				, Health, FirePower, ReloadPeriod, Region)) {
				cout << "Error while inserting an Paver node, check insert enemy function " << endl;
				return;
			}
		}
		input >> Index;
	}
	input.close();
}
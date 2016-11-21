#include "file_IO.h"

void PrintEnemy(enemy*head) {
	cout << "Enemy list is : "<<endl;
	while (head != NULL) {
		cout << head->ID << " ";
		cout << head->Type << " ";
		cout << head->ArrivalTime << " ";
		cout << head->Health << " ";
		cout << head->FirePower << " ";
		cout << head->ReloadPeriod<< " ";
		cout << head->Region << " ";
		cout<<endl;
		head = head->next;
	}
	cout << endl;
}

void PrintTower(Tower*head) {
	cout << "Tower list is : " << endl;
	while (head != NULL) {
		cout << head->Health << " ";
		cout << head->TowerKillingCapacity << " ";
		cout << head->TowerFirePower << " ";
		cout << head->UnpavedArea << " ";
		head = head->next;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cout<<"start working"<<endl;
	Tower* TowerHead = NULL; 
	enemy* regFigthersHead = NULL; enemy* SHFighterHead = NULL;
	double Constants[3];
	LoadFile(Constants,TowerHead, regFigthersHead,SHFighterHead);
	/*
	required functions to implement
	------------------------------
	void moveFromTo(enemy* list1,enemy * list2)
		moves the first element from the first list to the end of the other
		should be in the Enemy.cpp 
	
	void selectAndKill(enemy* list1, enemy* list2,enemy* list3)
		pick the first (2 or less) elements from the list1 and list2 
		call moveFromTo() to move selected enemies from list1/2 to list3
		should be in the Tower.cpp 

	void printEnemyByRegion(enemy* active1,enemy* active 2 ,enemy* dead)
		For each region, print
			1. Total number of active enemies and information of each one of them.
			2. Total number of killed enemies and information of each one of them.
			The killed enemies have to be printed ordered by enemy health.
	required steps to Implement
	---------------------------
	Loop through those steps
		Check if any enemy's arrival time matches the current one
			if matches call moveFromTo() to move to active list
		call selectAndKill()
		call printEnemyByRegion()  on active lists and dead list

	*/

	//TEST------------------------------
	
	PrintEnemy(regFigthersHead);
	cout << endl;
	PrintEnemy(SHFighterHead);
	cout << endl << endl;
	PrintTower(TowerHead);
	for (int i = 0; i < 3; i++) {
		cout << Constants[i] << " ";
	}
	/*
	while(true){
		
		Sleep(1000);
	}
	*/
	cin.get();
	//END OF TEST ------------------------
	return 0;
	
}

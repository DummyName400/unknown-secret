#include "file_IO.h"

void PrintEnemy(enemy*head) {
	cout << "list is : ";
	while (head != NULL) {
		cout << head->ID << " ";
		cout << head->Type << " ";
		cout << head->ArrivalTime << " ";
		cout << head->Health << " ";
		cout << head->FirePower << " ";
		cout << head->ReloadPeriod<< " ";
		cout << head->Region << " ";
		head = head->next;
	}
	cout << endl;
}

void PrintTower(Tower*head) {
	cout << "list is : " << endl;
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
	Tower* TowerHead = NULL; 
	enemy* regFigthersHead = NULL; enemy* SHFighterHead = NULL;
	double Constants[3];
	LoadFile(Constants,TowerHead, regFigthersHead,SHFighterHead);

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
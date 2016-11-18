#include "EnemyAndTower.h"

bool InsertEnemy(enemy*& enemyH,int ID, Etype TYP, 
				 int T, double H, double FP, int RP, REGION R)
{

	enemy* Enemy = new enemy;
	Enemy->ID = ID;
	Enemy->Type = TYP;
	Enemy->ArrivalTime = T;
	Enemy->Health = H;
	Enemy->FirePower = FP;
	Enemy->ReloadPeriod = RP;
	Enemy->Region = R;
	Enemy->next = NULL;

	if (enemyH == NULL) {
		enemyH = Enemy;
		return true;
	}
	else {
		enemy* iterator = enemyH;

		while (iterator->next != NULL) {
			iterator = iterator->next;
		}

		iterator->next = Enemy;
		return true;
	}
	return false;
}
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

//moves the first element from the first list to the end of the other
void moveFromTo(enemy* &list1,enemy * list2){
	enemy* temp =list1;
	list1=temp->next;
	if(list2==NULL){
		list2=temp;
		return;
	}
	enemy * iterator=list2;
	while(iterator->next!=NULL){ iterator=iterator->next;}
	iterator->next=temp;
	temp->next=NULL;
}
/*
For each region, print
			1. Total number of active enemies and information of each one of them.
			2. Total number of killed enemies and information of each one of them.
			The killed enemies have to be printed ordered by enemy health.
*/
void printEnemyByRegion(enemy* active1,enemy* active2 ,enemy* dead){
	//repeat this pattern for all regions , use ASCI code to loop through
	while(active1!=NULL){
		if(active1->Region=='A')
			printEnemyDetails(active1);
	}
	while(active2!=NULL){
		if(active2->Region=='A')
			printEnemyDetails(active2);
	}
	while(dead!=NULL){
		if(dead->Region=='A')
			printEnemyDetails(dead);
	}
}	
void printEnemyDetails(enemy* E){}

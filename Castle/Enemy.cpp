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


//moves the first element from the first list to the end of the other
void moveFromTo(enemy* &list1,enemy * &list2){
	enemy* temp =list1;
	list1=temp->next;
	if(list2==NULL){
		list2=temp;
		temp->next=NULL;
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
	printRegion(active1,A_REG);
	printRegion(active1,B_REG);
	printRegion(active1,C_REG);
	printRegion(active1,D_REG);
	printRegion(active2,A_REG);
	printRegion(active2,B_REG);
	printRegion(active2,C_REG);
	printRegion(active2,D_REG);
	printRegion(dead,A_REG);
	printRegion(dead,B_REG);
	printRegion(dead,C_REG);
	printRegion(dead,D_REG);

}

void printRegion(enemy * list,REGION region){
	while(list!=NULL){
		if(list->Region==region){
			cout << list->ID << " ";
			cout << list->Type << " ";
			cout << list->ArrivalTime << " ";
			cout << list->Health << " ";
			cout << list->FirePower << " ";
			cout << list->ReloadPeriod<< " ";
			cout << list->Region << " ";
			cout<<endl;
		}
		list=list->next;
	}
}

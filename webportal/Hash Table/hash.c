#include<stdio.h>
#include<stdlib.h>

typedef struct record{
	char name[20];
	long int id;
} * stu;

typedef struct linked{
	stu val;
	struct linked * next;
} * link;

typedef struct list{
	int count;
	link first;
} * lis;

typedef struct hashtable{
	int elementCount;
	float loadFactor;
	int insertionTime;
	int queryingTime;
	int tableLength;
	lis items;
} * hasht;

int insertInto(lis head, stu val){
	link temp = (link) malloc(sizeof(struct linked));
	temp -> val = val;
	temp -> next = NULL;
	if(head -> count == 0){
		head -> first = temp;
		head -> count ++;
		return 0;
	}else{
		link ptr = head -> first;
		while(ptr -> next != NULL){
			ptr = ptr-> next;
		}
		ptr->next = temp;
		head -> count ++;
		return 1;
	}
}

int readFrom(lis head, stu val){
	int pos = 1;
	link ptr = head -> first;
	while(ptr -> next != NULL){
		if(ptr->val->id == val->id){
			break;
		}
		ptr = ptr-> next;
		pos++;
	}
	return pos;
}

void createHashTable(hasht ht, stu rec, int no, int type){
	lis temp;
	int i, index, tl;
	switch(type){
		case 5:
			ht->tableLength = 20;
			tl = 20;
			temp = (lis) malloc(sizeof(struct list) * tl);
			for(i = 0; i< tl; i++){
				(temp+i)-> count = 0;
				(temp+i)-> first = NULL;
			}
			for(i = 0; i<no; i++){
				index = ((((rec+i)->id)%89)%tl);			
				ht-> insertionTime += insertInto(temp+index, rec+i);
				printf("inserting %d %d\n", index, ht->insertionTime);	
			}
			ht->items = temp; 			
			break;
		default:
			break;
	}
}

void readHashTable(hasht ht, stu rec, int no, int type){
	int i, index, tl = ht->tableLength;	
	lis temp = ht -> items;
	switch(type){
		case 5:
			for(i = 0; i<no; i++){
				index = ((((rec+i)->id)%89)%tl);
				ht->queryingTime += readFrom(temp+index, rec+i);	
			}	
			break;
		default:
			break;
	}
}

int main(){
	FILE *ftpr = stdin;
	int choice, no, i;
	hasht ht1 = (hasht) malloc(sizeof(struct hashtable));
	ht1 -> elementCount = 0;
	ht1 -> loadFactor = 0;
	ht1 -> insertionTime = 1;
	ht1 -> queryingTime = 0;
	ht1 -> items = NULL;	
	scanf("%d", &choice);
	while(choice != -1){
		switch(choice){
			case 1:
				scanf("%d", &no);
				stu rec = (stu) malloc(sizeof(struct record) * no);				
				for(i = 0; i< no; i++){
					scanf("%s", (rec+i)->name);
					scanf("%ld", &((rec+i)->id)); 				
				}
				createHashTable(ht1, rec, no, 5);
				break;

			case 2:
				scanf("%d", &no);
				stu rec2 = (stu) malloc(sizeof(struct record) * no);				
				for(i = 0; i< no; i++){
					scanf("%s", (rec+i)->name);
					scanf("%ld", &((rec+i)->id)); 				
				}
				readHashTable(ht1, rec, no, 5);
				break;
			case 3:
				printf("%d\n", ht1 -> insertionTime);
				break;
			case 4:
				printf("%d\n", ht1 -> queryingTime);
				break;
		}
		scanf("%d", &choice);
	}	
}

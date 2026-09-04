#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gconio.h"
#include "processos.h"

int main(){
	srand(time(NULL));
	Body list = new_Body();
	do{
		char opc;
		while(!kbhit(&opc)){
			Process head = list->head;
			printf("New Process: (K)ernel Process / (U)ser Process\n"
			"Actions: (D)elete Process / (E)xit Application\n");
			printf("%d Process ", list->size);
			if(list->current)
				printf("=> Running PID: %d\n\n", list->current->pid);
			else
				printf("\n\n");
			printf("RUNNING \t TYPE \t\t PID \t INSTRUCTIONS \t DONE\n");
			while(head){
				if(head->pid == list->current->pid)
					printf("*");
				else
					printf(" ");
				printf(" \t\t %s \t %d \t %d \t\t %d\n", head->type, head->pid,
				head->instructions, head->done);
				head = head->next;
			}
			if(list->current){
				list->current->done++;
				if(list->current->instructions == list->current->done)
					delete_Process(list);
			}
			if(list->current == list->tail)
				list->current = list->head;
			else
				list->current = list->current->next;
			system("sleep 1");
			system("clear");
		}
		if(opc == 'k' || opc == 'K')
			new_Process(list, 0);
		
		if(opc == 'u' || opc == 'U')
			new_Process(list, 1);
		
		if(opc == 'd' || opc == 'D'){
			if(list->current == list->head)
				list->current = list->tail;
			else 
				list->current = list->current->previous;
			delete_Process(list);
		}
		
		if(opc == 'e' || opc == 'E'){
			printf("Aplicação finalizada.");
			return 0;
		}
	} while (1);
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100
typedef struct cvor {
	char ime[MAX];
	char prezime[MAX];
	int god;
	struct cvor* next;
}cvor;


void naprid(cvor**, char*, char*, int);
void nakraj(cvor**, char*, char*, int);
void print_lista(cvor**);
void obrisi_po_prezimenu(cvor**, char*);
void pronadji_po_prezimenu(cvor**, char*);

int main() {

	cvor prvi;
	cvor* head = &prvi;

	strcpy(head->ime, "Drago");
	strcpy(head->prezime, "Dragic");
	head->god = 20;
	prvi.next = NULL;

	char ime1[MAX], prezime1[MAX], ime2[MAX], prezime2[MAX], potraznja[MAX], obris[MAX];
	int godina1;
	int godina2;

	printf("Unesite ime : ");
	scanf("%s", ime1);
	printf("Unesite prezime: ");
	scanf("%s", prezime1);
	printf("Unesite godine: ");
	scanf("%d", &godina1);

	naprid(&head, ime1, prezime1, godina1);

	print_lista(&head);

	printf("Unesite ime: ");
	scanf("%s", ime2);
	printf("Unesite prezime: ");
	scanf("%s", prezime2);
	printf("Unesite godine : ");
	scanf("%d", &godina2);

	nakraj(&head, ime2, prezime2, godina2);

	print_lista(&head);

	printf("Koje prezime zelite pretraziti : ");
	scanf("%s", potraznja);
	pronadji_po_prezimenu(&head, potraznja);
	printf("\n");


	printf("Upisite Prezime osobe kojeg zelite obristi : ");
	scanf("%s", obris);
	printf("\n");
	obrisi_po_prezimenu(&head, obris);
	print_lista(&head);
	return 0;
}
void naprid(cvor** head, char* ime, char* prezime, int god) {

	cvor* novi = (cvor*)malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}
	cvor* curr = *head;

	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	novi->next = *head;

	*head = novi;

}
void nakraj(cvor** head, char* ime, char* prezime, int god) {

	cvor* novi = (cvor*)malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}

	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	cvor* curr = *head;

	while (curr->next != NULL) {

		curr = curr->next;
	}
	novi->next = NULL;
	curr->next = novi;


}
void print_lista(cvor** head) {
	if (*head == NULL) {
		printf("Lista je prazna.\n");
		return;
	}
	printf("\n");
	cvor* curr = *head;
	printf("Ime:\tPrezime:\tGod:\n");
	while (curr != NULL) {
		printf("%s\t%s\t\t%d\n", curr->ime, curr->prezime, curr->god);
		curr = curr->next;
	}
	printf("\n");
}
void pronadji_po_prezimenu(cvor** head, char* prezime) {

	cvor* curr = *head;

	while (curr != NULL) {

		if (strcmp(curr->prezime, prezime) == 0) {
			printf("Podatci o osobi: \n");
			printf("Ime:\tPrezime:\tGod:\n");
			printf("%s\t%s\t\t%d", curr->ime, curr->prezime, curr->god);
			return;
		}

		curr = curr->next;
	}


}
void obrisi_po_prezimenu(cvor** head, char* prezime) {

	cvor* curr = *head;

	if (strcmp(curr->prezime, prezime) == 0) {

		*head = curr->next;
		free(curr);
		return;
	}



	while (curr != NULL) {

		if (strcmp(curr->next->prezime, prezime) == 0) {
			cvor* brisajuca = curr->next;
			curr->next = curr->next->next;
			free(brisajuca);
			return;
		}

		curr = curr->next;
	}




}





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
typedef struct cvor {

	int god;
	char ime[M];
	char prezime[M];
	struct cvor* next;

}cvor;

void unesi_na_kraj(cvor*, char*, char*, int);
void unos_varijabli(char*, char*, int*);
void print_liste(cvor*);
void unesi_naprijed(cvor*, char*, char*, int);
void unesi_nakon_clana(cvor*, char*, char*, int, int);
void oslobodi_listu(cvor*);
void pronajdi_po_prezimenu(cvor*, char*);

int main() {


	cvor* head = malloc(sizeof(cvor));
	if (head == NULL) {
		exit(1);
	}
	head->next = NULL;


	char i[M], p[M];
	int o;

	unos_varijabli(i, p, &o);
	unesi_na_kraj(head, i, p, o);
	print_liste(head);

	unos_varijabli(i, p, &o);
	unesi_na_kraj(head, i, p, o);
	print_liste(head);

	unos_varijabli(i, p, &o);
	unesi_naprijed(head, i, p, o);
	print_liste(head);

	printf("Unesite prezime osobe koju zelite istraziti: "); scanf("%s", p);
	pronajdi_po_prezimenu(head, p);


	oslobodi_listu(head);
	print_liste(head);

	return 0;
}

void unos_varijabli(char* ime, char* prezime, int* god) {

	printf("Unesi osobu :\n");
	printf("Unesi ime : ");
	scanf("%s", ime);
	printf("Unesi prezime : ");
	scanf("%s", prezime);
	printf("Unesi God : ");
	scanf("%d", god);
	return;
}

void unesi_na_kraj(cvor* head, char* ime, char* prezime, int god) {

	cvor* novi = malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}

	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	cvor* curr = head;

	// petlja za pronalazak zanjeg clana
	//da bi nasli zadnji clan moramo naci kome next pointa u NULL
	//jer da smo postavili da ide dok taj ne bude NULL ne bi imali zadnji clan 
	while (curr->next != NULL) {
		curr = curr->next;
	}

	novi->next = NULL;
	curr->next = novi;
}

void print_liste(cvor* head) {
	printf("\nIme\tPrezime\tGod:\n");

	cvor* curr = head->next;

	while (curr != NULL) {
		printf("%s\t%s\t%d\n", curr->ime, curr->prezime, curr->god);
		curr = curr->next;
	}
	printf("\n");
}

void unesi_naprijed(cvor* head, char* ime, char* prezime, int god) {

	cvor* novi = malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}

	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	cvor* curr = head;
	novi->next = curr->next;
	curr->next = novi;
}

void unesi_nakon_clana(cvor* head, char* ime, char* prezime, int god, int vrijednost) {

	cvor* novi = malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}

	cvor* curr = head;
	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	while (curr != NULL) {

		if (curr->god == vrijednost) {

			novi->next = curr->next;
			curr->next = novi;
			return;
		}

		curr = curr->next;
	}

	printf("Nemozem umetnuti novi clan jer nema Gode %d u listi ", vrijednost);
	free(novi);
}

void oslobodi_listu(cvor* head) {

	cvor* curr = head;

	while (curr != NULL) {

		cvor* temp = curr;
		curr = curr->next;
		free(temp);

	}

	curr->next = NULL;
}

void pronajdi_po_prezimenu(cvor* head, char* prezime) {

	cvor* curr = head;
	while (curr != NULL) {

		if (strcmp(curr->prezime, prezime) == 0) {

			printf("\nPodatci Pretrage:\n\n");
			printf("Ime:\tPrezime:\tGod:\n");
			printf("%s\t%s\t%d\n", curr->ime, curr->prezime, curr->god);
		}

		curr = curr->next;
	}
}

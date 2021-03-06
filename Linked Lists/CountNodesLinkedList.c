#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*first=NULL;

void create(int array[], int n) {
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = array[0];
	first->next = NULL;
	last = first;
	for (i=1; i<n; i++) { 
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = array[i];
		t->next = NULL;
		last->next = t;
		last = t; 
	}
}

int countNodes(struct Node *p) {
	int count=0;
	while(p) {
		count++;
		p = p->next;
	} 
	return count;
}

int recursiveCountNodes(struct Node *p) {
	if (p==NULL) 
		return 0;
	else 
		return recursiveCountNodes(p->next) + 1; 	
}

int main() {
	
	int array[7] = {2,4,6,8,10,12,14};
	create(array, 7);
	printf("Number of nodes: %d ", countNodes(first));
	printf("\nNumber of nodes using recursion: %d ", recursiveCountNodes(first));
	return 0;
}

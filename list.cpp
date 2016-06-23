#include "list.h"
#include <iostream>

list::list() {
	list *p;
	p = new list();
	p->front = NULL;
	p->rear = NULL;
} 

list::~list() {
	
}

void list::add_node_list(int x) {
	//random pra adicionar as informacoes de um node com cor
}
void list::remove_node_list(int x) {
	/*funcao desnecessaria, pq soh precisaremos do remove_all
	pra remover todos os nos e preencher novamente com 3 novos*/
}
void list::list_check(int x) {
	//funcao pra checar os elementos da lista se necessario
}
void list::remove_all(int x) {
	//funcao pra remover todos os nos que a lista contem
}

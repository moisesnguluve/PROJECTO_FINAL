//           AVISOS IMPORTANTES
//           USE A SETA 'CIMA' , 'BAIXO' PARA ESCOLHER AS OPÇÕES 
//           USE A TECLA 'ENTER' PARA CONFIRMAR 
// AUTOR:  Moisés Alfredo Vilanculo Nguluve
//PROJECTO FINAL DO MÓDULO de Algoritmo e Estrutura de Dados 


//   Programa para gerir uma fila de atendimento ao público do seu estabelecimento. 
// O programa deve apresentar no console uma lista de opções, como:
// 
// 1.      Próximo cliente = número de senha (ex.: 18);
// 
// 2.      Senha chamada = número de senha (ex.: 17);
// 
// 3.      Número total de senhas tiradas = número de senha (ex.: 23);
// 
// 4.      Senhas por atender = número de senha (ex.: 6), etc.


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define limit 10

void eixo_x_y(int x, int y);

struct fila_struct {
	int position[limit];
	int initial_position;
	int end_position;
};

struct fila_struct fila;
int num_atendimento = 0;
int num = 0;

int senha = 0;
bool sair = true;

int exit_program();
int validar();
void ver_fila();
void limpar_msg(int num);
void fila_increment(int senha);
void fila_decrement();
void exit();
void retirar_senha();
void painel();
void grid();


int main(){
	fila.initial_position = 0;
	fila.end_position = 0;
	
	int opcao = 1, x = 4;

    system("cls");
    system("color 0F");
    eixo_x_y(0,2); printf("Menu Principal");
   eixo_x_y(0,3);printf("Moises Alfredo Vilanculo Nguluve");
    eixo_x_y(0,4); printf("->");
	grid();
    while(sair){
        eixo_x_y(2,4);  printf(" 1 - RETIRAR SENHA");
        eixo_x_y(2,5);  printf(" 2 - ATENDIMENTO");
        eixo_x_y(2,6);  printf(" 3 - VER FILA");
        eixo_x_y(2,7); printf(" 4 - SAIR");
        
        eixo_x_y(2,8); printf("Ultimo atendimento: %d", num_atendimento);


        system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && x != 7) {
            eixo_x_y(0,x); printf("  ");
            x++;
            eixo_x_y(0,x); printf("->");
            opcao++;
            continue;
        }

		if(GetAsyncKeyState(VK_UP) && x != 4){
            eixo_x_y(0,x); printf("  ");
            x--;
            eixo_x_y(0,x); printf("->");
            opcao--;
            continue;
        }

		if(GetAsyncKeyState(VK_RETURN)){
            switch (opcao) {
            case 1:
                retirar_senha();
                break;
            case 2:
                fila_decrement();
                break;
            case 3:
                ver_fila();
                break;
            case 4:
                exit_program();
            }
        }
    }
    eixo_x_y(20,21);
	
	
	exit();
	return 0;
}

void eixo_x_y(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void grid(){
	
	int pos = 0;
	int y = 10;
	for(int i = 0; pos <= 5; i++){
		eixo_x_y(30, y);
		printf("|");
		
		eixo_x_y(60, y);
		printf("|");
		
		pos++;
		y++;
	}

}

void fila_increment(int senha){
	if (fila.end_position == limit) {
		printf("Fila cheia.");
	}
	else {
		fila.position[fila.end_position] = senha;
		fila.end_position++;
	}
}

void fila_decrement(){
	
	if (fila.initial_position == fila.end_position) {
		eixo_x_y(35,14);
		printf("Fila vazia");
	}
	else {
		eixo_x_y(35,14);
		printf("               ");
		for (int i=0; i<limit; i++) {
			fila.position[i] = fila.position[i+1];
		}
		fila.position[fila.end_position] = 0;
		fila.end_position--;
		num_atendimento++;
		painel();
	}
	ver_fila();
	limpar_msg(0);
	limpar_msg(1);
}

void ver_fila() {
	
	painel();
	eixo_x_y(65,10);
	printf("Fila: ");
	eixo_x_y(65,11);
	for (int i=0; i<limit; i++){
		
		printf("%d, ", fila.position[i]);
	}
	eixo_x_y(65,13);
	printf("Atendimento: %d", num_atendimento);
	limpar_msg(0);
}


void exit(){
	printf("EXIT");
}

void retirar_senha(){
	
	int sua_senha;
	if (validar() == 1) {
		sua_senha = senha + 1;
		
		eixo_x_y(10,12);
		printf("Sua senha: %d", sua_senha);
		senha++;
		fila_increment(sua_senha);
	} else if(senha == 10) {
		eixo_x_y(30,17);
 		printf("A fila ja esta completa, tente novamente mais tarde.");
	}
	
	ver_fila();
	limpar_msg(0);

}

int validar(){
	if (senha == limit) {
		return -1;
	}
	else if(senha <= limit) {
		return 1;
	}
	
}


void painel(){

	if (num_atendimento - 1 < 0){
		eixo_x_y(35,11);
		printf("SENHA ANTERIOR: 0\n");
	}
	else {
		eixo_x_y(35,11);
		printf("SENHA ANTERIOR: %d\n", num_atendimento -1);
	}

	eixo_x_y(35,12);
	printf("SENHA CHAMADA: %d \n", num_atendimento);
	
	eixo_x_y(35,13);
	printf("PROXIMO CLIENTE: %d\n",  num_atendimento + 1);

}

void limpar_msg(int num){
	
	if(num == 1){
		eixo_x_y(30,17);
 		printf("                                                               ");
	} else {
		eixo_x_y(30,16);
		printf("                                                              ");
	}
	

}

int exit_program(){

	if (fila.position[fila.initial_position] != 0){
		eixo_x_y(30,16);
		printf("Ainda ha pessoas para serem atendidas.");
		return 1;
	}
	else{
		sair = false;
		return sair;
	}

}
 
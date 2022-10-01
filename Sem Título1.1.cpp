#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<string>
#include<conio.h>




// Declaração da função gotoxy

#include <windows.h>
void gotoxy(int col, int lin)
	{
     	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});
	}

void estrutura();
void estrutura1();
void estrutura2();
void meio();
void meio2();
void meio3();
// Procedimento para limpar uma linha a partir do cursor, até a coluna 80

void clreol(int col,int lin)
	{
		int col1;
		if ((lin > 0 && lin < 25) && (col > 0 && col < 81))
			for (col1 = col; col1 <= 80; ++ col1)
				{
					gotoxy(col1,lin); 	puts(" ");
				}
	}


int main(){
	
	
	// Tamanho da tela
	system("mode con:cols=62 lines=43");
	
	// Declaração de variáveis
	
	const float moedas[5]={0.05,0.10,0.25,0.50,1}; 
	const float notas[7]={2,5,10,20,50,100,200};
	unsigned int qtd_moedas[5], qtd_notas[7];
	float valor_troco_moedas[6], multi_moedas[5],total_valor_moedas, total_troco_moedas, total;
	float multi_notas[7], total_valor_notas;
	float cart_debt[35], cart_credt[35], total_debt, total_credt,relat_debt, relat_credt, tot1,tot2;
	float crediarios[15], pix[15],deposito[15],total_deposito, total_crediarios, total_pix;
	int i, opcao, troco_moedas,qtd_deposito, qtd_pix, qtd_crediarios, qtd_debt, qtd_credt, qtd_correta,total_qtd_notas,total_qtd_moedas,total_qtd_troco;
	char sair;


	// Mensagem inicial
	
	estrutura();	
		system("color F4");
				gotoxy(7,7);
					printf("Lembrando que este programa %c algo para auxiliar!!",130);
				gotoxy(12,9);
					printf("ELE N%cO SUBSTITUI A CONTAGEM MANUAL!!",199);
		system("color F4");
				gotoxy(2,16);
					system("pause");
		system("cls");

	// Menu
	
	do{
	
		
		system("color 0A");
		
	estrutura();
		gotoxy(20,4);
			printf("Digite a opcao desejada");
			
		gotoxy(8,7);
			printf("%c 1 %c %c%c%c%c%c Moedas e Notas",175,174,196,196,196,196,196);
		gotoxy(8,8);
			printf("%c 2 %c %c%c%c%c%c Debito e Credito",175,174,196,196,196,196,196);
		gotoxy(8,9);
			printf("%c 3 %c %c%c%c%c%c Crediarios, PIX e Depositos",175,174,196,196,196,196,196);
		gotoxy(8,10);
			printf("%c 4 %c %c%c%c%c%c Sair",175,174,196,196,196,196,196);
		gotoxy(26,13);	
			printf("%c%c%c   %c%c%c",196,196,175,174,196,196);
		gotoxy(30,13);
			scanf("%d", &opcao);

		system("cls");

	switch(opcao){ 
	
		// Opção 1 -- Moedas e notas
		case 1:{ 
	
	do{				
	//MOEDAS
		for ( i=0; i<5; i++){
		
			system("cls");
		
	estrutura();
		gotoxy(22,3);
			printf("CONTAGEM DE CAIXA!");
		gotoxy(25,4);
				printf(">> MOEDAS <<");
		gotoxy(17,7);
				printf("Digite o que for solicitado");	
		gotoxy(5,11);
				printf("Quantidade de Moedas de R$ %.2f",moedas[i]);
		gotoxy(26,13);	
			printf("%c%c%c    %c%c%c",196,196,175,174,196,196);
		gotoxy(30,13);
				scanf("%d", &qtd_moedas[i]);
		
			multi_moedas[i]=qtd_moedas[i]*moedas[i];
			
			total_valor_moedas=total_valor_moedas+multi_moedas[i];
		
	}
	
	// TROCO DE MOEDAS
	
		system("cls");
		
			estrutura();
		gotoxy(22,3);
			printf("CONTAGEM DE CAIXA!");
		gotoxy(20,4);
				printf(">> TROCO DE MOEDAS <<");
		gotoxy(18,7);
				printf("Digite o que for solicitado");
		gotoxy(5,9);
				printf("Existe troco de moedas em saquinhos?");
		gotoxy(5,10);
				printf("%c SIM %c %c%c%c%c%c Digite a quantidade de saquinhos",175,174,196,196,196,196,196);
		gotoxy(5,11);
				printf("%c N%cO %c %c%c%c%c%c Digite 0 (Zero)",175,199,174,196,196,196,196,196);
		gotoxy(26,13);	
			printf("%c%c%c   %c%c%c",196,196,175,174,196,196);
		gotoxy(30,13);
				scanf("%d", &troco_moedas);
	
	if (troco_moedas >= 4){
			
		do{
			
		system("cls");
		
		system("color F4");	
			estrutura();
		gotoxy(22,3);
			printf("CONTAGEM DE CAIXA!");
		gotoxy(20,4);
				printf(">> TROCO DE MOEDAS <<");
		gotoxy(16,7);
				printf("DIGITE A QUANTIDADE CORRETA!!!");
		gotoxy(5,9);
				printf("Existe troco de moedas em saquinhos?");
		gotoxy(5,10);
				printf("SIM --- Digite a quantidade de saquinhos");
		gotoxy(5,11);
				printf("N%cO --- Digite 0  (Zero)",199);
		gotoxy(26,13);	
			printf("%c%c%c   %c%c%c",196,196,175,174,196,196);
		gotoxy(30,13);
				scanf("%d", &troco_moedas);
			system("color F4");
		gotoxy(2,16);
			
		
		}while (troco_moedas >= 4);
			
			}

		for( i=0; i< troco_moedas; i++){
		system("cls");
		system("color 0A");
			estrutura();
		gotoxy(22,3);
			printf("CONTAGEM DE CAIXA!");
		gotoxy(21,4);
				printf(">> TROCO DE MOEDAS <<");
		gotoxy(18,7);
				printf("Digite o que for solicitado");
		gotoxy(5,11);
				printf("Digite o valor do %d%c saquinho", 1+i,167);
		gotoxy(26,13);	
				printf("%c%c%c    %c%c%c",196,196,175,174,196,196);
		gotoxy(30,13);
					scanf("%f", &valor_troco_moedas[i]);
			
			}
			
		for ( i=0 ; i < troco_moedas ; i++)
		{
				
			total_troco_moedas=total_troco_moedas+valor_troco_moedas[i];
				
	}
	
	// NOTAS
				
		for ( i=0; i<7; ++i){
		
		system("cls");
			
			estrutura();
		gotoxy(22,3);
			printf("CONTAGEM DE CAIXA!");
		gotoxy(26,4);
				printf(">> NOTAS <<");
		gotoxy(17,7);
				printf("Digite o que for solicitado");	
		gotoxy(5,11);
				printf("Quantidade de Notas de R$ %.2f",notas[i]);
		gotoxy(26,13);	
				printf("%c%c%c    %c%c%c",196,196,175,174,196,196);
		gotoxy(30,13);
					scanf("%d", &qtd_notas[i]);
		
				multi_notas[i]=qtd_notas[i]*notas[i];
				total_qtd_notas=total_qtd_notas+qtd_notas[i];
				total_valor_notas=total_valor_notas+multi_notas[i];

	}
	
	// Relatórios
	system("cls");
			
			estrutura1();
		gotoxy(22,3);
			printf("CONTAGEM DE CAIXA!");
		gotoxy(21,4);
				printf(">> MOEDAS E NOTAS <<");
				
		gotoxy(16,7);
			printf(">> MOEDAS CONTIDAS NO CAIXA <<");
		gotoxy(14,8);
			printf("%c",204);
		gotoxy(15,8);
			for(int i=0; i<=31; i++){
				
				printf("%c",205);
	}			
		gotoxy(47,8);
			printf("%c",185);
		gotoxy(33,8);
			printf("%c",203);
			
		gotoxy(3,9);
				printf("Valor em Moedas de  %.2f	%c R$ %.2f	(%d Moedas)",moedas[0],186,multi_moedas[0], qtd_moedas[0]);
		gotoxy(3,10);
				printf("Valor em Moedas de  %.2f	%c R$ %.2f	(%d Moedas)",moedas[1],186,multi_moedas[1], qtd_moedas[1]);
		gotoxy(3,11);
				printf("Valor em Moedas de  %.2f	%c R$ %.2f	(%d Moedas)",moedas[2],186,multi_moedas[2], qtd_moedas[2]);
		gotoxy(3,12);
				printf("Valor em Moedas de  %.2f	%c R$ %.2f	(%d Moedas)",moedas[3],186,multi_moedas[3], qtd_moedas[3]);
		gotoxy(3,13);
				printf("Valor em Moedas de  %.2f	%c R$ %.2f	(%d Moedas)",moedas[4],186,multi_moedas[4], qtd_moedas[4]);
		
		gotoxy(16,16);
			printf(">> NOTAS  CONTIDAS NO CAIXA <<");
		
		gotoxy(14,17);
			printf("%c",204);
		gotoxy(15,17);
			for(int i=0; i<=31; i++){
				
				printf("%c",205);
	}			
		gotoxy(47,17);
			printf("%c",185);
		gotoxy(33,17);
			printf("%c",203);
				
		gotoxy(3,18);
				printf("Valor em Notas de R$ %.2f	%c R$ %.2f	(%d Notas)",notas[0],186,multi_notas[0], qtd_notas[0]);	
		gotoxy(3,19);
				printf("Valor em Notas de R$ %.2f	%c R$ %.2f	(%d Notas)",notas[1],186,multi_notas[1], qtd_notas[1]);
		gotoxy(3,20);
				printf("Valor em Notas de R$ %.2f	%c R$ %.2f	(%d Notas)",notas[2],186,multi_notas[2], qtd_notas[2]);
		gotoxy(3,21);
				printf("Valor em Notas de R$ %.2f	%c R$ %.2f	(%d Notas)",notas[3],186,multi_notas[3], qtd_notas[3]);	
		gotoxy(3,22);
				printf("Valor em Notas de R$ %.2f	%c R$ %.2f	(%d Notas)",notas[4],186,multi_notas[4], qtd_notas[4]);
		gotoxy(3,23);
				printf("Valor em Notas de R$ %.2f	%c R$ %.2f	(%d Notas)",notas[5],186,multi_notas[5], qtd_notas[5]);	
		gotoxy(3,24);
				printf("Valor em Notas de R$ %.2f	%c R$ %.2f	(%d Notas)",notas[6],186,multi_notas[6], qtd_notas[6]);

					total=total_valor_moedas+total_valor_notas+total_troco_moedas;
					
		gotoxy(21,27);
			printf(">> SOMAS DO CAIXA <<");
			
			gotoxy(14,28);
			printf("%c",204);
		gotoxy(15,28);
			for(int i=0; i<=31; i++){
				
				printf("%c",205);
	}
			gotoxy(47,28);
			printf("%c",185);
			gotoxy(33,28);
			printf("%c",203);
			
		gotoxy(3,29);
				printf("Valor total de Moedas		%c R$ %.2f",186,total_valor_moedas);
		gotoxy(3,30);		
				printf("Valor total de Troco		%c R$ %.2f",186,total_troco_moedas);
		gotoxy(3,31);		
				printf("Valor total de Notas		%c R$ %.2f",186,total_valor_notas);	
				
		gotoxy(21,34);
			printf(">> TOTAL DO CAIXA <<");
			
			gotoxy(14,35);
			printf("%c",204);
		gotoxy(15,35);
			for(int i=0; i<=31; i++){
				
				printf("%c",205);
	}
			gotoxy(47,35);
			printf("%c",185);
			gotoxy(33,35);
			printf("%c",203);
					
		gotoxy(3,36);		
				printf("Valor total em caixa		%c R$ %.2f",186,total);
			
		gotoxy(3,40);	
			system ("pause");
			
			system ("cls");
		estrutura1();
		gotoxy(22,3);
			printf("CONTAGEM DE CAIXA!");
		gotoxy(26,4);
			printf("DESEJA SAIR?");
		gotoxy(5,10);
				printf("SIM --- Digite S");
		gotoxy(5,11);
				printf("N%cO --- Digite N",199);
		gotoxy(26,13);	
			printf("%c%c%c   %c%c%c",196,196,175,174,196,196);
		gotoxy(30,13);
				scanf("%s", &sair);
	
					sair = toupper (sair); 		
						
		system("cls");
			
}while (sair != 'S');
		
		break;

		}
		
		case 2:{ // Opção 2 -- Débito e Crédito
	
	
	do{
		
		// VALOR DO RELATORIO STONE
				
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Débito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");	
				printf("\n	   Valor do RELATÓRIO DA STONE Débito : ");
					scanf("%f", &relat_debt);
				
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Crédito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");	
				printf("\n	   Valor do RELATÓRIO DA STONE Crédito : ");
					scanf("%f", &relat_credt);
					
			//VENDAS DEBITO
		
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Débito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");
				printf("\n	   Digite a quantia de vendas no Débito:  ");
					scanf("%d", &qtd_debt);
		
				
	if (qtd_debt >= 30){
		
	do{
				
		system("cls");
		
			system("color 2");
		
			printf("\n\n\n	   Foi digitado uma quantidade alta de vendas no Débito!");
			
				printf("\n\n	   Quantidade de Débito digitada >>> %d \n\n", qtd_debt);
				printf("\n\n	   Tem certeza que foi digitado certo?");
			
					printf("\n\n Se sim, digite 1 ---- Se não, digite 0 \n");
						scanf("%d", &qtd_correta);
					
		system("color 2");
		
			system("pause");
			
				system("color F");
			
	if (qtd_correta != 1){
				
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Débito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");
				printf("\n	   Digite a quantia de vendas no Débito:  ");
					scanf("%d", &qtd_debt);
			}
		}while(qtd_debt >= 30);
	}
			
			// VENDAS CREDITO
			
			system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Crédito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");
				printf("\n	   Digite a quantia de vendas no Crédito:  ");
					scanf("%d", &qtd_credt);
		
		
	if (qtd_credt >= 30){
			
	do{
				
		system("cls");
		
			system("color 2");
		
			printf("\n\n\n	   Foi digitado uma quantidade alta de vendas no Crédito!");
			
				printf("\n\n	   Quantidade de Crédito digitada >>> %d \n\n", qtd_credt);
				printf("\n\n	   Tem certeza que foi digitado certo?");
			
					printf("\n\n Se sim, digite 1 ---- Se não, digite 0 \n");
						scanf("%d", &qtd_correta);
					
		system("color 2");
		
			system("pause");
			
				system("color F");
			
	if (qtd_correta != 1){
				
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Crédito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");
				printf("\n	   Digite a quantia de vendas no Crédito:  ");
					scanf("%d", &qtd_credt);
			}
		
		}while(qtd_credt >= 30);
		
	}
		// VALOR VENDAS DEBITO
		
		for ( i=0; i<qtd_debt; ++i){
		
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Débito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");	
				printf("\n	   Valor da venda nº %d no Débito : ", 1+i);
					scanf("%f", &cart_debt[i]);
		
	}
	
		// VALOR VENDAS CREDITO
		
		for ( i=0; i<qtd_credt; ++i){
		
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Crédito < <<<\n");
				printf("\n		 Digite o que for solicitado\n");	
			printf("\n	==--------------------------------------==\n");	
				printf("\n	   Valor da venda nº %d no Crédito : ", 1+i);
					scanf("%f", &cart_credt[i]);
		
	}
		// RELATORIO FINAL DEBITO E CREDITO
		system("cls");
		
			printf("\n\n		>>> > Contagem de Caixa < <<<\n");
				printf("\n		>>> > Débito e Crédito < <<<\n");	
			printf("\n	==--------------------------------------==\n");	
		
		for ( i=0; i<qtd_debt; ++i){
		
			printf("\n	   Valor da venda nº %d no Débito : %.2f", 1+i, cart_debt[i]);
		
				total_debt=total_debt+cart_debt[i];
	
}
		tot1=total_debt-relat_debt;

			printf("\n\n		Quantidade de vendas: %d \n",qtd_debt);
	  			printf("\n	     Valor total Débito: %.2f \n",total_debt);	
	  			
	  				if(tot1 == 0){
					
					printf("\n		Vendas no Débito bateram");
					
						}else if (tot1 > 0){
					
							printf("\n		Vendas no Débito NÃO bateram --> %.2f ", tot1);
							printf("\n\n	 >>> > HÁ VENDAS A MAIS --- RECONFERIR < <<< \n");
				
								}else {
					
									printf("\n		Vendas no Débito NÃO bateram --> %.2f ", tot1);
									printf("\n\n	 >>> > HÁ VENDAS A MENOS --- RECONFERIR < <<< \n");
					
					}
					
			printf("\n	==--------------------------------------==\n");
		
		for ( i=0; i<qtd_credt; ++i){
		
			printf("\n	   Valor da venda nº %d no Crédito : %.2f", 1+i, cart_credt[i]);
		
				total_credt=total_credt+cart_credt[i];
	
}
	  	tot2=total_credt-relat_credt;
	  	
	  		printf("\n\n		Quantidade de vendas: %d \n",qtd_credt);
	  			printf("\n	     Valor total Crédito: %.2f \n",total_credt);
	  			
	  			if(tot2 == 0){
					
					printf("\n		Vendas no Crédito bateram");
					
						}else if(tot2 > 0){
							
							printf("\n		Vendas no Crédito NÃO bateram --> %.2f ", tot2);
							printf("\n\n	 >>> > HÁ VENDAS A MAIS --- RECONFERIR < <<< \n");
							
							}else {
									
									printf("\n		Vendas no Débito NÃO bateram --> %.2f ", tot2);
									printf("\n\n	 >>> > HÁ VENDAS A MENOS --- RECONFERIR < <<< \n");
							
					}
				
	printf("\n\n");
	  	
	  	system ("pause");
	  	
			system ("cls");
		
			printf("\n		Para sair digite >>  S <<  ==== Para fazer novamente digite >> N <<\n\n ");
				scanf("%s", &sair);
	
				sair = toupper (sair); 	
							
		system("cls");

	}while (sair != 'S');
	
	break;
}

		

	}
}while(opcao != 4);

system("pause");

return 0;

}
void meio(){
	
	printf("%c",219);
	for(int i=0; i<=59;i++){
	printf("%c",32);	
	}
	printf("%c",219);
	printf("\n");
}
void estrutura(){
	
	
	for(int i=0; i<=60; i++){
		printf("%c",254);
	} printf("%c",254);
	printf("\n");
	
	
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	
	
	for(int i=0; i<=60; i++){
		printf("%c",254);
	}printf("%c",254);
	printf("\n");
	
}
void estrutura1(){
	
	
	for(int i=0; i<=60; i++){
		printf("%c",254);
	} printf("%c",254);
	printf("\n");
	
	
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();meio();
	meio();meio();meio();meio();
	
	for(int i=0; i<=60; i++){
		printf("%c",254);
	}printf("%c",254);
	printf("\n");
	
}


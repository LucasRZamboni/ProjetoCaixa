#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<string>
#include<ctype.h>
#include<conio.h>

// Declaraçao da funçao gotoxy

#include <windows.h>
void gotoxy(int col, int lin)
	{
     	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});
	}

// Procedimento para limpar uma linha a partir do cursor, ate a coluna 80

void clreol(int col,int lin)
	{
		int col1;
		if ((lin > 0 && lin < 25) && (col > 0 && col < 81))
			for (col1 = col; col1 <= 80; ++ col1)
				{
					gotoxy(col1,lin); 	puts(" ");
				}
	}
	
void estrutura();
void estrutura1();
void estrutura2();

int main()

{
//	setlocale (LC_ALL, "Portuguese");
	
	
	// Declaraçao de variaveis
	const float moedas[5]={0.05,0.10,0.25,0.50,1}; 
	const float notas[7]={2,5,10,20,50,100,200};
	unsigned int qtd_moedas[5], qtd_notas[7];
	float valor_troco_moedas[6], multi_moedas[5], sangrias[15], suprimentos[15], total_valor_moedas, total_troco_moedas, total_sangrias, total_suprimentos, total;
	float multi_notas[7], total_valor_notas;
	float cart_debt[35], cart_credt[35], total_debt, total_credt,relat_debt, relat_credt, tot1,tot2;
	float crediarios[15], pix[15],deposito[15],total_deposito, total_crediarios, total_pix;
	int i, opcao, troco_moedas,qtd_deposito, qtd_sangrias, qtd_suprimentos, qtd_pix, qtd_crediarios, qtd_debt, qtd_credt, qtd_correta;
	char sair;

	
	system("mode con:cols=71 lines=43");
	
	// Mensagem inicial
	
		system("color 2");
		
		
		estrutura();
			gotoxy(10,15);
				printf("-----Lembrando que este programa e para auxiliar-----");
			gotoxy(14,18);
				    printf("-----ELE NAO SUBSTITUI A CONTAGEM MANUAL!-----");
		
		system("color 2");
			gotoxy(2,42);
		system("pause");
		
			system("cls");
	
	
	// Menu
	
	do {
		
		system("color F");
		
		
		estrutura();
		
		gotoxy(25,10);
				printf("Digite a opçao desejada");
		gotoxy(25,14);
				printf("1|--- Moedas e Notas");
		gotoxy(25,15);
				printf("2|--- Debito e Credito");
		gotoxy(25,16);
				printf("3|--- Crediarios");
		gotoxy(25,17);
				printf("4|--- Sair");
		gotoxy(31,20);
				printf("---|");
		gotoxy(38,20);		
				printf("|---");
			gotoxy(36,20);
			fflush(stdin);
					scanf("%d", &opcao);

		system("cls");

// Opções 
	switch(opcao){ 

		case 1:{ // Opçao 1 -- Moedas e notas
	
	
	//MOEDAS
	
	
	do{				
	
	system("cls");
		estrutura();
		gotoxy(20,10);		
				printf("DIGITAR PONTO AO INVES DE VIRGULA");
		gotoxy(25,14);		
				printf("Correto -- > Ex: 200.55");
		gotoxy(25,15);		
				printf("Correto -- > Ex: 200");
		gotoxy(25,17);		
				printf("Errado  -- > Ex: 200,55");
		gotoxy(2,42);
		system("pause");
		
	system("cls");
	
		for ( i=0; i<5; ++i){
		
		system("cls");
	
				
		estrutura();
		gotoxy(28,4);
				printf("Contagem de Caixa");
		gotoxy(33,10);
				printf("MOEDAS");
		gotoxy(23,14);
				printf("Quantidade de Moedas de %.2f",moedas[i]);
		gotoxy(30,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
		gotoxy(35,16);
		fflush(stdin);
					scanf("%d", &qtd_moedas[i]);
		
					multi_moedas[i]=qtd_moedas[i]*moedas[i];
		
					total_valor_moedas=total_valor_moedas+multi_moedas[i];
		
	}			// TROCO DE MOEDAS
	
		system("cls");
		
		estrutura();
		gotoxy(28,4);
				printf("Contagem de Caixa");
		gotoxy(29,10);
				printf("Troco de moedas");
		gotoxy(19,14);	
				printf("Existe troco de moedas em saquinhos?");
		gotoxy(17,16);		
				printf("SIM --- Digite a quantidade de saquinhos");
		gotoxy(17,17);		
				printf("NaO --- Digite 0 (Zero)");
		gotoxy(31,20);			
				printf("Quantidade?");
		gotoxy(31,23);
				printf("---|");
		gotoxy(38,23);		
				printf("|---");
		gotoxy(36,23);
		fflush(stdin);
				scanf("%d", &troco_moedas);
	
	if (troco_moedas >= 6){
			
		do{
			
		system("cls");
			
		estrutura();						
		gotoxy(28,8);
				printf("Contagem de Caixa");
		gotoxy(29,10);
				printf("Troco de moedas");
		gotoxy(23,15);		
				printf("DIGITE A QUANTIDADE CORRETA!!!");
		/*	gotoxy(46,20);
				printf("Existe troco de moedas em saquinhos?");
		gotoxy(43,16);		
				printf("SIM --- Digite a quantidade de saquinhos");
		gotoxy(43,17);		
				printf("NaO --- Digite 0 (Zero)");
					
		*/		
		gotoxy(31,20);			
				printf("Quantidade?");
		gotoxy(31,21);
				printf("---|");
		gotoxy(38,21);		
				printf("|---");
		gotoxy(36,21);
		fflush(stdin);
				scanf("%d", &troco_moedas);
			
		
		}while (troco_moedas >= 6);
			
			}

		
		for( i=0; i< troco_moedas; i++){
		
		system("cls");
		estrutura();
		gotoxy(28,4);
				printf("Contagem de Caixa");
		gotoxy(29,10);
				printf("Troco de moedas");
		gotoxy(22,15);		
				printf("Digite o valor do %dº saquinho", 1+i);
		gotoxy(27,18);
				printf("---| R$");
		gotoxy(41,18);		
				printf("|---");
		gotoxy(35,18);
		fflush(stdin);
				scanf("%f", &valor_troco_moedas[i]);
			
			}
			
		for ( i=0 ; i < troco_moedas ; i++){
				
			total_troco_moedas=total_troco_moedas+valor_troco_moedas[i];
				
	}

				// NOTAS
				
		for ( i=0; i<7; ++i){
		
		system("cls");
		estrutura();	
		gotoxy(28,4);
				printf("Contagem de Caixa");
		gotoxy(34,10);
				printf("NOTAS");
		gotoxy(21,15);		
				printf("Quantidade de Notas de R$ %.2f",notas[i]);
		gotoxy(31,20);			
				printf("Quantidade?");
		gotoxy(30,23);
				printf("---|");
		gotoxy(38,23);		
				printf("|---");
		gotoxy(35,23);
		fflush(stdin);
				scanf("%d", &qtd_notas[i]);
		
				multi_notas[i]=qtd_notas[i]*notas[i];
				
				total_valor_notas=total_valor_notas+multi_notas[i];

	}
		// Sangrias	----------------------------------------------------------------------------------------
		/*
		system("cls");
			
			printf("\n\n		Contagem de Caixa\n");
				printf("\n	            SANGRIAS\n");
				printf("\n		Digite o que for solicitado\n\n");	
			printf("\n	==--------------------------------------==\n\n");
					printf("\n		  Foi feito alguma sangria?\n");
						printf("\n	     SIM --- Digite a quantidade de sangrias \n");
						printf("\n	     NaO --- Digite 0 (Zero) para continuar \n");
						
							printf("\n	     Quantidade ----> ");
							scanf("%d", &qtd_sangrias);
		
	if( qtd_sangrias >= 6){
				
	do{
			
		system("cls");
			
			printf("\n\n		SANGRIAS\n");
				printf("\n	            QUANTIDADE MUITO ALTA\n");
				printf("\n\n		 DIGITE A QUANTIDADE CORRETA!!! \n\n");	
			printf("\n	==--------------------------------------==\n\n");
				printf("\n		  Foi feito alguma sangria?\n");
						printf("\n	     SIM --- Digite a quantidade de sangrias \n");
						printf("\n	     NaO --- Digite 0  (Zero) \n");
						
							printf("\n	     Quantidade ----> ");
							
							scanf("%d", &qtd_sangrias);
			
		
		}while (qtd_sangrias >= 6);
	}
			
		for( i=0; i< qtd_sangrias; i++){
			
		system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n	            SANGRIAS\n");
				printf("\n		Digite o que for solicitado\n\n");	
			printf("\n	==--------------------------------------==\n\n");
					printf("\n	    	Sangrias \n");
						printf("\n\n	    	Digite o valor da %dº sangria:  ", 1+i);
						scanf("%f", &sangrias[i]);
			
			total_sangrias=total_sangrias+sangrias[i];
			
			}
		*/	
		
		// Suprimentos	------------------------------------------------------------------------------------
		 /*
		system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n	            SUPRIMENTOS\n");
				printf("\n		Digite o que for solicitado\n\n");	
			printf("\n	==--------------------------------------==\n\n");
				printf("\n		 Foi feito algum suprimento?\n");
				printf("\n	     SIM --- Digite a quantidade de suprimentos \n");
					printf("\n	     NaO --- Digite 0  (Zero) \n");
					
						printf("\n	     Quantidade ----> ");
					
						scanf("%d", &qtd_suprimentos);
		
	if (qtd_suprimentos >= 7){
		
		do{
			
		system("cls");
			
			printf("\n\n		SUPRIMENTOS\n");
				printf("\n	            QUANTIDADE MUITO ALTA\n");
				printf("\n\n		 DIGITE A QUANTIDADE CORRETA!!! \n\n");	
			printf("\n	==--------------------------------------==\n\n");
				printf("\n		  Foi feito algum suprimento?\n");
						printf("\n	     SIM --- Digite a quantidade de suprimentos \n");
						printf("\n	     NaO --- Digite 0  (Zero) \n");
							scanf("%d", &qtd_suprimentos);
			
		
		}while (qtd_suprimentos >= 7);	
		
	}
	
	for( i=0; i < qtd_suprimentos; i++){
			
		system("cls");
			
			printf("\n\n		Contagem de Caixa\n");
				printf("\n	            SUPRIMENTOS\n");
				printf("\n		Digite o que for solicitado\n\n");	
			printf("\n	==--------------------------------------==\n\n");
				printf("\n	    	Suprimentos \n");
				printf("\n\n	    	Digite o valor do %dº suprimento:  ", 1+i);
					scanf("%f", &suprimentos[i]);
			
				total_suprimentos=total_suprimentos+suprimentos[i];
			
	}	
		*/	
		system("cls");
		
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(29,4);
				printf("MOEDAS e NOTAS");
		gotoxy(20,5);		
				printf("==-----------------------------==");
		gotoxy(24,7);
				printf("Moedas contidas no caixa");	
		gotoxy(20,8);		
				printf("==-----------------------------==");
		gotoxy(2,9);
		for ( i=0; i<5; ++i){
				printf("\n%c Valor em Moedas de R$ %.2f	%c R$ %.2f %c Qtd (%d Moedas)",186,moedas[i],186,multi_moedas[i],186, qtd_moedas[i]);
	}
		
		gotoxy(20,15);
				printf("==-----------------------------==");
		gotoxy(25,18);
				printf("Notas contidas no caixa");
		gotoxy(20,19);
				printf("==-----------------------------==");
		
		gotoxy(2,20);
		for ( i=0; i<7; ++i){
				printf("\n%c Valor em Notas de R$ %.2f	%c R$ %.2f	%c Qtd (%d Notas)",186,notas[i],186,multi_notas[i],186, qtd_notas[i]);	
	}
	
		gotoxy(20,28);
				printf("==-----------------------------==");
		
				total=total_valor_moedas+total_valor_notas+total_troco_moedas-total_sangrias+total_suprimentos;
		gotoxy(29,30);
				printf("Somas do caixa");
		gotoxy(20,31);
				printf("==-----------------------------==");
						
		gotoxy(2,33);
				printf("  Valor total de Moedas		%c R$ %.2f ",186,total_valor_moedas);
				/*	
					if (troco_moedas > 0){
					printf("\n");
					for (i=0 ; i < troco_moedas ; i++){
						
						printf("\n%c %dº Valor de Troco em Moedas	%c R$ %.2f",186, 1+i,186, valor_troco_moedas[i]);
						
					}
					printf("\n");
				} */
		gotoxy(2,34);				
				printf("  Valor total de Troco em Moedas	%c R$ %.2f",186,total_troco_moedas);
				
				
		gotoxy(2,35);			
				printf("  Valor total de Notas		%c R$ %.2f",186,total_valor_notas);
		gotoxy(20,36);
				printf("==-----------------------------==");
				
			/*	-----------------------------------------------------------------------------------------------------
				if (qtd_sangrias > 0)
					{
						
						for (i = 0 ; i < qtd_sangrias ; i ++)
						{
						
						printf("	   Sangria nº %d -> %.2f\n", 1+i, sangrias[i]);
						
						}
					}
					
				printf("\n	   Sangrias ------------->> R$ %.2f \n",total_sangrias);
					
			
				if (qtd_suprimentos > 0)
					{
						
						for (i = 0 ; i < qtd_suprimentos ; i ++)
						{
						
						printf("	   Suprimento nº %d -> %.2f\n", 1+i, suprimentos[i]);
						
						}
					}
					printf("\n	   Suprimentos ---------->> R$ %.2f \n",total_suprimentos);
					
					
		printf("\n	==--------------------------------------==\n");
			
			
			*/ // ----------------------------------------------------------------------------------------------------
			gotoxy(2,39);
				printf("  Valor total em caixa		%c R$ %.2f",186,total);
				
				
		gotoxy(2,42);		
		system ("pause");
			
			total=0;
			total_valor_notas=0;
			total_valor_moedas=0;
			total_troco_moedas=0;
			
			system ("cls");
		gotoxy(24,15);
			printf("Para sair digite >>  S <<");
		gotoxy(24,16);
			printf("Para fazer novamente digite >> N <<");
		gotoxy(31,21);
				printf("---|");
		gotoxy(38,21);		
				printf("|---");
		gotoxy(36,21);
			fflush(stdin);
				scanf("%s", &sair);
	
					sair = toupper (sair); 		
						
		system("cls");
		
	}while (sair != 'S');
	
		break;

}
		case 2:{ // Opçao 2 -- Debito e Credito
	
	
	do{
		
		// VALOR DO RELATORIO STONE
		
		
		
		system("cls");
		estrutura();
		gotoxy(20,10);		
				printf("DIGITAR PONTO AO INVES DE VIRGULA");
		gotoxy(25,14);		
				printf("Correto -- > Ex: 200.55");
		gotoxy(25,15);		
				printf("Correto -- > Ex: 200");
		gotoxy(25,17);		
				printf("Errado  -- > Ex: 200,55");
		gotoxy(2,42);
		system("pause");
		
					
		system("cls");
	
		estrutura();
		gotoxy(28,4);
				printf("Contagem de Caixa");
		gotoxy(33,6);
				printf("Debito");	
		gotoxy(22,10);		
				printf("Valor do RELAToRIO DA STONE Debito");
		gotoxy(26,20);
				printf("---| R$ ");
		gotoxy(42,20);		
				printf("|---");
		gotoxy(34,20);
		fflush(stdin);
				scanf("%f", &relat_debt);
				
		system("cls");
	
		estrutura();
		gotoxy(28,4);
				printf("Contagem de Caixa");
		gotoxy(33,6);
				printf("Credito");	
		gotoxy(22,10);		
				printf("Valor do RELAToRIO DA STONE Credito");
		gotoxy(26,20);
				printf("---| R$ ");
		gotoxy(42,20);		
				printf("|---");
		gotoxy(34,20);
		fflush(stdin);
				scanf("%f", &relat_credt);
					
			//VENDAS DEBITO
		
		system("cls");
		
		estrutura();
		gotoxy(28,4);
				printf("Contagem de Caixa");
		gotoxy(33,6);
				printf("Debito");	
		gotoxy(23,10);		
				printf("Digite a quantidade de vendas no Debito");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_debt);
		
				
	if (qtd_debt >= 30 && qtd_debt <= 40){
		
	do{
				
		system("cls");
		
			system("color 2");
			
			
		
		estrutura();
		gotoxy(17,2);
				printf("Foi digitado uma quantidade alta de vendas no Debito!");
		gotoxy(19,4);
				printf("Quantidade de Debito digitada >>> %d n", qtd_debt);	
		gotoxy(23,7);		
				printf("Tem certeza que foi digitado certo?");
		gotoxy(20,9);
				printf("Se sim, digite 1 ---- Se nao, digite 0");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_correta);
					
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
			
	if (qtd_correta != 1){
				
		system("cls");
		
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(26,4);
				printf("Debito");	
		gotoxy(23,7);		
				printf("Digite a quantidade de vendas no Debito");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_debt);
			}
		}while(qtd_debt >= 30 && qtd_debt <= 40);
	}
	
	if (qtd_debt > 41){
		
		do{
				
		system("cls");
		
			system("color 2");
		
		
		estrutura();
		gotoxy(17,2);
				printf("Foi digitado uma quantidade alta de vendas no Debito!");
		gotoxy(19,4);
				printf("Quantidade de Debito digitada >>> %d n", qtd_debt);

		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
				
			system("cls");
		
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(26,4);
				printf("Debito");	
		gotoxy(23,7);		
				printf("Digite a quantidade de vendas no Debito");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_debt);
				
		}while(qtd_debt > 41);
	}
	
	
			// VENDAS CREDITO
			
			system("cls");
		
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(26,4);
				printf("Credito");	
		gotoxy(23,7);		
				printf("Digite a quantidade de vendas no Credito");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_credt);
		
		
	if (qtd_credt >= 30 && qtd_credt <= 40){
			
	do{
				
		system("cls");
		
			system("color 2");
		
	
		estrutura();
		gotoxy(17,2);
				printf("Foi digitado uma quantidade alta de vendas no Credito!");
		gotoxy(19,4);
				printf("Quantidade de Credito digitada >>> %d n", qtd_credt);	
		gotoxy(23,7);		
				printf("Tem certeza que foi digitado certo?");
		gotoxy(20,9);
				printf("Se sim, digite 1 ---- Se nao, digite 0");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_correta);
			
					
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
			
	if (qtd_correta != 1){
				
		system("cls");
		
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(26,4);
				printf("Credito");	
		gotoxy(23,7);		
				printf("Digite a quantidade de vendas no Credito");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_credt);
			}
		
		}while(qtd_credt >= 30 && qtd_credt <= 40);
		
	}
	
	if (qtd_credt > 41){
		
		do{
				
		system("cls");
		
			system("color 2");
		
	
		estrutura();
		gotoxy(17,2);
				printf("Foi digitado uma quantidade alta de vendas no Credito!");
		gotoxy(19,4);
				printf("Quantidade de Credito digitada >>> %d n", qtd_credt);

		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
				
				system("cls");
		
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(26,4);
				printf("Credito");	
		gotoxy(23,7);		
				printf("Digite a quantidade de vendas no Credito");
		gotoxy(31,16);
				printf("---|");
		gotoxy(38,16);		
				printf("|---");
			gotoxy(36,16);
			fflush(stdin);
					scanf("%d", &qtd_credt);
				
		}while(qtd_credt > 41);
	}
		// VALOR VENDAS DEBITO
		
		for ( i=0; i<qtd_debt; ++i){
		
		system("cls");
		
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(26,4);
				printf("Debito");	
		gotoxy(23,7);	
				printf("Valor da venda nº %d no Debito : R$ ", 1+i);
				fflush(stdin);
					scanf("%f", &cart_debt[i]);
		
	}
	
		// VALOR VENDAS CREDITO
		
		for ( i=0; i<qtd_credt; ++i){
		
			system("cls");
	
		estrutura();
		gotoxy(28,2);
				printf("Contagem de Caixa");
		gotoxy(26,4);
				printf("Credito");	
		gotoxy(23,7);	
				printf("\n	   Valor da venda nº %d no Credito : R$ ", 1+i);
				fflush(stdin);
				scanf("%f", &cart_credt[i]);
		
	}
		// RELATORIO FINAL DEBITO E CREDITO
		
		system("cls");
	
		estrutura();
		gotoxy(26,2);
				printf("RELATORIO FINAL");
		gotoxy(30,4);
				printf("Debito");	
			
		
		for ( i=0; i<qtd_debt; ++i){
		
		//	printf("\n	   Valor da venda nº %d no Debito : %.2f", 1+i, cart_debt[i]);
		
				total_debt=total_debt+cart_debt[i];
	
}
		tot1=total_debt-relat_debt;
			
		gotoxy(26,9);
			printf("Quantidade de vendas: %d ",qtd_debt);
		gotoxy(26,10);
	  			printf("Valor total Debito: %.2f ",total_debt);	
	  			
	  				if(tot1 == 0){
		gotoxy(26,13);			
					printf("Vendas no Debito bateram");
					
						}else if (tot1 > 0){
		gotoxy(26,13);
							printf("Vendas no Debito NaO bateram");
		gotoxy(26,15);
							printf("Ha VENDAS A MAIS --- RECONFERIR");
				
								}else {
		gotoxy(26,13);			
									printf("Vendas no Debito NaO bateram");
		gotoxy(26,15);							
									printf("Ha VENDAS A MENOS --- RECONFERIR");
					
					}
			gotoxy(14,20);		
			printf("]-------------------------------------------[");
		
		for ( i=0; i<qtd_credt; ++i){
		
		//	printf("\n	   Valor da venda nº %d no Credito : %.2f", 1+i, cart_credt[i]);
		
				total_credt=total_credt+cart_credt[i];
	
}
	  	tot2=total_credt-relat_credt;
	  	
	  	gotoxy(26,22);
				printf("Credito");
				
	  		gotoxy(25,23);
	  		printf("Quantidade de vendas: %d",qtd_credt);
	  		gotoxy(25,24);
	  			printf("Valor total Credito: %.2f",total_credt);
	  			
	  			if(tot2 == 0){
	  				
				gotoxy(22,27);
					printf("Vendas no Credito bateram");
					
						}else if(tot2 > 0){
							
				gotoxy(19,29);
							printf("Vendas no Credito NaO bateram");
				gotoxy(20,31);
							printf("Ha VENDAS A MAIS --- RECONFERIR");
							
							}else {
									
				gotoxy(19,29);
									printf("Vendas no Debito NaO bateram");
					gotoxy(20,31);
									printf("Ha VENDAS A MENOS --- RECONFERIR");
							
					}
				
	printf("\n\n");
	  	
	  	gotoxy(2,42);
	  	system ("pause");
	  	
	  	total_credt=0;
	  	total_debt=0;
	  	
			system ("cls");
		gotoxy(24,15);
			printf("Para sair digite >>  S <<");
		gotoxy(24,16);
			printf("Para fazer novamente digite >> N <<");
		gotoxy(31,21);
				printf("---|");
		gotoxy(38,21);		
				printf("|---");
		gotoxy(36,21);
			fflush(stdin);
				scanf("%s", &sair);
	
				sair = toupper (sair); 	
							
		system("cls");

	}while (sair != 'S');
	
	break;
}


case 3:{ // Crediarios, PIX e Depositos
	
	do{
				
			gotoxy(28,2);
				printf("Contagem de Caixa");
				printf("\n		   Crediarios \n");
			printf("\n	==--------------------------------------==\n");
		
		
			printf("\n	    Digite a quantidade de crediarios: ");
				fflush(stdin);
				scanf("%d", &qtd_crediarios);
		
			
	if (qtd_crediarios >= 6 && qtd_crediarios < 15) {
			
	do{
				
		system("cls");
		
			system("color 2");
		
			printf("\n\n	   Foi digitado uma quantidade alta de crediarios!");
			
				printf("\n\n	   Quantidade de crediarios digitada >>> %d \n\n", qtd_crediarios);
				printf("\n\n	   Tem certeza que foi digitado certo?");
			
					printf("\n\n Se sim, digite 1 ---- Se nao, digite 0 \n");
						fflush(stdin);
						scanf("%d", &qtd_correta);
					
	system("color 2");
		
 	gotoxy(2,42);
			system("pause");
			
				system("color F");
			
	if (qtd_correta != 1){
				
		system("cls");
			
				printf("\n\n		Contagem de Caixa\n");
					printf("\n		   Crediarios \n");
				printf("\n	==--------------------------------------==\n");
					printf("\n	   Digite a quantidade de crediarios: ");
						fflush(stdin);
						scanf("%d", &qtd_crediarios);
						
		}
	}while(qtd_crediarios >= 6 && qtd_crediarios < 15);
}	
		
	else if (qtd_crediarios >= 15){
		
	do{
		
		system("cls");
	
			system("color 2");
	
				printf("\n\n	   		Digite a quantidade correta!\n\n");
		
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
				
					system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		   Crediarios \n");
				printf("\n	==--------------------------------------==\n");
					printf("\n	   Digite a quantidade de crediarios: ");
						fflush(stdin);
						scanf("%d", &qtd_crediarios);
						
	}while (qtd_crediarios >= 15);
		
}

		for( i=0 ; i < qtd_crediarios ; i++){
		
		system("cls");
			
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		   Crediarios \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	    Digite o valor do crediario n° %d: R$ ", 1+i);
					fflush(stdin);
					scanf("%f", &crediarios[i]);
			}
		
		for ( i=0 ; i < qtd_crediarios ; i++){
			
			total_crediarios=total_crediarios+crediarios[i];		

	}
		
		// PIX
		
		system("cls");
			
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		     PIX \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	    Digite a quantidade de PIX: ");
					fflush(stdin);
					scanf("%d", &qtd_pix);
					
		
	if (qtd_pix >= 8 && qtd_pix < 15) {

	do{
				
		system("cls");
		
			system("color 2");
		
			printf("\n\n	   Foi digitado uma quantidade alta de crediarios!");
			
				printf("\n\n	   Quantidade de PIX digitada >>> %d \n\n", qtd_pix);
					printf("\n\n	   Tem certeza que foi digitado certo?");
			
						printf("\n\n Se sim, digite 1 ---- Se nao, digite 0 \n");
							fflush(stdin);
							scanf("%d", &qtd_correta);
					
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
			
	if (qtd_correta != 1){
				
		system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		     PIX \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	   Digite a quantidade de PIX: ");
					fflush(stdin);
					scanf("%d", &qtd_pix);
		}
	
	}while(qtd_pix >= 8 && qtd_pix < 15);
		
}	
		
	else if(qtd_pix >= 15) {
		
	do{
		
		system("cls");
		
			system("color 2");
		
			printf("\n\n	   		Digite a quantidade correta!\n\n");
		
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
				
					system("cls");
			
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		     PIX \n");
			printf("\n	==--------------------------------------==\n");
					printf("\n	   Digite a quantidade de PIX: ");
						fflush(stdin);
						scanf("%d", &qtd_pix);
			
			
	}while (qtd_pix >= 15);
		
}

		for( i=0 ; i < qtd_pix ; i++){
			
		system("cls");
			
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		     PIX \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	    Digite o valor do PIX n° %d: R$ ", 1+i);
					fflush(stdin);
					scanf("%f", &pix[i]);
	
		}
		
		for ( i=0 ; i < qtd_pix ; i++){
	
			total_pix=total_pix+pix[i];
	
	}
		
		
		// Depositos
		
		
		system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		   Depositos \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	    Digite a quantidade de Depositos: ");
					fflush(stdin);
					scanf("%d", &qtd_deposito);
		
			
	if (qtd_deposito >= 6 && qtd_deposito < 15) {
			
	do{
				
		system("cls");
	
			system("color 2");
	
			printf("\n\n	   Foi digitado uma quantidade alta de depositos!");
				printf("\n\n	   Quantidade de depositos digitada >>> %d \n\n", qtd_deposito);
					printf("\n\n	   Tem certeza que foi digitado certo?");
					printf("\n\n Se sim, digite 1 ---- Se nao, digite 0 \n");
						fflush(stdin);
						scanf("%d", &qtd_correta);
					
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");

	if (qtd_correta != 1){
				
		system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		   Depositos \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	   Digite a quantidade de depositos: ");
					fflush(stdin);
					scanf("%d", &qtd_deposito);
		}
	}	while(qtd_deposito >= 6 && qtd_deposito < 15);
}	
		
	else if (qtd_deposito >= 15){
		
	do{
		
		system("cls");
		
			system("color 2");
		
			printf("\n\n	   		Digite a quantidade correta!\n\n");
		
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
			
				system("color F");
				
					system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		   Depositos \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	   Digite a quantidade de depositos: ");
					fflush(stdin);
					scanf("%d", &qtd_deposito);
	
	}while (qtd_deposito >= 15);
}

		for( i=0 ; i < qtd_deposito ; i++){
			
		system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n		   Depositos \n");
			printf("\n	==--------------------------------------==\n");
				printf("\n	    Digite o valor do deposito n° %d: R$ ", 1+i);
					fflush(stdin);
					scanf("%f", &deposito[i]);
		
		}
			
		for ( i=0 ; i < qtd_deposito ; i++){
		
			total_deposito=total_deposito+deposito[i];		
	
	}

		// TOTAL CREDIARIOS, PIX E DEPoSITOS
		
			
		system("cls");
		
			printf("\n\n		Contagem de Caixa\n");
				printf("\n	    Crediarios, PIX e Depositos \n");
			printf("\n	==--------------------------------------==\n");
			
			if (qtd_crediarios > 0){
			
				printf("\n\n	     Quantidade de crediarios digitada: %d\n", qtd_crediarios);
		
		for( i=0 ; i < qtd_crediarios ; i++){
		
			printf("\n	     Valor do crediario nº %d: R$ %.2f ", 1+i,  crediarios[i]);
			
		}
				}else{
		
					printf("\n	     Nenhum Crediario digitado");
					}
			printf("\n	==--------------------------------------==\n");
		if (qtd_pix > 0){
				printf("\n\n	     Quantidade de PIX digitada: %d\n", qtd_pix);
		
		for( i=0 ; i < qtd_pix ; i++){
		
			printf("\n	     Valor do PIX nº %d: R$ %.2f ", 1+i,  pix[i]);
			
		}
				}else{
		
					printf("\n	     Nenhum PIX digitado");
					}
			printf("\n	==--------------------------------------==\n");
		if (qtd_deposito > 0){
				printf("\n\n	     Quantidade de Depositos digitada: %d\n", qtd_deposito);
		
		for( i=0 ; i < qtd_deposito ; i++){
		
			printf("\n	     Valor do deposito nº %d: R$ %.2f ", 1+i,  deposito[i]);
			
		}
		}else{
		
					printf("\n	     Nenhum Deposito digitado");
					}
		if(qtd_crediarios > 0 || qtd_pix > 0 || qtd_deposito > 0){
		
			printf("\n	==--------------------------------------==\n");
				printf("\n\n	     Valor total de Crediarios: R$ %.2f ", total_crediarios);
					printf("\n\n	     Valor total de PIX: R$ %.2f ", total_pix);
						printf("\n\n	     Valor total de Depositos: R$ %.2f ", total_deposito);
			printf("\n	==--------------------------------------==\n");	
		
				total = total_crediarios + total_pix + total_deposito;
		
				printf("\n	     Crediarios + PIX + Depositos: R$ %.2f \n\n", total);
		}
		
		gotoxy(2,42);
			system("pause");
		
		system ("cls");
		gotoxy(24,15);
			printf("Para sair digite >>  S <<");
		gotoxy(24,16);
			printf("Para fazer novamente digite >> N <<");
		gotoxy(31,21);
				printf("---|");
		gotoxy(38,21);		
				printf("|---");
		gotoxy(36,21);
			fflush(stdin);
				scanf("%s", &sair);
	
					sair = toupper (sair); 								
		
		system("cls");
		
	}while (sair != 'S');
	
	break;
}

		case 4:{ // Opçao 4 -- Sair + Mensagem importante
	
		system("cls");
		
			system("color 2");
			estrutura();
			gotoxy(10,15);
				printf("-----Lembrando que este programa e para auxiliar-----");
			gotoxy(14,18);
				    printf("-----ELE NAO SUBSTITUI A CONTAGEM MANUAL!-----");
		
		system("color 2");
		
		gotoxy(2,42);
			system("pause");

	break;
}

	default:{ // Outra opçao -- ERRO
	
		system("cls");
		
			system("color 2");
			estrutura();
			gotoxy(21,18);
			printf("------ Opçao invalida!! ------");
		
		system("color 2");
		
		gotoxy(2,42);
			system("pause");
		
				system("cls");
		
					system("color F");
	
	break;
	
		}

	}
	
}while(opcao != 4);

		
	
	return 0;
}


void estrutura(){
	
int lado=43;


for(int col=0; col<=69;col++){		
		printf("%c",205);
	}
	printf("\n");
	
	for(int lin=0;lin<41;lin++){			
			printf("%c",186);
	 	for(int col=0;col<69;col++){
			printf(" ");
		}	
		printf("%c\n",186);
		
	}
    for(int col=0; col<=69;col++){		
		printf("%c",205);
			
	}
	
	gotoxy(1,1);
	printf("%c",201);
	gotoxy(71,1);
	printf("%c",187);
	gotoxy(1,43);
	printf("%c",200);
	gotoxy(71,43);
	printf("%c",188);
	
	}	
	
	


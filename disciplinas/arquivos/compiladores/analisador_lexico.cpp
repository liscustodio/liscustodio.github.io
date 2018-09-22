
/*
 * ESTE CÓDIGO IMPLEMENTA UM ANALIZADOR LÉXICO PARA O EXEMPLO DE FRAGMENTO DE LINGUAGEM APRESENTADO EM SALA DE AULA (VEJA OS SLIDES DA AULA 4: ANÁLISE LÉXICA: PARTE 2)
 * E PODERÁ SER UTILIZADO COMO PONTO DE PARTIDA PARA IMPLEMENTAÇÃO DO ANALISADOR LÉXICO PARA LINGUAGEM ADOTADO NO TRABALHO PROPOSTO.
 * */

#include <stdio.h>

int estado = 0;
int partida = 0;
int cont_sim_lido = 0;
int valor_lexico;
char *code;


char *readFile(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	char *code;
	int n = 0;
	int c;

	if(file == NULL) return NULL;

	fseek(file, 0, SEEK_END);
	long f_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	code = new char (f_size);

	while ((c = fgetc(file))!= EOF)
	{
		code[n++] = (char) c;
	}
	code[n] = '\0';
	return code;
}




int falhar()
{
	switch(estado)
	{
	case 0: partida = 9; break;

	case 9: partida = 12; break;

	case 12: partida = 20; break;

	case 20: partida = 25; break;

	case 25:
		//retornar msg de erro
		printf("Erro encontrado no código\n");
		cont_sim_lido++;
		break;

	default: printf("Erro do compilador");
	}
	return(partida);
}

int proximo_token()
{
	char c;
	while(code[cont_sim_lido] != NULL)
	{
		switch(estado)
		{
			case 0:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else if(c == '<') estado = 1;
				else if(c == '=') estado = 5;
				else if(c == '>') estado = 6;
				else
					{
					 estado = falhar();
					}
				break;

			case 1:
				cont_sim_lido++;
				c = code[cont_sim_lido];

				if(c == '=') estado = 2;
				else if(c == '>') estado = 3;
				else estado = 4;
				break;

			case 2:
				cont_sim_lido++;
				printf("<relop, LE>\n");
				estado = 0;
				return(0);
				break;

			case 3:
				cont_sim_lido++;
				printf("<relop, NE>\n");
				estado = 0;
				return(0);
				break;

			case 4:
				cont_sim_lido++;
				printf("<relop, LT>\n");
				estado = 0;
				return(0);
				break;

			case 5:
				cont_sim_lido++;
				printf("<relop, EQ>\n");
				estado = 0;
				return(0);
				break;

			case 6:
				cont_sim_lido++;
				c = code[cont_sim_lido];
				if(c == '=') estado = 7;
				else estado = 8;
				break;

			case 7:
				cont_sim_lido++;
				printf("<relop, GE>\n");
				estado = 0;
				return(0);
				break;

			case 8:
				cont_sim_lido++;
				printf("<relop, GT>\n");
				return(0);
				break;

			case 9:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else
				{
					/*implementar ações referentes aos estado */
					estado = falhar();
				}

				break;

				/*implementar ações para os estados 10, 11, 12*/

			case 12:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else
				{
					/*implementar ações referentes aos estado */
					estado = falhar();
				}
				break;

				/*implementar ações para os estados 13-19*/

			case 20:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else
				{
					/*implementar ações referentes aos estado */
					estado = falhar();
				}
				break;

				/*implementar ações para os estados 21-24*/

			case 25:
				c = code[cont_sim_lido];
				if((c == ' ')||(c == '\n'))
				{
					estado = 0;
					cont_sim_lido++;
				}
				else
				{
					/*implementar ações referentes aos estado */
					estado = falhar();
					return(1);
				}
				break;
		}

	}
    return(0);
}




int main ()
{
    code = readFile("programa.txt");
	proximo_token();
	proximo_token();

}

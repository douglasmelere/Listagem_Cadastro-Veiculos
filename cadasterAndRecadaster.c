#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct {

    char marca[30];
    char modelo[30];
    float litragem;
    int ano_fabricacao;
    int portas;
    int ocupantes;
    int kms;

}veiculo;

                          // Assinatura das funções
//------------------------------------------------------------------------------//

void imprimeVeiculo();
veiculo cadastraVeiculo();

//------------------------------------------------------------------------------//

                       // Função para imprimir veículos
//------------------------------------------------------------------------------//

    int proximoIndice = 0;
    veiculo veiculos[100];

//------------------------------------------------------------------------------//

    int main(void) {

            veiculo carro1;
            UINT CPAGE_UTF8 = 65001;
            UINT CPAGE_DEFAULT = GetConsoleOutputCP();
            SetConsoleOutputCP(CPAGE_UTF8);

        while(1) {
        
        system("cls");

        printf("\t\tLista de veículos\n\n"
                "Escolha uma das opções abaixo:\n\n "
                "[1] - Cadastrar veículo\n"
                " [2] - Relatório de veículos\n"
                " [ESC] Encerrar o programa\n"
        );

            switch(getch()) {
                
                case '1': 
                if(proximoIndice < 100) {
                    veiculos[proximoIndice++] = cadastraVeiculo();
                    break;
                }
                case '2': 
                    for(int n = 0; n < proximoIndice; n++) 
                    imprimeVeiculo(veiculos[n]);
                    
                    break;
                case 27: 
                    return EXIT_SUCCESS;
                default: 
                    printf("Opção inválida!\n");
                    break;

            }

        system("pause");

        }

        carro1 = cadastraVeiculo();
        imprimeVeiculo(carro1);

        return EXIT_SUCCESS;
    }

     //------------------------------------------------------------------------------//
                        // Função para imprimir veículos
    //------------------------------------------------------------------------------//

    void imprimeVeiculo(veiculo carro) {

        printf("\n--------------------\n\n");
        printf("Dados do veículo:\n");
        printf("Marca:\t\t\t%s\n", carro.marca);
        printf("Modelo:\t\t%s\n", carro.modelo);
        printf("Ano de fabricação:\t%d\n", carro.ano_fabricacao);
        printf("Litragem:\t\t%.1f\n", carro.litragem);
        printf("Número de portas:\t%d\n", carro.portas);
        printf("Numero de ocupantes:\t%d\n", carro.ocupantes);
        printf("Kilometragem:\t\t%d\n", carro.kms);
        printf("\n--------------------\n");
    
    }

     //------------------------------------------------------------------------------//
                          // Função para cadastrar veículos
    //------------------------------------------------------------------------------//

    veiculo cadastraVeiculo() {
        
        veiculo carro;

        printf("\n------------------------------\n");
        printf("\nCadastro de veículo:\n\n");

        printf("Informe a marca do veículo: ");
        fflush(stdin);
        gets(carro.marca);
        system("cls");

        printf("Informe o ano de fabricação do veículo: ");
        scanf("%d", &carro.ano_fabricacao);

        printf("Informe o modelo do veiculo: ");
        fflush(stdin);
        gets(carro.modelo);
        system("cls");

        printf("Informe a litragem do veículo: ");
        scanf("%f", &carro.litragem);
        system("cls");

        printf("Informe o número de portas do veículo: ");
        scanf("%d", &carro.portas);
        system("cls");

        printf("Informe o número de ocupantes do veículo: ");
        scanf("%d", &carro.ocupantes);
        system("cls");

        printf("Informe a kilometragem do veículo: ");
        scanf("%d", &carro.kms);
        system("cls");

        return carro;

    }
#include <stdio.h>
#include <string.h>

int main(){
    int id[300], ano[300], status[300];
    char titulo[300][50], autor[300][50];
    
    int contadorLivros = 0;
    int sair = 0;
     do {
        int opc;
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar um livro:\n");
        printf("2 - Listar:\n");
        printf("3 - Buscar:\n");
        printf("4 - Atualizar:\n");
        printf("5 - Ativar/Inativar:\n");
        printf("6 - Estatisticas:\n");
        printf("7 - Ordenar:\n");
        printf("8 - Sair.\n");
        printf("Opcao: ");
        scanf("%d", &opc);
        getchar();
        
        switch(opc) {
            case 1: {
                int novoId, novoAno;
                char novoTitulo[50], novoAutor[50];
                
                printf("Cadastrar:\n");
    
                if (contadorLivros >= 300) {
                    printf("Erro: inventário cheio, Nao e possivel cadastrar mais livros.\n");
                } else {
                    printf("Digite o ID do livro: ");
                    scanf("%d", &novoId);
                    getchar();
    
                    if (novoId <= 0) {
                        printf("Erro: O ID deve ser um numero positivo.\n");
                    } else {
                        int idDuplicado = 0;
                        for (int i = 0; i < contadorLivros; i++) {
                            if (id[i] == novoId) {
                                idDuplicado = 1;
                            }
                        }
    
                        if (idDuplicado == 1) {
                            printf("Erro: ID ja existente. Por favor, digite um ID unico.\n");
                        } else {
                            printf("Digite o titulo do livro: ");
                            fgets(novoTitulo, 50, stdin);
                            
                            if (novoTitulo[strlen(novoTitulo) - 1] == '\n') {
                                novoTitulo[strlen(novoTitulo) - 1] = '\0';
                            }
    
                            printf("Digite o autor do livro: ");
                            fgets(novoAutor, 50, stdin);
                            
                            if (novoAutor[strlen(novoAutor) - 1] == '\n') {
                                novoAutor[strlen(novoAutor) - 1] = '\0';
                            }
                            
                            printf("Digite o ano de publicacao (1500 a 2025): ");
                            scanf("%d", &novoAno);
                            getchar();
    
                            if (strlen(novoTitulo) == 0 || strlen(novoAutor) == 0) {
                                printf("Erro: Titulo e autor nao podem ser vazios.\n");
                            } else if (novoAno < 1500 || novoAno > 2025) {
                                printf("Erro: O ano deve estar entre 1500 e 2025.\n");
                            } else {
                                // Copia o titulo digitado
                                int j = 0;
                                while(novoTitulo[j] != '\0'){
                                    titulo[contadorLivros][j] = novoTitulo[j];
                                    j++;
                                }
                                titulo[contadorLivros][j] = '\0'; // o terminador finzaliza nulo
                                
                                // Copia o autor  
                                j = 0;
                                while(novoAutor[j] != '\0'){
                                    autor[contadorLivros][j] = novoAutor[j];
                                    j++;
                                }
                                autor[contadorLivros][j] = '\0'; // terminador finaliza nulo

                                // Salva os outros dados
                                id[contadorLivros] = novoId;
                                ano[contadorLivros] = novoAno;
                                status[contadorLivros] = 1;
    
                                contadorLivros++;
                                printf("Livro cadastrado com sucesso! ID: %d\n", novoId);
                            }
                        }
                    }
                }
                break;
            }
            case 2:{
                printf("Listar:\n");
                
                int opcListagem;
                
                if (contadorLivros == 0) {
                    printf("Nenhum livro cadastrado no acervo.\n");
                    break;
                }
                
                printf("\n--- Submenu de Listagem ---\n");
                printf("1 - Listar todos os livros\n");
                printf("2 - Listar apenas livros ativos\n");
                printf("3 - Listar apenas livros inativos\n");
                printf("Opcao: ");
                scanf("%d", &opcListagem);
                getchar();
                
                
                for(int i = 0; i < contadorLivros; i++){
                    int exibir = 0; // Variavel de controle para a exibicao
                    
                    if(opcListagem == 1){  
                        exibir = 1;
                    } else if( opcListagem == 2 && status[i] == 1){
                        exibir = 1;
                    } else if ( opcListagem == 3 && status[i == 0]){
                        exibir = 1;
                    }
                    
                    if(exibir){
                        printf("Id: %d | Titulo: %s | Autor: %s | Ano: %d | Status: %s\n", 
                               id[i], 
                               titulo[i], 
                               autor[i], 
                               ano[i], 
                               status[i] == 1 ? "Ativo" : "Inativo");
                    }
                }
                
            }
                break;
            case 3:
                printf("Buscar:\n");
                break;
            case 4:
                printf("Atualizar:\n");
                break;
            case 5:
                printf("Ativar/Inativar:\n");
                break;
            case 6:
                printf("Estatisticas:\n");
                break;
            case 7:
                printf("Ordenar:\n");
                break;
            case 8: {
                char out;
                printf("Deseja sair: (S/N) \n ");
                scanf(" %c", &out);
                if (out == 's' || out == 'S') {
                    printf("Saindo do programa...\n");
                    sair = 1;
                }
            }
            break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (sair == 0);
    
    return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int numero_apt;
    char responsavel[50];
    float valor_condominio;
} Apartamento;

int main(void) {
    Apartamento predio[10];
    int qtd = 0; // controla o total de cadastros
    int opcao;

    do {
        printf("\n--- MENU CONDOMINIO ---\n");
        printf("1) Cadastrar Apartamento\n");
        printf("2) Listar Apartamentos\n");
        printf("3) Buscar por ID\n");
        printf("4) Atualizar Apartamento\n");
        printf("5) Remover Apartamento\n");
        printf("6) Sair\n");
        printf("Escolha uma opcao: ");

        // valida opcao do menu
        if (scanf("%d", &opcao) != 1) {
            printf("\nOpcao invalida! Digite um numero.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch(opcao) {
            case 1:
                printf("\n[ NOVO CADASTRO ]\n");
                if (qtd >= 10) {
                    printf("Erro: Limite de 10 apartamentos atingido.\n");
                    break;
                }

                int temp_id;
                int ja_existe;
                
                while (1) {
                    printf("ID unico: ");
                    if (scanf("%d", &temp_id) != 1) {
                        printf("Erro: digite apenas numeros!\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    while(getchar() != '\n');

                    ja_existe = 0;
                    for (int i = 0; i < qtd; i++) {
                        if (predio[i].id == temp_id) {
                            ja_existe = 1;
                            break;
                        }
                    }
                    
                    if (ja_existe) {
                        printf("Erro: Esse ID ja esta cadastrado.\n");
                    } else {
                        break;
                    }
                }
                
                predio[qtd].id = temp_id;

                // valida numero do apt
                while (1) {
                    printf("Numero do apartamento: ");
                    if (scanf("%d", &predio[qtd].numero_apt) == 1) {
                        while(getchar() != '\n');
                        break;
                    }
                    printf("Erro: digite um numero valido.\n");
                    while(getchar() != '\n');
                }

                printf("Nome do responsavel: ");
                fgets(predio[qtd].responsavel, 50, stdin);
                predio[qtd].responsavel[strcspn(predio[qtd].responsavel, "\n")] = '\0';

                // valida valor do condominio
                while (1) {
                    printf("Valor do condominio: ");
                    if (scanf("%f", &predio[qtd].valor_condominio) == 1) {
                        while(getchar() != '\n');
                        break;
                    }
                    printf("Erro: valor invalido.\n");
                    while(getchar() != '\n');
                }

                qtd++;
                printf("Apartamento cadastrado com sucesso.\n");
                break;

            case 2:
                printf("\n[ APARTAMENTOS CADASTRADOS ]\n");
                if (qtd == 0) {
                    printf("Nenhum registro encontrado.\n");
                    break;
                }
                for (int i = 0; i < qtd; i++) {
                    printf("ID: %d | Apt: %d | Morador: %s | Taxa: R$ %.2f\n",
                        predio[i].id, predio[i].numero_apt, predio[i].responsavel, predio[i].valor_condominio);
                }
                break;

            case 3:
                printf("\n[ BUSCAR POR ID ]\n");
                if (qtd == 0) {
                    printf("Nenhum apartamento cadastrado.\n");
                    break;
                }
                
                int id_busca, achou_id = 0;
                while (1) {
                    printf("Digite o ID para buscar: ");
                    if (scanf("%d", &id_busca) == 1) {
                        while(getchar() != '\n');
                        break;
                    }
                    printf("Erro: digite um ID valido.\n");
                    while(getchar() != '\n');
                }

                for (int i = 0; i < qtd; i++) {
                    if (predio[i].id == id_busca) {
                        printf("Resultado -> ID: %d | Apt: %d | Morador: %s | Taxa: R$ %.2f\n",
                            predio[i].id, predio[i].numero_apt, predio[i].responsavel, predio[i].valor_condominio);
                        achou_id = 1;
                        break;
                    }
                }
                if (!achou_id) printf("ID nao encontrado.\n");
                break;

            case 4:
                printf("\n[ ATUALIZAR DADOS ]\n");
                if (qtd == 0) {
                    printf("Nenhum apartamento cadastrado.\n");
                    break;
                }
                
                int id_edit, achou_edit = 0;
                while (1) {
                    printf("Digite o ID que deseja alterar: ");
                    if (scanf("%d", &id_edit) == 1) {
                        while(getchar() != '\n');
                        break;
                    }
                    printf("Erro: digite um numero valido.\n");
                    while(getchar() != '\n');
                }

                for (int i = 0; i < qtd; i++) {
                    if (predio[i].id == id_edit) {
                        achou_edit = 1;
                        
                        while (1) {
                            printf("Novo numero do apt: ");
                            if (scanf("%d", &predio[i].numero_apt) == 1) {
                                while(getchar() != '\n');
                                break;
                            }
                            printf("Erro: digite um numero.\n");
                            while(getchar() != '\n');
                        }

                        printf("Novo responsavel: ");
                        fgets(predio[i].responsavel, 50, stdin);
                        predio[i].responsavel[strcspn(predio[i].responsavel, "\n")] = '\0';

                        while (1) {
                            printf("Novo valor condominio: ");
                            if (scanf("%f", &predio[i].valor_condominio) == 1) {
                                while(getchar() != '\n');
                                break;
                            }
                            printf("Erro: valor invalido.\n");
                            while(getchar() != '\n');
                        }

                        printf("Dados atualizados.\n");
                        break;
                    }
                }
                if (!achou_edit) printf("ID nao encontrado.\n");
                break;

            case 5:
                printf("\n[ EXCLUIR REGISTRO ]\n");
                if (qtd == 0) {
                    printf("Nenhum apartamento cadastrado.\n");
                    break;
                }
                
                int id_del, index_del = -1;
                while (1) {
                    printf("Digite o ID para remover: ");
                    if (scanf("%d", &id_del) == 1) {
                        while(getchar() != '\n');
                        break;
                    }
                    printf("Erro: digite um ID numerico.\n");
                    while(getchar() != '\n');
                }

                // acha a posicao do elemento
                for (int i = 0; i < qtd; i++) {
                    if (predio[i].id == id_del) {
                        index_del = i;
                        break;
                    }
                }

                if (index_del != -1) {
                    // puxa os elementos para cobrir a vaga
                    for (int j = index_del; j < qtd - 1; j++) {
                        predio[j] = predio[j + 1];
                    }
                    qtd--;
                    printf("Apartamento removido.\n");
                } else {
                    printf("ID nao encontrado.\n");
                }
                break;

            case 6:
                printf("\nSaindo... Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}

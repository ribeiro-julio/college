#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    char address[50];
    int inserted_in_day, inserted_in_month, inserted_in_year;
}Client;

void add_client(){
    Client client[1];
    FILE *file;
    file = fopen("./clients.dat", "ab");
    if(file == NULL){
        printf("Erro ao abrir o arquivo");
        system("pause");
        exit(1);
    }
    
    printf("Adicionar um cliente\n");
    printf("========================================\n");
    printf("Nome do cliente: ");
    setbuf(stdin, NULL);
    fgets(client[0].name, 29, stdin);
    client[0].name[strcspn(client[0].name, "\n")] = '\0';
    printf("Endereco do cliente: ");
    setbuf(stdin, NULL);
    fgets(client[0].address, 49, stdin);
    client[0].address[strcspn(client[0].address, "\n")] = '\0';
    printf("Data de cadastro (dia mes e ano separados com espaco): ");
    scanf("%d %d %d", &client[0].inserted_in_day, &client[0].inserted_in_month, &client[0].inserted_in_year);
    fwrite(client, sizeof(client), 1, file);

    fclose(file);
    system("clear");
    printf("Cliente salvo\n");
    printf("========================================\n");
}

void update_client(){
    int size, found = 0, i;
    char name[30];
    Client *clients;
    FILE *file;
    file = fopen("clients.dat", "rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file)/sizeof(Client);
    clients = (Client*)calloc(size, sizeof(Client));
    rewind(file);
    fread(clients, sizeof(Client), size, file);
    fclose(file);

    printf("Alterar informacoes do cliente\n");
    printf("Digite o nome do cliente para alterar: ");
    setbuf(stdin, NULL);
    fgets(name, 29, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("========================================\n");
    for(i = 0; i < size; i++){
        if(strcmp(name, clients[i].name) == 0){
            found = 1;
            break;
        }
    }

    if(found == 1){
        file = fopen("clients.dat", "w+b");
        if(file == NULL){
            printf("Erro ao abrir o arquivo\n");
            system("pause");
            exit(1);
        }

        printf("Digite o novo nome do cliente: ");
        setbuf(stdin, NULL);
        fgets(clients[i].name, 29, stdin);
        clients[i].name[strcspn(clients[i].name, "\n")] = '\0';
        printf("Digite o novo endereco do cliente: ");
        setbuf(stdin, NULL);
        fgets(clients[i].address, 49, stdin);
        clients[i].address[strcspn(clients[i].address, "\n")] = '\0';
        printf("Digite a nova data de cadastro do cliente (dia mes e ano separados com espaco): ");
        scanf("%d %d %d", &clients[i].inserted_in_day, &clients[i].inserted_in_month, &clients[i].inserted_in_year);
        fwrite(clients, sizeof(Client), size, file);

        fclose(file);

        printf("Alteracoes salvas\n");
        printf("========================================\n");
    }
    else{
        system("clear");
        printf("Erro -> Cliente fornecido nao esta cadastrado\n");
        printf("========================================\n");
    }

    free(clients);
}

void print_clients(){
    int size;
    Client *clients;
    FILE *file;
    file = fopen("clients.dat", "rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    size = ftell(file)/sizeof(Client);
    clients = (Client*) calloc(size, sizeof(Client));
    rewind(file);
    fread(clients, sizeof(Client), size, file);
    printf("Clientes cadastrados:\n");
    printf("========================================\n");
    for(int i = 0; i < size; i++){
        puts(clients[i].name);
        puts(clients[i].address);
        printf("Adicionado em: %d/%d/%d\n", clients[i].inserted_in_day, clients[i].inserted_in_month, clients[i].inserted_in_year);
        printf("========================================\n");
    }

    free(clients);
    fclose(file);
}

void print_client(){
    int size, found = 0, i;
    char name[30];
    Client *clients;
    FILE *file;
    file = fopen("clients.dat", "rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file)/sizeof(Client);
    clients = (Client*)calloc(size, sizeof(Client));
    rewind(file);
    fread(clients, sizeof(Client), size, file);
    fclose(file);

    printf("Pesquisar cliente\n");
    printf("Digite o nome do cliente para pesquisar: ");
    setbuf(stdin, NULL);
    fgets(name, 29, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("========================================\n");
    for(i = 0; i < size; i++){
        if(strcmp(name, clients[i].name) == 0){
            found = 1;
            puts(clients[i].name);
            puts(clients[i].address);
            printf("Adicionado em: %d/%d/%d\n", clients[i].inserted_in_day, clients[i].inserted_in_month, clients[i].inserted_in_year);
            printf("========================================\n");
        }
    }
    if(found == 0){
        system("clear");
        printf("Erro -> Cliente fornecido nao esta cadastrado\n");
        printf("========================================\n");
    }
    free(clients);
}

void remove_client(){
    int size, found = 0, i;
    char name[30];
    Client *clients;
    FILE *file;
    file = fopen("clients.dat", "rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file)/sizeof(Client);
    clients = (Client*)calloc(size, sizeof(Client));
    rewind(file);
    fread(clients, sizeof(Client), size, file);
    fclose(file);

    printf("Remover cliente\n");
    printf("Digite o nome do cliente para remover: ");
    setbuf(stdin, NULL);
    fgets(name, 29, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("========================================\n");
    for(i = 0; i < size; i++){
        if(strcmp(name, clients[i].name) == 0){
            found = 1;
            break;
        }
    }

    if(found == 1){
        for(int j = i; j < size-1; j++){
            clients[j] = clients[j+1];
        }

        file = fopen("clients.dat", "w+b");
        if(file == NULL){
            printf("Erro ao abrir o arquivo\n");
            system("pause");
            exit(1);
        }

        fwrite(clients, sizeof(Client), size-1, file);

        fclose(file);

        printf("Cliente removido\n");
        printf("========================================\n");
    }
    else{
        system("clear");
        printf("Erro -> Cliente fornecido nao esta cadastrado\n");
        printf("========================================\n");
    }

    free(clients);
}

int main(){
    int option = -1;
    while(option != 0){
        printf("Selecione uma opcao:\n");
        printf("1 - Adicionar um cliente\n");
        printf("2 - Alterar informacoes do cliente\n");
        printf("3 - Imprimir informacoes de todos os cliente\n");
        printf("4 - Imprimir informacoes de um cliente\n");
        printf("5 - Remover um cliente\n");
        printf("0 - Sair\n");
        scanf("%d", &option);
        switch(option){
            case 0: break;
            case 1:
                system("clear");
                add_client();
                break;
            case 2:
                system("clear");
                update_client();
                break;
            case 3:
                system("clear");
                print_clients();
                break;
            case 4:
                system("clear");
                print_client();
                break;
            case 5:
                system("clear");
                remove_client();
                break;
            default:
                system("clear");
                printf("Opcao Invalida\n");
                break;
        }
    }
    return 0;
}
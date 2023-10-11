#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "Biblioteca.h"

// FUNÇÃO QUE IMPRIME TAREFAS COM E SEM ATRASOS
void com_e_sem_atrasos(No *lista_tarefas_concluidas)
{
    // Limpando a tela
    system("cls");

    // Declarando variáveis
    No* aux;

    // Título
    printf ("\n\n\n\t\t\t\t\t\t---------------------------------------\n");
    printf ("\t\t\t\t\t\tLISTA DE TAREFAS CONCLUIDAS COM ATRASO\n");
    printf ("\t\t\t\t\t\t---------------------------------------\n\n");

    // Percorrendo Lista de tarefas concluidas
    for(aux = lista_tarefas_concluidas ; aux != NULL ; aux = aux->prox)
    {
        if(aux->info.status == 1) // A condição para imprimir é estar atrasada (status = 1)
        {
            imprimir_No_Lista(aux); // Chama a função que imprime um nó
        }
    }

    // Título
    printf ("\n\n\n\t\t\t\t\t\t---------------------------------------\n");
    printf ("\t\t\t\t\t\tLISTA DE TAREFAS CONCLUIDAS SEM ATRASO\n");
    printf ("\t\t\t\t\t\t---------------------------------------\n\n");

    // Percorrendo a lista de tarefas concluidas novamente
    for(aux = lista_tarefas_concluidas ; aux != NULL ; aux = aux->prox)
    {
        if(aux->info.status == 0) // A condição para imprimir é estar em dia (status = 0)
        {
            imprimir_No_Lista(aux); // Chama a função que imprime um nó
        }
    }

    // Pausa para visualização
    printf ("\n\n\n");
    system ("pause");
}

// FUNÇÃO QUE IMPRIME A LISTA DE TAREFAS PENDENTES
void pendentes(No *pendente)
{
    // Limpando a tela
    system("cls");
    printf ("\n\n\n\t\t\t\t\t\t---------------------------\n");
    printf ("\t\t\t\t\t\tLISTA DE TAREFAS PENDENTES\n");
    printf ("\t\t\t\t\t\t---------------------------\n\n");

    // Chamando função imprime lista
    imprimir_Lista(pendente);

    system("pause");
}

// FUNÇÃO QUE IMPRIME A LISTA DE TAREFAS CONCLUIDAS
void concluidas(No *estruturaLista)
{
    // Limpando a tela
    system("cls");
    printf ("\n\n\n\t\t\t\t\t\t---------------------------\n");
    printf ("\t\t\t\t\t\tLISTA DE TAREFAS CONCLUIDAS\n");
    printf ("\t\t\t\t\t\t---------------------------\n\n");

    // chamando função imprime lista
    imprimir_Lista(estruturaLista);

    printf ("\n\n\n");
    system("pause");

    return;
}

// FUNÇÃO QUE ATRIBUI STATUS DE PENDENCIA EM UMA TAREFA
No *atualizar (Fila *fila,No *pendente,data data_atual)
{
    // Limpando a tela
    system("cls");
    printf ("\n\n\n\t\t\t\t\t\t---------------------------\n");
    printf ("\t\t\t\t\t\tADICIONAR OU RETIRAR PENDENCIA \n");
    printf ("\t\t\t\t\t\t---------------------------\n\n");

    // Declarando variaveis
    int verificador;
    int opcao;
    int codigo;
    No *aux;
    No *anterior = NULL;
    tarefa tarefa_pendente;
    Fila *fila_aux;
    data referencia;

    // Cria a fila para Fila auxiliar
    fila_aux=CriaFila(fila_aux);

    // Filtro para recolher o valor de opcao
    do
    {
        system ("cls");
        opcao = 0;

        printf ("\n\n\n\t\t\t\t\t\t------------------------------\n");
        printf ("\t\t\t\t\t\tADICIONAR OU RETIRAR PENDENCIA \n");
        printf ("\t\t\t\t\t\t------------------------------\n\n");

        printf ("\n\n\t\t\t\t\t[1]. Adicionar pendencia a uma tarefa\n");
        printf ("\t\t\t\t\t[2]. Remover a pendencia de uma tarefa");
        printf ("\n\t\t\t\t\t Digite a sua opcao: ");

        scanf ("%d",&opcao);

    } while(opcao != 1 && opcao != 2);

    system("cls");

    printf ("\n\n\n\t\t\t\t\t\t------------------------------\n");
    printf ("\t\t\t\t\t\tADICIONAR OU RETIRAR PENDENCIA \n");
    printf ("\t\t\t\t\t\t------------------------------\n\n");

    // Direcionando usaario para opcao escolhida
    if(opcao == 1)
    {
        // Recebendo o codigo
        printf ("\nInsira o codigo da tarefa que deseja aplicar a pendencia: ");
        scanf  ("%d",&codigo);

        // verificador do codigo encontrado ou nao
        verificador = 0;

        // percorrendo a fila original
        for(aux = fila->ini ; aux != NULL ; aux = aux->prox)
        {
            // se enontrarmos o codigo digitado, entramos no bloco
            if(codigo == aux->info.codigo)
            {
                // codigo encontrado
                verificador = 1;

                printf ("\nSua tarefa foi atualizada para pendente!!\n\n");

                // atualizando o status para pendente e enviando para lista de pendencia
                aux->info.status = -1;
                tarefa_pendente = aux->info;
                pendente = Insere_Lista_Ordenada(pendente,aux->info);

            }
            else // codigo nao enontrado, joga para fila auxiliar
            {
                InsereFila(fila_aux,aux->info);
            }
        }

        // A fila auxiliar vira a fila original
        fila->ini = fila_aux->ini;
        fila->fim = fila_aux->fim;

        // liberamos a fila auxiliar da memoria
        free(fila_aux);

        // informando se encontrou o codigo ou nao
        if(verificador == 0) // Caso o codigo nao foi econtrado
        {
            printf ("O código digitado nao foi encontrado !!\n\n\n");
            system ("pause");
        }
        else // Caso codigo for econtrado
        {
            printf ("Tarefa atualizada com sucesso !!\n\n\n");
            system ("pause");
        }
    }
    else // Se a opcao 2 foi selecionada
    {
        printf ("\nInsira o codigo da tarefa que deseja remover a pendencia: ");
        scanf  ("%d",&codigo);

        pendente = retiralista(fila,pendente,codigo,data_atual);

    }

    return pendente;
}

// FUNÇÃO QUE CONCLUI UMA TAREFA
No* concluir(Fila*f,No* lista_tarefas_concluidas,data data_atual)
{
    // Limpando a tela
    system("cls");
    printf ("\n\n\n\t\t\t\t\t\t-----------------------\n");
    printf ("\t\t\t\t\t\tCONCLUINDO UMA TAREFA \n");
    printf ("\t\t\t\t\t\t-----------------------\n\n");

    // Declarando variáveis
    int codigo,verificador;
    tarefa concluida;
    Fila *fila_aux;
    No *aux;

    // Criando fila auxiliar
    fila_aux = CriaFila(fila_aux);

    // Recebendo o codigo do usuario
    printf("Digite o Codigo da Tarefa que deseja marcar como concluida:");
    scanf ("%d",&codigo);

    // Verificador de codigo encontrado ou nao
    verificador = 0;

    // Percorrendo a Fila
    for (aux = f->ini ; aux != NULL ; aux = aux->prox)
    {
         // Encontrei a tarefa com o codigo determinado
        if(aux->info.codigo == codigo)
        {
            verificador = 1;        // codigo encontrado
            concluida = aux->info;  // passando as informações para uma variavel
            concluida.data_termino = data_atual;                     // atualizando a data
            lista_tarefas_concluidas = Insere_Lista_Ordenada(lista_tarefas_concluidas,concluida);  // Função que insere na lista
        }
        else
        {
            InsereFila(fila_aux,aux->info);
        }
    }

    // Copiando fila_aux para f
    f->ini = fila_aux->ini;
    f->fim = fila_aux->fim;

    // Liberando a memória ocupada pela fila auxiliar
    free(fila_aux);

    // Avisando que o código não foi encontrado
    if(verificador == 0)
    {
        printf ("O código digitado nao foi encontrado !!\n\n\n");
        system ("pause");
    }

    return lista_tarefas_concluidas;
}

// Função que modifica uma determinada tarefa
Fila* modificar(Fila *f,data data_atual)
{
    // limpando a tela
    system("cls");
    printf ("\n\n\n\t\t\t\t\t\t----------------------\n");
    printf ("\t\t\t\t\t\tMODIFICANDO UMA TAREFA \n");
    printf ("\t\t\t\t\t\t----------------------\n\n");

    // Declarando Variáveis
    int codigo,verificador;
    No *aux;
    Fila *fila_aux;

    // Criando a Fila auxiliar
    fila_aux = CriaFila(f);

    // Recebendo o código a ser modificado
    codigo = 0;
    printf("Informe o código da tarefa a ser modificada: ");
    scanf ("%d", &codigo);

    // Iniciando a Flag
    verificador = 0;

    // Percorrendo a Fila
    for (aux = f->ini ; aux != NULL ; aux = aux->prox)
    {
        // Analisa se o elemento atual é igual ao codigo digitado
        if (aux->info.codigo == codigo)
        {
            // Código encontrado
            verificador = 1;

            printf("Informe o novo Nome Da Tarefa: ");
            fflush(stdin);
            gets(aux->info.nome_tarefa);

            printf("Informe o novo Nome Do Projeto: ");
            fflush(stdin);
            gets(aux->info.nome_projeto);

            printf ("\nINFORME A NOVA DATA DE INICIO (APENAS NUMEROS): \n");

            do
            {
                printf ("Dia: ");
                scanf  ("%d",&aux->info.data_inicio.dia);
            }while(aux->info.data_inicio.dia < 1 || aux->info.data_inicio.dia > 31);

            do
            {
                printf ("Mes: ");
                scanf  ("%d",&aux->info.data_inicio.mes);
            }while(aux->info.data_inicio.mes < 1 || aux->info.data_inicio.mes > 12);

            do
            {
                printf ("Ano: ");
                scanf  ("%d",&aux->info.data_inicio.ano);
            }while(aux->info.data_inicio.ano < 1);

            printf ("\nINFORME A NOVA DATA DE TERMINO (APENAS NUMEROS): \n");

            do
            {
                printf ("Dia: ");
                scanf  ("%d",&aux->info.data_termino.dia);
            }while(aux->info.data_termino.dia < 1 || aux->info.data_termino.dia > 31);

            do
            {
                printf ("Mes: ");
                scanf  ("%d",&aux->info.data_termino.mes);
            }while(aux->info.data_termino.mes < 1 || aux->info.data_termino.mes > 12 );

            do
            {
                printf ("Ano: ");
                scanf  ("%d",&aux->info.data_termino.ano);
            }while(aux->info.data_termino.ano < 1);

            printf ("\nREFERENCIA: ATRASADA = 1 ; EM DIA = 0 ; PENDENTE = -1\n");
            imprime_status(data_atual,&aux->info);

            // inserindo a tarefa modificada na fila aux
            InsereFila(fila_aux,aux->info);

            system("cls");
            printf("Tarefa modificada com sucesso!\n");
            system("pause");
        }
        else
        {
            InsereFila(fila_aux,aux->info); // Se o a tarefa não contem o código, envia para uma nova fila
        }
    }

    // A fila auxiliar (modificada) se torna a original
    f = fila_aux;

    // Avisando que o código não foi encontrado
    if(verificador == 0)
    {
        printf ("O código digitado nao foi encontrado !!\n\n\n");
        system ("pause");
    }

    liberaFila(fila_aux);

    return f;
}

// Função que adiciona as informações de uma tarefa
tarefa adicionar (data data_atual)
{
    system("cls");
    printf ("\n\n\n\t\t\t\t\t\t---------------------------\n");
    printf ("\t\t\t\t\t\tADICIONANDO UMA TAREFA \n");
    printf ("\t\t\t\t\t\t---------------------------\n\n");
    // Declarando variáveis
    tarefa tarefa;

    // Limpando a tela
    system("cls");
    printf ("\n\n\n\t\t\t\t\t\t-------------------\n");
    printf ("\t\t\t\t\t\tADICIONANDO TAREFA\n");
    printf ("\t\t\t\t\t\t-------------------\n\n");

    // Recebendo Informações
    printf ("\nInforme o codigo: ");
    scanf  ("%d",&tarefa.codigo);

    printf ("Informe o nome da tarefa: ");
    fflush(stdin);
    gets(tarefa.nome_tarefa);

    printf ("Informe o nome do projeto: ");
    fflush(stdin);
    gets(tarefa.nome_projeto);

    printf ("\nINFORME A DATA DE INICIO (APENAS NUMEROS): \n");

    do
    {
    printf ("Dia: ");
    scanf  ("%d",&tarefa.data_inicio.dia);
    }while(tarefa.data_inicio.dia < 1 || tarefa.data_inicio.dia > 31 );

    do
    {
        printf ("Mes: ");
        scanf  ("%d",&tarefa.data_inicio.mes);
    }while(tarefa.data_inicio.mes < 1 || tarefa.data_inicio.mes > 12 );

    do
    {
    printf ("Ano: ");
    scanf  ("%d",&tarefa.data_inicio.ano);
    }while(tarefa.data_inicio.ano < 1 );

    printf ("\nINFORME A DATA DE TERMINO (APENAS NUMEROS): \n");

    do
    {
        printf ("Dia: ");
        scanf  ("%d",&tarefa.data_termino.dia);
    }while(tarefa.data_termino.dia < 1 || tarefa.data_termino.dia > 31 );

    do
    {
        printf ("Mes: ");
        scanf  ("%d",&tarefa.data_termino.mes);
    }while(tarefa.data_termino.mes < 1 || tarefa.data_termino.mes > 12 );

    do
    {
        printf ("Ano: ");
        scanf  ("%d",&tarefa.data_termino.ano);
    }while(tarefa.data_termino.ano < 1);

    // Informando o Status Da Tarefa Automaticamente
    printf ("\nREFERENCIA: ATRASADA = 1 ; EM DIA = 0 ; PENDENTE = -1\n");
    imprime_status(data_atual,&tarefa);

    return tarefa;
}

// FUNÇÃO PRINCIPAL
int main()
{
    // Definindo o idioma em pt br
    setlocale(LC_ALL,"portuguese");

    // Declarando Variáveis
    int opcao = 0;
    Fila *f;
    No *f_pendentes;
    No *lista_tarefas_concluidas; // É uma lista
    data data_atual;

    // Chamando Funções Iniciais
    data_atual = recebe_data(); // Recebe a data do sistema
    f = CriaFila(f);            // Cria um Fila de Tarefas
    f_pendentes = inicializa_lista(); // Cria um Fila de Tarefas Pendentes
    lista_tarefas_concluidas = inicializa_lista();

    // Imprimindo Menu de Opções
    do
    {
        opcao = 0;
        system ("cls");
        printf ("\n\n\n\t\t\t\t-------------------------------------------------\n");
        printf ("\t\t\t\tBEM VINDO AO SOFTWARE DE GERENCIAMENTO DE TAREFAS\n");
        printf ("\t\t\t\t-------------------------------------------------\n\n");
        printf ("\t\t\t\t\t[1]. Adicionar uma nova tarefa\n");
        printf ("\t\t\t\t\t[2]. Modificar uma tarefa\n");
        printf ("\t\t\t\t\t[3]. Concluir uma tarefa\n");
        printf ("\t\t\t\t\t[4]. Atualiza  o do Status da tarefa\n");
        printf ("\t\t\t\t\t[5]. Lista de tarefas pendentes\n");
        printf ("\t\t\t\t\t[6]. Lista de tarefas concluidas\n");
        printf ("\t\t\t\t\t[7]. Lista de tarefas concluidas com e sem atrasos\n");
        printf ("\t\t\t\t\t[8]. Sair do programa\n\n");
        printf ("\t\t\t\t\tDigite sua opcao: ");

        scanf ("%d",&opcao); // Recolhendo opcao

        // Direcionando Usuário para Opção Escolhida
        switch (opcao)
        {

            case 1: InsereFila(f,adicionar(data_atual));
            break;

            case 2: modificar(f,data_atual);
            break;

            case 3: lista_tarefas_concluidas = concluir(f,lista_tarefas_concluidas,data_atual);
            break;

            case 4: f_pendentes = atualizar(f,f_pendentes,data_atual);
            break;

            case 5: pendentes(f_pendentes);
            break;

            case 6: concluidas(lista_tarefas_concluidas);
            break;

            case 7: com_e_sem_atrasos(lista_tarefas_concluidas);
            break;

            case 8:
                system("cls");
                printf ("Programa finalizado");
            break;
        }

    }while(opcao!=8);

    return 0;
}

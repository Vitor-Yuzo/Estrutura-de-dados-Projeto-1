#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FILA.h"

void com_e_sem_atrasos(Fila*f)
{
    No* aux;

    printf ("\nAS TAREFAS COM ATRASO SÃO: \n");
    for (aux=f->ini; aux!=NULL; aux=aux->prox)
    {
        if (aux->info.status == 1)
        printf("%s - ",aux->info.nome_tarefa);
    }

    printf ("\n\nAS TAREFAS SEM ATRASO SÃO: \n");
    for (aux=f->ini; aux!=NULL; aux=aux->prox)
    {
        if (aux->info.status == 0)
        printf("%s - ",aux->info.nome_tarefa);
    }

    printf ("\n\n");
    system("pause");

}

tarefa adicionar (data data_atual)
{
    tarefa tarefa;

    printf ("\nInforme o codigo: ");
    scanf  ("%d",&tarefa.codigo);

    printf ("Informe o nome da tarefa: ");
    fflush(stdin);
    gets(tarefa.nome_tarefa);

    printf ("Informe o nome do projeto: ");
    fflush(stdin);
    gets(tarefa.nome_projeto);

    printf ("\nINFORME A DATA DE INICIO (APENAS NUMEROS): \n");

    printf ("Dia: ");
    scanf  ("%d",&tarefa.data_inicio.dia);

    printf ("Mes: ");
    scanf  ("%d",&tarefa.data_inicio.mes);

    printf ("Ano: ");
    scanf  ("%d",&tarefa.data_inicio.ano);

    printf ("\nINFORME A DATA DE TERMINO (APENAS NUMEROS): \n");

    printf ("Dia: ");
    scanf  ("%d",&tarefa.data_termino.dia);

    printf ("Mes: ");
    scanf  ("%d",&tarefa.data_termino.mes);

    printf ("Ano: ");
    scanf  ("%d",&tarefa.data_termino.ano);

    printf ("\nSTATUS: ATRASADA = 1 ; EM DIA = 0 ; PENDENTE = -1\n");

    if (data_atual.ano <= tarefa.data_termino.ano)
    {
        if(data_atual.ano = tarefa.data_termino.ano)
        {
                if(data_atual.mes <= tarefa.data_termino.mes)
                {
                    if(data_atual.mes = tarefa.data_termino.mes)
                    {
                        if(data_atual.dia <= tarefa.data_termino.dia)
                        {
                            printf ("O status da sua tarefa é: 0 (EM DIA)");
                            tarefa.status = 0;
                        }
                        else
                        {
                            printf ("O status da sua tarefa é: 1 (ATRASADA)");
                            tarefa.status = 1;
                        }
                    }
                    else
                    {
                        printf ("O status da sua tarefa é: 0 (EM DIA)");
                        tarefa.status = 0;
                    }
                }
                else
                {
                    printf ("O status da sua tarefa é: 1 (ATRASADA)");
                    tarefa.status = 1;
                }
        }
        else
        {
            printf ("O status da sua tarefa é: 0 (EM DIA)");
            tarefa.status = 0;
        }
    }
    else
    {
        printf ("O status da sua tarefa é: 1 (ATRASADA)");
        tarefa.status = 1;
    }

    printf ("\n\n");
    system ("pause");

    return tarefa;
}

data recebe_data ()
{
    data data;

    printf ("\nINFORME A DATA ATUAL\n");

    printf ("Dia: ");
    scanf  ("%d",&data.dia);

    printf ("Mes: ");
    scanf  ("%d",&data.mes);

    printf ("Ano: ");
    scanf  ("%d",&data.ano);

    return data;
}

int main()
{
    setlocale(LC_ALL,"portuguese");

    int opcao = 0;
    Fila *f;
    data data_atual;
    f = CriaFila(f);

    data_atual = recebe_data();



    do
    {
        system ("cls");
        printf ("Bem vindo ao software de gerenciamento de tarefas\n\n");
        printf ("[1]. Adicionar uma nova tarefa\n");
        printf ("[2]. Modificar uma tarefa\n");
        printf ("[3]. Concluir uma tarefa\n");
        printf ("[4]. Atualização do Status da tarefa\n");
        printf ("[5]. Lista de tarefas pendentes\n");
        printf ("[6]. Lista de tarefas concluidas\n");
        printf ("[7]. Lista de tarefas concluidas com e sem atrasos\n");
        printf ("[8]. Sair do programa\n");
        printf ("\nDigite sua opcao: ");
        scanf ("%d",&opcao);

        switch (opcao)
        {

            case 1: InsereFila(f,adicionar(data_atual));
            break;

            /*
            case 2: modificar();
            break;

            case 3: concluir();
            break;

            case 4: atualizar();
            break;

            case 5: pendentes();
            break;

            case 6: concluidas();
            break;*/

            case 7: com_e_sem_atrasos(f);
            break;

            case 8:
            system("cls");
            printf ("Programa finalizado");
            return 0;
            break;
        }

    }while(opcao!=8);

    return 0;
}

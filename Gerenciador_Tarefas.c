#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FILA.h"






tarefa adicionar ()
{
    tarefa tarefa;

    printf ("\nInforme o codigo: ");
    scanf  ("%d",&tarefa.codigo);

    printf ("Informe o nome da tarefa: ");
    fflush(stdin);
    gets(&tarefa.nome_tarefa);


    printf ("Informe o nome do projeto: ");
    fflush(stdin);
    gets(&tarefa.nome_projeto);

    printf ("Informe a data de inicio: ");
    scanf  ("%d",&tarefa.data_inicio);

    printf ("Informe a data de termino: ");
    scanf  ("%d",&tarefa.data_termino);

    printf ("Informe o Status: ");
    scanf  ("%d",&tarefa.status);

    return tarefa;

}











int main()
{
    int opcao;

    setlocale(LC_ALL,"portuguese");

    opcao = 0;
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

    }while (opcao<1 || opcao>8);

    Fila *f;
    f = CriaFila(f);

    switch (opcao)
    {

        case 1: InsereFila(f,adicionar());
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
        break;

        case 7: com_e_sem_atrasos();
        break;

        */
        case 8:
        system("cls");
        printf ("Programa finalizado");
        return 0;
        break;

    }

    return 0;
}

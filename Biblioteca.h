#include <time.h>
#ifndef Biblioteca_H_INCLUDED
#define Biblioteca_H_INCLUDED


// CONSTRUINDO E DECLARANDO ESTRUTURAS

// ESTRUTURA PARA VARIÁVEIS DO TIPO DATA
struct Modelo_Data
{
    int dia;
    int mes;
    int ano;
};
typedef struct Modelo_Data data;

// ESTRUTURA PARA VARIÁVEIS DO TIPO TAREFA
struct Tarefas
{
    int codigo;
    char nome_tarefa[30];
    char nome_projeto[30];
    data data_inicio;
    data data_termino;
    int status;
};
typedef struct Tarefas tarefa;

// ESTRUTURA PARA VARIÁVEIS DO TIPO NO
struct nos
{
    tarefa info;
    struct nos *prox;
};
typedef struct nos No;

// ESTRUTURA PARA VARIÁVEIS DO TIPO FILA
struct fila
{
    No * ini;
    No * fim;

};
typedef struct fila Fila;



// FUNÇÕES

// FUNÇÃO QUE OBTÉM E RETORNA A DATA DO SISTEMA
data recebe_data()
{
    // Declarando Variáveis
    time_t tempo_atual;
    struct tm *info_tempo;
    data data_atual;

    time(&tempo_atual);
    info_tempo = localtime(&tempo_atual);

    // Obtendo data atual do sistema
    data_atual.dia = info_tempo->tm_mday;
    data_atual.mes = info_tempo->tm_mon + 1;
    data_atual.ano = info_tempo->tm_year + 1900;

    // Retornando data do sistema
    return data_atual;
}

// FUNÇÃO QUE INICIALIZA A LISTA
No *inicializa_lista()
{
    return NULL;
}

// FUNÇÃO QUE CRIA UM NÓ
No* criar_no(tarefa t)
{
    No *novoNo = (No*)malloc(sizeof(No));

    if (novoNo == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }

    novoNo->info = t;
    novoNo->prox = NULL;

    return novoNo;
}

// FUNÇÃO QUE CRIA UM FILA
Fila* CriaFila(Fila *f)
{
    f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

// FUNÇÃO QUE INSERE TAREFA NA FILA
No* ins_fim (No* fim, tarefa  t)
{
    No* p;
    p = (No*) malloc(sizeof(No));
    p->info = t;
    p->prox = NULL;
    if (fim != NULL)
        fim->prox = p;
    return p;
}
Fila *InsereFila (Fila* f, tarefa t)
{
    f->fim = ins_fim(f->fim,t);
    if (f->ini==NULL)
        f->ini = f->fim;

    return f;
}

//FUNÇÃO QUE IMPRIME A FILA
void imprimeFila (Fila* f)
{
    No* q;
    printf("\n");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("Codigo: %d\n",q->info.codigo);
        printf("Nome da tarefa: %s \n",q->info.nome_tarefa);
        printf("Nome do projeto: %s \n",q->info.nome_projeto);
        printf("---DATA DE INICIO--- \n");
        printf(" %d /",q->info.data_inicio.dia);
        printf(" %d /",q->info.data_inicio.mes);
        printf(" %d \n",q->info.data_inicio.ano);
        printf("---DATA DE TERMINO--- \n");
        printf(" %d /",q->info.data_termino.dia);
        printf(" %d /",q->info.data_termino.mes);
        printf(" %d \n",q->info.data_termino.ano);
        printf("STATUS: %d\n\n",q->info.status);
    }
}

// FUNÇÃO QUE LIBERA A FILA
Fila* liberaFila (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

// Função que analisa o STATUS e imprime
void imprime_status(data data_atual, tarefa *tarefa)
{
    if (data_atual.ano <= tarefa->data_termino.ano)
    {
        if(data_atual.ano == tarefa->data_termino.ano)
        {
                if(data_atual.mes <= tarefa->data_termino.mes)
                {
                    if(data_atual.mes == tarefa->data_termino.mes)
                    {
                        if(data_atual.dia <= tarefa->data_termino.dia)
                        {
                            printf ("O status da sua tarefa  : 0 (EM DIA)");
                            tarefa->status = 0;
                        }
                        else
                        {
                            printf ("O status da sua tarefa  : 1 (ATRASADA)");
                            tarefa->status = 1;
                        }
                    }
                    else
                    {
                        printf ("O status da sua tarefa  : 0 (EM DIA)");
                        tarefa->status = 0;
                    }
                }
                else
                {
                    printf ("O status da sua tarefa  : 1 (ATRASADA)");
                    tarefa->status = 1;
                }
        }
        else
        {
            printf ("O status da sua tarefa  : 0 (EM DIA)");
            tarefa->status = 0;
        }
    }
    else
    {
        printf ("O status da sua tarefa  : 1 (ATRASADA)");
        tarefa->status = 1;
    }

    printf ("\n\n\n");
    system ("pause");
}

// FUNÇÃO QUE INSERE NA LISTA DE MANEIRA ORDENADA, PELA DATA DE TERMINO (TERMINA ANTES = VEM ANTES)
No* Insere_Lista_Ordenada(No *lista,tarefa t)
{
    // declarando variaveis
    No *aux;
    No *anterior;
    No *novo;

    // atribuindo informações
    anterior = NULL;
    novo = criar_no(t);

    if(lista == NULL) // Está vazia?
    {
        lista = novo;
    }
    else
    {
        for(aux=lista ; aux != NULL ; aux = aux->prox)
        {
                if(novo->info.data_termino.ano <= aux->info.data_termino.ano)
                {
                    if(novo->info.data_termino.ano == aux->info.data_termino.ano)
                    {
                        if(novo->info.data_termino.mes <= aux->info.data_termino.mes)
                        {
                           if(novo->info.data_termino.mes == aux->info.data_termino.mes)
                           {
                                if(novo->info.data_termino.dia <= aux->info.data_termino.dia)
                                {
                                    if(anterior == NULL)
                                    {
                                        novo->prox = lista;
                                        lista = novo;
                                        return lista;
                                    }
                                    else
                                    {
                                        anterior->prox = novo;
                                        novo->prox = aux;
                                        return lista;
                                    }
                                }
                           }
                           else
                           {
                                if(anterior == NULL)
                                {
                                    novo->prox = lista;
                                    lista = novo;
                                    return lista;
                                }
                                else
                                {
                                    anterior->prox = novo;
                                    novo->prox = aux;
                                    return lista;
                                }
                           }
                        }
                    }
                    else
                    {
                       if(anterior == NULL)
                        {
                            novo->prox = lista;
                            lista = novo;
                            return lista;
                        }
                        else
                        {
                            anterior->prox = novo;
                            novo->prox = aux;
                            return lista;
                        }
                    }
                }

            if(aux->prox == NULL)
            {
                aux->prox = novo;
                return lista;
            }
            anterior = aux;
        }
    }
    return lista;
}

// FUNÇÃO PARA IMPRIMIR UMA LISTA
void imprimir_Lista(No *lista)
{
    No *aux;

    for (aux = lista; aux != NULL ; aux=aux->prox)
    {
        printf("Codigo: %d\n",aux->info.codigo);
        printf("Nome da tarefa: %s \n",aux->info.nome_tarefa);
        printf("Nome do projeto: %s \n",aux->info.nome_projeto);
        printf("---DATA DE INICIO--- \n");
        printf(" %d /",aux->info.data_inicio.dia);
        printf(" %d /",aux->info.data_inicio.mes);
        printf(" %d \n",aux->info.data_inicio.ano);
        printf("---DATA DE TERMINO--- \n");
        printf(" %d /",aux->info.data_termino.dia);
        printf(" %d /",aux->info.data_termino.mes);
        printf(" %d \n",aux->info.data_termino.ano);
        printf("STATUS: %d\n\n",aux->info.status);
    }
}

// FUNÇÃO PARA IMPRIMIR APENAS UMA TAREFA (NO) DA LISTA
void imprimir_No_Lista(No *aux)
{
    printf("Codigo: %d\n",aux->info.codigo);
    printf("Nome da tarefa: %s \n",aux->info.nome_tarefa);
    printf("Nome do projeto: %s \n",aux->info.nome_projeto);
    printf("---DATA DE INICIO--- \n");
    printf(" %d /",aux->info.data_inicio.dia);
    printf(" %d /",aux->info.data_inicio.mes);
    printf(" %d \n",aux->info.data_inicio.ano);
    printf("---DATA DE TERMINO--- \n");
    printf(" %d /",aux->info.data_termino.dia);
    printf(" %d /",aux->info.data_termino.mes);
    printf(" %d \n",aux->info.data_termino.ano);
    printf("STATUS: %d\n\n",aux->info.status);

}

// FUNÇÃO QUE RETIRA DA LISTA, ENVIA PARA FILA E RETORNA A LISTA PENDENTE ATUALIZADA
No* retiralista( Fila *f,No* inicio, int codigo,data data_atual)
{

    // DECLARANDO VARIÁVEIS
	No*aux=inicio;
	No*anterior=NULL;
	No *removido;
	int verificador = 0;

	//Percorrendo a lista
	for(aux = inicio ; aux != NULL ; aux = aux->prox)
    {
        // codigo encontrado
		if(aux->info.codigo==codigo)
		{
		    // codigo encontrado
		    verificador = 1;

		    // atualizando o status da tarefa (retirando pendencia)
            imprime_status(data_atual,&aux->info);

            // caso precisemos inserir no inicio
            if(anterior==NULL)
            {
                inicio=aux->prox;
                InsereFila(f,aux->info);
                return inicio;
            }

            // caso precisemos inserir no meio
            if(aux->prox==NULL)
            {
                anterior->prox=NULL;
                InsereFila(f,aux->info);
                return inicio;
            }

            // caso precisemos inserir no fim
            else
            {
                anterior->prox=aux->prox;
                InsereFila(f,aux->info);
                return inicio;
            }
		}

		anterior = aux; // incrementando o auxiliar
    }

    if(verificador == 0) // codigo nao encontrado
    {
        printf ("O código digitado nao foi encontrado !!\n\n\n");
        system ("pause");
    }
}


#endif // Biblioteca_H_INCLUDED

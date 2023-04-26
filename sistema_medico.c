//Aline Ayumi Soma Hamano
//Projeto nº 3 - Medicos
#include <stdio.h>
#include <string.h>
#define N 500
#define clear_screen() printf("\e[1;1H\e[2J") // Limpa o console (no linux, pelo menos)
#define enter_para_retornar() {printf("\nPressione ENTER para retornar."); getchar(); }

typedef struct {
        long int crm;
        char nome[40];
        char atuacao[40];
        int titulacao;
        char telefone[16];
        char endereco[40];
        char email[40];
        float salario;
        char data_adm[11];
        char data_nasc[11];
        float anos_experiencia;
        } MEDICO;

MEDICO medico [N];
int ult;

void inicializar_med() {
    ult=0;
}

unsigned int menu () {
    int op;
    clear_screen();
    printf ("Entre com a opcao Desejada\n");
    printf ("1 - Cadastrar Medico\n");
    printf ("2 - Alterar dados do Medico\n");
    printf ("3 - Buscar Medico pelo CRM\n");
    printf ("4 - Exibir os Medicos de uma Area de Atuacao\n");
    printf ("5 - Exibir Medico conforme seu Titulo Academico\n");
    printf ("6 - Sair\n");
    
    while (1) {
        scanf("%u", &op);
        getchar();
        // Se a opção do usuário for válida, sai do loop sem executar as linhas seguintes
        if ((op > 0) && (op <= 6)) { 
            break;
        }
        printf("Digite uma opção válida > ");
    }
} 
void cadastrar_medico() {
    
        printf ("\nInforme os dados do Médico\n\n");
        
        printf ("%-10s > ", "Entre com o nome do Médico");
    	fgets(medico[ult].nome, 40, stdin);
    	getchar();
    	
    	printf ("%-10s > ", "Entre com o codigo do CRM");
    	scanf ("%ld", &medico[ult].crm);
    	getchar();
    	
    	printf ("%-10s > ", "Entre com o Salario");
    	scanf ("%f", &medico[ult].salario);
    	getchar();
    	
    	printf("%-10s > ", "Data de Admissao no Hospital Soma");
        fgets(medico[ult].data_adm, 11, stdin);
        getchar();
        
        printf ("---Titulos----\n");
        printf("0 - Graduado\n");
        printf("1 – Especialista\n");
        printf("2 – Mestrado\n");
        printf("3 – Doutorado\n");
        printf("4 – Pós-Doutorado\n");
        printf("%-10s > ", "Informe a Titulacao do Medico");
        scanf ("%d", &medico[ult].titulacao);
        getchar();
    
        printf("%-10s > ", "Informe a Area de Atuacao do Medico");
        fgets(medico[ult].atuacao, 40, stdin);
        getchar();
     
    	printf ("%-10s > ", "Entre com o tempo de Experiencia do Medico");
    	scanf ("%f", &medico[ult].anos_experiencia);
    	getchar();   
    
        printf("%-10s > ", "Data de nascimento");
        fgets(medico[ult].data_nasc, 11, stdin);
        getchar();
    
        printf("%-10s > ", "Telefone para contato");
        fgets(medico[ult].telefone, 16, stdin);
        getchar();
        
        printf("%-10s > ", "Informe o Endereco da Residencia");
        fgets(medico[ult].endereco, 40, stdin);
        getchar();
    
        printf("%-10s >", "Email para contato");
        fgets(medico[ult].email, 40, stdin);
        getchar();
        printf ("Medico Cadastrado com Sucesso!\n\n");
}

void inserir_med() {
    
    if (ult==N) {
        printf("Limite de Medicos Alcancado!!!!\n");
    }
    else {
        cadastrar_medico();
        ult++;
    }
}
unsigned menu_alteracao() {
    int op;
    clear_screen();
    printf ("Entre com a opcao desejada\n");
    printf ("1 - Alterar Telefone\n");
    printf ("2 - Alterar Endereco\n");
    printf ("3 - Alterar Email\n");
    printf ("4 - Alterar Atuacao\n");
    printf ("5 - Sair\n");
    
    while (1) {
        scanf("%u", &op);
        getchar();
        // Se a opção do usuário for válida, sai do loop sem executar as linhas seguintes
        if ((op > 0) && (op <= 5)) { 
            break;
        }
        printf("Digite uma opção válida > ");
    }
}

int busca_crm_medico() {
    int op, i, j, flag=0;
    long int cod_crm;
    
    printf ("Informe o CRM do Médico\n");
    scanf ("%ld", &cod_crm);
    
    for (i=0; i<ult; i++) {
        if (medico[i].crm == cod_crm) {
            flag=1;
            return i;
        }
    }
    if (flag==0) {
        getchar();
        printf ("Nao ha Medico com esse CRM no Sistema\n");
        return -1;
    }
}
void altera_dados() {
    int op, j;
    
    j = busca_crm_medico();
    if (j>=0) {
        do {
            op = menu_alteracao();
            switch (op) {
                case 1:
                printf("%-10s > ", "Informe o novo Telefone do Medico");
                fgets(medico[j].telefone, 16, stdin);
                getchar();
                printf ("Telefone Salvo\n");
                break;
                
                case 2:
                printf("%-10s > ", "Informe o novo Endereco do Medico");
                fgets(medico[j].endereco, 40, stdin);
                getchar();
                printf ("Endereco Salvo\n");
                break;
                
                case 3:
                printf("%-10s > ", "Informe o novo Email do Medico");
                fgets(medico[j].email, 40, stdin);
                getchar();
                printf ("Email Salvo\n");
                break;
                
                case 4:
                printf("%-10s > ", "Informe a nova Atuacao do Medico");
                fgets(medico[j].atuacao, 40, stdin);
                getchar();
                printf ("Atuacao Salva\n");
                break;
                
                default:
                break;
            }
        } while (op!=5);
        printf ("Dados Alterados com Sucesso!\n");
    }
}

void exibe_med_posicao(int i) {
    printf ("\n\n------Dados do Medico------\n\n");
    printf ("Nome: %s\n", medico[i].nome);
    printf ("CRM: %ld\n", medico[i].crm);
    printf ("Area de Atuacao: %s\n", medico[i].atuacao);
    if (medico[i].titulacao == 0) {
        printf ("Titulo: GRADUADO\n");
    }
    else if (medico[i].titulacao == 1) {
        printf ("Titulo: ESPECIALISTA\n");
    }
    else if (medico[i].titulacao == 2) {
        printf ("Titulo: MESTRADO\n");
    }
    else if (medico[i].titulacao == 3) {
        printf ("Titulo: DOUTORADO\n");
    }
    else if (medico[i].titulacao == 4) {
        printf ("Titulo: POS-DOUTORADO\n");
    }
    printf ("Anos de Experiencia: %.2f anos\n", medico[i].anos_experiencia);
    printf ("Telefone: %s\n", medico[i].telefone);
    printf ("Email: %s\n", medico[i].email);
    printf ("Endereco: %s\n", medico[i].endereco);
    printf ("Salario: %.2f\n", medico[i].salario);
    printf ("Data de Admissao: %s\n", medico[i].data_adm);
    printf ("Data de Nascimento: %s\n", medico[i].data_nasc);
}

void busca_medico () {
    int i;
    i = busca_crm_medico();
    if (i>=0) {
        getchar();
        exibe_med_posicao(i);
    }
}

void exibe_med_atuacao() {
    int i, flag=0;
    char atc[40];
    printf ("\nEntre com o a Atuacao do medico\n");
    fgets (atc, 40, stdin);
    getchar();

    for (i=0; i<ult; i++) {
        if (strcmp(atc, medico[i].atuacao)==0) {
            getchar();
            exibe_med_posicao(i);
            flag=1;
        }
    }

    if (flag==0) {
        printf ("Nao ha medicos com esta Atuacao\n");
    }
}

void exibe_med_titulo() {
    int i, titulo, flag=0;
    printf ("---Titulos----\n");
    printf("0 - Graduado\n");
    printf("1 – Especialista\n");
    printf("2 – Mestrado\n");
    printf("3 – Doutorado\n");
    printf("4 – Pós-Doutorado\n");
    printf("%-10s > ", "Informe a Titulacao do Medico");
    scanf ("%d", &titulo);
    getchar();

    for (i=0; i<ult; i++) {
        if (medico[i].titulacao == titulo) {
            getchar();
            exibe_med_posicao(i);
            flag=1;
        }
    }

    if (flag==0) {
        printf ("Nao ha medicos com este Titulo\n");
    }
}

int main() {
    int op;
    inicializar_med();
    do {
        op = menu();
        switch (op) {
            case 1:
            clear_screen();
            inserir_med();
            enter_para_retornar();
            break;
            
            case 2:
            clear_screen();
            altera_dados();
            enter_para_retornar();
            break;
            
            case 3:
            clear_screen();
            busca_medico ();
            enter_para_retornar();
            break;
            
            case 4:
            clear_screen();
            exibe_med_atuacao();
            enter_para_retornar();
            break;
            
            case 5:
            clear_screen();
            exibe_med_titulo();
            enter_para_retornar();
            break;
        }
    } while (op!=6);

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 300

int main() {
    char base[N];
    unsigned int i, j, cont=0;

    while (scanf("%s", base)!=EOF)
    { 
        while (base[i]!="\0")
        {
            if((base[i]=='S' && base[j] == 'B') || (base[i]=='B' && base[j]=='S')) {
                    cont++;
            }
            else if ((base[i]=='C' && base[j] == 'F') || (base[i]=='F' && base[j]=='C')) {
                    cont++;
            }
            i++;
        }
        
                
            }
    printf("%d\n", cont);
    
return 0;
}

*/

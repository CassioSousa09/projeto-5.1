#ifndef TRABALHO_H
#define TRABALHO_H

#define MAX_CONTACTS 255
#define MAX_LENGTH 50

typedef struct {
  char nome[MAX_LENGTH];
  char sobrenome[MAX_LENGTH];
  char email[MAX_LENGTH];
  char telefone[MAX_LENGTH];
} Contato;

typedef enum { PESSOAL, TRABALHO } TipoContato;

void adicionar_contato(TipoContato tipo);
void listar_contatos(TipoContato tipo);
void deletar_contato(char *telefone, TipoContato tipo);
void salvar_agenda(TipoContato tipo);
void carregar_agenda(TipoContato tipo);
void alterar_contato(char *telefone, TipoContato tipo);

int validar_email(const char *email);
int telefone_unico(const char *telefone, TipoContato tipo);

#endif /* TRABALHO_H */
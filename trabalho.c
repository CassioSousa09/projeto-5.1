#include "trabalho.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

Contato agenda_pessoal[MAX_CONTACTS];
Contato agenda_trabalho[MAX_CONTACTS];
int num_contatos_pessoais = 0;
int num_contatos_trabalho = 0;



void listar_contatos(TipoContato tipo) {
  Contato *agenda;
  int num_contatos;

  if (tipo == PESSOAL) {
    agenda = agenda_pessoal;
    num_contatos = num_contatos_pessoais;
  } else {
    agenda = agenda_trabalho;
    num_contatos = num_contatos_trabalho;
  }

  printf("Lista de contatos:\n");
  for (int i = 0; i < num_contatos; i++) {
    printf("%d: %s %s, %s, %s\n", i + 1, agenda[i].nome, agenda[i].sobrenome,
           agenda[i].email, agenda[i].telefone);
  }
}




void alterar_contato(char *telefone, TipoContato tipo) {
  Contato *agenda;
  int num_contatos;

  if (tipo == PESSOAL) {
    agenda = agenda_pessoal;
    num_contatos = num_contatos_pessoais;
  } else {
    agenda = agenda_trabalho;
    num_contatos = num_contatos_trabalho;
  }

  for (int i = 0; i < num_contatos; i++) {
    if (strcmp(agenda[i].telefone, telefone) == 0) {
      Contato *contato = &agenda[i];
      printf("Digite o Novo Nome: ");
      scanf("%s", contato->nome);
      printf("Digite o Novo Sobrenome: ");
      scanf("%s", contato->sobrenome);
      printf("Digite o Novo Email: ");
      scanf("%s", contato->email);

      if (validar_email(contato->email) == -1) {
        printf("Email inválido!\n");
        return;
      }

      printf("Digite o Novo Telefone: ");
      scanf("%s", contato->telefone);

      if (!telefone_unico(contato->telefone, tipo)) {
        printf("Telefone já existe!\n");
        return;
      }

      printf("Contato alterado com sucesso!\n");
      return;
    }
  }
  printf("O Contato não foi encontrado!\n");
}
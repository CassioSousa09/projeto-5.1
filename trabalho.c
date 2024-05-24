#include "trabalho.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

Contato agenda_pessoal[MAX_CONTACTS];
Contato agenda_trabalho[MAX_CONTACTS];
int num_contatos_pessoais = 0;
int num_contatos_trabalho = 0;

int validar_email(const char *email) {
  const char *at = strchr(email, '@');
  if (at == NULL)
    return -1;
  const char *dot = strrchr(at, '.');
  if (dot == NULL || dot <= at + 1)
    return -1;
  return dot[1] != '\0' ? 1 : -1;
}

int telefone_unico(const char *telefone, TipoContato tipo) {
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
      return 0;
    }
  }
  return 1;
}

void adicionar_contato(TipoContato tipo) {
  Contato *agenda;
  int *num_contatos;

  if (tipo == PESSOAL) {
    agenda = agenda_pessoal;
    num_contatos = &num_contatos_pessoais;
  } else {
    agenda = agenda_trabalho;
    num_contatos = &num_contatos_trabalho;
  }

  if (*num_contatos < MAX_CONTACTS) {
    Contato novo_contato;
    printf("Digite o Nome: ");
    scanf("%s", novo_contato.nome);
    printf("Digite o Sobrenome: ");
    scanf("%s", novo_contato.sobrenome);
    printf("Digite o Email: ");
    scanf("%s", novo_contato.email);

    if (validar_email(novo_contato.email) == -1) {
      printf("Email inválido!\n");
      return;
    }

    printf("Digite o Telefone: ");
    scanf("%s", novo_contato.telefone);

    if (!telefone_unico(novo_contato.telefone, tipo)) {
      printf("Telefone já existe!\n");
      return;
    }

    agenda[*num_contatos] = novo_contato;
    (*num_contatos)++;
    printf("Contato adicionado com sucesso!\n");
  } else {
    printf("O limite de contatos chegou ao limite, exclua contatos para "
           "adicionar mais!\n");
  }
}

int validar_email(const char *email) {
  const char *at = strchr(email, '@');
  if (at == NULL)
    return -1;
  const char *dot = strrchr(at, '.');
  if (dot == NULL || dot <= at + 1)
    return -1;
  return dot[1] != '\0' ? 1 : -1;
}

int telefone_unico(const char *telefone, TipoContato tipo) {
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
      return 0;
    }
  }
  return 1;
}

void adicionar_contato(TipoContato tipo) {
  Contato *agenda;
  int *num_contatos;

  if (tipo == PESSOAL) {
    agenda = agenda_pessoal;
    num_contatos = &num_contatos_pessoais;
  } else {
    agenda = agenda_trabalho;
    num_contatos = &num_contatos_trabalho;
  }

  if (*num_contatos < MAX_CONTACTS) {
    Contato novo_contato;
    printf("Digite o Nome: ");
    scanf("%s", novo_contato.nome);
    printf("Digite o Sobrenome: ");
    scanf("%s", novo_contato.sobrenome);
    printf("Digite o Email: ");
    scanf("%s", novo_contato.email);

    if (validar_email(novo_contato.email) == -1) {
      printf("Email inválido!\n");
      return;
    }

    printf("Digite o Telefone: ");
    scanf("%s", novo_contato.telefone);

    if (!telefone_unico(novo_contato.telefone, tipo)) {
      printf("Telefone já existe!\n");
      return;
    }

    agenda[*num_contatos] = novo_contato;
    (*num_contatos)++;
    printf("Contato adicionado com sucesso!\n");
  } else {
    printf("O limite de contatos chegou ao limite, exclua contatos para "
           "adicionar mais!\n");
  }
}

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

void deletar_contato(char *telefone, TipoContato tipo) {
  Contato *agenda;
  int *num_contatos;

  if (tipo == PESSOAL) {
    agenda = agenda_pessoal;
    num_contatos = &num_contatos_pessoais;
  } else {
    agenda = agenda_trabalho;
    num_contatos = &num_contatos_trabalho;
  }

  for (int i = 0; i < *num_contatos; i++) {
    if (strcmp(agenda[i].telefone, telefone) == 0) {
      for (int j = i; j < *num_contatos - 1; j++) {
        agenda[j] = agenda[j + 1];
      }
      (*num_contatos)--;
      printf("Contato deletado com Sucesso!\n");
      return;
    }
  }
  printf("O Contato não foi encontrado!\n");
}

void salvar_agenda(TipoContato tipo) {
  FILE *arquivo;
  Contato *agenda;
  int num_contatos;

  if (tipo == PESSOAL) {
    arquivo = fopen("agenda_pessoal.bin", "wb");
    agenda = agenda_pessoal;
    num_contatos = num_contatos_pessoais;
  } else {
    arquivo = fopen("agenda_trabalho.bin", "wb");
    agenda = agenda_trabalho;
    num_contatos = num_contatos_trabalho;
  }

  if (arquivo == NULL) {
    printf("Erro ao abrir o Arquivo!\n");
    return;
  }
  fwrite(agenda, sizeof(Contato), num_contatos, arquivo);
  fclose(arquivo);
  printf("Agenda salva com Sucesso!\n");
}

void carregar_agenda(TipoContato tipo) {
  FILE *arquivo;
  Contato *agenda;
  int *num_contatos;

  if (tipo == PESSOAL) {
    arquivo = fopen("agenda_pessoal.bin", "rb");
    agenda = agenda_pessoal;
    num_contatos = &num_contatos_pessoais;
  } else {
    arquivo = fopen("agenda_trabalho.bin", "rb");
    agenda = agenda_trabalho;
    num_contatos = &num_contatos_trabalho;
  }

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }
  *num_contatos = fread(agenda, sizeof(Contato), MAX_CONTACTS, arquivo);
  fclose(arquivo);
  printf("Agenda carregada com Sucesso!\n");
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
#include "trabalho.h"
#include <stdio.h>

int main() {
  int escolha, tipo;
  char telefone[MAX_LENGTH];
  TipoContato tipoContato;

  while (1) {
    printf("\nEscolha uma Opção:\n");
    printf("1. Adicionar Contatos\n");
    printf("2. Listar Contatos\n");
    printf("3. Deletar Contatos\n");
    printf("4. Salvar Agenda\n");
    printf("5. Carregar Agenda\n");
    printf("6. Alterar Contato\n");
    printf("7. Sair\n");
    scanf("%d", &escolha);

    // Limpar o buffer de entrada para evitar problemas com scanf
    while (getchar() != '\n')
      ;

    if (escolha >= 1 && escolha <= 6) {
      printf("Selecione o tipo de contato:\n");
      printf("1. Pessoal\n");
      printf("2. Trabalho\n");
      scanf("%d", &tipo);

      // Limpar o buffer de entrada para evitar problemas com scanf
      while (getchar() != '\n')
        ;

      if (tipo == 1) {
        tipoContato = PESSOAL;
      } else if (tipo == 2) {
        tipoContato = TRABALHO;
      } else {
        printf("Tipo de contato inválido!\n");
        continue;
      }
    }

    switch (escolha) {
    case 1:
      adicionar_contato(tipoContato);
      break;
    case 2:
      listar_contatos(tipoContato);
      break;
    case 3:
      printf("Digite o telefone que deseja deletar: ");
      scanf("%s", telefone);
      deletar_contato(telefone, tipoContato);
      break;
    case 4:
      salvar_agenda(tipoContato);
      break;
    case 5:
      carregar_agenda(tipoContato);
      break;
    case 6:
      printf("Digite o telefone do contato que deseja alterar: ");
      scanf("%s", telefone);
      alterar_contato(telefone, tipoContato);
      break;
    case 7:
      printf("Aguarde, saindo..\n");
      return 0;
    default:
      printf("Opção não encontrada!\n");
    }
  }

  return 0;
}
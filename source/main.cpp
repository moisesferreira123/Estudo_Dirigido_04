#include "produto.h"
#include "catalogo.h"
#include "pedido.h"
#include "loggerManager.h"
#include "interfaceSistema.h"
#include "gerenciadorSistema.h"

int main(){

  static auto logger = loggerManager::obterLogger();
  logger->info("\nComeçando um novo registro\n");
  interfaceSistema interface;
  gerenciadorSistema gerenciador;
  interface.boasBindas();
  while(!gerenciador.retornarSaidaDoProgama()){
    interface.imprimirInterfaceAtual(gerenciador.retornarInterfaceAtual());
    gerenciador.obterEscolhaDoUsuario();
    gerenciador.escolhaDoUsuario();
  }

  return 0;
}
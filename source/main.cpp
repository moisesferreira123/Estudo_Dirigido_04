#include "produto.h"
#include "catalogo.h"
#include "pedido.h"
#include "loggerManager.h"

int main(){

  static auto logger = loggerManager::obterLogger();
  logger->info("\nComeçando um novo registro\n");
  
  

  return 0;
}
#include "produto.h"
#include "catalogo.h"
#include "pedido.h"
#include "loggerManager.h"

int main(){

  static auto logger = loggerManager::obterLogger();
  logger->info("\nComeçando um novo registro\n");
  
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15), produto3(3,"Carne",40);
  
  Catalogo catalogo;
  catalogo.adicionarProduto(produto1);
  catalogo.adicionarProduto(produto2);
  
  catalogo.buscarProdutoPorId(1);
  catalogo.buscarProdutoPorId(2);

  // Buscando o produto 3 no catálogo (Deve informar algum erro, já que o produto 3 não está no catálogo).
  catalogo.buscarProdutoPorId(3);

  catalogo.listarProdutos();

  Pedido pedido("Jonathan", catalogo);
  pedido.adicionarProduto(produto1);
  pedido.adicionarProduto(produto2);

  pedido.calcularTotal();

  // Deve ser informado uma mensagem de erro, pois o produto 3 não está no catálogo.
  pedido.adicionarProduto(produto3);

  catalogo.adicionarProduto(produto3);

  // Agora que o produto 3 foi adicionado no catálogo, o produto 3 irá ser adicionado no pedido.
  pedido.adicionarProduto(produto3);

  pedido.calcularTotal();
  pedido.adicionarProduto(produto3);
  pedido.adicionarProduto(produto3);

  // Agora, como o valor do pedido é maior que 100 reais, será aplicado o desconto.
  pedido.calcularTotal();

  return 0;
}
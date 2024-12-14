#include <gtest/gtest.h>
#include "../source/produto.h"
#include "../source/catalogo.h"
#include "../source/pedido.h"

#define TOLERANCIA_PARA_DOUBLE 1e-9
bool testeDesligado = false;

TEST(ProdutoTeste, Construtor){
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15);
  
  EXPECT_EQ(produto1.obterId(),1);
  EXPECT_EQ(produto1.obterNome(),"Sabonete");
  EXPECT_NEAR(produto1.obterPreco(),2.59,TOLERANCIA_PARA_DOUBLE);

  EXPECT_EQ(produto2.obterId(),2);
  EXPECT_EQ(produto2.obterNome(),"Shampoo");
  EXPECT_NEAR(produto2.obterPreco(),15,TOLERANCIA_PARA_DOUBLE);
}

TEST(CatalogoTeste, AdicionarProdutosAoCatalogo){
  Catalogo catalogo;
  EXPECT_EQ(catalogo.quantidadeProdutos(),0);
  
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15);

  catalogo.adicionarProduto(produto1, testeDesligado);
  std::map<int, Produto> produtos = {{1,produto1}};
  EXPECT_EQ(catalogo.quantidadeProdutos(),1);
  EXPECT_EQ(catalogo.listarProdutos(testeDesligado),produtos);
  
  catalogo.adicionarProduto(produto2,testeDesligado);
  produtos.insert({2,produto2});
  EXPECT_EQ(catalogo.quantidadeProdutos(),2);
  EXPECT_EQ(catalogo.listarProdutos(testeDesligado),produtos);
}

TEST(CatalogoTeste, TentandoAdicionarProdutosRepetidos){
  Catalogo catalogo;
  EXPECT_EQ(catalogo.quantidadeProdutos(),0);
  
  Produto produto1(1,"Sabonete",2.59);

  catalogo.adicionarProduto(produto1, testeDesligado);
  std::map<int, Produto> produtos = {{1,produto1}};
  EXPECT_EQ(catalogo.quantidadeProdutos(),1);
  EXPECT_EQ(catalogo.listarProdutos(testeDesligado),produtos);
  
  catalogo.adicionarProduto(produto1,testeDesligado);
  EXPECT_EQ(catalogo.quantidadeProdutos(),1);
  EXPECT_EQ(catalogo.listarProdutos(testeDesligado),produtos);
}

TEST(CatalogoTeste, BuscarProdutosPresentesNoCatalogo){
  Catalogo catalogo;
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15);
  catalogo.adicionarProduto(produto1,testeDesligado);
  catalogo.adicionarProduto(produto2, testeDesligado);
  
  EXPECT_EQ(catalogo.buscarProdutoPorId(1, testeDesligado),produto1);
  EXPECT_EQ(catalogo.buscarProdutoPorId(2, testeDesligado),produto2);
}

TEST(CatalogoTeste, BuscarProdutosNaoPresentesNoCatalogo){
  Catalogo catalogo;
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15);
  catalogo.adicionarProduto(produto1,testeDesligado);
  catalogo.adicionarProduto(produto2, testeDesligado);
  
  EXPECT_EQ(catalogo.buscarProdutoPorId(1, testeDesligado),produto1);
  EXPECT_EQ(catalogo.buscarProdutoPorId(2, testeDesligado),produto2);
  EXPECT_EQ(catalogo.buscarProdutoPorId(3, testeDesligado),Produto(-1,"Produto não encontrado",0));
}

TEST(PedidoTeste, Construtor){
  Catalogo catalogo;
  Pedido pedido1("Jonas",catalogo), pedido2("Fernando",catalogo);
  
  EXPECT_EQ(pedido1.obterNomeCliente(), "Jonas");
  EXPECT_EQ(pedido2.obterNomeCliente(), "Fernando");
}

TEST(PedidoTeste, AdicionarProdutosAoPedido){
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15);
  Catalogo catalogo;
  catalogo.adicionarProduto(produto1,testeDesligado);
  catalogo.adicionarProduto(produto2,testeDesligado);

  Pedido pedido("Jonas", catalogo);
  EXPECT_EQ(pedido.quantidadeProdutos(), 0);

  pedido.adicionarProduto(produto1, testeDesligado);
  std::vector<Produto> produtos = {produto1};
  EXPECT_EQ(pedido.quantidadeProdutos(), 1);
  EXPECT_EQ(pedido.retornarListaDeProdutos(), produtos);

  pedido.adicionarProduto(produto2,testeDesligado);
  produtos.push_back(produto2);
  EXPECT_EQ(pedido.quantidadeProdutos(), 2);
  EXPECT_EQ(pedido.retornarListaDeProdutos(), produtos);

  pedido.adicionarProduto(produto1,testeDesligado);
  produtos.push_back(produto1);
  EXPECT_EQ(pedido.quantidadeProdutos(), 3);
  EXPECT_EQ(pedido.retornarListaDeProdutos(), produtos);
}

TEST(PedidoTeste, TentandoAdicionarProdutosQueNaoEstaoNoCatalogo){
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15);
  Catalogo catalogo;
  catalogo.adicionarProduto(produto1, testeDesligado);

  Pedido pedido("Jonas", catalogo);
  EXPECT_EQ(pedido.quantidadeProdutos(), 0);

  pedido.adicionarProduto(produto1, testeDesligado);
  std::vector<Produto> produtos = {produto1};
  EXPECT_EQ(pedido.quantidadeProdutos(), 1);
  EXPECT_EQ(pedido.retornarListaDeProdutos(), produtos);

  pedido.adicionarProduto(produto2, testeDesligado);
  EXPECT_EQ(pedido.quantidadeProdutos(), 1);
  EXPECT_EQ(pedido.retornarListaDeProdutos(), produtos);
}

TEST(PedidoTeste, CalcularValorTotalSemDesconto){
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15), produto3(3,"Leite em pó", 35.50);
  Catalogo catalogo;
  catalogo.adicionarProduto(produto1, testeDesligado);
  catalogo.adicionarProduto(produto2, testeDesligado);
  catalogo.adicionarProduto(produto3, testeDesligado);

  Pedido pedido1("Jonas", catalogo);
  pedido1.adicionarProduto(produto1,testeDesligado);
  pedido1.adicionarProduto(produto2,testeDesligado);
  pedido1.adicionarProduto(produto3,testeDesligado);

  EXPECT_NEAR(pedido1.calcularTotal(testeDesligado), 53.09, TOLERANCIA_PARA_DOUBLE);

  Produto produto4(4,"1Kg de Carne",30);
  catalogo.adicionarProduto(produto4, testeDesligado);

  Pedido pedido2("João", catalogo);
  pedido2.adicionarProduto(produto4, testeDesligado);
  pedido2.adicionarProduto(produto4, testeDesligado);
  pedido2.adicionarProduto(produto4, testeDesligado);

  EXPECT_NEAR(pedido2.calcularTotal(testeDesligado), 90, TOLERANCIA_PARA_DOUBLE);
}

TEST(PedidoTeste, CalcularValorTotalComDesconto){
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15), produto3(3,"Leite em pó", 35.50);
  Catalogo catalogo;
  catalogo.adicionarProduto(produto1, testeDesligado);
  catalogo.adicionarProduto(produto2, testeDesligado);
  catalogo.adicionarProduto(produto3, testeDesligado);

  Pedido pedido1("Jonas", catalogo);
  pedido1.adicionarProduto(produto1, testeDesligado);
  pedido1.adicionarProduto(produto2, testeDesligado);
  pedido1.adicionarProduto(produto2, testeDesligado);
  pedido1.adicionarProduto(produto3, testeDesligado);
  pedido1.adicionarProduto(produto3, testeDesligado);

  EXPECT_NEAR(pedido1.calcularTotal(testeDesligado), 103.59*(1-DESCONTO), TOLERANCIA_PARA_DOUBLE);

  Produto produto4(4,"1Kg de Carne",40);
  catalogo.adicionarProduto(produto4, testeDesligado);

  Pedido pedido2("João", catalogo);
  pedido2.adicionarProduto(produto4, testeDesligado);
  pedido2.adicionarProduto(produto4, testeDesligado);
  pedido2.adicionarProduto(produto4, testeDesligado);

  EXPECT_NEAR(pedido2.calcularTotal(testeDesligado), 120*(1-DESCONTO), TOLERANCIA_PARA_DOUBLE);
}
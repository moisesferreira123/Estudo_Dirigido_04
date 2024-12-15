#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock_test.h"

using  ::testing::Return;
bool testeDesligadoMock = false;

TEST(CenarioCompletoTeste, TesteDeIntegracao){
  MockCatalogo mockcatalogo;
  Produto produto1(1,"Sabonete",2.59), produto2(2,"Shampoo",15), produto3(3,"Carne",40);
  std::map<int, Produto> produtos = {{1,produto1}};

  EXPECT_CALL(mockcatalogo, adicionarProduto(produto1, ::testing::_))
    .Times(1)
    .WillOnce(Return(true));

  EXPECT_CALL(mockcatalogo, adicionarProduto(produto2,::testing::_))
    .Times(1)
    .WillOnce(Return(true));

  EXPECT_CALL(mockcatalogo, adicionarProduto(produto3, ::testing::_))
    .Times(1)
    .WillOnce(Return(true));
  
  // Configurando o mock para refletir dinamicamente as alterações no mapa.
  EXPECT_CALL(mockcatalogo, listarProdutos(testeDesligadoMock))
    .WillRepeatedly(::testing::Invoke([&produtos]() { return produtos; }));

  EXPECT_CALL(mockcatalogo, buscarProdutoPorId(1, ::testing::_))
    .Times(2)
    .WillRepeatedly(Return(produto1));

  EXPECT_CALL(mockcatalogo, buscarProdutoPorId(2, ::testing::_))
    .Times(2)
    .WillRepeatedly(Return(produto2));
  
  EXPECT_CALL(mockcatalogo, buscarProdutoPorId(3, ::testing::_))
    .Times(2)
    .WillRepeatedly(Return(produto3));

  // Testando a adição de produtos no catálogo
  mockcatalogo.adicionarProduto(produto1, testeDesligadoMock);
  auto resultado = mockcatalogo.listarProdutos(testeDesligadoMock);

  EXPECT_EQ(resultado.size(), 1);

  EXPECT_EQ(resultado[1].obterId(),1);
  EXPECT_EQ(resultado[1].obterNome(),"Sabonete");
  EXPECT_NEAR(resultado[1].obterPreco(),2.59,TOLERANCIA_PARA_DOUBLE);

  mockcatalogo.adicionarProduto(produto2, testeDesligadoMock);
  produtos.insert({2,produto2});
  resultado = mockcatalogo.listarProdutos(testeDesligadoMock);

  EXPECT_EQ(resultado.size(), 2);

  EXPECT_EQ(resultado[2].obterId(),2);
  EXPECT_EQ(resultado[2].obterNome(),"Shampoo");
  EXPECT_NEAR(resultado[2].obterPreco(),15,TOLERANCIA_PARA_DOUBLE);

  mockcatalogo.adicionarProduto(produto3, testeDesligadoMock);
  produtos.insert({3,produto3});
  resultado = mockcatalogo.listarProdutos(testeDesligadoMock);

  EXPECT_EQ(resultado.size(), 3);

  EXPECT_EQ(resultado[3].obterId(),3);
  EXPECT_EQ(resultado[3].obterNome(),"Carne");
  EXPECT_NEAR(resultado[3].obterPreco(),40,TOLERANCIA_PARA_DOUBLE);
  // ---

  // Testando a adição de produtos no pedido
  Pedido pedido("Jonas",mockcatalogo);

  pedido.adicionarProduto(produto1, testeDesligadoMock);
  pedido.adicionarProduto(produto1, testeDesligadoMock);
  pedido.adicionarProduto(produto2, testeDesligadoMock);
  pedido.adicionarProduto(produto2, testeDesligadoMock);

  auto resultado2 = pedido.retornarListaDeProdutos();
  
  EXPECT_EQ(resultado2.size(), 4);

  EXPECT_EQ(resultado2[0].obterId(),1);
  EXPECT_EQ(resultado2[0].obterNome(),"Sabonete");
  EXPECT_NEAR(resultado2[0].obterPreco(),2.59,TOLERANCIA_PARA_DOUBLE);

  EXPECT_EQ(resultado2[1].obterId(),1);
  EXPECT_EQ(resultado2[1].obterNome(),"Sabonete");
  EXPECT_NEAR(resultado2[1].obterPreco(),2.59,TOLERANCIA_PARA_DOUBLE);

  EXPECT_EQ(resultado2[2].obterId(),2);
  EXPECT_EQ(resultado2[2].obterNome(),"Shampoo");
  EXPECT_NEAR(resultado2[2].obterPreco(),15,TOLERANCIA_PARA_DOUBLE);

  EXPECT_EQ(resultado2[3].obterId(),2);
  EXPECT_EQ(resultado2[3].obterNome(),"Shampoo");
  EXPECT_NEAR(resultado2[3].obterPreco(),15,TOLERANCIA_PARA_DOUBLE);
  // ---

  // Testando o cálculo total do pedido sem desconto.
  EXPECT_NEAR(pedido.calcularTotal(testeDesligadoMock), 35.18, TOLERANCIA_PARA_DOUBLE);

  // Testando a adição de mais dois produtos no pedido.
  pedido.adicionarProduto(produto3,testeDesligadoMock);
  pedido.adicionarProduto(produto3,testeDesligadoMock);

  auto resultado3 = pedido.retornarListaDeProdutos();

  EXPECT_EQ(resultado3.size(), 6);

  EXPECT_EQ(resultado3[4].obterId(),3);
  EXPECT_EQ(resultado3[4].obterNome(),"Carne");
  EXPECT_NEAR(resultado3[4].obterPreco(),40,TOLERANCIA_PARA_DOUBLE);

  EXPECT_EQ(resultado3[5].obterId(),3);
  EXPECT_EQ(resultado3[5].obterNome(),"Carne");
  EXPECT_NEAR(resultado3[5].obterPreco(),40,TOLERANCIA_PARA_DOUBLE);
  // ---

  // Testando o cálculo total do pedido com desconto.
  EXPECT_NEAR(pedido.calcularTotal(testeDesligadoMock),115.18*(1-DESCONTO) , TOLERANCIA_PARA_DOUBLE);
}
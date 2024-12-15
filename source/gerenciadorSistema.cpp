#include "gerenciadorSistema.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "loggerManager.h"
#include <iomanip>

static auto logger = loggerManager::obterLogger();

void gerenciadorSistema::obterEscolhaDoUsuario(){
  std::cin >> opcao;
  if(std::cin.fail()){
    opcao = 0;
  }
}

void gerenciadorSistema::escolhaDoUsuario(){
  if(opcao == 1 and interfaceAtual == 1){
    adicionarProdutoAoCatalogo();
  }else if(opcao == 2 and interfaceAtual == 1){
    listarProdutosDoCatalogo();
  }else if(opcao == 3 and interfaceAtual == 1){
    buscarProdutoNoCatalogoPorId();
  }else if(opcao == 4 and interfaceAtual == 1){
    realizarPedido();
  }else if(opcao == 5 and interfaceAtual == 1){
    sairDoPrograma();
  }else if(opcao == 1 and interfaceAtual == 2){
    listarProdutosDoCatalogo();
  }else if(opcao == 2 and interfaceAtual == 2){
    buscarProdutoNoCatalogoPorId();
  }else if(opcao == 3 and interfaceAtual == 2){
    adicionarProdutoAoPedidoPeloId();
  }else if(opcao == 4 and interfaceAtual == 2){
    mostrarListaDeProdutosdoPedido();
  }else if(opcao == 5 and interfaceAtual == 2){
    mostrarValorTotalDoPedido();
  }else if(opcao == 6 and interfaceAtual == 2){
    cancelarPedido();
  }else if(opcao == 7 and interfaceAtual == 2){
    finalizarPedido();
  }else if(opcao == 8 and interfaceAtual == 2){
    sairDoPrograma();
  }else if(opcao == 1 and interfaceAtual == 3){
    pagarPedido();
  }else if(opcao == 2 and interfaceAtual == 3){
    voltar();
  }else{
    std::cout << "Opção inválida! Digite outra opção correspondente a ação que deseja realizar.\n";
  }
}

int gerenciadorSistema::retornarInterfaceAtual(){
  return interfaceAtual;
}

void gerenciadorSistema::adicionarProdutoAoCatalogo(){
  std::string idProdutoString, nomeProduto, precoProdutoString;
  std::cout << "Digite o ID do produto: ";
  std::cin >> idProdutoString;
  try{
    int num = std::stoi(idProdutoString);
    if(num<=0) throw std::exception();
  }catch(std::exception& e){
    spdlog::error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao catálogo");
    logger->error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao catálogo");
    return;
  }
  std::cout << "Digite o nome do produto: ";
  std::cin >> nomeProduto;
  std::cout << "Digite o preço do produto: ";
  std::cin >> precoProdutoString;
  try{
    double num = std::stod(precoProdutoString);
    if(num<=0) throw std::exception();
  }catch(std::exception& e){
    spdlog::error("O preço fornecido não é um número maior que zero. Não foi possível adicionar produto ao catálogo.");
    logger->error("O preço fornecido não é um número maior que zero. Não foi possível adicionar produto ao catálogo.");
    return;
  }
  int idProduto = std::stoi(idProdutoString);
  double precoProduto = std::stod(precoProdutoString);
  Produto produto(idProduto, nomeProduto, precoProduto);
  bool adicionou = catalogo.adicionarProduto(produto);
  if(adicionou){
    spdlog::info("Produto foi adicionado com sucesso ao catálogo.");
    logger->info("Produto foi adicionado com sucesso ao catálogo.");
  }else{
    spdlog::error("Não foi possível adicionar o novo produto ao catálogo. Id {} já existe no catálogo.", produto.obterId());
    logger->error("Não foi possível adicionar o novo produto ao catálogo. Id {} já existe no catálogo.", produto.obterId());
  }
}

void gerenciadorSistema::listarProdutosDoCatalogo(){
  if(catalogo.quantidadeProdutos() == 0){
    std::cout << "O catálogo está vazio. Não há produto para ser listado.\n";
  }else{
    std::map<int, Produto> catalogoProdutos = catalogo.listarProdutos();
    for(auto produto:catalogoProdutos){
      std::cout << produto.second.obterId() << " " << produto.second.obterNome() << " " << produto.second.obterPreco() << "\n";
    }
  }
}

void gerenciadorSistema::buscarProdutoNoCatalogoPorId(){
  std::string idProdutoString;
  std::cout << "Digite o ID do produto desejado: ";
  std::cin >> idProdutoString;
  int idProduto;
  try{
    idProduto = std::stoi(idProdutoString);
    if(idProduto<=0) throw std::exception();
  }catch(std::exception& e){
    spdlog::error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao catálogo\n");
    logger->error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao catálogo\n");
    return;
  }
  Produto produto = catalogo.buscarProdutoPorId(idProduto);
  if(produto == Produto(-1,"Produto não encontrado",0)){
    spdlog::error("Esse produto não está presente no catálogo.");
    logger->error("Esse produto não está presente no catálogo.");
  }else{
    spdlog::info("Produto de id {} foi encontrado no catálogo!", idProduto);
    logger->info("Produto de id {} foi encontrado no catálogo!", idProduto);
    std::cout << "Informações do produto buscado:\nId: " << produto.obterId() << "  Nome: " << produto.obterNome() << "  Preço: R$" << std::fixed << std::setprecision(2) << produto.obterPreco() << "\n";
  }
}

void gerenciadorSistema::realizarPedido(){
  interfaceAtual = 2;
  std::string nomeCliente;
  std::cout << "Digite o nome do cliente: ";
  std::cin >> nomeCliente;
  Pedido pedidoCliente(nomeCliente, catalogo);
  pedido.push_back(pedidoCliente);
}

void gerenciadorSistema::adicionarProdutoAoPedidoPeloId(){
  std::string idProdutoString;
  int idProduto;
  std::cout << "Digite o ID do produto: ";
  std::cin >> idProdutoString;
  try{
    idProduto = std::stoi(idProdutoString);
    if(idProduto<=0) throw std::exception();
  }catch(std::exception& e){
    spdlog::error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao pedido");
    logger->error("O id fornecido não é um inteiro positivo. Não foi possível adicionar produto ao pedido");
    return;
  }
  Produto produto = catalogo.buscarProdutoPorId(idProduto);
  if(produto == Produto(-1,"Produto não encontrado",0)){
    spdlog::error("Esse produto não está presente no catálogo. Não foi possível adicioná-lo ao pedido.");
    logger->error("Esse produto não está presente no catálogo. Não foi possível adicioná-lo ao pedido.");
  }else{
    pedido[0].adicionarProduto(produto);
    spdlog::info("Produto foi adicionado ao pedido.");
    logger->info("Produto foi adicionado ao pedido.");
  }
}

void gerenciadorSistema::mostrarValorTotalDoPedido(){
  if(pedido.empty()){
    spdlog::error("Não há nenhum pedido em andamento para mostrar o valor total.");
    logger->error("Não há nenhum pedido em andamento para mostrar o valor total.");
  }else{
    pedido[0].calcularTotal();
  }
}

void gerenciadorSistema::mostrarListaDeProdutosdoPedido(){
  std::vector<Produto> listaDeProdutos = pedido[0].retornarListaDeProdutos();
  for(auto produto:listaDeProdutos){
    std::cout << produto.obterId() << " " << produto.obterNome() << " " << produto.obterPreco() << "\n";
  }
}

void gerenciadorSistema::cancelarPedido(){
  std::string resposta{""};
  while(resposta != "s" and resposta != "n"){
    std::cout << "Uma vez cancelado o pedido, todas as informações dele serão perdidas. Você realmente deseja cancelar o pedido (s/n)? ";
    std::cin >> resposta;
    if(resposta == "s"){
      pedido.pop_back();
      std::cout << "Pedido foi cancelado.\n";
      interfaceAtual = 1;
    }else if(resposta == "n"){
      std::cout << "Pedido não foi cancelado. Continue com o seu pedido!\n";
    }else{
      std::cout << "Resposta inválida! Responda com 's' se deseja cancelar o pedido e com 'n' caso não queira.\n";
    }
  }
}

void gerenciadorSistema::finalizarPedido(){
  interfaceAtual = 3;
  std::cout << "Finalizando o pedido...\n";
  pedido[0].calcularTotal();
}

void gerenciadorSistema::pagarPedido(){
  std::cout << "Pedido pago com sucesso.\n";
  interfaceAtual = 1;
  pedido.pop_back();
}

void gerenciadorSistema::voltar(){
  interfaceAtual = 2;
}

void gerenciadorSistema::sairDoPrograma(){
  std::string resposta{""};
  while(resposta != "s" and resposta != "n"){
    std::cout << "Desejas sair da loja virtual (s/n)? ";
    std::cin >> resposta;
    if(resposta == "s"){
      std::cout << "Muito obrigado pela sua visita à loja virtual! Volte sempre!!!\n";
      saidaDoPrograma =  true;
    }else if(resposta == "n"){
      std::cout << "Ótima escolha. Continue suas compras.\n";
    }else{
      std::cout << "Resposta inválida! Responda com 's' se deseja sair da loja virtual e com 'n' caso não queira.\n";
    }
  }
}

bool gerenciadorSistema::retornarSaidaDoProgama(){
  return saidaDoPrograma;
}
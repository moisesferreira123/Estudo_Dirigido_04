#add_library(source_lib
#    ${CMAKE_SOURCE_DIR}/source/produto.cpp
#    ${CMAKE_SOURCE_DIR}/source/catalogo.cpp
#    ${CMAKE_SOURCE_DIR}/source/pedido.cpp
#)
#
#add_executable(run_test 
#                test.cpp 
#                mock_test.cpp
#                ../source/catalogo.cpp
#                ../source/pedido.cpp 
#                ../source/produto.cpp
#)
#
#target_include_directories(run_test PUBLIC 
#    ${CMAKE_SOURCE_DIR}/source
#)
#
#find_package(fmt REQUIRED)
#target_link_libraries(run_test PRIVATE gtest GTest::gtest_main fmt::fmt gmock gmock_main)
#
#enable_testing()
#add_test(NAME AllTests COMMAND run_test)

add_library(source_lib
    ${CMAKE_SOURCE_DIR}/source/produto.cpp
    ${CMAKE_SOURCE_DIR}/source/catalogo.cpp
    ${CMAKE_SOURCE_DIR}/source/pedido.cpp
)

# Adicionar o executável de teste
add_executable(run_test 
                test.cpp 
                mock_test.cpp
                ../source/catalogo.cpp
                ../source/pedido.cpp 
                ../source/produto.cpp
)

# Incluir diretórios de cabeçalho
target_include_directories(run_test PUBLIC 
    ${CMAKE_SOURCE_DIR}/source
)

find_package(fmt REQUIRED)

# Linkar as bibliotecas necessárias
target_link_libraries(run_test PRIVATE gtest gtest_main fmt::fmt gmock gmock_main spdlog::spdlog)

# Habilitar os testes
enable_testing()
add_test(NAME AllTests COMMAND run_test)
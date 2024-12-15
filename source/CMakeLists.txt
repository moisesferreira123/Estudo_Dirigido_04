add_executable(main main.cpp catalogo.cpp pedido.cpp produto.cpp gerenciadorSistema.cpp interfaceSistema.cpp)

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(fmt REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt spdlog::spdlog)
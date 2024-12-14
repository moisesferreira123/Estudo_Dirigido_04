#ifndef _LOGGER_MANAGER_H_
#define _LOGGER_MANAGER_H_

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <memory>

class loggerManager {
public:
    // Função para obter o logger compartilhado
    static std::shared_ptr<spdlog::logger> obterLogger() {
        static std::shared_ptr<spdlog::logger> logger = spdlog::basic_logger_mt("arquivo_logger", "../source/logs.txt");
        return logger;
    }
};

#endif 
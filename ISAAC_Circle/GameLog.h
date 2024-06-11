#pragma once
#include <spdlog/spdlog-inl.h>
#include "spdlog/sinks/rotating_file_sink.h"

#ifndef MACROS_H
#define MACROS_H

class GameLogger
{
public:
    static std::shared_ptr<spdlog::logger>& getGameLoggerInstance() {
        static std::shared_ptr<spdlog::logger> instance = spdlog::rotating_logger_mt("Game_logger", "logs/Game/Game.txt", 1024 * 1024 * 5, 10);
        instance->set_pattern("%^[%Y-%m-%d %H:%M] [%l] [%s] %v");
        return instance;
    }
private:
    GameLogger() = default;
    // you can add more loggers here as needed
};

#define LOG_GAME(level, message) GameLogger::getGameLoggerInstance()->log(spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION}, level, message)

#endif // MACROS_H
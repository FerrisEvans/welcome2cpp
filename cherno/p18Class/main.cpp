#include <iostream>

class Log {
public:
    enum Level {
        ERROR, WARN, INFO, DEBUG
    };

private:
    // prefix m tells us it's a private member variable. m stands for member.
    Level m_LogLevel = INFO;

public:
    void SetLevel(Level level) {
        m_LogLevel = level;
    }

    void Error(const char* msg) {
        if (m_LogLevel >= ERROR) std::cout << "[ERROR]: " << msg << std::endl;
    }

    void Warn(const char* msg) {
        if (m_LogLevel >= WARN) std::cout << "[WARN]: " << msg << std::endl;
    }

    void Info(const char* msg) {
        if (m_LogLevel >= INFO) std::cout << "[INFO]: " << msg << std::endl;
    }
};

int main() {
    Log log;
    log.SetLevel(Log::INFO);
    log.Error("This is a error message");
    log.Warn("This is a warn message");
    log.Info("This is a info message");
    return 0;
}

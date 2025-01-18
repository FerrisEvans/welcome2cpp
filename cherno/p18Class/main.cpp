#include <iostream>

class Log {
public:
    const int LogLevelError = 0;
    const int LogLevelWaring = 1;
    const int LogLevelInfo = 2;

private:
    // prefix m tells us it's a private member variable. m stands for member.
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level) {
        m_LogLevel = level;
    }

    void Error(const char* msg) {
        if (m_LogLevel >= LogLevelError) std::cout << "[ERROR]: " << msg << std::endl;
    }

    void Warn(const char* msg) {
        if (m_LogLevel >= LogLevelWaring) std::cout << "[WARN]: " << msg << std::endl;
    }

    void Info(const char* msg) {
        if (m_LogLevel >= LogLevelInfo) std::cout << "[INFO]: " << msg << std::endl;
    }
};

int main() {
    Log log;
    log.SetLevel(log.LogLevelInfo);
    log.Error("This is a error message");
    log.Warn("This is a warn message");
    log.Info("This is a info message");
    return 0;
}

#include <exception>
#include <string>

class CodeGenerationException : public std::exception {
public:
    CodeGenerationException(std::string msg) : m_message(msg) {}

    const char *what() const throw() {
        return m_message.c_str();
    }

private:
    std::string m_message;
};
#include <exception>
#include <string>

class GrammarException : public std::exception {
public:
    GrammarException(std::string msg) : m_message(msg) {}

    const char *what() const throw() {
        return m_message.c_str();
    }

private:
    std::string m_message;
};
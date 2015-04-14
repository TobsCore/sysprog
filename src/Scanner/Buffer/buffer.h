class Buffer {
private:
    char* filePath;
    static int bufferSize;
    char* buffer1;
    char buffer2;
    short currentBuffer;
    char* currentCharacter;
    
    
public:
    Buffer(char* filePath);
    virtual ~Buffer();
    char getChar();
    void ungetChar();
};
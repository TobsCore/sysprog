class Token {
public:
    Token();
    
    char* getValue();
    void setValue(char* value);
    
    int getType();
    void setType(int type);
    
    int getColumn();
    void setColumn(int column);
    
    int getRow();
    void setRow(int row);
    
private:
    
    char* value;
    int type;
    int column;
    int row;
};


class Container {
public:
    Container();
    
    char* getValue();
    void setValue(char* value);
    
    int getType();
    void setType(int type);

private:
    char* value;
    int type;
};


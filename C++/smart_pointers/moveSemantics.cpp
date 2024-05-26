#include <iostream>

extern "C"{
    #include <string.h>
}

class String
{
    public:

    String(const char * string)
    {
        printf("created\n");
        sz = strlen(string);
        data = new char[sz];
        memcpy(data, string, sz);
    }

    String(const String& other) //copy construtor
    {
        printf("Copied\n");
        sz = other.sz;
        data = new char[sz];
        memcpy(this->data, other.data, sz);
    }

    String(String&& other) //rvalue reference in move constructor
    {
        printf("move\n");
        sz = other.sz;
        data = other.data;
        other.sz = 0;
        other.data = nullptr;
    }

    String& operator=(String&& other)
    {
        printf("move assignment\n");
        sz = other.sz;
        data = other.data;
        other.sz = 0;
        other.data = nullptr;
        return *this;
    }

    void print()
    {
        for(int i = 0; i < sz; i++){
            printf("%c", data[i]);
        }
        printf("\n");
    }

    ~String()
    {
        delete data;
    }


    private:
    int sz;
    char * data;
};

class Entity
{
    public:

    Entity(const String& name) : mName(name)
    {

    }

    Entity(String&& name) : mName(std::move(name))
    {
        std::cout << "Entity move constructor\n";
    }

    void printName()
    {
        mName.print();
    }

    private:
    String mName;
};

int main()
{
    String str("RoboticsCorner");
    Entity entity(str);
    str = "Embedded";
    Entity entity2(String("Embedded Linux"));
    entity.printName();

    return 0;
}
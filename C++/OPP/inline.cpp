#include <iostream>

class Device{
    public:
    inline Device(){}

    inline void SplashScreen(){
        std::cout << "class hello world!!\n";
    }
};

inline void Init(){
    std::cout << "hello world!!\n";
}

void Initialize(){
    std::cout << "Hello world 2\n";
}

int main(){
    Init(); //code bloat
    Init(); //text replacment in compile time not in preprocessing time
    Device d;
    d.SplashScreen();
    /*
    push context of main in stack
    create stack frame for Initialize
    execute the function
    pop context of main from stack
    
    */
    Initialize();
}
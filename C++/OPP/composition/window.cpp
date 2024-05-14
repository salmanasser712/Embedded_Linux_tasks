#include <iostream>

class Button{
    public:
    Button(bool pStatus) :status(pStatus){

    }

    bool getStatus(){
        return status;
    }
    private:
    bool status;

};

class Window{
    public:
    Window(Button *pButton): button(pButton){

    }
    private:
    Button *button;
};

int main(){
    Window screen(new Button(false));
}
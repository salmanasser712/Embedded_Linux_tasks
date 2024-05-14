#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack{

    public:
    Stack(int s = 10){
        size = s > 0 && s < 1000? s : 10;
        top = -1;
        buffer = new T[size];
    }

    void Push(T temp){
        if(top == size - 1){
            std::cout << "Out of bounds, can't add another item size = " << this->size << std::endl;
        }
        else{
            buffer[++top] = temp;
        }
    }

    void Pop(){
        if(top == -1){
            std::cout << "the stack is empty!! \n";
        }
        else{
            top--;
        }
    }

    T Top(){
        if(top == -1){
            std::cout << "the stack is empty!! \n";
        }
        else{
            return buffer[top];
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == size - 1;
    }
    ~Stack()
    {
        delete[] buffer;
    }


    private:
    int size;
    int top;
    T* buffer;

};



#endif
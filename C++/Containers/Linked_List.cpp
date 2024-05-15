#include <iostream>

namespace Container{
    struct Record{
        std::string name;
        int age;
        int id;
    };

    struct Node{
        Record record;
        Node * Next;
    };

    void Traverse(Node * Head, void(*callback)(Container::Node*)){
        Node * temp = Head;
        if(temp != nullptr){
            temp = temp->Next;
        }
        while(temp){
            callback(temp);
            temp = temp->Next;
        }
    }

    void print(Container::Node * node){
        std::cout << node->record.id << " " << node->record.name << " " << node->record.age << std::endl;
    }
}

int main(){
    Container::Node* Head = new Container::Node();
    Container::Node* first = new Container::Node();
    Container::Node* second = new Container::Node();
    Container::Node* third = new Container::Node();

    Head->Next = first;

    first->record.id = 1;
    first->record.name = "Luffy";
    first->record.age = 19;
    first->Next = second;

    second->record.id = 2;
    second->record.name = "Sanji";
    second->record.age = 21;
    second->Next = third;

    third->record.id = 3;
    third->record.name = "Law";
    third->record.age = 26;
    third->Next = nullptr;

    Traverse(Head, Container::print);

    delete first;
    delete second;
    delete third;


    return 0;
}
#include <iostream>
#include <vector>

class PageObject{
    public:
    virtual void addItem(){};
    virtual void removeItem(){};
    virtual void deleteItem(){};
};

class Page : public PageObject{
    public:
    void addItem(PageObject a) {
        std::cout << "Item added into the page" << std::endl;
    }
    void removeItem() {
       std::cout << "Item Removed from page" << std::endl;
    }
    void deleteItem(PageObject a) {
       std::cout << "Item Deleted from Page" << std::endl;
    }
};

class Copy : public PageObject{
    std::vector<PageObject> copyPages;
    public:
    void AddElement(PageObject a) {
        copyPages.push_back(a);
    }
    void addItem(PageObject a) {
        std::cout << "Item added to the copy" << std::endl;
    }
    void removeItem() {
        std::cout << "Item removed from the copy" << std::endl;
    }
    void deleteItem(PageObject a) {
        std::cout << "Item deleted from the copy" << std::endl;
    }
};


int main(){
    Page p1;
    Page p2;
    PageObject po1;

    p1.addItem(po1);
    
    return 0;
}
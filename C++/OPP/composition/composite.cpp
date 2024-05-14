#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

class Graphic{
    public:
    virtual void draw() const = 0;
    virtual void remove(Graphic *) {};
    virtual void add(Graphic *) {};
    virtual void getChild(int) {};
    virtual ~Graphic() {};
};

class Line : public Graphic{
    void draw() const{
        std::cout << "Drawing a line\n";
    }

};

class Rectangle : public Graphic{
    void draw() const{
        std::cout << "Drawing a Rectangle\n";
    }
};

class Text : public Graphic{
    void draw() const{
        std::cout << "writting text\n";
    }
};

class Picture : public Graphic{
    public:
    void draw() const{
        for_each(glist.begin(), glist.end(), std::mem_fn(&Graphic::draw));
    }

    void remove(Graphic *g){
        glist.erase(std::remove(glist.begin(), glist.end(), g));
    }

    void add(Graphic *g){
        glist.push_back(g);
    }

    private:
    std::vector<Graphic *> glist;

};

int main(){
    Line line;
    Rectangle rect;
    Text text;

    Picture pic;
    pic.add(&line);
    pic.add(&rect);
    pic.add(&text);

    pic.remove(&rect);

    pic.draw();
}
#include <iostream>
#include <vector>
#include <algorithm> 

class Subject;

class Observer
{
    public:
    virtual void update(Subject& sub)=0;
    virtual ~Observer() = default;
};

class Subject
{
    public:
    void Attach(Observer& ob)
    {
        Observers.push_back(&ob);
    }
    void Deattach(Observer& ob)
    {
        auto it = std::find(Observers.begin(), Observers.end(), &ob);
        Observers.erase(it);
    }
    void Notify()
     {
         for (auto* o : Observers) {
             o->update(*this);
         }
     }
    virtual ~Subject() = default;

    private:
    std::vector<Observer*> Observers;
};

class ClockTimer:public Subject
{
    public:
    void setTime(int hour, int min, int second){
        this->hours = hour;
        this->mins = min;
        this->seconds = second;

        Notify();
    }

    int GetHour()
    {
        return hours;
    }

    int GetMins()
    {
        return mins;
    }

    int GetSeconds()
    {
        return seconds;
    }

    private:
    int hours;
    int mins;
    int seconds;
};

class AnalogClock : public Observer
{
    public:
    AnalogClock(Subject & sub)
    {
        subject = &sub;
        subject->Attach(*this);
    }
    ~AnalogClock(){
        subject->Deattach(*this);
    }

    void Draw()
    {
        ClockTimer* ct = dynamic_cast<ClockTimer *>(this->subject);
        int hour = ct->GetHour(); 
        int minute = ct->GetMins(); 
        int second = ct->GetSeconds(); 

        std::cout << "Analog time is " << hour << ":" 
                   << minute << ":" 
                   << second << std::endl; 
    }
    void update(Subject &sub) override
    {
        if(&sub == subject) Draw();
    }

    private:
    Subject * subject;
};

class DigitalClock : public Observer
{
    public:
    DigitalClock(Subject & sub)
    {
        subject = &sub;
        subject->Attach(*this);
    }
    ~DigitalClock(){
        subject->Deattach(*this);
    }

    void Draw()
    {
        ClockTimer* ct = dynamic_cast<ClockTimer *>(this->subject);
        int hour = ct->GetHour(); 
        int minute = ct->GetMins(); 
        int second = ct->GetSeconds(); 

        std::cout << "Analog time is " << hour << ":" 
                   << minute << ":" 
                   << second << std::endl; 
    }
    void update(Subject &sub) override
    {
        if(&sub == subject) Draw();
    }

    private:
    Subject * subject;
};

int main()
{
    ClockTimer ct;
    AnalogClock AC(ct);
    DigitalClock DC(ct);

    ct.setTime(12, 15, 20);
    
    return 0;
}
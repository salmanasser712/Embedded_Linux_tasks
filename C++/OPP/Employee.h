#ifndef Employee_H
#define Employee_H

class Employee{

    public:
    Employee();

    Employee(int id, int salary);

    Employee(const Employee& copy);

    ~Employee();

    // "const" to say we won't change variables in this function
    inline int getId() const;

    private:
    int m_id;
    int m_salary;



};



#endif
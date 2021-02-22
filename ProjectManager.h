

#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"

class ProjectManager : public Employee, public Heading, public Project {
protected:
    int subordes_num;
public:
    ProjectManager() : Employee() {
        this->subordes_num = 0;
    }
    ~ProjectManager() {}

    double calcHeads(int subordes) override{
        return subordes * 10;
    }

    void set_payment() override{
        this->payment = calcHeads(subordes_num) + project_payment(budget,rate);
    }

};

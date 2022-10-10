#include<iostream>
#include<string.h>
using namespace std;


class customer
{
    public:
        int ID;
        string name;
        int age;
        char sex;
        int incomeRange;
        bool segment;
        customer *next;
};


class arrange
{
    public:
        customer *head_id;
        customer *head_age;
        customer *head_income;
        customer *fence;

    public:
        arrange()
        { 
            head_id = NULL;
            head_age = NULL;
            head_income = NULL;
        }

    void H1(int id, string name, int age, char sex, int income, bool segment)
    {
        customer* curr = new customer();
        curr->ID = id;
        curr->age = age;
        curr->name = name;
        curr->incomeRange = income;
        curr->segment = segment;
        curr->sex = sex;
        curr->next = NULL;

        if(head_id == NULL)
        {
            head_id = curr;
        }
        else
        {
            if(curr->ID < head_id->ID)
            {
                curr->next = head_id;
                head_id = curr;
            }
            else
            {
                fence = head_id;
                while(fence->next != NULL)
                {
                    if(curr->ID < fence->next->ID)
                    {
                        curr->next = fence->next;
                        fence->next = curr;
                        return ;
                    }
                    fence = fence->next;
                }
                fence->next = curr;
            }
        }
    }

    void H2(int id, string name, int age, char sex, int income, bool segment)
    {
        customer* curr = new customer();
        curr->ID = id;
        curr->age = age;
        curr->name = name;
        curr->incomeRange = income;
        curr->segment = segment;
        curr->sex = sex;
        curr->next = NULL;

        if(head_age == NULL)
        {
            head_age = curr;
        }
        else
        {
            if(curr->age < head_age->age)
            {
                curr->next = head_age;
                head_age = curr;
            }
            else
            {
                fence = head_age;
                while(fence->next != NULL)
                {
                    if(curr->age < fence->next->age)
                    {
                        curr->next = fence->next;
                        fence->next = curr;
                        return ;
                    }
                    fence = fence->next;
                }
                fence->next = curr;
            }
        }
    }

    void H3(int id, string name, int age, char sex, int income, bool segment)
    {
        customer* curr = new customer();
        curr->ID = id;
        curr->age = age;
        curr->name = name;
        curr->incomeRange = income;
        curr->segment = segment;
        curr->sex = sex;
        curr->next = NULL;

        if(head_income == NULL)
        {
            head_income = curr;
        }
        else
        {
            if(curr->incomeRange < head_income->incomeRange)
            {
                curr->next = head_income;
                head_income = curr;
            }
            else
            {
                fence = head_income;
                while(fence->next != NULL)
                {
                    if(curr->incomeRange < fence->next->incomeRange)
                    {
                        curr->next = fence->next;
                        fence->next = curr;
                        return ;
                    }
                    fence = fence->next;
                }
                fence->next = curr;
            }
        }
    }

    void append(int id, string name, int age, char sex, int income, bool segment)
    {
        H1(id, name, age, sex, income, segment);
        H2(id, name, age, sex, income, segment);
        H3(id, name, age, sex, income, segment);
    }

    void show()
    {
        fence = head_id;
        cout << "sort by ID ...\n";
        for(;fence != NULL;)
        {
                cout << fence->ID << "\t" << fence->name << "\t" << fence->age << "\t" << fence->sex << "\t" << fence->incomeRange << endl;
                fence = fence->next;
        }
        fence = head_age;
        cout << "sort by Age ...\n";
        for(;fence != NULL;)
        {
                cout << fence->ID << "\t" << fence->name << "\t" << fence->age << "\t" << fence->sex << "\t" << fence->incomeRange << endl;
                fence = fence->next;
        }
        fence = head_income;
        cout << "sort by IncomeRange ...\n";
        for(;fence != NULL;)
        {
                cout << fence->ID << "\t" << fence->name << "\t" << fence->age << "\t" << fence->sex << "\t" << fence->incomeRange << endl;
                fence = fence->next;
        }
        cout << endl;
    }
};

int main()
{
    arrange data;
    data.append(1,"Kiva",58,'F',20000,true);
    data.append(2,"Ryu",20,'M',18000,false);
    data.append(3,"Ken",18,'M',30000,false);
    data.append(4,"Zio",19,'F',16000,false);
    data.append(5,"Fourze",40,'F',40000,true);
    data.show();
    data.append(6,"Gaim",22,'F',25000,true);
    data.show();
}

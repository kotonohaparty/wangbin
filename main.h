#ifndef _MAIN_H_
#define _MAIN_H_

#include"base.h"

class Feifeirun
{
    public:
        Feifeirun():name("wangbin"),age(18),sex("male"){}
   void show()
        {
            cout<<"name:"<<name<<endl<<"age:"<<age<<endl<<"sex:"<<sex<<endl;
        }
    private:
        string name;
        INT age;
        string sex;
};

#endif

#pragma once

class Date{
    private:
        int month{0}, year{0}, day{0};
    public:
        //constructor
        Date(int,int,int);

        //setter & getter
        void setdate(int,int,int);
        int get_day()const;
        int get_month()const;
        int get_year()const;

        //print function & destructor
        void print()const;
        ~Date();
};
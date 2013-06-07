#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include <ctime>
using namespace std;


bool isLeapYear(int year){
    bool flag = false;
    if (year%400 == 0){
        flag = true;
    }
    else if (year%100 == 0){
        flag = false;
    }
    else if(year%4 == 0){
        flag = true;
    }
    else{
        flag = false;
    }
    
    return flag;
}

int main(){
    clock_t begin = clock();
    
    
    //Jan 1 1900 is monday, Jan 7 for 1900 is Sunday
    //so all sunday should be 7x distance from Jan 7 1900
    int countOfSunday = 0;
    
    int startYear = 1900;
    int currentDistance = 0;
    for (int year = startYear; year<=2000; year++) { //year
        //count how many suday are the first day of a month
        int numerOfDays = 365;
        int janDays = 31;
        int febDays = 28;
        int marDays = 31;
        int aprDays = 30;
        int mayDays = 31;
        int junDays = 30;
        int julDays = 31;
        int augDays = 31;
        int septDays = 30;
        int octDays = 31;
        int novDays = 30;
        int decDays = 31;
        
        if (isLeapYear(year)) {
            cout<<year<<" is leap year!"<<endl;
            numerOfDays = 366;
            febDays = 29;
        }
        else{
            numerOfDays = 365;
            febDays = 28;
        }
        int month = 0;
        int day = 0;
        for (int j = 1; j<=numerOfDays; j++) {
            
            if (j <= 31) {
                month = 1;
                day = j;
            }
            else if(j <= 31+febDays){
                month = 2;
                day = j - janDays;
            }
            else if(j <= 31+febDays+marDays){
                month = 3;
                day = j - janDays- febDays;
            }
            else if(j <= 31+febDays+marDays+aprDays){
                month = 4;
                day = j - janDays- febDays - marDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays){
                month = 5;
                day = j - janDays- febDays - marDays - aprDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays+junDays){
                month = 6;
                day = j - janDays- febDays - marDays - aprDays- mayDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays+junDays+julDays){
                month = 7;
                day = j - janDays- febDays - marDays - aprDays- mayDays- junDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays+junDays+julDays+augDays){
                month = 8;
                day = j - janDays- febDays - marDays - aprDays- mayDays- junDays- julDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays+junDays+julDays+augDays+septDays){
                month = 9;
                day = j - janDays- febDays - marDays - aprDays- mayDays- junDays- julDays - augDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays+junDays+julDays+augDays+septDays+octDays){
                month = 10;
                day = j - janDays- febDays - marDays - aprDays- mayDays- junDays- julDays - augDays- septDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays+junDays+julDays+augDays+septDays+octDays+novDays){
                month = 11;
                day = j - janDays- febDays - marDays - aprDays- mayDays- junDays- julDays - augDays- septDays- octDays;
            }
            else if(j <= 31+febDays+marDays+aprDays+mayDays+junDays+julDays+augDays+septDays+octDays+novDays+decDays){
                month = 12;
                day = j - janDays- febDays - marDays - aprDays- mayDays- junDays- julDays - augDays- septDays- octDays-novDays;
            }
            
//            cout<<year<<"\t"<<month<<"\t"<<day<<endl;
            if (currentDistance%7 == 0) {
                cout<<year<<"\t"<<month<<"\t"<<day<<" is Monday!\n"<<endl;
                if (day == 2 && year >= 1901) {
                    cout<<"Is the second day of the month"<<endl;
                    countOfSunday++;
                }
            }
            currentDistance++;
        }
        

    }
    
    
    cout<<"Number of Sundays: "<<countOfSunday<<endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"Time elapse: "<<elapsed_secs<<" seconds"<<endl;
    return 1;
}



#include<iostream>
#include<time.h>
using namespace std;
int month_in_year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapyear(int year){
    if(year % 400==0)return 1;
    else if(year%100==0)return 0;
    else if(year % 4 ==0)return 1;
    else return 0;
}
int getDay(int year,int month,int day){
    int date = 0;
    for(int i=2000;i<=year;i++){
        for(int j=1;j<=12;j++){
            if(j==2){
                if(isLeapyear(i)){
                    month_in_year[j-1] = 29;
                }
                else month_in_year[j-1] = 28;
            }
            for(int k=1;k<=month_in_year[j-1];k++){
                if(i==year && month == j && k == day)break;
                date ++;
            }
            if(year==i && j==month)break;
        }
    }
    return date+6;
}
int main(int argc, char**argv){
    int year,month,day;
    int month_day = 0;
    while(1){
        cin>>year>>month>>day;
        if(year<2000||year>2010||month<1||month>12){
            cout<<"INPUT ERROR!"<<endl;
            continue;
        }
        if(month!=2){
                month_day=month_in_year[month-1];
        }
        else{
            if(isLeapyear(year))month_day = 29;
            else month_day = 28;
        }
        if(month_day<day || day<1){
            cout<<"INPUT ERROR!"<<endl;
            continue;
        }
        else{
            break;
        }
    }
    cout<<year<<". "<<month<<endl;
    printf("%s %s %s %s %s %s %s\n","sun","mon","tue","wed","thu","fri","sat");
    int diff_day = getDay(year,month,1)%7;
    int curr_day = getDay(year,month,day)%7;
    string current_date;
    switch(curr_day){
        case 0:
            current_date = "Sunday";
            break;
        case 1:
            current_date = "Monday";
            break;
        case 2:
            current_date = "Tuesday";
            break;
        case 3:
            current_date = "Wednesday";
            break;
        case 4:
            current_date = "Thursday";
            break;
        case 5:
            current_date = "Friday";
            break;
        case 6:
            current_date = "Saturday";
            break;
    }
    //cout<<diff_day<<endl;
    for(int i=0;i<diff_day;i++){
        printf("   ");
        printf(" ");
    }
    for(int cnt = 1; cnt<=month_day;cnt++){
        printf("%3d ",cnt);
        if(diff_day%7==6)cout<<endl;
        diff_day++;
    }
    cout<<endl<<current_date<<endl;
}
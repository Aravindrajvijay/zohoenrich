#include <stdio.h>
#include <stdlib.h>
char *month_nam[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *weekdays[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int days[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
void leap_check(int);
int previous_year(void);
char *month_name(int);
char *previous_month(int);
char *day(void);
int day_index(void);
int date_before_N_days(void);
int date_difference(int,int,int);
int julian(int ,int,int);
struct date
{
    int year;
    int month;
    int day;
}d;
int main(void) 
{
    char input[20],*month,*prev_month,*day_in_words;
    int pre_year,dayindex,days_diff,y,m,d;
    printf("Enter date (YYYY-MM-DD):\n");
    fgets( input, 20, stdin);
    sscanf( input, "%d%*c%d%*c%d", &d.year, &d.month, &d.day);
    y=d.year;
    m=d.month;
    d=d.day;
	printf("\nThe Year = %d",d.year);
	pre_year = previous_year();
	printf("\nThe Previous Year = %d",pre_year);
	printf("\nThe Month = %d",d.month);
	month = month_name(d.month);
	printf("\nThe month Name = %s",month);
	prev_month = previous_month(d.month);
	printf("\nThe Previous Month = %s",prev_month);
	printf("\nThe Day in Number = %d",d.day);
	day_in_words = day();
	printf("\nThe Day Name = %s",day_in_words);
	dayindex=day_index();
	printf("\nDay Index of the Year = %d",dayindex);
	d.day = date_before_N_days();
	printf("\nDate before N days %d-%d-%d",d.year,d.month+1,d.day);
	days_diff=date_difference(y,m,d);
	printf("\nThe difference in date = %d",days_diff);
	return 0;
}

int previous_year()
{
    int prev_year;
    prev_year = d.year-1;
    return prev_year;
}

char *month_name(int i)
{
  return month_nam[i-1];
}

char *previous_month(int i)
{
    return month_nam[i-2];
}

char *day()
{
    int century,temp,century_offset,i,day_offset,year_offset,day_index;
    int month_offset[12]={0,3,3,6,1,4,6,2,5,0,3,5};
    century = d.year / 100;
    i=century+1;
    while(1)
    {
        if(i%4==0)
        {
            break;
        }
        i++;
    }
    temp = i - 1;
    century_offset = ( temp - century) * 2;
    day_offset = d.day%7;
    year_offset = ( (d.year%100) + ( (d.year%100) / 4)) % 7;
    day_index = (day_offset + month_offset[d.month-1] + year_offset + century_offset)%7;
    return weekdays[day_index];
}

int day_index()
{
    int pre_month,i,day_index=0;
    leap_check(d.year);
    pre_month = d.month-1;
    for(i=0;i<pre_month;i++)
    {
        day_index = day_index + days[i];
    }
    return day_index+d.day;
}

int date_before_N_days()
{
    int n,date_before,month,year;
    month=d.month;
    year=d.year;
    leap_check(year);
    days[month-1]=d.day;
    scanf("%d",&n);
    date_before = days[month-1]-n;
    if( date_before==0)
    {
        if(month==1)
        {
            year=year-1;
            leap_check(year);
            month=11;
        }
        else
        {
            month=month-2;
        }
        date_before= days[month];
    }
    if(date_before<0)
    {
        if(month==1)
        {
            year=year-1;
            leap_check(year);
            month=11;
        }
        else
        {
            month=month-2;
        }
        date_before= days[month] + date_before;
    }
    return date_before;
}

void leap_check(int year)
{
    if(year%4==0 || ((year%100)&&(year%400)) )
    {
      days[1] = 29;
    }
}

int date_difference(int year,int month,int day)
{
    char date[12];
    int julian_day1,julian_day2,difference,y,m,d;
    fgets( date, 12, stdin);
    sscanf( date, "%d%*c%d%*c%d", &y, &m, &d);
    
    julian_day1 = julian(year, month, day); 
    julian_day2 = julian(y, m, d); 
    difference = abs(julian_day2 - julian_day1); 
    return difference;
}
int julian(int year, int month, int day) 
{ 
  int a = (14 - month) / 12; 
  int y = year + 4800 - a; 
  int m = month + 12 * a - 3; 
  if (year > 1582 || (year == 1582 && month > 10) || (year == 1582 && month == 10 && day >= 15)) 
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045; 
  else 
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083; 
} 

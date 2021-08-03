using namespace std;

#include <iostream>
#include <iomanip>
#include "Time.h"
#include <math.h>


bool Time::operator<(const Time& t) const {
    //convert the time into seconds, and then compare for lowest digit.
  return (this->hour*3600 + this->min*60 + this->sec) < (t.hour*3600 + t.min*60 + t.sec);
}

bool Time::operator==(const Time& t) const {
  //check if hours are equal, and mins, and secs
  return (this->hour == t.hour && this->min == t.min && this->sec == t.sec);
}

bool Time::operator<=(const Time& t) const {
  //return a bool if this is lower than T, or if its equal to T
    return ((*this) < t || (*this) == t);
}

bool operator>(const Time& a, const Time& b) {
  //return if its NOT smaller than or equal to (by deduction its greater!)
  return !(a <= b);
}

bool operator>=(const Time& a, const Time& b) {
   //return if its not smaller than B (logically, it then must be greater or equal)
   return !(a < b);
}

bool operator!=(const Time& a, const Time& b) {
  //return if theyre not equal.
  return !(a == b);
}

unsigned int operator%(const Time& t1, const Time& t2){
  // t1%t2 should mean the elapsed time in seconds from t1 to t2
  // e.g. if t1 is 10.45am and t2 is 11.55am t1%t2 would be 4200 (i.e. 70 mins)
  // if t1 is later in the day than t2 then you should assume t2 is on the next day

  //convert t1 to seconds
  int secH = t1.hour*3600;
  int secM = t1.min*60;
  int secS = t1.sec;
  int t1Total = secH + secM + secS; // in total seconds

  secH = t2.hour*3600;
  secM = t2.min*60;
  secS = t2.sec;
  int t2Total = secH + secM + secS;

  if(t1Total > t2Total)
  {
        return ((t2Total-t1Total)*(-1))+86400; //if its a negative value abs it and add a day
  }

  else{
    return (t2Total-t1Total);
  }

}

Time Time::operator-(unsigned int n) const
{
  //returns a new object, copy time and minus 1
  Time tCopy(*this);
  tCopy -= n;
  return tCopy;
}

Time& Time::operator--()        // prefix version , copy time -1
{
    *this -= 1;
    return *this;
}

Time Time::operator--(int n)    // postfix version, returns a copy. copy time -1
{ Time tCopy(*this);
  *this -= 1;
  return tCopy;
}

Time& Time::operator-=(unsigned int n) {

    //get the total time in seconds. and minus n
    int totalSeconds = this->hour*3600 + this->min*60 + this->sec;
    totalSeconds = totalSeconds - n;
    //loop if were negative so that we can add 24 hours back to the clock. cant have neg time
    if(totalSeconds<0)
    {
        while(totalSeconds<0)
            {
                totalSeconds = totalSeconds + 24*3600;
            }
    }
    //revert back to hours and seconds and minutes
    this->hour = (int)totalSeconds/3600;
    totalSeconds = totalSeconds%3600;
    this->min = (int)totalSeconds/60;
    this->sec = (int)totalSeconds%60;

  return *this;
}

//------------------------------------------
//Sandersons code below
//------------------------------------------
Time::Time()
{ hour = min = sec = 0;
}

Time::Time(int h, int m, int s)
{ setTime(h, m, s);
}

void Time::setTime(int h, int m, int s)
{ hour = (h>=0 && h<24) ? h : 0;
  min = (m>=0 && m<60) ? m : 0;
  sec = (s>=0 && s<60) ? s : 0;
}

Time& Time::operator+=(unsigned int n)
{ sec += n;
  if (sec >= 60)
  { min += sec/60;
    sec %= 60;
    if (min >=60)
    { hour = (hour + min/60) % 24;
      min %= 60;
    }
  }
  return *this;
}

Time Time::operator+(unsigned int n) const
{ Time tCopy(*this);
  tCopy += n;
  return tCopy;
}

Time& Time::operator++()        // prefix version
{ *this += 1;
  return *this;
}

Time Time::operator++(int n)    // postfix version
{ Time tCopy(*this);
  *this += 1;
  return tCopy;
}

ostream& operator<<(ostream &o, const Time &t)
{ o << setfill('0') << setw(2) <<  t.hour << ':' << setw(2) << t.min << ':' << setw(2) << t.sec;
  return o;
}


#include <iostream>

class Time {
public:
  int h; //hours
  int m; //minutes
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
  std::string title;
  Genre genre;     // only one genre per movie
  int duration;    // in minutes
};

class TimeSlot { 
public: 
  Movie movie;     // what movie
  Time startTime;  // when it starts
};

void printTime(Time time) {
  std::cout << time.h << ":" << time.m; //prints out the timestamp in 00:00 form
}

int minutesSinceMidnight(Time time){
  return (time.h*60)+time.m; //number of minutes since 00:00
}

int minutesUntil(Time earlier, Time later){
  return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min){
  int addition=time0.m+min;
  while(addition>=60){ //while an hour or more in terms of minutes
    time0.h+=1; //add 1 hour
    //time0.m=addition-60;
    addition-=60; //subrtact 60 minutes to accomodate
  }
  if(addition<60){
    time0.m=addition; //just add together
  }
  //std::cout << addition;
  //std::cout << time0.h << ":" << time0.m; //new time
  return time0;
}

void printMovie(Movie mv){ //prints movie title, genre, and duration
  std::string g;
  switch (mv.genre) {
  case ACTION   : g = "ACTION"; break;
  case COMEDY   : g = "COMEDY"; break;
  case DRAMA    : g = "DRAMA";  break;
  case ROMANCE  : g = "ROMANCE"; break;
  case THRILLER : g = "THRILLER"; break;
  }
  std::cout << mv.title << " " << g << " (" << mv.duration << " min) ";
}

void printTimeSlot(TimeSlot ts){
  Time timeEnd=addMinutes(ts.startTime, ts.movie.duration);
  printMovie(ts.movie);
  std::cout << "[starts at " << ts.startTime.h<<":"<<ts.startTime.m<<", ends by "<< timeEnd.h<<":"<<timeEnd.m<<"]";
  //std::cout << m << " " << g;
  //std::cout << ts;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  TimeSlot next={nextMovie,addMinutes(ts.startTime,ts.movie.duration)};
  return next;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  int first=minutesSinceMidnight(ts1.startTime);
  int second=minutesSinceMidnight(ts2.startTime);
  if(second==first){
    return true;
  }
  else if(first<second){
    int timegap = minutesUntil(ts1.startTime,ts2.startTime);
    if(timegap<ts1.movie.duration){
      return true;
    }
    return false;
  }
  else{
    int timegap = minutesUntil(ts2.startTime,ts1.startTime);
    if(timegap<ts2.movie.duration){
      return true;
    }
    return false;
    
  }
}

int main(){
  //printTime({10,30});
  //std::cout << minutesSinceMidnight({10, 30}) << std::endl;
  //std::cout << minutesUntil({10, 30},{13, 40}) << std::endl;
  //addMinutes({8,10}, 75);
  //addMinutes({0,10}, 120);
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};

  TimeSlot morning = {movie1, {9, 15}};  
  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie2, {16, 45}};

  //printMovie(movie1);
  //printTimeSlot(morning);
  return 0;
}

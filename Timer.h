#ifndef TIMER_H
#define TIMER_H

class Timer {
 public:
  Timer();

  void start();
  void stop();
  void pause();
  void unpause();

  int get_ticks();
  bool is_started();
  bool is_paused();
 private: 
  int startticks;
  int pauseticks;

  bool paused;
  bool started;
};


#endif

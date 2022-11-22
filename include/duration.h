#ifndef _DURATION_CLASS_
#define _DURATION_CLASS_
#include <stdbool.h>

class Duration {
   private:
    int time;
    int alarm;
    bool alarmHasBeenSet;

    bool checkAndUpdateAlarm();

   public:
    Duration();
    Duration(int);
    ~Duration();

    int getDuration();
    bool tick();
    bool tick(int);
    void setAlarm(int);
};

#endif
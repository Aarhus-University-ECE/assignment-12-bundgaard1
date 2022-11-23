#ifndef _DURATION_CLASS_
#define _DURATION_CLASS_
#include <stdbool.h>

class Duration {
    // Private attributes
   private:
    int time;
    int alarm;
    bool alarmHasBeenSet;

    bool checkAndUpdateAlarm();

    // Public attributes
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
#include "duration.h"

#include <assert.h>
#include <stdbool.h>

// Constructor with no arguments
Duration::Duration() {
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false;
}

// Constructor with time argument
Duration::Duration(int t) {
    assert(t >= 0);
    time = t;
    alarm = -1;
    alarmHasBeenSet = false;
    return;
}

// Destructor
Duration::~Duration() {}

int Duration::getDuration() { return time; }

// increment time
bool Duration::tick() {
    time++;
    return checkAndUpdateAlarm();
}

// increment time with dt
bool Duration::tick(int dt) {
    assert(dt >= 0);
    time += dt;
    return checkAndUpdateAlarm();  // Returns whether time excedes alarm
}

// Sets alarm to time a
void Duration::setAlarm(int a) {
    if (a >= time) {
        alarm = a;
        alarmHasBeenSet = true;  // Returns whether time excedes alarm
    }
}

// Checks if the alarm time has been exceted,
// Called from tick.
bool Duration::checkAndUpdateAlarm() {
    if (alarmHasBeenSet && time > alarm) {
        alarm = -1;
        alarmHasBeenSet = false;
        return true;
    } else {
        return false;
    }
}

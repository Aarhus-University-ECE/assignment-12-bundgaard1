#include "duration.h"

#include <assert.h>
#include <stdbool.h>

Duration::Duration() {
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false;
}

Duration::Duration(int t) {
    assert(t >= 0);
    time = t;
    alarm = -1;
    alarmHasBeenSet = false;
    return;
}

Duration::~Duration() {}

int Duration::getDuration() { return time; }

bool Duration::tick() {
    time++;
    return checkAndUpdateAlarm();
}
bool Duration::tick(int dt) {
    assert(dt >= 0);
    time += dt;
    return checkAndUpdateAlarm();
}

void Duration::setAlarm(int a) {
    if (a >= time) {
        alarm = a;
        alarmHasBeenSet = true;
    }
}

bool Duration::checkAndUpdateAlarm() {
    if (alarmHasBeenSet && time >= alarm) {
        alarm = -1;
        alarmHasBeenSet = false;
        return true;
    } else {
        return false;
    }
}
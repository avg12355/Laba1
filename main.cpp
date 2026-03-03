#include <iostream>

#include <string>

const int invisible = 0;
const int silent = 1;
const int infrared = 2;
const int radiowaves = 3;
const int safeenergy = 4;

void invers(int funk, bool( & sts)[5]) {
    sts[funk] = !sts[funk];

}

int activ(int funk,
    const bool( & sts)[5]) {
    if (sts[funk] == 0) {
        return 0;
    }
    return 1;
}

int cnt_activ(bool( & sts)[5]) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (sts[i] == 1) {
            cnt++;
        }
    }
    return cnt;
}

bool detected(bool( & sts)[5]) {
    if (!activ(invisible, sts) && !activ(silent, sts)) {
        return 1;
    }
    if (activ(safeenergy, sts) && !activ(radiowaves, sts)) {
        return 1;
    }
    return 0;
}

int main() {
    bool status[5] = {0,0,0,0,0};
       
    invers(invisible, status);
    invers(safeenergy, status);
    int a_infrared = activ(infrared, status);
    int a_invisible = activ(invisible, status);
    int c_activ = cnt_activ(status);
    int det1 = detected(status);
    invers(radiowaves, status);
    int det2 = detected(status);

}
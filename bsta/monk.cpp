#include <bits/stdc++.h>
using namespace std;

#define MAXN 5003
#define MAXT 5000005
#define EPS 0.000001

// A segment has a height, time and cumulative time
struct Segment {
    int h, t, ct;
} asc[MAXN], dsc[MAXN];

// Get the height at a specific time, O(n)
double get_height(const Segment sg[], int n, double time) {
    // Cumulative height from previous segments
    double cum_height = 0.0;

    // Find the time's current segment
    Segment cur;
    for (int i = 0; i < n; i++) {
        cur = sg[i];
        if (time <= sg[i].ct) break;
        cum_height += sg[i].h;
    }

    // Relative time within the segment
    double rel_time = cur.t - (cur.ct - time);
    // Relative height within the segment
    double rel_height = (double)cur.h / cur.t * rel_time;

    // Real height at the given time
    return cum_height + rel_height;
}

int a, d, total_h;

int main() {
    // Read input
    cin >> a >> d;
    for (int i = 0; i < a; i++) {
        cin >> asc[i].h >> asc[i].t;
        asc[i].ct = (i == 0) ? asc[0].t : asc[i - 1].ct + asc[i].t;
        total_h += asc[i].h;
    }
    for (int i = 0; i < d; i++) {
        cin >> dsc[i].h >> dsc[i].t;
        dsc[i].ct = (i == 0) ? dsc[0].t : dsc[i - 1].ct + dsc[i].t;
    }

    // BSTA
    double lo = 0, hi = MAXT;
    while (fabs(hi - lo) > EPS) {
        double mid = (lo + hi) / 2.0;
        double asc_height = get_height(asc, a, mid);
        double dsc_height = total_h - get_height(dsc, d, mid);

        (asc_height < dsc_height) ? lo = mid : hi = mid;
    }

    // Output answer
    printf("%.6f\n", hi);
}
class Solution {
public:
    double angleClock(int hr, int mn) {
        hr = hr%12;
        double hour = hr, minutes = mn;
        double Hr = (hour + (minutes/60))*30;
        double Min = 6 * minutes;
        double maxDeg = Hr > Min ? Hr : Min;
        double minDeg = Hr < Min ? Hr : Min;
        
        double diff = maxDeg - minDeg;
        return min(diff, 360-diff);
    }
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {

if(intervals.empty())
{ return vector{newInterval}; }

vector<Interval> res;
bool newInserted = 0;

// If newInterval is behind push newInteval and tell flag that 
// newInterval is Inserted.
for(int i=0;i<intervals.size();i++){
    if(intervals[i].end<newInterval.start)
        res.push_back(intervals[i]);
    else{
        if(newInterval.end < intervals[i].start && newInserted==0){
            res.push_back(newInterval);
            res.push_back(intervals[i]);
            newInserted = 1;
        }
        else if(newInterval.end > intervals[i].start){
            Interval temp;
            temp.start = min(newInterval.start, intervals[i].start);
            temp.end = max(newInterval.end, intervals[i].end);
            if(newInserted==0)  res.push_back(temp);
            else                res.back() = temp;
            
            newInterval = temp;
            newInserted = 1;
        }
        else{
            res.push_back(intervals[i]);
        }
    }
}
if(!newInserted && res.back().end < newInterval.start)
    res.push_back(newInterval);
return res;
}

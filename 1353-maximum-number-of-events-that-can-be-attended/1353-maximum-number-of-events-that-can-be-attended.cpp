class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>>pq;

        int day =1, lastEvent =0, attended =0;

        while(lastEvent <n || !pq.empty()){
            while(lastEvent < n && events[lastEvent][0] <= day){
                pq.push(events[lastEvent][1]);
                lastEvent++;
            }

            while(!pq.empty() && pq.top()< day)pq.pop();

            if(!pq.empty()){
                pq.pop();
                attended++;
                day++;
            }
            else{
                if(lastEvent < n)day = events[lastEvent][0];
            }
        }
        return attended;
    }
};
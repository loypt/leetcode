class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

      int count=0;
      int day=0;
      int n=apples.size();

      while(day < n || !pq.empty()){
        if(day < n)
            pq.push({day + days[day],apples[day]});
            while(!pq.empty() && (pq.top().first <= day || pq.top().second <= 0)){
                pq.pop();
            }
            if(!pq.empty()){
                count++;
                int cont=pq.top().first;
               int fre=pq.top().second-1;
              
                pq.pop();
                pq.push({cont,fre});
            }
        
        day++;

      }
      return count;
    }
};

class Solution {
public:
    string predictPartyVictory(string senate) {
        // Know index of the party
        queue <int> R,D;
        for(int i = 0; i<senate.size(); i++){
            if(senate[i]=='R') R.push(i);
            else if(senate[i]=='D') D.push(i);
        }

        int next = R.size() + D.size();
        while(!R.empty()&&!D.empty()){
            if(R.front()<D.front()){
                R.push(next++);
            }
            else{
                D.push(next++);
            }
            R.pop();
            D.pop();
        }

        if(!R.empty())
            return "Radiant";
        else
            return "Dire";
    }
};

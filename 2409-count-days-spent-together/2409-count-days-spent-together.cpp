class Solution {
public:
    int getDays(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int total = day;

        // current month se pehle ke months ke days add karo
        for(int i = 0; i < month - 1; i++) {
            total += days[i];
        }

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                           string arriveBob, string leaveBob) {

        int aliceStart = getDays(arriveAlice);
        int aliceEnd = getDays(leaveAlice);

        int bobStart = getDays(arriveBob);
        int bobEnd = getDays(leaveBob);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        if(start > end)
            return 0;

        return end - start + 1;
    }
};
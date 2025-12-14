class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        vector<int> seats;

        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }

        int s = seats.size();
        if (s == 0 || s % 2 == 1) return 0;

        long long ans = 1;

        // Multiply number of choices between every pair-group
        for (int i = 2; i < s; i += 2) {
            int prevRightSeat = seats[i - 1];
            int nextLeftSeat  = seats[i];

            // gap plants between these two groups
            long long ways = nextLeftSeat - prevRightSeat;
            ans = (ans * ways) % MOD;
        }

        return ans;
    }
};

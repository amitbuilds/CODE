class Solution {
    public int countPartitions(int[] nums, int k) {
        int n = nums.length;
        final int MOD = 1_000_000_007;

        long[] dp = new long[n + 1];   // dp[i] = ways for prefix of length i
        long[] pref = new long[n + 1]; // prefix sums of dp

        dp[0] = 1;
        pref[0] = 1;

        Deque<Integer> maxD = new ArrayDeque<>();
        Deque<Integer> minD = new ArrayDeque<>();

        int l = 0;

        for (int r = 0; r < n; r++) {

            // Maintain decreasing max deque
            while (!maxD.isEmpty() && maxD.peekLast() < nums[r])
                maxD.pollLast();
            maxD.addLast(nums[r]);

            // Maintain increasing min deque
            while (!minD.isEmpty() && minD.peekLast() > nums[r])
                minD.pollLast();
            minD.addLast(nums[r]);

            // Shrink window until valid
            while (!maxD.isEmpty() && !minD.isEmpty() &&
                   maxD.peekFirst() - minD.peekFirst() > k) {

                if (maxD.peekFirst() == nums[l]) maxD.pollFirst();
                if (minD.peekFirst() == nums[l]) minD.pollFirst();
                l++;
            }

            // dp[r+1] = sum(dp[l] .. dp[r])
            long sum = pref[r];
            if (l > 0) sum = (sum - pref[l - 1] + MOD) % MOD;

            dp[r + 1] = sum;
            pref[r + 1] = (pref[r] + dp[r + 1]) % MOD;
        }

        return (int) dp[n];
    }
}


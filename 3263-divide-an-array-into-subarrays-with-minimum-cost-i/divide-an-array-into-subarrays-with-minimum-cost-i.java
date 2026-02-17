class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;
        int a = Integer.MAX_VALUE;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int c = nums[0] + nums[i + 1] + nums[j + 1];
                a = Math.min(a, c);
            }
        }

        return a;
    }
}
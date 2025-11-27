class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int total = 0;
        for (int num : arr) total += num;
        
        // If total sum is not divisible by 3, impossible
        if (total % 3 != 0) return false;
        
        int target = total / 3;
        int sum = 0, count = 0;
        
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum == target) {
                count++;
                sum = 0; // reset for next partition
            }
            // If we already found 2 partitions, no need to check further
            if (count == 2 && i < arr.length - 1) return true;
        }
        
        return false;
    }
}
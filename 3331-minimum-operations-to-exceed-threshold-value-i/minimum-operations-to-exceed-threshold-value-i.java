class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int o = 0;
        for(int num : nums)
        {
            if(num < k)
            {
                o++;
            }else{
                break;
            }
        }
        return o;
    }
}
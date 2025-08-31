void moveZeroes(int* nums, int numsSize) {
    int temp[numsSize];
    int i,j=0;
    for(i=0; i<numsSize; i++)
    {
        if (nums[i]!=0)
            {
                temp[j++]= nums[i];
            }
    }
    while (j<numsSize)
    {
        temp[j++]=0;
    }
    for(i=0; i<numsSize; i++)
    {
        nums[i] = temp[i];
    }

}
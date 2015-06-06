int removeElement(int nums, int numsSize, int val) {
    
    for (int i = 0;inumsSize;++i)
    {
        if(nums[i] == val)
        {
            int j = 0;
            while((i+j+1) != numsSize)
            {
                nums[i+j] = nums[i+j+1];
                ++j;
            }
            --i;
            numsSize--;
        }
    }
    return numsSize;
}
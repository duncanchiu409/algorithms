// Find Median from a sorted array

#include <iostream>
#include <vector>

double findMedian(std::vector<int>& nums, int length){
    if(length%2==0){
        int index = length/2;
        return ((double)nums[index-1]+(double)nums[index])/2.0;
    }
    else{
        return nums[length/2];
    }
};
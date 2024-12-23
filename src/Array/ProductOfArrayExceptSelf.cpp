/*
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * 
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *  
 * 
 * Constraints:
 * 
 * 2 <= nums.length <= 105
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *  
 * 
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int result = 1;
        int noOfZero = 0;
        vector <int>res;
        // here we will use noOfZero cause
        // if count of 0s in an array is > 1 
        // then product at each index  will always be 0
        // if noOfZero == 1 then product at each index of array
        // is 0 except where 0 is situated in actual array.
        for (int num: nums) {
            if (num != 0)
                result *= num;
            else
                noOfZero += 1;
        }
        // if number of 0s in array greater than 1
        // then result is always 0
        if (noOfZero > 1)
            result = 0;
        for (unsigned i = 0; i< nums.size(); i++) {
            // if current element is non zero and array contains 
            // zero then some other element is zero so result is always
            // zero
            if (nums[i] != 0 && noOfZero)
                res.push_back(0);
            // if number of 0s is equal to 0 in an array
            // and current element is non 0 then result will be
            // total product of array devided by current element
            else if (nums[i] != 0)
                res.push_back(result/nums[i]);
            // this means no of 0s in array is 1
            // currrent element is 0 so result of product of array
            // except current element i.e. 0 in our case result
            else
                res.push_back(result);
        }
        return res;
    }
};
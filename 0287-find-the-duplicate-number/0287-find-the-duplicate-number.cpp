class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize two pointers, slow and fast, both starting at the first element of the array.
        int slow = nums[0];
        int fast = nums[0];

        // Floyd's Tortoise and Hare cycle detection
        while(true){
             slow = nums[slow];
            // Move the fast pointer two steps forward.
            fast = nums[nums[fast]];
            if(slow == fast)break;
        }
        // Reset the fast pointer back to the start of the array.
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
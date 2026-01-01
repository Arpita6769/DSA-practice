class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0 , rightMax = 0;
        int left = 0 , right = n-1;
        int total = 0;


        while(left < right){
            if(height[left] <= height[right]){
                if(leftMax <= height[left]){
                    leftMax = height[left];
                }
                else{
                    total += (leftMax - height[left]);
                }
                left++;
            }
            else{
                if(rightMax <= height[right]){
                    rightMax = height[right];
                }
                else{
                    total += (rightMax - height[right]);
                }
                right--;
            }
        }
        return total;
    }
};

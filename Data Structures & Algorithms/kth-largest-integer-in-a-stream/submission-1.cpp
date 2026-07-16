class KthLargest {
public:
    int kth;
    std::vector<int> nums;
    KthLargest(int k, vector<int>& num):kth(k),nums(num){}
    
    int add(int val) {
        nums.push_back(val);

        int flip{};
        do{
            flip=0;
            for(int i{};i<nums.size()-1;i++){
                if(nums[i] > nums[i+1]){
                    swap(nums[i],nums[i+1]);
                    flip++;
                }
            }
        }while(flip);

        return nums[nums.size()-kth];
    }
};

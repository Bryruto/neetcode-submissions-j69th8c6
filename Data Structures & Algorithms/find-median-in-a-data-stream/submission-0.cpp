class MedianFinder {
private:
    std::vector<double> vec;
public:

    MedianFinder(){}
    
    void addNum(int num){
        if(vec.empty() || vec[vec.size()-1] <= num){
            vec.push_back(num);
            return;
        }

        for(int i{};i<vec.size();i++){
            if(vec[i] >= num){
                vec.insert(vec.begin() + i,static_cast<double>(num));
                break;
            }
        }

    }
    
    double findMedian(){
        int size = vec.size();
        return size%2 == 0 ? (vec[size/2 - 1] + vec[size/2])/2.0 : vec[size/2];
    }
};

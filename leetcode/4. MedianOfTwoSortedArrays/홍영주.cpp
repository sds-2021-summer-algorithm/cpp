class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        int index1 = 0;
        int index2 = 0;

        while(nums1.size() >index1 && nums2.size() >index2){
            // nums1 counting
            if(nums1[index1] < nums2[index2]){
                sorted.push_back(nums1[index1]);
                index1++;
            }else {
                sorted.push_back(nums2[index2]);
                index2++;
            }
        }

        while(nums1.size() > index1){
            sorted.push_back(nums1[index1]);
            index1++;
        }

        while(nums2.size() > index2){
            sorted.push_back(nums2[index2]);
            index2++;
        }

        /*
        for(int i = 0 ; i < sorted.size() ; i++){
            cout << sorted[i] << " " ;
        }*/
        int index = sorted.size() / 2;
        double sum = 0.0;
        // even number
        if(sorted.size() % 2 == 0){
            sum = ((double)(sorted[index] + sorted[index-1])) / 2;
        }else {
            // odd number
            sum = sorted[index];
        }

        return sum;
    }
};

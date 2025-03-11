class Solution {
public:
    int partition(vector<int>& a, int low, int high)
    {
        int i = low, j = high;
        int pivot = a[low];
        while(i < j){
            while(a[i] <= pivot and i <= high-1)i++;
            while(a[j] > pivot and j >= low+1)j--;

            if(i < j)swap(a[i],a[j]);
        }
        swap(a[low],a[j]);
        return j;
    }

    void quickSort(vector<int>& a, int low, int high)
    {
        if(low < high)
        {
            int idx = partition(a,low,high);
            quickSort(a,low,idx-1);
            quickSort(a,idx+1,high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};
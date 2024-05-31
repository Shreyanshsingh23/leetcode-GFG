class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
       sort(nums1,nums1.length-1,0);
       sort(nums2,nums2.length-1,0);
        // both arrays are sorted now

        int i = 0;
        int j = 0;

        ArrayList <Integer> list1 = new ArrayList<>();
        ArrayList <Integer> list2 = new ArrayList<>();


        // add the elements of nums1 which are not present in nums2 to list1
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] != nums2[j]){
                if(nums1[i] < nums2[j]){

                   if(i == 0 || (nums1[i] != nums1[i-1])){
                     list1.add(nums1[i]);
                     
                   }
                  i++;
                }
                else{
                    j++;
                }
            }
            else{
                i++;
                j++;
            }
        }

        while(i < nums1.length){
            if(i == 0 || (nums1[i] != nums1[i-1])){
                list1.add(nums1[i]);
            }
            i++;
        }

            i=0;
            j=0;

        // add the elements of nums2 which are not present in nums1 to list2
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] != nums2[j]){
                if(nums1[i] > nums2[j]){

                   if(j == 0 || (nums2[j] != nums2[j-1])){
                     list2.add(nums2[j]);
                     
                   }
                    j++;
                }
                else {
                    i++;
                }
            }
            else{
                i++;
                j++;
            }
        }

           while(j < nums2.length){
            if(j == 0 || (nums2[j] != nums2[j-1])){
                     list2.add(nums2[j]);
                     
                   }
                    j++;
        }

        List <List<Integer>> ansList = new ArrayList<>();
        ansList.add(list1);
        ansList.add(list2);

        return ansList;
    }

     static void sort(int[] arr,int r, int c){
        if(r==0){
            return;
        }

        if(c<r){
          if(arr[c] > arr[c+1]){
            swap(arr,c,c+1);
             sort(arr,r,c+1);
          }
          else{
            sort(arr,r,c+1);
          }

        }
        else{
             sort(arr,r-1,0);
        }
    }
    static void swap(int[] arr, int f, int s){
        int temp = arr[f];
        arr[f] = arr[s];
        arr[s] = temp;
    }
}

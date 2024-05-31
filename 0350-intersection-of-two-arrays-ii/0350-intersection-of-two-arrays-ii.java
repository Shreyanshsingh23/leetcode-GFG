class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
       bubbleSort(nums1,nums1.length-1,0);
        bubbleSort(nums2,nums2.length-1,0);
        // both arrays are sorted now

        int i = 0;
        int j = 0;

        ArrayList <Integer> list = new ArrayList<>();
        
        while(i<nums1.length && j<nums2.length){
            if(nums1[i] != nums2[j]){
                if(nums1[i] > nums2[j]){
                    j++;
                }
                else if(nums1[i] < nums2[j]){
                    i++;
                }
            }
            else{
              
                    list.add(nums1[i]);
                i++;
                j++;
               
            }
        }

        int[] ans = new int[list.size()];

        for(int k = 0; k < list.size();k++){
            ans[k]=list.get(k);
        }

        return ans;
        
    }
    static void bubbleSort(int[] arr,int r, int c){
        if(r==0){
            return;
        }

        if(c<r){
          if(arr[c] > arr[c+1]){
            swap(arr,c,c+1);
             bubbleSort(arr,r,c+1);
          }
          else{
            bubbleSort(arr,r,c+1);
          }

        }
        else{
             bubbleSort(arr,r-1,0);
        }
    }
    static void swap(int[] arr, int f, int s){
        int temp = arr[f];
        arr[f] = arr[s];
        arr[s] = temp;
    }
}
class Solution {
  public:
    void merge(vector<int> &arr,vector<int>&copy,int s,int e,int &ans){
        if(s==e)return;
        
        int mid=s+((e-s)/2);
        merge(arr,copy,s,mid,ans);
        merge(arr,copy,mid+1,e,ans);
        //here i have two sorted arrays
        //what i must do is merge them into one big sorted array
        int low=s;
        int high=mid+1;
        
        while(low<=mid && high<=e){
            if(arr[low]>1ll*2*arr[high]){
                ans+=mid-low+1;
                high++;
            }
            else{
                low++;
            }
        }
        
        
        
        int i=s;
        int j=mid+1;
        int k=s;
        
        while(i<=mid && j<=e){
            if(arr[i]<arr[j]){
                copy[k]=arr[i];
                i++;
                k++;
            }
            else{
                copy[k]=arr[j];
                j++;
                k++;
            }
        }
        while(i<=mid){
            copy[k]=arr[i];
            i++;
            k++;
        }
        while(j<=e){
            copy[k]=arr[j];
            j++;
            k++;
        }
        
        for(int l=s;l<=e;l++){
            arr[l]=copy[l];
        }
    }
  
    int reversePairs(vector<int> &arr) {
        // code here
        vector<int>copy=arr;
        int ans=0;
        merge(arr,copy,0,arr.size()-1,ans);
        return ans;
    }
};

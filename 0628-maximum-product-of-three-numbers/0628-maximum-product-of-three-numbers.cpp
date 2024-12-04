class Solution {
public:
    int maximumProduct(vector<int>& nums) 
{
   int max1=INT_MIN;
   int max2=INT_MIN;
   int max3=INT_MIN;
   
   int min1=INT_MAX;
   int min2=INT_MAX;
   
   //taking out the first 3 max number
   for(int i=0;i<nums.size();i++)
   {
   	  int num = nums[i];
   	  if(num > max1)        // max1=3 max2=2  max3=1  -->num=4--->  max1=4 max2=3 max3=2
   	  {
   	     max3=max2;
	     max2=max1;
		 max1=num;			
      }
      else if(num > max2)  //max1=5 max2=3 max1=1 -->num=4 --> max1=5 max2=4 max3=3
      {
      	 max3=max2;
      	 max2=num;
	  }
	  else if(num > max3)   //max1=5 max2=4 max1=1 -->num=2 --> max1=5 max2=4 max3=2
	  { 
	  	 max3=num;
	  }
   }
   //taking out the min 2 numbres
   for(int i=0;i<nums.size();i++)
   {
	  int num = nums[i];
	  
	  if(num < min1)
	  {
	  	 min2=min1;
	  	 min1=num;
	  }
	  else if(num < min2)
	  {
	     min2=num;
	  }
   }
   int temp1 = max2*max3*max1;
   int temp2 = min1*min2*max1;
   return max(temp1,temp2);
}
};
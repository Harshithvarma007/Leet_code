class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());

        while(left<right)
        {
            int hours=0;
            int mid= left +(right -left )/2;
            
                for (int pile : piles) {
            hours += (pile + mid - 1) / mid;
        }
            if (hours <= h)
            {
               
                right=mid;
            }
            else
            {
                left=mid+1; 
            }

            
            

        }
        return left;

        
    }
};
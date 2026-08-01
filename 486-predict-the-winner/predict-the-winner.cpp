class Solution {
public:


    int generator(int score1,int score2,int n,vector<int>&nums,int i,int j,bool flag){
        if(i>j){
            return score1; 
        }
        //pick for p1
        if(flag){
            int left=generator(score1+nums[i],score2,n,nums,i+1,j,!flag);
            int right=generator(score1+nums[j],score2,n,nums,i,j-1,!flag);
            return max(left,right);//if any turn the player1 is winning
        }
        else{
            int left=generator(score1,score2+nums[i],n,nums,i+1,j,!flag);
            int right=generator(score1,score2+nums[j],n,nums,i,j-1,!flag);
            return min(left,right);//we try that to return the min so that the p2 can loose 
        }
    }

    //score1->p1
    //score2->p2
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(auto it:nums){
            total+=it;
        }
        int score1=generator(0,0,n,nums,0,n-1,true);
        int score2=total-score1;
        return score1>=score2;
    }
};
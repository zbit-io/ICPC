#include <iostream>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> >matrix;
    int target,m,n;
    bool ans=false;
     bool binary_search(int low,int high,const vector<int>&arr)const{
        while(low<=high){
            int mid=(low+high)>>1;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return false;
    }
    void f(int p){
        if(ans||p>=m||p>=n){
            return;
        }
        if(binary_search(p, n-1, matrix[p])){
            ans=true;
        }
       
       vector<int>temp;

       for(int i=0;i<m;i++){
           temp.push_back(matrix[i][p]);
       }

       if(binary_search(p, m-1, temp)){
            ans=true;
       }
       f(n+1);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        this->m=matrix.size();
        this->n=matrix.front().size();
        this->matrix=std::move(matrix);
        this->target=target;
        f(0);
        return ans;
    }
};
int main(){
    
}
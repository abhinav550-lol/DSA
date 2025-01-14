class Solution 
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        stack<int> s;
        for (int i = 0; i < n; i++) 
            s.push(i);
        
        while (s.size() > 1) 
        {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            
            if (M[A][B] == 0) 
                s.push(A);
            else 
                s.push(B);
        }
        
        int potentialCelebrity = s.top();
        
        // Check if potential celebrity is known by everyone.
        for (int i = 0; i < n; i++) 
        {
            if (i != potentialCelebrity && (M[i][potentialCelebrity] == 0 || M[potentialCelebrity][i] == 1)) 
                return -1;
        }
        
        return potentialCelebrity;
    }
};
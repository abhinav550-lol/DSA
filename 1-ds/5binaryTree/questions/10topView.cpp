    {
        //Your code here
          map<int , int> m;
    queue<pair<Node* ,int>> q;
    vector<int> res;

    if(root == NULL ) return res;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        int xAxis = curr.second;
        Node* currNode = curr.first;
        if(m.find(xAxis) == m.end()) m[xAxis] = currNode -> data;
        

        if(currNode -> left) q.push(make_pair(currNode->left,xAxis -1));
        if(currNode -> right) q.push(make_pair(currNode->right,xAxis +1));
    }
    for(auto i : m){
        res.push_back(i.second);
    }
    return res;
    }
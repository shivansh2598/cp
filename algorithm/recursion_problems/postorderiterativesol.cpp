void postOrder(Node* root)
{
    stack<pair<Node *,int>>st;
    st.push(make_pair(root,0));
    
    while(!st.empty())
    {
        pair<Node *, int>No = st.top();
        st.pop();
        
        if(No.second==1)
        {
            cout<<No.first->data<<" ";
        }
        else
        {
            No.second=1;
            st.push(No);
            if(No.first->right!=NULL)
            st.push(make_pair(No.first->right,0));
            if(No.first->left!=NULL)
            st.push(make_pair(No.first->left,0));
            
            
        }
       
    }
}


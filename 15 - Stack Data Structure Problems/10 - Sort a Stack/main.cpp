void sortedInsertion(stack<int> &st, int num){
    if(st.empty() || st.top() <= num){
        st.push(num);
        return;
    }
    
    int preserveNum = st.top();
    st.pop();
    
    sortedInsertion(st, num);
    
    st.push(preserveNum);
}

void SortedStack :: sort() {
    if(s.empty()) return;
    
    int preserveNum = s.top();
    s.pop();
    
    sort();
    
    sortedInsertion(s, preserveNum);
}

Do the same thing for this source code.

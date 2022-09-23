// https://practice.geeksforgeeks.org/problems/sort-a-stack/1
// https://www.youtube.com/watch?v=MOGBRkkOhkY
// PLEASE PLEASE DRY RUN

// this fn place val in sorted stack at its place
// pop elements in stack and place in temp variable till we have emptied stack or at correct pos to push
// push val and return, after that while backtracking it will place the pop elements again
void insert(stack<int> &s, int val){
    
    // base case and case when val > means found correct pos to push val
    if (s.empty() || s.top() <= val) {
        s.push(val);
        return;
    }
    // place top in temp and pop it
    // call fn again with val and s as arguments
    // push back temp in backtracking
    int temp = s.top();
    s.pop();
    insert(s, val);
    s.push(temp);
}

// we use backtracing here
// first pop all elements from stack and save it in a variable (saved in recursion stack)
// after stack empty, start backtracing and sort stack
// insert the val in sorted stack at correct pos using insert function
void sort_stack(stack<int> &s){
    
    // base case
    if (s.empty()) return;
    
    // pop out topmost val and store in val
    // sort stack will sort the remaining stack
    // then place val at correct sorted pos using insert fn
    int val = s.top();
    s.pop();
    sort_stack(s);
    insert(s, val);
}

// main
void SortedStack :: sort(){
   sort_stack(s);
}

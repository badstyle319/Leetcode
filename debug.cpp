#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int value;
    Node(int x): value(x) {}
    bool operator <(const Node& node) const
    {
        // return this < &node;
        size_t addA = (size_t)this;
        size_t addB = (size_t)&node;
        
        cout << (void*)addA << " " << (void*)addB << endl;
        
        return true;
        
        // return this->value < node.value;
    }
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef DBG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    
    // int a[] = {1, 2, 3, 4, 5};
    
    // printf("address of a: %x\n", &a);
    // for(int i = 0; i < 5; i++)
        // printf("address of a[%d]: %x\n", i, &a[i]);
    // printf("address of (&a+1): %x\n", (&a+1));
    // printf("address of *(&a+1): %x\n", *(&a+1));
    
    
    set<Node> s;
    
    Node a(1), b(1);
    
    s.insert(a);
    s.insert(b);
    
    cout << s.size() << endl;
    // if(s.count(a))
        // cout << "a found" << endl;
    // else
        // cout << "a not found" << endl;
    
#ifdef DBG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
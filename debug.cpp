#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef DBG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    
    int a[] = {1, 2, 3, 4, 5};
    
    printf("address of a: %x\n", &a);
    for(int i = 0; i < 5; i++)
        printf("address of a[%d]: %x\n", i, &a[i]);
    printf("address of (&a+1): %x\n", (&a+1));
    printf("address of *(&a+1): %x\n", *(&a+1));
    
#ifdef DBG
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
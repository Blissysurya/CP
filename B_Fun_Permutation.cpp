#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        vector<int> ans;

        if (n == 2)
        {
            if (vec[0] == 2)
            {
                ans.push_back(1);
                ans.push_back(2);
            }
            else
            {
                ans.push_back(2);
                ans.push_back(1);
            }

            cout << ans[0] << " " << ans[1];
        }
        else
        {

            for (int i = 0; i < n; i++)
            {
                if (vec[i] - n == 0)
                {
                    ans.push_back(n);
                }
                else
                {
                    ans.push_back(abs(vec[i] - n));
                }
            }

            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
        }

        cout << endl;
    }
}
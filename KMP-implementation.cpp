// Interview-bit question: https://www.interviewbit.com/problems/implement-strstr.

void compute_lps(string s, vector<int>& lps) {
    //     j
    // aabcaabd
    //  i
    int i = 0, j = 1;
    while(j < s.length()) {
        if (s[i] == s[j]) {
            lps[j] = i + 1;
            i++;
        } else {
            i = 0;
        }
        j++;
    }
}

int Solution::strStr(const string A, const string B) {
    // String A is Haystack;
    // String B is needle;
    int ans = -1;
    if (A.length() == 0 || B.length() == 0) {
        return ans;
    }

    if (A.length() < B.length()) {
        return ans;
    }

    // Lowest proper prefix/suffix.
    vector<int> lps(B.length(), 0);

    compute_lps(B, lps);

    int i = 0, j = 0;

    while (j < A.length()) {
        if (A[j] == B[i]) {
            if (i == B.length() - 1) {
                return (j - B.length() + 1);
            }
            j++;
            i++;
        } else {
            if (i == 0) {
                // No backward movement/backtracking in B possible now.
                j++;
            } else {
                i = lps[i - 1];
            }
        }
    }

    return -1;
}

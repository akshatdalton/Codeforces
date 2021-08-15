// https://www.interviewbit.com/problems/implement-strstr.

int Solution::strStr(const string A, const string B) {
    if (A.length() == 0 || B.length() == 0) {
        return 0;
    }
    if (A.length() < B.length()) {
        return -1;
    }
    int len = B.length();
    size_t str_hash[A.length()];
    string s = A.substr(0, len - 1);
    // We have used in-built hash template; can also use a custom operator.
    // in-built provides the ability to avoid collision.
    hash<string> hasher;
    for (int i = len - 1; i < A.length(); i++) {
        s.push_back(A[i]);
        str_hash[i] = hasher(s);
        s.erase(0, 1);
    }
    size_t B_hash = hasher(B);
    for (int i = len - 1; i < A.length(); i++) {
        if (str_hash[i] == B_hash) {
            string s = A.substr(i - (len - 1), len);
            if (s.compare(B) == 0) {
                return (i - len + 1);
            }
        }
    }

    return -1;
}

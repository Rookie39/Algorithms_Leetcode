class Solution {
public:
    int *getNext(string needle) {
        int *next = new int[needle.length()];
        next[0] = -1;
        int k = -1, p = 0;

        while (p < needle.length() - 1)
        {
            if (k == -1 || needle[p] == needle[k])
            {
                next[++p] = ++k;
            }
            else
            {
                k = next[k];
            }
        }
        return next;
    }

	int strStr(string haystack, string needle) {
		if (needle.length() < 1)
		{
			return 0;
		}
		if (haystack.length() < 1 || haystack.length() < needle.length())
		{
			return -1;
		}

		int i = 0, j = 0;
		int *index = getNext(needle);
		while (i < static_cast<int>(haystack.length()) && j < static_cast<int>(needle.length()))
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				++j;
				++i;
			}
			else
            {
                j = index[j];
            }
		}
		if (j == needle.length())
        {
            return i - j;
        }
        else
        {
            return -1;
        }
	}
};
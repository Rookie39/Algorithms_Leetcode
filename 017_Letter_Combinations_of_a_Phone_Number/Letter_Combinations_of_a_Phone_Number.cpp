
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;

		/** 错误情况检测 */
		if (digits.length() == 0)
			return res;
		for (size_t i = 0; i < digits.length(); i++)
		{
			if (!isdigit(digits[i]))
				return res;
		}

		map<char, string> phone_map = { { '2',"abc" },{ '3',"def" },{ '4',"ghi" },{ '5',"jkl" },
										{ '6',"mno" },{ '7',"pqrs" },{ '8',"tuv" },{ '9',"wxyz" } };

		/** 求出结果数量 */
		int result_size = 1;
		for (size_t i = 0; i < digits.length(); i++)
		{
			result_size *= phone_map[digits[i]].length();
		}
		string *result = new string[result_size];

		int length = phone_map[digits[0]].length();  //数字对应字母数量
		int interval_size = result_size / length;  //字母间隔区间大小

		/** 求出所有数字对应的字母组合结果 */
		for (size_t i = 0; i < digits.length(); i++)
		{
			int count = 0;  //统计字母改变次数
			for (size_t j = 0; j < result_size; j++)
			{
				if(i == 0)  //第一个数字对应的字母填充情况
					result[j] += phone_map[digits[i]].at(j / interval_size);
				else if (i < digits.length() - 1)  //中间数字对应的字母填充情况
				{
					if (j != 0 && j % interval_size == 0)
						++count;
					result[j] += phone_map[digits[i]].at(count % length);
				}
				else  //最后一个数字对应的字母填充情况
					result[j] += phone_map[digits[i]].at(j % length);
			}
			if (i < digits.length() - 1)
			{
				length = phone_map[digits[i + 1]].length();  //获得下一个数字对应的字母数量
				interval_size /= length;  //获得下一个数字对应的字母间隔区间大小
			}
		}

        /** 输出结果 */
		for (size_t i = 0; i < result_size; i++)
		{
			res.push_back(result[i]);
		}
		return res;
	}
};

int main()
{
	string digits = "6789";
	vector<string> result;
	Solution sol;
	result = sol.letterCombinations(digits);
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}

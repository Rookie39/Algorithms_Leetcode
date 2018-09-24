/**
  * Author: Rookie118
  * Title: UTF-8_Validation
  * Completion time: 2018-09-24
 */

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if(data.size() == 0)
            return false;

        bitset<8> temp;
        vector<bitset<8>> bin_data;
        for(size_t i = 0; i < data.size(); ++i)
        {
            temp = data[i];
            bin_data.push_back(temp);
        }

        size_t count_visit = 0;
        bool isVisit[bin_data.size()] = {false};
        for(size_t i = 0; i < bin_data.size(); ++i)
        {
            size_t cn = 0;
            if(!isVisit[i])
            {
                for(size_t j = bin_data[i].size()-1; j >= 0; --j)
                {
                    if(bin_data[i][j] == 0)
                    {
                        isVisit[i] = true;
                        break;
                    }
                    else
                    {
                        ++cn;
                    }
                }
                ++count_visit;
                if(cn > 1 && cn < 5 && i+cn <= bin_data.size())
                {
                    for(size_t j = i+1; j < i+cn; ++j)
                    {
                        if(bin_data[j][7] == 1 && bin_data[j][6] == 0)
                        {
                            isVisit[j] = true;
                            ++count_visit;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else if(cn == 0)
                    continue;
                else
                    return false;
            }
        }
        if(count_visit == bin_data.size())
        {
            return true;
        }
        return false;
    }
};
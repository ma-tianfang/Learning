// 枚举
class Solution {
public:
    string getStr(int &num)
    {
        string ret="";
        if(num>=1000)
        {
            num-=1000;
            ret = "M";
        }
        else if(num>=900)
        {
            num-=900;
            ret = "CM";
        }
        else if(num>=500)
        {
            num-=500;
            ret = "D"; 
        }
        else if(num>=400)
        {
            num-=400;
            ret = "CD";
        }
        else if(num>=100)
        {
            num-=100;
            ret = "C";
        }
        else if(num>=90)
        {
            num-=90;
            ret = "XC";
        }
        else if(num>=50)
        {
            num-=50;
            ret = "L";
        }
        else if(num>=40)
        {
            num-=40;
            ret = "XL";
        }
        else if(num>=10)
        {
            num-=10;
            ret = "X";
        }
        else if(num>=9)
        {
            num-=9;
            ret = "IX";
        }
        else if(num>=5)
        {
            num-=5;
            ret = "V";
        }
        else if(num>=4)
        {
            num-=4;
            ret = "IV";
        }
        else if(num>=1)
        {
            num-=1;
            ret = "I";
        }
        return ret;
    }
    string intToRoman(int num) {
        string result = "";
        while(num>0)
        {
            result+=getStr(num);
        }
        return result;
    }
};

// 模拟2
const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};


// 硬编码
const string thousands[] = {"", "M", "MM", "MMM"};
const string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};

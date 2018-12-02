#ifndef YQ_SNUM_H
#define YQ_SNUM_H

#include <string>
#include "StrInt.h"
#include <exception>
#include <istream>
#include <ostream>

using std::string;
using std::istream;
using std::ostream;

#define MAXNUM_SNUM "2147483647"
#define MINNUM_SNUM "-2147483648"
#define INTLEN_SNUM 9

class snum
{
	private:
		string num="0";
		bool iszero();
		bool belowzero();
		
		static bool bigger_act(string a,string b);
		
		static string plus_act(string a,string b);
		static string minus_act(string a,string b);
		static string multiply_act(string a,string b);
		static string divide_act(string a,string b,string *remainer=nullptr);
		
		static bool isnum(char c,bool nozero=false);
		
	public:
		//通用函数 
		static string negative(const string &n);
		static bool belowzero(const string &n);
		static bool iszero(const string &n);
		
		static string getInt(const string &n);
		static bool checkInt(const string &n);
		static string abs(const string &n);
		
		static string plus(const string &a,const string &b);								//BUG!!!!
		static string minus(const string &a,const string &b);
		static string multiply(const string &a,const string &b);								//BUG!!!!
		static string divide(const string &a,const string &b,string *remainer=nullptr);
		static string remainer(const string &a,const string &b);
		
		static bool smaller(const string &a,const string &b,bool equal=false);
		static bool bigger(const string &a,const string &b,bool equal=false);
	
	
		//构造函数 
		snum() = default;
		snum(const snum&) = default;
		snum(snum&&) noexcept = default;
		snum(const string &n);
		snum(const char *n);
		snum(const int &n);
		//析构函数 
		~snum() = default;
		
		//普通操作 
		void set(int n);
		void set(const string &n="");
		int getInt() const;
		string getStr() const;
		
		void append(const string &n);
		void swap(snum &n);
		string::size_type size() const;
		const char* c_str() const;
		
		snum& inc();
		snum& dec();
		snum abs() const;
		snum divide(snum n,snum *remainer=nullptr);
		
		//类型转换运算符 
		operator int() const;
		operator string() const;
		explicit operator bool() const;
		
		//非成员函数运算符
		friend ostream& operator<<(ostream &os,const snum &n);
		friend istream& operator>>(istream &is,snum &n);
		
		friend snum operator+(const snum &sn,const int &n);
		friend snum operator+(const int &n,const snum &sn);
		friend snum	operator+(const snum &sn,const string &n);
		friend snum	operator+(const string &n,const snum &sn);
		friend snum operator+(const snum &sn,const snum &n);
		
		friend snum operator-(const snum &sn,const int &n);
		friend snum operator-(const int &n,const snum &sn);
		friend snum	operator-(const snum &sn,const string &n);
		friend snum	operator-(const string &n,const snum &sn);
		friend snum operator-(const snum &sn,const snum &n);
		
		friend snum operator*(const snum &sn,const int &n);
		friend snum operator*(const int &n,const snum &sn);
		friend snum	operator*(const snum &sn,const string &n);
		friend snum	operator*(const string &n,const snum &sn);
		friend snum operator*(const snum &sn,const snum &n);
		
		friend snum operator/(const snum &sn,const int &n);
		friend snum operator/(const int &n,const snum &sn);
		friend snum	operator/(const snum &sn,const string &n);
		friend snum	operator/(const string &n,const snum &sn);
		friend snum operator/(const snum &sn,const snum &n);
		
		friend snum operator%(const snum &sn,const int &n);
		friend snum operator%(const int &n,const snum &sn);
		friend snum	operator%(const snum &sn,const string &n);
		friend snum	operator%(const string &n,const snum &sn);
		friend snum operator%(const snum &sn,const snum &n);
		
		friend bool operator==(const snum &sn,const int &n);
		friend bool operator==(const int &n,const snum &sn);
		friend bool operator==(const snum &sn,const string &n);
		friend bool operator==(const string &n,const snum &sn);
		friend bool operator==(const snum &sn,const snum &n);
		
		friend bool operator!=(const snum &sn,const int &n);
		friend bool operator!=(const int &n,const snum &sn);
		friend bool operator!=(const snum &sn,const string &n);
		friend bool operator!=(const string &n,const snum &sn);
		friend bool operator!=(const snum &sn,const snum &n);
		
		friend bool operator>(const snum &sn,const int &n);
		friend bool operator>(const int &n,const snum &sn);
		friend bool operator>(const snum &sn,const string &n);
		friend bool operator>(const string &n,const snum &sn);
		friend bool operator>(const snum &sn,const snum &n);
		
		friend bool operator<(const snum &sn,const int &n);
		friend bool operator<(const int &n,const snum &sn);
		friend bool operator<(const snum &sn,const string &n);
		friend bool operator<(const string &n,const snum &sn);
		friend bool operator<(const snum &sn,const snum &n);
		
		friend bool operator>=(const snum &sn,const int &n);
		friend bool operator>=(const int &n,const snum &sn);
		friend bool operator>=(const snum &sn,const string &n);
		friend bool operator>=(const string &n,const snum &sn);
		friend bool operator>=(const snum &sn,const snum &n);
		
		friend bool operator<=(const snum &sn,const int &n);
		friend bool operator<=(const int &n,const snum &sn);
		friend bool operator<=(const snum &sn,const string &n);
		friend bool operator<=(const string &n,const snum &sn);
		friend bool operator<=(const snum &sn,const snum &n);
		
		//成员函数运算符 
		snum &operator=(const int &n);
		snum &operator=(const string &n);
		snum &operator=(const char *n);
		snum &operator=(const snum&) = default;
		snum &operator=(snum&& n) noexcept;
		
		char &operator[](string::size_type n);
		snum operator+() const;
		snum operator-() const;
		snum &operator++();
		snum &operator--();
		snum operator++(int);
		snum operator--(int);
		
		
		snum &operator+=(const int &n);
		snum &operator+=(const string &n);
		snum &operator+=(const snum &n);
		
		snum &operator-=(const int &n);
		snum &operator-=(const string &n);
		snum &operator-=(const snum &n);
		
		snum &operator*=(const int &n);
		snum &operator*=(const string &n);
		snum &operator*=(const snum &n);
		
		snum &operator/=(const int &n);
		snum &operator/=(const string &n);
		snum &operator/=(const snum &n);
		
		snum &operator%=(const int &n);
		snum &operator%=(const string &n);
		snum &operator%=(const snum &n);
		
		string operator()() const;
};

//private
bool snum::iszero()
{
	return iszero(num);
}
bool snum::belowzero()
{
	return belowzero(num);
}

bool snum::bigger_act(string a,string b)
{
	if(a.size() > b.size())
		return true;
	else
		return a>b;
}

bool snum::isnum(char c,bool nozero)
{
	return c<='9' && (nozero?c>='1':c>='0');
}

//核心计算函数 - 开始 
//加法 
string snum::plus_act(string a,string b)
{
	if(a.size()<b.size())
		a.swap(b);
	
	auto pa=a.end();
	auto pb=b.cend();
	while(--pb != b.cbegin())
	{
		*--pa+=*pb-'0';
		if(*pa>'9')
		{
			*pa-=10;
			++(*(pa-1));
		}
	}

	*--pa+=*pb-'0';
	if(pa == a.begin())
	{
		if(*pa>'9')
		{
			*pa-=10;
			return "1"+a;
		}
		else
			return a;
	}
	while(pa != a.begin())
	{
		if(*pa<='9')
			break;
		*pa-=10;
		++(*--pa);
	}
	if(a[0]>'9')
	{
		a[0]-=10;
		return "1"+a;
	}
	else
		return a;
}
//减法 
string snum::minus_act(string a,string b)
{
	bool negative_res=false,remove_zero=false;
	if(bigger(b,a))
	{
		negative_res=true;
		a.swap(b);
	}
	
	auto pa=a.end();
	auto pb=b.cend();
	do
	{
		if(*--pa < *--pb)
		{
			auto pa_b=pa;
			bool borrowed=false;
			while(--pa_b != a.begin())
				if(*pa_b == '0')
					*pa_b='9';
				else
				{
					--(*pa_b);
					borrowed=true;
					break;
				}
			if(!borrowed && pa_b == a.begin())
			{
				if(*pa_b == '1')
					remove_zero=true;
				--(*pa_b);
			}
			*pa+=10;
		}
		*pa-=*pb-'0';
	}
	while(pb != b.begin());
	
	if(remove_zero)
		return negative_res?negative(a.substr(1)):a.substr(1);
	else 
		return negative_res?negative(a):a;
}

//乘法辅助函数
void snum_multiply_help_add(string &res,const int pos,int val)
{
	if(pos<res.size())
		res[pos]+=val;
	else
	{
		while(pos>=res.size())
			res.append(1,'0');
		res[pos]=val+'0';
	}
	if(res[pos]>'9')
	{
		snum_multiply_help_add(res,pos+1,res[pos]-'0'-10);
		res[pos]-=10;
	}
}
//乘法 
string snum::multiply_act(string a,string b)
{
	if(a.size()<b.size())
		a.swap(b);
	
	string res;
	int stepa=0,stepb=0;
	auto pa=a.end();
	auto pb=b.cend();
	
	do
	{
		stepa=0;
		int ib=(*--pb)-'0';
		do
		{
			int total=ib*((*--pa)-'0');
			if(total>10)
			{
				snum_multiply_help_add(res,stepa+stepb+1,total/10);
				snum_multiply_help_add(res,stepa+stepb,total%10);
			}
			else
				snum_multiply_help_add(res,stepa+stepb,total);
			++stepa;
		}
		while(pa != a.begin());
		++stepb;
		pa=a.end();
	}
	while(pb != b.cbegin());
	
	auto pres=res.begin(),rpres=res.end()-1;
	while(pres<rpres)
		std::swap(*pres++,*rpres--);
	return res;
}
//除法 
string snum::divide_act(string a,string b,string *remainer)
{
	auto pa=a.cbegin()+b.size();
	string res(a.size(),'0'),sub(a.cbegin(),pa);
	auto pr=res.begin()+b.size()-1;
	--pa;
	while(true)
	{
		//取被除数 
		if(bigger(b,sub))
			do
			{
				if(pr >= res.end())
				{
					*remainer=sub;
					pr=res.begin();
					while(*pr == '0')
						++pr;
					return string(pr,res.end());
				}
				if(iszero(sub))
					sub.clear();
				sub.append(1,*pa++);
				++pr;
			}
			while(bigger(b,sub));
		
		//累减
		int count=0;
		while(bigger(b,sub))
		{
			++count;
			sub=minus(sub,b);
		}
		*pr=count+'0';
		
		//0处理 
		if(iszero(sub))
			while(pa+1 != a.cend() && *(pa+1) == '0')
			{
				++pa;++pr;
			}
		++pa;++pr;
	}
}
//核心计算函数 - 结束 


//通用函数 (static)
string snum::negative(const string &n)
{
	if(iszero(n))
		return "0";
	else if(belowzero(n))
		return n.substr(1);
	else
		return "-"+n;
}
bool snum::belowzero(const string &n)
{
	return !iszero(n) && n[0] == '-';
}
bool snum::iszero(const string &n)
{
	return n == "0" || n.empty() || n == "-0" || n == "-";
}

string snum::getInt(const string &n)
{
	string res;
	int i=0,len=n.size();
	
	for(;i<len;++i)
	{
		if(isnum(n[i],true))
			break;
		if(n[i] == '-' && i+1<len && isnum(n[i+1],true))
		{
			res="-";
			++i;
			break;
		}
	}
	
	for(;i<len;++i)
	{
		if(!isnum(n[i]))
			break;
		res.append(1,n[i]);
	}
	
	if(iszero(res))
		return "0";
	else
		return res;
}
bool snum::checkInt(const string &n)
{
	string s=getInt(n);
	return bigger(s,MINNUM_SNUM,1) && smaller(s,MAXNUM_SNUM,1);
}
string snum::abs(const string &n)
{
	if(belowzero(n))
		return n.substr(1);
	else
		return n;
}

string snum::plus(const string &a,const string &b)
{
	if(iszero(a))
		return b;
	if(iszero(b))
		return a;
	
	bool b1=belowzero(a),b2=belowzero(b);
	if(!b1 && b2)
		return minus_act(a,negative(b));
	else if(b1 && !b2)
		return minus_act(b,negative(a));
	else if(b1 && b2)
		return negative(plus_act(negative(a),negative(b)));
	else
		return plus_act(a,b);
}
string snum::minus(const string &a,const string &b)
{
	return plus(a,negative(b));
}
string snum::multiply(const string &a,const string &b)
{
	if(iszero(a) || iszero(b))
		return "0";
	if(a.size()+b.size() <= INTLEN_SNUM)
		return int2str(str2int(a)*str2int(b));
	
	bool b1=belowzero(a),b2=belowzero(b);
	if((b1 && b2) != (b1 || b2))	//xor
		return negative(multiply_act(abs(a),abs(b)));
	else
		return multiply_act(abs(a),abs(b));
}
string snum::divide(const string &a,const string &b,string *remainer)
{
	if(iszero(b))
		throw std::logic_error("[SNUM] Divide by zero!");
	
	auto setrm=[&remainer](const string &val)
				{
					if(remainer!=nullptr)
						*remainer=val;
				};
	if(iszero(a))
	{
		setrm("0");
		return "0";
	}
	else if(a == b)
	{
		setrm("0");
		return "1";
	}
	else if(smaller(abs(a),abs(b)))
	{
		setrm(a);
		return "0";
	}
	else if(checkInt(a) && checkInt(b))
	{
		int ia=str2int(a),ib=str2int(b);
		setrm(int2str(ia%ib));
		return int2str(ia/ib);
	}
	
	string res,rm;
	bool b1=belowzero(a),b2=belowzero(b);
	if((b1 && b2) != (b1 || b2))	//xor
		res=negative(divide_act(abs(a),abs(b),&rm));
	else
		res=divide_act(abs(a),abs(b),&rm);
	setrm(b1?negative(rm):rm);
	return res;
}
string snum::remainer(const string &a,const string &b)
{
	string remain;
	divide(a,b,&remain);
	return remain;
}

bool snum::smaller(const string &a,const string &b,bool equal)
{
	if(equal && a == b)
		return true;
	return !bigger(a,b,false);
}
bool snum::bigger(const string &a,const string &b,bool equal)
{
	if(equal && a == b)
		return true;
		
	bool b1=belowzero(a),b2=belowzero(b);
	if(!b1 && b2)
		return true;
	else if(b1 && !b2)
		return false;
	else if(b1 && b2)
		return !bigger_act(negative(a),negative(b));
	else
		return bigger_act(a,b);
}


//构造函数 
snum::snum(const string &n)
:num(getInt(n))		{}
snum::snum(const char *n)
:num(getInt(string(n)))		{}
snum::snum(const int &n)
:num(int2str(n))	{}

//普通操作 
void snum::set(int n)
{
	num=int2str(n);
}
void snum::set(const string &n)
{
	num=getInt(n);
}
int snum::getInt() const
{
	return checkInt(num)?str2int(num):0;
}
string snum::getStr() const
{
	return num;
}

void snum::append(const string &n)
{
	string s=getInt(n);
	if(belowzero(s))
		s=negative(s);
	num.append(s);
}
void snum::swap(snum &n)
{
	num.swap(n.num);
}
string::size_type snum::size() const
{
	return num.size();
}
const char* snum::c_str() const
{
	return num.c_str();
}

snum& snum::inc()
{
	num=plus(num,"1");
	return *this;
}
snum& snum::dec()
{
	num=minus(num,"1");
	return *this;
}
snum snum::abs() const
{
	return abs(num);
}
snum snum::divide(snum n,snum *remainer)
{
	return snum::divide(num,n.num,&(remainer->num));
}

//类型转换运算符 
snum::operator int() const
{
	return getInt();
}
snum::operator string() const
{
	return getStr();
}
snum::operator bool() const
{
	return !iszero(num);
}

//非成员函数运算符
ostream& operator<<(ostream &os,const snum &n)
{
	os << n.num;
}
istream& operator>>(istream &is,snum &n)
{
	if(!(is >> n.num))
		n.num="0";
	n.num=getInt(n.num);
}

snum operator+(const snum &sn,const int &n)
{
	snum tmp(sn);
	tmp+=n;
	return tmp;
}
snum operator+(const int &n,const snum &sn)
{
	snum tmp(sn);
	tmp+=n;
	return tmp;
}
snum operator+(const snum &sn,const string &n)
{
	snum tmp(sn);
	tmp+=n;
	return tmp;
}
snum operator+(const string &n,const snum &sn)
{
	snum tmp(sn);
	tmp+=n;
	return tmp;
}
snum operator+(const snum &sn,const snum &n)
{
	snum tmp(sn);
	tmp+=n;
	return tmp;
}

snum operator-(const snum &sn,const int &n)
{
	snum tmp(sn);
	tmp-=n;
	return tmp;
}
snum operator-(const int &n,const snum &sn)
{
	snum tmp(sn);
	tmp-=n;
	return tmp;
}
snum operator-(const snum &sn,const string &n)
{
	snum tmp(sn);
	tmp-=n;
	return tmp;
}
snum operator-(const string &n,const snum &sn)
{
	snum tmp(sn);
	tmp-=n;
	return tmp;
}
snum operator-(const snum &sn,const snum &n)
{
	snum tmp(sn);
	tmp-=n;
	return tmp;
}

snum operator*(const snum &sn,const int &n)
{
	snum tmp(sn);
	tmp*=n;
	return tmp;
}
snum operator*(const int &n,const snum &sn)
{
	snum tmp(sn);
	tmp*=n;
	return tmp;
}
snum operator*(const snum &sn,const string &n)
{
	snum tmp(sn);
	tmp*=n;
	return tmp;
}
snum operator*(const string &n,const snum &sn)
{
	snum tmp(sn);
	tmp*=n;
	return tmp;
}
snum operator*(const snum &sn,const snum &n)
{
	snum tmp(sn);
	tmp*=n;
	return tmp;
}

snum operator/(const snum &sn,const int &n)
{
	snum tmp(sn);
	tmp/=n;
	return tmp;
}
snum operator/(const int &n,const snum &sn)
{
	snum tmp(sn);
	tmp/=n;
	return tmp;
}
snum operator/(const snum &sn,const string &n)
{
	snum tmp(sn);
	tmp/=n;
	return tmp;
}
snum operator/(const string &n,const snum &sn)
{
	snum tmp(sn);
	tmp/=n;
	return tmp;
}
snum operator/(const snum &sn,const snum &n)
{
	snum tmp(sn);
	tmp/=n;
	return tmp;
}

snum operator%(const snum &sn,const int &n)
{
	snum tmp(sn);
	tmp%=n;
	return tmp;
}
snum operator%(const int &n,const snum &sn)
{
	snum tmp(sn);
	tmp%=n;
	return tmp;
}
snum operator%(const snum &sn,const string &n)
{
	snum tmp(sn);
	tmp%=n;
	return tmp;
}
snum operator%(const string &n,const snum &sn)
{
	snum tmp(sn);
	tmp%=n;
	return tmp;
}
snum operator%(const snum &sn,const snum &n)
{
	snum tmp(sn);
	tmp%=n;
	return tmp;
}

bool operator==(const snum &sn,const int &n)
{
	return sn.num == int2str(n);
}
bool operator==(const int &n,const snum &sn)
{
	return sn.num == int2str(n);
}
bool operator==(const snum &sn,const string &n)
{
	return sn.num == n;
}
bool operator==(const string &n,const snum &sn)
{
	return sn.num == n;
}
bool operator==(const snum &sn,const snum &n)
{
	return sn.num == n.num;
}

bool operator!=(const snum &sn,const int &n)
{
	return sn.num != int2str(n);
}
bool operator!=(const int &n,const snum &sn)
{
	return sn.num != int2str(n);
}
bool operator!=(const snum &sn,const string &n)
{
	return sn.num != n;
}
bool operator!=(const string &n,const snum &sn)
{
	return sn.num != n;
}
bool operator!=(const snum &sn,const snum &n)
{
	return sn.num != n.num;
}

bool operator>(const snum &sn,const int &n)
{
	return snum::bigger(sn.num,int2str(n));
}
bool operator>(const int &n,const snum &sn)
{
	return snum::bigger(int2str(n),sn.num);
}
bool operator>(const snum &sn,const string &n)
{
	return snum::bigger(sn.num,snum::getInt(n));
}
bool operator>(const string &n,const snum &sn)
{
	return snum::bigger(snum::getInt(n),sn.num);
}
bool operator>(const snum &sn,const snum &n)
{
	return snum::bigger(sn.num,n.num);
}

bool operator<(const snum &sn,const int &n)
{
	return snum::smaller(sn.num,int2str(n));
}
bool operator<(const int &n,const snum &sn)
{
	return snum::smaller(int2str(n),sn.num);
}
bool operator<(const snum &sn,const string &n)
{
	return snum::smaller(sn.num,snum::getInt(n));
}
bool operator<(const string &n,const snum &sn)
{
	return snum::smaller(snum::getInt(n),sn.num);
}
bool operator<(const snum &sn,const snum &n)
{
	return snum::smaller(sn.num,n.num);
}

bool operator>=(const snum &sn,const int &n)
{
	return snum::bigger(sn.num,int2str(n),true);
}
bool operator>=(const int &n,const snum &sn)
{
	return snum::bigger(int2str(n),sn.num,true);
}
bool operator>=(const snum &sn,const string &n)
{
	return snum::bigger(sn.num,snum::getInt(n),true);
}
bool operator>=(const string &n,const snum &sn)
{
	return snum::bigger(snum::getInt(n),sn.num,true);
}
bool operator>=(const snum &sn,const snum &n)
{
	return snum::bigger(sn.num,n.num,true);
}

bool operator<=(const snum &sn,const int &n)
{
	return snum::smaller(sn.num,int2str(n),true);
}
bool operator<=(const int &n,const snum &sn)
{
	return snum::smaller(int2str(n),sn.num,true);
}
bool operator<=(const snum &sn,const string &n)
{
	return snum::smaller(sn.num,snum::getInt(n),true);
}
bool operator<=(const string &n,const snum &sn)
{
	return snum::bigger(snum::getInt(n),sn.num,true);
}
bool operator<=(const snum &sn,const snum &n)
{
	return snum::smaller(sn.num,n.num,true);
}

//成员函数运算符 
char &snum::operator[](string::size_type n)
{
	return num[n];
}
snum &snum::operator=(const int &n)
{
	set(n);
	return *this;
}
snum &snum::operator=(const string &n)
{
	set(n);
	return *this;
}
snum &snum::operator=(const char *n)
{
	set(n);
	return *this;
}
snum &snum::operator=(snum&& n) noexcept
{
	num=std::move(n.num);
}

snum snum::operator+() const
{
	return *this;
}
snum snum::operator-() const
{
	return snum(negative(num));
}
snum &snum::operator++()
{
	return inc();
}
snum &snum::operator--()
{
	return dec();
}
snum snum::operator++(int)
{
	snum tmp(num);
	inc();
	return tmp;
}
snum snum::operator--(int)
{
	snum tmp(num);
	dec();
	return tmp;
}

snum &snum::operator+=(const int &n)
{
	num=plus(num,int2str(n));
}
snum &snum::operator+=(const string &n)
{
	num=plus(num,getInt(n));
}
snum &snum::operator+=(const snum &n)
{
	num=plus(num,n.num);
}

snum &snum::operator-=(const int &n)
{
	num=minus(num,int2str(n));
}
snum &snum::operator-=(const string &n)
{
	num=minus(num,getInt(n));
}
snum &snum::operator-=(const snum &n)
{
	num=minus(num,n.num);
}

snum &snum::operator*=(const int &n)
{
	num=multiply(num,int2str(n));
}
snum &snum::operator*=(const string &n)
{
	num=multiply(num,getInt(n));
}
snum &snum::operator*=(const snum &n)
{
	num=multiply(num,n.num);
}

snum &snum::operator/=(const int &n)
{
	num=divide(num,int2str(n));
}
snum &snum::operator/=(const string &n)
{
	num=divide(num,getInt(n));
}
snum &snum::operator/=(const snum &n)
{
	num=divide(num,n.num);
}

snum &snum::operator%=(const int &n)
{
	num=remainer(num,int2str(n));
}
snum &snum::operator%=(const string &n)
{
	num=remainer(num,getInt(n));
}
snum &snum::operator%=(const snum &n)
{
	num=remainer(num,n.num);
}

string snum::operator()() const
{
	return getStr();
}

#endif

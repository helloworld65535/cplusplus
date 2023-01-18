#include <iostream>
using namespace std;

class Fractions
{
private:
	/// @brief 分子
	long long numerator;
	/// @brief 分母
	long long denominator;

	friend ostream &operator<<(ostream &cout, const Fractions &fractions)
	{
		cout << "(" << fractions.numerator << "/" << fractions.denominator << ")" << endl;
		return cout;
	}

public:
	/// @brief 构造函数
	/// @param numerator 分子默认0
	/// @param denominator 分母默认为1
	Fractions(long long numerator = 0, long long denominator = 1) : numerator(numerator), denominator(denominator)
	{
		if (denominator < 0)
		{
			denominator = -denominator;
			numerator = -numerator;
		}
		Reduction();
		cout << "构造一个分数：" << *this << endl;
	}

	Fractions(const Fractions &other)
	{
		numerator = other.numerator;
		denominator = other.denominator;
		Reduction();
		cout << "复制一个分数：" << *this << endl;
	}

	double getDouble() const
	{
		return double(numerator) / double(denominator);
    }
	
	/// @brief 最大公约数 greatest_common_divisor
	/// @return 最大公约数
	long long GCD()
	{
		// 更相减损术
		long long a = abs(numerator);
		long long b = denominator;
		while (a != 0 && b != 0)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		if (a)
			return a;
		else
			return b;
	}
	/// @brief 约分
	void Reduction()
	{
		// 求最大公约数
		long long gcd = GCD();
		// 分子除以最大公约数
		numerator /= gcd;
		// 分母除以最大公约数
		denominator /= gcd;
	}

	Fractions operator=(const Fractions &other)
	{
		numerator = other.numerator;
		denominator = other.denominator;
	}

	Fractions operator+(const Fractions &other)
	{
		long long n = (this->numerator) * (other.denominator) + (this->denominator) * (other.numerator);
		long long d = (this->denominator) * (other.denominator);
		return Fractions(n, d);
	}
	Fractions &&operator+(Fractions &&other)
	{
		other.numerator = (this->numerator) * (other.denominator) + (this->denominator) * (other.numerator);
		other.denominator = (this->denominator) * (other.denominator);
		other.Reduction();
		return (Fractions &&) other;
	}

	Fractions operator-(const Fractions &other)
	{
		long long n = (this->numerator) * (other.denominator) - (this->denominator) * (other.numerator);
		long long d = (this->denominator) * (other.denominator);
		return Fractions(n, d);
	}
	Fractions &&operator-(Fractions &&other)
	{
		other.numerator = (this->numerator) * (other.denominator) - (this->denominator) * (other.numerator);
		other.denominator = (this->denominator) * (other.denominator);
		other.Reduction();
		return (Fractions &&) other;
	}

	Fractions operator*(const Fractions &other)
	{
		long long n = this->numerator * other.numerator;
		long long d = this->denominator * other.denominator;
		return Fractions(n, d);
	}
	Fractions &&operator*(Fractions &&other)
	{
		other.numerator = this->numerator * other.numerator;
		other.denominator = this->denominator * other.denominator;
		other.Reduction();
		return (Fractions &&) other;
	}

	Fractions operator/(const Fractions &other)
	{
		long long n = this->numerator * other.denominator;
		long long d = this->denominator * other.numerator;
		return Fractions(n, d);
	}
	Fractions &&operator/(Fractions &&other)
	{
		swap(other.numerator, other.denominator);
		other.numerator = this->numerator * other.numerator;
		other.denominator = this->denominator * other.denominator;
		other.Reduction();
		return (Fractions &&) other;
	}

	bool operator<(const Fractions &other)
	{
		return ((this->numerator) * (other.denominator) < (other.numerator) * (this->denominator));
	}
	bool operator>(const Fractions &other)
	{
		return ((this->numerator) * (other.denominator) > (other.numerator) * (this->denominator));
	}
	bool operator==(const Fractions &other)
	{
		return ((this->numerator) * (other.denominator) == (other.numerator) * (this->denominator));
	}
	bool operator<=(const Fractions &other)
	{
		return ((this->numerator) * (other.denominator) <= (other.numerator) * (this->denominator));
	}
	bool operator>=(const Fractions &other)
	{
		return ((this->numerator) * (other.denominator) >= (other.numerator) * (this->denominator));
	}
	bool operator!=(const Fractions &other)
	{
		return ((this->numerator) * (other.denominator) != (other.numerator) * (this->denominator));
	}
};

int main()
{
	// 使用两个以上匿名对象运算后的结果 初始化 需要重载operator=
	Fractions fractions = Fractions(123, 2254) * Fractions(645, 2342);
	printf("%.15lf\n", fractions.getDouble());
	double a = 123.0 / 2254 * 645 / 2342;
	printf("%.15lf\n", a);

	return 0;
}
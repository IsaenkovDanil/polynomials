// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;
template<int N>
struct poly {
    double data[N + 1];//koeffs
    //friend	poly<N -1> differnetiate(poly<N>& a);
    friend	ostream& operator<<(ostream& str, const poly& c) {
        for (int i = N; i >= 0; --i) {
            //str << c.data[i] << "*x^" << i << "+";
            if (i == 0) str << c.data[i];
            else {
                str << c.data[i] << " * x^" << i << " + ";
            }
        }return str;
    }

    template<int N, int M, int size  >
    friend poly<size> operator+(poly<N>& a, poly<M>& b);
};

template<int N, int M, int size = (N > M) ? N : M >
poly<size> operator+(poly<N>& a, poly<M>& b)
{
    poly<size>result = { 1,1,1 };
    for (int i = 0; i <= size; ++i) {
        double aValue = (i <= N) ? a.data[i] : 0;
        double bValue = (i <= M) ? b.data[i] : 0;
        result.data[i] = aValue + bValue;
    }
    return result;
}

template<int N>
poly<N - 1> differentiate(const poly<N>& a) {
    poly<N - 1> res;
    for (int i = 0; i < N; ++i) {
        res.data[i] = a.data[i + 1] * (i + 1);
    }
    return res;
}
template<int N>
poly<N> operator+(const poly<N>& a, double b) {
    poly<N> result = a;
    result.data[0] += b;
    return result;
}
template<int N>

poly<N> operator+(double b, poly<N>& a)
{
    return a + b;
}


int main()
{
    setlocale(LC_ALL, "ru");
    poly<3>p = { 1,4,3,2 };
    poly<1>q = { 2,5 };

    cout << p << endl << q << endl;

    cout << p + q << endl << differentiate(p);
    cout << endl;
    cout << endl;
    cout << p + 1651 << endl;
    cout << 8757 + p;

    /*  poly<3>pp = { -1,4,-3,2 };
      cout << "======" << endl << endl << " ---------- " << endl;
      poly<2>qq = differnetiate(pp); cout << endl;
      cout << qq;*/
      //p + q;
      //const double PI2 = asin(1); cout << PI2*2;

}



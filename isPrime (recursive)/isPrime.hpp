#include <vector>
#include <cmath>

bool _isPrime(long long num, std::vector<long long> div_list) {
    long long div = div_list[0];
    std::vector<long long> new_div_list = {};
    for (const long long& d : div_list) {if (d % div != 0) new_div_list.push_back(d);}
    div_list = new_div_list;
    if (div_list.empty()) return true; else
    if (num <= 1) return false; else
    if (num == 2) return true; else
    if (num % div == 0) return false;

    return _isPrime(num, div_list);
}

bool isPrime(long long num) {
    std::vector<long long> div_list = {};
    for (long long i = 2; i <= static_cast<long long>(sqrt(num)); ++i) {div_list.push_back(i);}
    return _isPrime(num, div_list);
}

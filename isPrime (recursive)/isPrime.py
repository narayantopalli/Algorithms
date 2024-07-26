import math


def isPrime(num: int) -> bool:
    div_list: list[int] = list(range(2, int(math.sqrt(num)) + 1))
    return _isPrime(num, div_list)


def _isPrime(num: int, div_list: list[int]) -> bool:
    div: int = div_list[0]
    # keep pruning list to make sure only primes are tested
    div_list: list[int] = [d for d in div_list if d % div != 0]
    if not div_list:
        return True
    if num <= 1:
        return False
    if num == 2:
        return True
    if num % div == 0:
        return False

    return _isPrime(num, div_list)


print(isPrime(257))

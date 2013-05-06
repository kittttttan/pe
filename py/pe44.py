#! /usr/bin/env python3

def pe44(limit=1500):
    """
    Find the smallest pair of pentagonal numbers
    whose sum and difference is pentagonal.
    """
    pents = [i * (3 * i - 1) >> 1 for i in range(1, limit << 1)]
    ps = set(pents)
    for i in range(limit):
        p1 = pents[i]
        for j in range(i + 1, (limit << 1) - 1):
            p2 = pents[j]
            diff = p2 - p1
            if p2 + p1 in ps and diff in ps:
                return (diff, p2, p1, j, i)
    return None

if __name__ == "__main__":
    ans = pe44()
    if ans is None:
        print("Not Found")
    else:
        print(ans)

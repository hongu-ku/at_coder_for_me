def main():
    N, M = [int(x) for x in input().split()]
    xy = [map(int, input().split()) for _ in range(M)]
    s, c = [list(i) for i in zip(*xy)]
    result = 0

    for i in range(M):
        if s[i] > N:
            result = -1
            print(result)
            return
        else:
            result = result + c[i] * 10**s[i]


if __name__ == '__main__':
    main()

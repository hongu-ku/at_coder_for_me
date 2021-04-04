def main():
    N = int(input())
    X = [int(x) for x in input().split()]
    result = 10000000000
    for p in range(101):
        num = 0
        for i in range(N):
            num = num + (X[i] - p)**2
        result = num if num < result else result
    print(result)


if __name__ == '__main__':
    main()

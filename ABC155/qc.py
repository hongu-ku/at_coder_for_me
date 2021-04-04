def main():
    N = int(input())
    S = [input() for x in range(N)]
    S.sort()
    num = 0
    m = 0
    s = [S[0]]
    for i in range(1, N):
        if S[i-1] == S[i]:
            num = num + 1
        else:
            num = 0
        if num > m:
            m = num
            s = [S[i]]
        elif num == m:
            s.append(S[i])
    # print(s)
    for str in s:
        print(str)


if __name__ == '__main__':
    main()

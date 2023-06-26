def maxsec(v):
    n = len(v)
    dp = [[x] for x in v]

    for i in range (1 , n):
        for j in range(0 , i):
            if v[i] > v[j] and len(dp[i]) < len(dp[j]) + 1 :
                dp[i] = dp[j] + [v[i]]

    return max(dp, key=len)

v = [11, 17, 5, 8, 6, 4, 7, 12, 3]
print(maxsec(v))
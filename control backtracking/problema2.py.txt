import numpy as np

def backtracking(c):
    n = len(c)
    nivel = 0
    s = [-1]*n
    voa = -(np.inf)
    soa = None  
    bact = 0  

    used = [0]*n  # Initialize the 'used' array
    n -=1

    while True:
        used[s[nivel]]-=1
        s[nivel] += 1
        used[s[nivel]]+=1
        if s[nivel] == 1:
            bact += c[nivel][s[nivel]]
        else:
            bact += c[nivel][s[nivel]] -c[nivel][s[nivel]-1]

        if (nivel == n ) and bact > voa:
            voa = bact
            soa = list(s)
        if nivel < n and used[s[nivel]] == 0:
            nivel += 1
        else:
            while not (s[nivel] < n) and nivel > 0:
                if s[nivel] < n:
                    bact -= c[nivel][s[nivel]]
                    used[s[nivel]] -= 1
                s[nivel] -= 1
                nivel -= 1
            if nivel == 0:
                break
    return soa, voa

c = [[178, 168,190,170], [183, 188, 168,175]]  
print(backtracking(c)) 
import numpy as np
   
def backtracking (p,b,M):
    n = len(p)
    nivel = 0
    s = [-1]*n
    soa = None
    voa = -(np.inf)
    pact = 0
    bact = 0
    n -=1
   
    while True :
        #Generar(pact,bact,p,b,nivel,s)
        s[nivel] = s[nivel] + 1
        pact = pact + p[nivel]*s[nivel]
        bact = bact + b[nivel]*s[nivel]
        if(nivel == n and pact <= M) and (bact > voa):
            voa = bact
            soa = list(s)
        if nivel < n and pact <= M:
            nivel = nivel + 1
            
        else:
            while True:
                if nivel < 0 or s[nivel] < 1:
                    break
                pact = pact - p[nivel]*s[nivel]
                bact = bact - b[nivel]*s[nivel]
                s[nivel] = -1
                nivel = nivel - 1
                
            if nivel < 0:
                break
            
    return soa,voa

   
print(backtracking([1,11,21,23,33],[11,21,31,33,43],61))
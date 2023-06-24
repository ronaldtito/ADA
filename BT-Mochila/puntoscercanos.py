import math

def problema4(Puntos,inicio,fin):
    n = fin - inicio
    if (n<3):
        mindistance = 10000
        distance = 0
        for i in range (inicio,fin-1):
            distance = math.dist(Puntos[i],Puntos[i+1])
            if distance < mindistance :
                mindistance = distance
                puntos = [(i,i+1),mindistance]
                distance = math.dist(Puntos[inicio],Puntos[fin-1])
        if distance < mindistance :
            mindistance = distance
            puntos = [(inicio,fin-1),mindistance]
        return puntos
        
    Psort = sorted(Puntos)
    mid = math.floor((fin+inicio) /2)
    izq = problema4(Psort,inicio,mid-1)
    der = problema4(Psort,mid,fin)

    if izq[1] < der[1]:
        return izq
    else:
        return der


puntos = [(2,3),(4,5),(7,2),(3,4),(6,6),(8,1),(3,2),(5,3),(8,5),(7,0),(6,4),(10,10)]
puntos2 = [(1,1),(3,3),(5,3),(6,1),(6,5),(7,8)]
puntos = sorted(puntos)
print(problema4(puntos2,0,6))

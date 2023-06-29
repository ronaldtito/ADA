def vecinos(laberinto, punto):
    n = len(laberinto)
    vecinos = []
    
    if punto[1]+1 < n and laberinto[punto[0]][punto[1]+1] != 1: 
        vecinos.append((punto[0],punto[1]+1))
    if punto[0]+1 < n and laberinto[punto[0]+1][punto[1]] != 1: 
        vecinos.append((punto[0]+1,punto[1]))
    if punto[1]-1 >= 0 and laberinto[punto[0]][punto[1]-1] != 1: 
        vecinos.append((punto[0],punto[1]-1))
    if punto[0]-1 >= 0 and laberinto[punto[0]-1][punto[1]] != 1: 
        vecinos.append((punto[0]-1,punto[1]))
        
    return vecinos
    
def FS(laberinto, inicio,fin):
    
    ruta = []
    stack = []
    
    stack.append(inicio)
    
    while stack:
        temp = stack[0]
        if temp == fin:
            ruta.append(temp)
            return ruta
        del stack[0]
        if temp not in ruta:
            ruta.append(temp)
            nbh = vecinos(laberinto,temp)
            for vecino in nbh:
                if vecino == fin:
                    ruta.append(vecino)
                    return ruta
                stack.insert(0,vecino)
            




laberinto = [[0,0,0,0,0,0],
            [1,0,0,1,0,1],
            [0,0,1,1,0,0],
            [0,1,1,1,0,1],
            [0,1,0,0,0,1],
            [0,0,0,1,0,1]]

print(FS(laberinto,(0,0),(5,4)))    
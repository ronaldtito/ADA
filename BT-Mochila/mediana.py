import random

def mediana(lst, pivot_fn=random.choice):
    if len(lst) % 2 == 1:
        return select(lst, len(lst) // 2, pivot_fn)
    else:
        return 0.5 * (select(lst, len(lst) // 2 - 1, pivot_fn) +
                      select(lst, len(lst) // 2, pivot_fn))

def select(lst, k, pivot_fn):
    if len(lst) == 1:
        return lst[0]

    pivot = pivot_fn(lst)

    lows = [el for el in lst if el < pivot]
    highs = [el for el in lst if el > pivot]
    pivots = [el for el in lst if el == pivot]

    if k < len(lows):
        return select(lows, k, pivot_fn)
    elif k < len(lows) + len(pivots):
        return pivots[0]
    else:
        return select(highs, k - len(lows) - len(pivots), pivot_fn)
        
print(mediana([2,3,4,1,7,5,6,9,8,10]))

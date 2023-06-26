import math

def dist(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def brute_force(points):
    min_dist = float('inf')
    pair = None
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            if dist(points[i], points[j]) < min_dist:
                min_dist = dist(points[i], points[j])
                pair = (points[i], points[j])
    return pair, min_dist

def strip_closest(strip, d, pair):
    min_dist = d
    strip.sort(key = lambda point: point[1])  
    for i in range(len(strip)):
        for j in range(i + 1, len(strip)):
            if not (strip[j][1] - strip[i][1]) < min_dist:
                break
            if dist(strip[i], strip[j]) < min_dist:
                min_dist = dist(strip[i], strip[j])
                pair = strip[i], strip[j]
    return pair, min_dist

def closest_pair(points):
    if len(points) <= 3:
        return brute_force(points)

    mid = len(points) // 2
    left_half = points[:mid]
    right_half = points[mid:]

    pair1, dist1 = closest_pair(left_half)
    pair2, dist2 = closest_pair(right_half)

    if dist1 <= dist2:
        d = dist1
        min_pair = pair1
    else:
        d = dist2
        min_pair = pair2

    strip = []
    for point in points:
        if abs(point[0] - points[mid][0]) < d:
            strip.append(point)

    strip_pair, strip_dist = strip_closest(strip, d, min_pair)

    if d <= strip_dist:
        return min_pair, d
    else:
        return strip_pair, strip_dist


# Ejemplo de uso:

points = [(2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (3, 4)]
points.sort()
print("El par de puntos más cercano es: ", closest_pair(points))

def find_cover(graph):
    # Convertir el grafo a un diccionario de adyacencia
    adjacency_dict = {key: set(val) for key, val in graph.items()}

    # Inicializar un conjunto para almacenar los vértices en el recubrimiento
    cover = set()

    # Mientras el grafo aún tenga aristas
    while any(adjacency_dict.values()):
        # Encontrar el vértice que está conectado al mayor número de aristas
        v = max(adjacency_dict, key=lambda v: len(adjacency_dict[v]))

        # Añadir el vértice al recubrimiento
        cover.add(v)

        # Eliminar el vértice y todas sus aristas del grafo
        for v2 in adjacency_dict[v]:
            adjacency_dict[v2].remove(v)
        del adjacency_dict[v]

    return cover

# Definición del grafo como un diccionario de Python
graph = {
    "A": ["B", "C", "E"],
    "B": ["A", "C", "D"],
    "C": ["A", "B", "D", "E"],
    "D": ["B", "C", "E", "F"],
    "E": ["A", "C", "D"],
    "F": ["D"]
}

print(find_cover(graph))


print(find_cover(graph))

import networkx as nx
import numpy as np
from scipy.spatial import distance
import matplotlib.pyplot as plt

def graph_coord():
    nodes = 10
    radio = 0.4
    semilla = 16
    G = nx.random_geometric_graph(nodes,radius = radio,seed = semilla)
    pos = nx.get_node_attributes(G,"pos")
    #----------DRAW--------------#

    nx.draw_networkx(G,pos) 
    plt.show()
#child = [n for n in nx.all_neighbors(self.graph,Node_temp['id'])]


def fun():
    print(distance.euclidean((2,2),(2,4)))

def graph_normal():
    G = nx.Graph()
    G.add_edges_from(
    [
        (0, 1, {"weight": 4}),
        (0, 7, {"weight": 8}),
        (1, 7, {"weight": 11}),
        (1, 2, {"weight": 8}),
        (2, 8, {"weight": 2}),
    ]
    )

    pos = nx.spring_layout(G)
    nx.draw_networkx(G,pos)
    nx.draw_networkx_edge_labels(G,pos,edge_labels={(u, v): d["weight"] for u, v, d in G.edges(data=True)}) 
    plt.show()
graph_normal()

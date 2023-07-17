import sys

def calcular_dijkstra(grafo, origem):
    # Inicialização das distâncias com infinito, exceto a origem que é zero
    distancias = {v: sys.maxsize for v in grafo}
    distancias[origem] = 0

    # Conjunto de vértices visitados
    visitados = set()

    while visitados != set(distancias):
        # Encontra o vértice não visitado com menor distância atual
        vertice_atual = None
        menor_distancia = sys.maxsize
        for v in grafo:
            if v not in visitados and distancias[v] < menor_distancia:
                vertice_atual = v
                menor_distancia = distancias[v]

        # Marca o vértice atual como visitado
        visitados.add(vertice_atual)

        # Atualiza as distâncias dos vértices vizinhos
        if vertice_atual is not None:
            for vizinho, peso in grafo[vertice_atual].items():
                if distancias[vertice_atual] + peso < distancias[vizinho]:
                    distancias[vizinho] = distancias[vertice_atual] + peso

    # Retorna as distâncias mais curtas a partir da origem
    return distancias

grafo = {
    '1': {'6': 71, '2': 33},
    '2': {'1': 45, '7': 42, '3': 65},
    '3': {'2': 100, '8': 80, '4': 17},
    '4': {'3': 91, '5': 22},
    '5': {'4': 90, '10': 24},
    '6': {'1': 50, '11': 89, '7': 23},
    '7': {'2': 71, '6': 81, '8': 58},
    '8': {'3': 43, '7': 28},
    '10': {'5': 29, '15': 48},
    '11': {'6': 13, '16': 52},
    '15': {'10': 20, '20': 52},
    '16': {'11': 75, '21': 50},
    '18': {'23': 46, '19': 35},
    '19': {'18': 73, '24': 16, '20': 2},
    '20': {'15': 0, '19': 17, '25': 13},
    '21': {'16': 16, '22': 24},
    '22': {'21': 4, '23': 19},
    '23': {'18': 21, '22': 43, '24': 78},
    '24': {'19': 4, '23': 58, '25': 36},
    '25': {'20': 63, '24': 39}
}

origem = '1'

caminhos_mais_curto = calcular_dijkstra(grafo, origem)

for destino, distancia in caminhos_mais_curto.items():
    print(f"Caminho mais curto de {origem} para {destino}: {distancia}")



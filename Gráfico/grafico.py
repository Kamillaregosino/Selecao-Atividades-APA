import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

try:
    df = pd.read_csv('../Data/resultados_complexidade.csv')
except FileNotFoundError:
    print("Erro: O arquivo 'Data/resultados_complexidade.csv' não foi encontrado.")
    exit()

plt.figure(figsize=(10, 6))

# Plotar o Tempo Real
plt.plot(df['N'], df['Tempo_Microsegundos'], 'ro-', label='Tempo Real (Experimento)')

# Plotar a Curva Teórica
escala = df['Tempo_Microsegundos'].max() / df['Teoria_NlogN'].max()
plt.plot(df['N'], df['Teoria_NlogN'] * escala, 'b--', label='Curva Teórica O(n log n) [Escalada]')

# Gráfico
plt.title('Comparação de Complexidade: Real vs Teórico')
plt.xlabel('Tamanho da Entrada (N)')
plt.ylabel('Tempo de Execução / Escala Teórica')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)


plt.show()
import numpy as np
from scipy.optimize import linprog

def optimize_production(P, M, S, materials, machines, production_time, MM, PP):
    variables = P * np.ones(S)
    
    c = np.zeros(S)
    
    A_eq = np.zeros((P, S))
    for i in range(P):
        A_eq[i] = materials[i] * machines[i] * production_time[i]
    
    b_eq = np.array([MM, PP])
    
    bounds = [(1, None) for _ in range(S)]
    
    result = linprog(c, A_eq=A_eq, b_eq=b_eq, bounds=bounds, method='highs')
    
    print("Optymalna ilość produktów w magazynie dla każdego rodzaju:")
    for i in range(S):
        print(f"Produkt_{i+1}: {result.x[i]}")

P = 5
M = 10
S = 3
materials = np.array([[5, 0, 6, 3, 0], [2, 3, 0, 1, 4], [0, 2, 1, 0, 3], [4, 1, 2, 3, 0], [0, 0, 5, 2, 1]])
machines = np.array([[1, 0, 1], [0, 1, 0], [1, 0, 0], [0, 1, 1], [0, 0, 1]])
production_time = np.array([2, 3, 1, 4, 2])
MM = 100
PP = 50

optimize_production(P, M, S, materials, machines, production_time, MM, PP)

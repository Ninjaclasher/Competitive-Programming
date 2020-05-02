#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**5+10)
MOD = 10**9+7

def solve(n):
    lines = [input() for i in range(n)]
    _i = 0
    def next():
        nonlocal lines
        nonlocal _i
        _i += 1
        return lines[_i - 1]

    # cache stores lines of the form (a, b) where y = ax+b
    cache = {}

    def recurse(funcname):
        assert funcname not in cache
        vals = [0, 1]
        while True:
            try:
                tokens = next().split()
            except IndexError:
                break
            if tokens[0] == 'ADD':
                vals[0] += int(tokens[1])
                vals[1] += int(tokens[1])
            elif tokens[0] == 'SUB':
                vals[0] -= int(tokens[1])
                vals[1] -= int(tokens[1])
            elif tokens[0] == 'MULT':
                vals[0] *= int(tokens[1])
                vals[1] *= int(tokens[1])
            elif tokens[0] == 'FUN':
                recurse(tokens[1])
            elif tokens[0] == 'END':
                break
            elif tokens[0] == 'CALL':
                func = tokens[1]
                assert func in cache
                a, b = cache[func]
                vals[0] = a * vals[0] + b
                vals[1] = a * vals[1] + b
            vals[0] %= MOD
            vals[1] %= MOD
        cache[funcname] = (vals[1] - vals[0], vals[0])
    
    recurse('_')
    return cache['_'][1] % MOD


t = int(input())

for i in range(t):
    print(solve(int(input())))

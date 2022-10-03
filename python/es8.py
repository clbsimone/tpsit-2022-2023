s = "ciao"

#le stringhe sono immutabili s[1] = '?' (errore)

s1 = s[0] + "?" + s[2] + s[3]

print(s1)

print(f'{s[0]}{"?"}{s[2: ]}')
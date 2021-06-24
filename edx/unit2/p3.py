balance = 999999
annualInterestRate = 0.18

monthlyInterestRate = annualInterestRate / 12.0

lo = balance / 12.0
hi = balance * (1 + monthlyInterestRate) ** 12 / 12.0

while lo <= hi:
    bal = balance
    pay = (lo + hi) / 2.0
    for _ in range(12):
        bal = (bal - pay) * (1 + monthlyInterestRate)

    if bal < 0:
        hi = pay - 0.001
    else:
        lo = pay + 0.001

print("Lowest Payment: %.2f" % pay)

balance = 3926
annualInterestRate = 0.2

for payment in range(10, balance, 10):
    bal = balance
    for _ in range(12):
        bal = (bal - payment) * (1 + (annualInterestRate / 12.0))

    if bal <= 0:
        print("Lowest Payment: ", payment)
        break

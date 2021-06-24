balance = 42
annualInterestRate = 0.2
monthlyPaymentRate = 0.04

for _ in range(12):
    balance = (balance * (1 - monthlyPaymentRate)) * (1 + (annualInterestRate / 12.0))

print("Remaining balance: %.2f" % balance)

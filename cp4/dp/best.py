# With memo
def best_itinerary(profit, quarantine, home):
    max_day = len(profit) - 1  # 0-indexed
    max_city = len(profit[0]) - 1  # 0-indexed
    max_idle = max(quarantine)

    memo = [[[-1 for i in range(max_idle + 1)] 
                 for j in range(max_city + 1)]
                 for k in range(max_day + 1)]

    def get_idle(city):
        return quarantine[city] if city in range(max_city + 1) else 0

    def earn(day, city, idle):
        if day > max_day or city < 0 or city > max_city:
            return 0

        if memo[day][city][idle] != -1:
            return memo[day][city][idle]

        stay = earn(day + 1, city, max(idle - 1, 0)) + (profit[day][city] if idle == 0 else 0)
        left = earn(day + 1, city - 1, get_idle(city - 1))
        right = earn(day + 1, city + 1, get_idle(city + 1))

        memo[day][city][idle] = max(stay, left, right)
        return memo[day][city][idle]

    return earn(0, home, 0)


if __name__ == "__main__":
    profit = [[6, 9, 7, 5, 9], 
              [4, 7, 3, 10, 9], 
              [7, 5, 4, 2, 8],
              [2, 7, 10, 9, 8], 
              [2, 7, 10, 9, 8], 
              [35, 5, 2, 6, 111]]
    quarantine = [3, 1, 5, 1, 2]
    home = 1

    print(best_itinerary(profit, quarantine, home))  # 111

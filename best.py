import copy

def best_itinerary(profit, quarantine, home):
    max_day = len(profit) - 1  # 0-indexed
    max_city = len(profit[0]) - 1  # 0-indexed

    def get_idle(city):
        return quarantine[city] if city in range(max_city + 1) else 0

    def earn(day, city, idle, path):
        if day > max_day or city < 0 or city > max_city:
            return 0
        
        path.append(city)

        stay = earn(day + 1, city, idle - 1, copy.deepcopy(path)) + (profit[day][city] if idle <= 0 else 0)
        left = earn(day + 1, city - 1, get_idle(city - 1), copy.deepcopy(path))
        right = earn(day + 1, city + 1, get_idle(city + 1), copy.deepcopy(path))

        result = max(stay, left, right)
        print(result, path)
        return result

    return earn(0, home, 0, [])


if __name__ == "__main__":
    profit = [[6, 9, 7, 5, 9], [4, 7, 3, 10, 9], [7, 5, 4, 2, 8],
              [2, 7, 10, 9, 8], [2, 7, 10, 9, 8], [35, 5, 2, 6, 111]]
    quarantine = [3, 1, 5, 1, 2]
    home = 1

    print(best_itinerary(profit, quarantine, home)) # 111

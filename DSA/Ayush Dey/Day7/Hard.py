#Buying Cheapest Property
#Author - Ayush Dey

def min_cost_to_buy_properties(n, station, p):
    import bisect
    station.sort()

    def calc_cost(position, stations):
        index = bisect.bisect_left(stations, position)
        cost = float('inf')
        if index < len(stations):
            cost = min(cost, abs(stations[index] - position))
        if index > 0:
            cost = min(cost, abs(stations[index - 1] - position))
        return cost

    low, high = min(station) - p, max(station) + p
    total_cost = 0
    bought_positions = []

    while p > 0:
        min_cost = float('inf')
        for pos in range(low, high):
            if pos not in station and pos not in bought_positions:
                cost = calc_cost(pos, station)
                if cost < min_cost:
                    min_cost = cost
                    min_pos = pos

        total_cost += min_cost
        bought_positions.append(min_pos)
        station.append(min_pos)
        station.sort()
        p -= 1

    return total_cost


def main():
    n = int(input())
    station = list(map(int, input().split()))
    p = int(input())
    result = min_cost_to_buy_properties(n, station, p)
    print(result)

if __name__ == "__main__":
    main()

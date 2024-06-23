def climbing_leaderboard(leaderboard, player_scores):
    unique_leaderboard = sorted(set(leaderboard), reverse=True)
    results = []
    index = len(unique_leaderboard) - 1
    
    for score in player_scores:
        while index >= 0 and score >= unique_leaderboard[index]:
            index -= 1
        results.append(index + 2)
    return results
leaderboard = [100, 90, 90, 80]
player_scores = [70, 80, 105]
print(climbing_leaderboard(leaderboard, player_scores))

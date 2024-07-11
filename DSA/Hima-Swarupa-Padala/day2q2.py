def climbingLeaderboard(leaderboard_scores, player_scores):
    leaderboard_scores = sorted(set(leaderboard_scores), reverse=True)
    result = []
    for score in player_scores:
        leaderboard_rank = len([x for x in leaderboard_scores if x > score])
        result.append(leaderboard_rank + 1)
    return result

leaderboard_scores = [120, 100, 100, 80, 70, 50]
player_scores = [60, 97, 73, 80, 105]
print(climbingLeaderboard(leaderboard_scores, player_scores))  
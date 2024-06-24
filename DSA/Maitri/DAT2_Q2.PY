def climbing_leaderboard(leaderboard_scores, player_scores):
    
    unique_scores = sorted(set(leaderboard_scores), reverse=True)
    player_ranks = []

    for score in player_scores:
        while unique_scores and score >= unique_scores[-1]:
            unique_scores.pop()
        player_ranks.append(len(unique_scores) + 1)

    return player_ranks

leaderboard_scores = list(map(int, input("Enter the leaderboard scores separated by spaces: ").split()))

player_scores = list(map(int, input("Enter the player's scores separated by spaces: ").split()))


ranks = climbing_leaderboard(leaderboard_scores, player_scores)


print("Player's ranks after each new score: ", ranks)
